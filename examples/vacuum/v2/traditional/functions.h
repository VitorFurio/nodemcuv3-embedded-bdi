#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include "driver/gpio.h"
#include "driver/adc.h"
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

#define CYCLE_DELAY 500000
#define SUCK_DELAY 20000
#define D0 GPIO_NUM_16
#define D1 GPIO_NUM_5
#define D2 GPIO_NUM_4
#define D3 GPIO_NUM_0
#define D4 GPIO_NUM_2

void setup();

uint8_t action_suck();

uint8_t action_right();

uint8_t action_down();

uint8_t action_up();

uint8_t action_left();

uint8_t action_suck();

uint8_t update_dirty();

uint8_t update_start();

uint8_t update_pos(uint8_t var);

#endif /* FUNCTIONS_H_ */
