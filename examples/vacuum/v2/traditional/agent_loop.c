/*
 * agent_loop.c
 *
 *  Created on: Feb 03, 2021
 *      Author: Matuzalem Muller
 */

#include "driver/gpio.h"
#include "driver/adc.h"
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

#define D0 GPIO_NUM_16
#define D1 GPIO_NUM_5
#define D2 GPIO_NUM_4
#define D3 GPIO_NUM_0
#define D4 GPIO_NUM_2

adc_config_t adc_config;
uint16_t adc_data[100];

uint8_t dirt = 0;
uint8_t pos = 0;
uint8_t stop = 0;

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
  pos = 0;
  gpio_set_level(D0, 1);
}

uint8_t update_dirt(uint8_t var)
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
        (adc_data[0] > 740))
    {
      return 1;
    }
  }
  return 0;
}

uint8_t clean()
{
  for (int i = 0; i < 5; i++)
  {
    gpio_set_level(D4, 1);
    usleep(20000);
    gpio_set_level(D4, 0);
    usleep(20000);
  }
  printf("It's dirty!\tSucking...\n");
  return 1;
}

uint8_t update_start()
{
  if (ESP_OK == adc_read(&adc_data[0]))
  {
    if (
       (adc_data[0] < 605 && adc_data[0] > 550) ||
       (adc_data[0] < 630 && adc_data[0] > 605) ||
       (adc_data[0] < 650 && adc_data[0] > 630) ||
       (adc_data[0] < 680 && adc_data[0] > 650) ||
       (adc_data[0] < 705 && adc_data[0] > 680) ||
       (adc_data[0] < 725 && adc_data[0] > 705) ||
       (adc_data[0] < 740 && adc_data[0] > 725) ||
       (adc_data[0] > 740)
       )
    {
      return 1;
    }
  }
  return 0;
}

void app_main()
{
  setup();

  while (1)
  {
    if (update_start())
    {
      stop = 0;
      while (!stop)
      {
        usleep(500000);
        dirt = update_dirt(dirt);
        if (dirt)
        {
          clean();
        }
        else
        {
          switch (pos)
          {
          case 0:
            printf("Moving right...\t(P1->P2)\n");
            pos = 1;
            gpio_set_level(D0, 0);
            gpio_set_level(D1, 1);
            break;
          case 1:
            printf("Moving down...\t(P2->P4)\n");
            pos = 3;
            gpio_set_level(D3, 1);
            gpio_set_level(D1, 0);
            break;
          case 2:
            printf("Moving up...\t(P3->P1)\n");
            pos = 0;
            gpio_set_level(D0, 1);
            gpio_set_level(D2, 0);
            stop = 1;
            break;
          case 3:
            printf("Moving left...\t(P4->P3)\n");
            pos = 2;
            gpio_set_level(D2, 1);
            gpio_set_level(D3, 0);
            break;
          default:
            break;
          }
        }
      }
    }
  }
}