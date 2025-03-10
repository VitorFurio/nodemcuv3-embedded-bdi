#include "wifi_station.h"
#include "esp_system.h"
#include "esp_log.h"
#include "nvs_flash.h"
static const char *TAG = "wifi station";

void app_main()
{
    ESP_ERROR_CHECK(nvs_flash_init());

    ESP_LOGI(TAG, "ESP_WIFI_MODE_STA");
    wifi_init_sta();
}
