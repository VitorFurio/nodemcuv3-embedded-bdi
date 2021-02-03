/*
 * Blink onboard LED
 */
#include <stdio.h>
#include "driver/gpio.h"
#include "sdkconfig.h"
#include <unistd.h>

#define BLINK_GPIO GPIO_NUM_2

extern "C" {
	void app_main(void);
}

void app_main(void)
{
  double sleep_time_usec = 2000000;

  // config pin
  gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
  gpio_set_level(BLINK_GPIO, 1);

  while(1){
    gpio_set_level(BLINK_GPIO, 0);
    printf("ON\n");
    printf("gpio_get_level: %d\n", gpio_get_level(BLINK_GPIO));
    printf("\n-------------\n\n");
    usleep(sleep_time_usec);
    gpio_set_level(BLINK_GPIO, 1);
    printf("OFF\n");
    printf("gpio_get_level: %d\n", gpio_get_level(BLINK_GPIO));
    printf("\n-------------\n\n");
    usleep(sleep_time_usec);
  }
}