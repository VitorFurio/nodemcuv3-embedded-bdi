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
   gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);

   while(1){
      printf("Ligado\n");
      gpio_set_level(BLINK_GPIO, 0);
      usleep(1000000);
      gpio_set_level(BLINK_GPIO, 1);
      printf("Desligado\n");
      usleep(1000000);
   }
}