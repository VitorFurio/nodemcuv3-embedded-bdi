#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <string.h>
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/adc.h"
#include "esp_log.h"

// agent actions
bool action_trigger_alarm();
bool action_print_init();
bool action_print_alert();
bool action_print_default();
bool action_print_fire();
bool action_print_not_fire();
bool update_fire(bool var);

void setup();

#endif /* FUNCTIONS_H_ */

