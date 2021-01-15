/*
 * D0, D1, and D2 are inputs (button switches)
 * D3, D4, and TX are outputs (leds)
 */
#include <stdio.h>
#include "driver/gpio.h"
#include "sdkconfig.h"
#include <unistd.h>

#define D0 GPIO_NUM_16
#define D1 GPIO_NUM_5
#define D2 GPIO_NUM_4
#define D3 GPIO_NUM_0
#define D4 GPIO_NUM_2
#define TX GPIO_NUM_1

extern "C" {
	void app_main(void);
}

void app_main(void)
{
  double sleep_time_usec = 500000;

  // config pin
  gpio_set_direction(D1, GPIO_MODE_INPUT);
  gpio_set_direction(D2, GPIO_MODE_INPUT);
  gpio_set_direction(D0, GPIO_MODE_INPUT);
  gpio_set_direction(D3, GPIO_MODE_OUTPUT);
  gpio_set_direction(D4, GPIO_MODE_OUTPUT);
  gpio_set_direction(TX, GPIO_MODE_OUTPUT);

  while(1)
  {
    gpio_set_level(D3, 0);
    gpio_set_level(D4, 0);
    gpio_set_level(TX, 0);
    printf("D0: %d\n", gpio_get_level(D0));
    printf("D1: %d\n", gpio_get_level(D1));
    printf("D2: %d\n", gpio_get_level(D2));
    printf("\n-------------\n\n");
    usleep(sleep_time_usec);
    gpio_set_level(D3, 1);
    gpio_set_level(D4, 1);
    gpio_set_level(TX, 1);
    printf("D0: %d\n", gpio_get_level(D0));
    printf("D1: %d\n", gpio_get_level(D1));
    printf("D2: %d\n", gpio_get_level(D2));
    printf("\n-------------\n\n");
    usleep(sleep_time_usec);
  }
}