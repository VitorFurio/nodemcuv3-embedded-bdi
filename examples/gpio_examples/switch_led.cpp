/*
 * Blink onboard D4 led on D0 button press
 */
#include <stdio.h>
#include "driver/gpio.h"
#include "sdkconfig.h"
#include <unistd.h>

#define D0 GPIO_NUM_16
#define D4 GPIO_NUM_2

extern "C" {
	void app_main(void);
}

void app_main(void)
{
  double sleep_time_usec = 500000;

  // config pin
  gpio_set_direction(D0, GPIO_MODE_INPUT);
  gpio_set_direction(D4, GPIO_MODE_OUTPUT);

  while(1)
  {
    gpio_set_level(D4, 0);
    printf("D0: %d\n", gpio_get_level(D0));
    printf("\n-------------\n\n");
    usleep(sleep_time_usec);
    gpio_set_level(D4, 1);
    printf("D0: %d\n", gpio_get_level(D0));
    printf("\n-------------\n\n");
    usleep(sleep_time_usec);
  }
}