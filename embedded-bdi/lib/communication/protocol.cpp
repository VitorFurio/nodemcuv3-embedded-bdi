#include "protocol.h"

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "lwip/sockets.h"
#include "lwip/dns.h"
#include "lwip/netdb.h"

#include "esp_log.h"
#include "mqtt_client.h"

//#define ADDRESS     "mqtt://mqtt.eclipseprojects.io"
#define ADDRESS     "mqtt://192.168.1.12"

static const char *TAG = "MQTT_CLIENT";
static esp_mqtt_client_handle_t client = NULL;
static bool mqtt_connected = false;

// ------------------------- MQTT Functions ----------------------------------------
static esp_err_t mqtt_event_handler_cb(esp_mqtt_event_handle_t event)
{
    std::string message;
    switch (event->event_id) {
        case MQTT_EVENT_CONNECTED:
            //ESP_LOGI(TAG, "MQTT_EVENT_CONNECTED");
            mqtt_connected = true;
            break;
        case MQTT_EVENT_DISCONNECTED:
            ESP_LOGI(TAG, "MQTT_EVENT_DISCONNECTED");
            mqtt_connected = false;
            break;
        case MQTT_EVENT_SUBSCRIBED:
            //ESP_LOGI(TAG, "MQTT_EVENT_SUBSCRIBED, msg_id=%d", event->msg_id);
            break;
        case MQTT_EVENT_UNSUBSCRIBED:
            //ESP_LOGI(TAG, "MQTT_EVENT_UNSUBSCRIBED, msg_id=%d", event->msg_id);
            break;
        case MQTT_EVENT_PUBLISHED:
            //ESP_LOGI(TAG, "MQTT_EVENT_PUBLISHED, msg_id=%d", event->msg_id);
            break;
        case MQTT_EVENT_DATA:
           // ESP_LOGI(TAG, "MQTT_EVENT_DATA");
            //ESP_LOGI(TAG, "Message arrived on %.*s : %.*s\r", event->topic_len, event->topic, event->data_len, event->data);
            message.assign(event->data, event->data_len);
            Communicator::messageArrived(message);
            break;
        case MQTT_EVENT_ERROR:
            ESP_LOGI(TAG, "MQTT_EVENT_ERROR");
            break;
        default:
            ESP_LOGI(TAG, "Other event id:%d", event->event_id);
            break;
    }
    return ESP_OK;
}

static void mqtt_event_handler(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data) {
    mqtt_event_handler_cb((esp_mqtt_event_handle_t) event_data);
}

static void mqtt_app_start(const char* id)
{
    esp_mqtt_client_config_t mqtt_cfg = {
        .uri = ADDRESS,
        .client_id = id,
    };

    client = esp_mqtt_client_init(&mqtt_cfg);

    // Registrar eventos específicos
    esp_mqtt_client_register_event(client, MQTT_EVENT_CONNECTED, mqtt_event_handler, client);
    esp_mqtt_client_register_event(client, MQTT_EVENT_DISCONNECTED, mqtt_event_handler, client);
    esp_mqtt_client_register_event(client, MQTT_EVENT_SUBSCRIBED, mqtt_event_handler, client);
    esp_mqtt_client_register_event(client, MQTT_EVENT_UNSUBSCRIBED, mqtt_event_handler, client);
    esp_mqtt_client_register_event(client, MQTT_EVENT_PUBLISHED, mqtt_event_handler, client);
    esp_mqtt_client_register_event(client, MQTT_EVENT_DATA, mqtt_event_handler, client);
    esp_mqtt_client_register_event(client, MQTT_EVENT_ERROR, mqtt_event_handler, client);

    esp_mqtt_client_start(client);
    esp_mqtt_client_subscribe(client, "broadcast", 0);
    esp_mqtt_client_subscribe(client, id, 0);
}

static bool mqtt_send_message(const char* topic, const char* message) {
    if (client == NULL || !mqtt_connected) {
        ESP_LOGE(TAG, "MQTT client not ready");
        return false;
    }
    int msg_id = esp_mqtt_client_publish(client, topic, message, 0, 1, 0);
    if (msg_id != -1) {
        //ESP_LOGI(TAG, "Message sent to topic %s: %s.", topic, message);
        return true;
    } else {
        ESP_LOGE(TAG, "Failed to send message to topic %s", topic);
    }
    return false;
}

static void mqtt_app_stop(void) {
    if (client != NULL) {
        esp_mqtt_client_stop(client);
        esp_mqtt_client_destroy(client);
        client = NULL;
        mqtt_connected = false;
        ESP_LOGI(TAG, "MQTT client stopped and destroyed");
    } else {
        ESP_LOGE(TAG, "MQTT client is not initialized");
    }
}

// ------------------------------------------------------------------------------------

// ------------------------- Protocol Functions ----------------------------------------
void Protocol::initialize(const std::string& Id) {
    printf("Initialize client with ID: %s.\n", Id.c_str());
    mqtt_app_start(Id.c_str());
}

bool Protocol::send(const std::string& destination, const std::string& message) {
    return mqtt_send_message(destination.c_str(),message.c_str());
}

int Protocol::messageArrived() { // Implemented on mqtt_event_handler_cb.
    // Message arrived by the protocol in ILF/proposition format
    std::string message = "ILF/proposition";
    Communicator::messageArrived(message);
    return 1;
}

int Protocol::disconnect() {
    printf("Disconnect MQTT client.\n");
    mqtt_app_stop();
    return 0;
}
// ------------------------------------------------------------------------------------

