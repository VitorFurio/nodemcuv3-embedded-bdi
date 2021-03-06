#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <stdio.h>
#include <unistd.h>
#include "driver/gpio.h"
#include "driver/adc.h"

#define CYCLE_DELAY 500000
#define SUCK_DELAY 20000
#define D0 GPIO_NUM_16
#define D1 GPIO_NUM_5
#define D2 GPIO_NUM_4
#define D3 GPIO_NUM_0
#define D4 GPIO_NUM_2

void setup();

bool action_right();

bool action_down();

bool action_up();

bool action_left();

bool action_suck();

bool update_button_start(bool var);

bool update_dirty(bool var);

bool update_clean(bool var);

bool update_pos_1(bool var);

bool update_pos_2(bool var);

bool update_pos_3(bool var);

bool update_pos_4(bool var);

#endif /* FUNCTIONS_H_ */
