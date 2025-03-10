#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include "esp_wifi.h"
#include "esp_system.h"
#include "nvs_flash.h"
#include "esp_event.h"
#include "esp_netif.h"
#include "protocol_examples_common.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "lwip/sockets.h"
#include "lwip/dns.h"
#include "lwip/netdb.h"

#include "esp_log.h"
#include "mqtt_client.h"

#define ADDRESS     "mqtt://mqtt.eclipseprojects.io"

static const char *TAG = "MQTT_EXAMPLE";
static esp_mqtt_client_handle_t client = NULL;
static bool mqtt_connected = false;

static void mqtt_send_message(const char* topic, const char* message);
static void mqtt_app_start(const char* id);
static void mqtt_app_stop(void);

static esp_err_t mqtt_event_handler_cb(esp_mqtt_event_handle_t event)
{
    switch (event->event_id) {
        case MQTT_EVENT_CONNECTED:
            ESP_LOGI(TAG, "MQTT_EVENT_CONNECTED");
            mqtt_connected = true;
            esp_mqtt_client_subscribe(client, "broadcast", 0);
            break;
        case MQTT_EVENT_DISCONNECTED:
            ESP_LOGI(TAG, "MQTT_EVENT_DISCONNECTED");
            mqtt_connected = false;
            break;
        case MQTT_EVENT_SUBSCRIBED:
            ESP_LOGI(TAG, "MQTT_EVENT_SUBSCRIBED, msg_id=%d", event->msg_id);
            break;
        case MQTT_EVENT_UNSUBSCRIBED:
            ESP_LOGI(TAG, "MQTT_EVENT_UNSUBSCRIBED, msg_id=%d", event->msg_id);
            break;
        case MQTT_EVENT_PUBLISHED:
            ESP_LOGI(TAG, "MQTT_EVENT_PUBLISHED, msg_id=%d", event->msg_id);
            break;
        case MQTT_EVENT_DATA:
            ESP_LOGI(TAG, "MQTT_EVENT_DATA");
            printf("TOPIC=%.*s\r\n", event->topic_len, event->topic);
            printf("DATA=%.*s\r\n", event->data_len, event->data);
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
    mqtt_event_handler_cb(event_data);
}

static void mqtt_app_start(const char* id)
{
    esp_mqtt_client_config_t mqtt_cfg = {
        .uri = ADDRESS,
        .client_id = id,
    };

    client = esp_mqtt_client_init(&mqtt_cfg);
    esp_mqtt_client_register_event(client, ESP_EVENT_ANY_ID, mqtt_event_handler, client);
    esp_mqtt_client_start(client);
}

static void mqtt_send_message(const char* topic, const char* message) {
    if (client == NULL || !mqtt_connected) {
        ESP_LOGE(TAG, "MQTT client not ready");
        return;
    }
    int msg_id = esp_mqtt_client_publish(client, topic, message, 0, 1, 0);
    if (msg_id != -1) {
        ESP_LOGI(TAG, "Message sent to topic %s, msg_id=%d", topic, msg_id);
    } else {
        ESP_LOGE(TAG, "Failed to send message to topic %s", topic);
    }
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

void app_main(void)
{
    ESP_LOGI(TAG, "[APP] Startup.. Free memory: %d bytes", esp_get_free_heap_size());

    ESP_ERROR_CHECK(nvs_flash_init());
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    ESP_ERROR_CHECK(example_connect());

    mqtt_app_start("ESP8266_Client");

    vTaskDelay(3000 / portTICK_PERIOD_MS);
    mqtt_send_message("broadcast", "ACHIEVE/hello");
    vTaskDelay(3000 / portTICK_PERIOD_MS);
    mqtt_app_stop();
}

