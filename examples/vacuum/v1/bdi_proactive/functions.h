#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include "driver/gpio.h"
#include "driver/adc.h"
#include <stdio.h>
#include <unistd.h>

#define D0 GPIO_NUM_16
#define D1 GPIO_NUM_5
#define D2 GPIO_NUM_4
#define D3 GPIO_NUM_0
#define D4 GPIO_NUM_2

int pos;
adc_config_t adc_config;  
uint16_t adc_data[100];

void setup()
{
  // config adc for usage
  adc_config.mode = ADC_READ_TOUT_MODE;
  adc_config.clk_div = 8;
  adc_init(&adc_config);

  // config gpio for usage
  gpio_set_direction(D0, GPIO_MODE_OUTPUT);
  gpio_set_direction(D1, GPIO_MODE_OUTPUT);
  gpio_set_direction(D2, GPIO_MODE_OUTPUT);
  gpio_set_direction(D3, GPIO_MODE_OUTPUT);
  gpio_set_direction(D4, GPIO_MODE_OUTPUT);

  // reset gpio values
  gpio_set_level(D0, 0);
  gpio_set_level(D1, 0);
  gpio_set_level(D2, 0);
  gpio_set_level(D3, 0);
  gpio_set_level(D4, 0);

  // set initial position
  pos = 1;
}

bool action_right()
{
  printf("Moving right...\t(P1->P2)\n");
  pos = 2;
  return true;
}

bool action_down()
{
  printf("Moving down...\t(P2->P4)\n");
  pos = 4;
  return true;
}

bool action_up()
{
  printf("Moving up...\t(P3->P1)\n");
  pos = 1;
  return true;
}

bool action_left()
{
  printf("Moving left...\t(P4->P3)\n");
  pos = 3;
  return true;
}

bool action_suck()
{
  for (int i = 0; i < 5; i++)
  {
    gpio_set_level(D4, 1);
    usleep(20000);
    gpio_set_level(D4, 0);
    usleep(20000);
  }
  printf("It's dirty!\tSucking...\n");
  return true;
}

bool update_dirty(bool var)
{
  if (ESP_OK == adc_read(&adc_data[0]))
  {
    if (
       (adc_data[0] < 400 && adc_data[0] > 320) ||
       (adc_data[0] < 440 && adc_data[0] > 400) ||
       (adc_data[0] < 490 && adc_data[0] > 440) ||
       (adc_data[0] < 550 && adc_data[0] > 490) ||
       (adc_data[0] < 705 && adc_data[0] > 685) ||
       (adc_data[0] < 725 && adc_data[0] > 705) ||
       (adc_data[0] < 740 && adc_data[0] > 725) ||
       (adc_data[0] > 740)
       )
    {
      return true;
    }
  }
  return false;
}

bool update_clean(bool var)
{
  if (ESP_OK == adc_read(&adc_data[0]))
  {
    if (
       (adc_data[0] < 400 && adc_data[0] > 320) ||
       (adc_data[0] < 440 && adc_data[0] > 400) ||
       (adc_data[0] < 490 && adc_data[0] > 440) ||
       (adc_data[0] < 550 && adc_data[0] > 490) ||
       (adc_data[0] < 705 && adc_data[0] > 685) ||
       (adc_data[0] < 725 && adc_data[0] > 705) ||
       (adc_data[0] < 740 && adc_data[0] > 725) ||
       (adc_data[0] > 740)
       )
    {
      return false;
    }
  }
  return true;
}

bool update_pos_1(bool var)
{
  if (pos == 1)
  {
    gpio_set_level(D0, 1);
    return true;
  }
  gpio_set_level(D0, 0);
  return false;
}

bool update_pos_2(bool var)
{
  
  if (pos == 2)
  {
    gpio_set_level(D1, 1);
    return true;
  }
  gpio_set_level(D1, 0);
  return false;
}

bool update_pos_3(bool var)
{
  if (pos == 3)
  {
    gpio_set_level(D2, 1);
    return true;
  }
  gpio_set_level(D2, 0);
  return false;
}

bool update_pos_4(bool var)
{
  if (pos == 4)
  {
    gpio_set_level(D3, 1);
    return true;
  }
  gpio_set_level(D3, 0);
  return false;
}

#endif /* FUNCTIONS_H_ */
