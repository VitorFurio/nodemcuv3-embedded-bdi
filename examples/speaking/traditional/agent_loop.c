/*
 * agent_loop.c
 *
 *  Created on: Feb 28, 2021
 *      Author: Matuzalem Muller
 */

#include <stdint.h>
#include "../data/functions.h"
#include "../data/wifi_station.h"

uint8_t pos;

void app_main()
{
  setup();

  wifi_init_sta();
  //action_connect_to_wifi(); // Chame uma vez durante a inicialização

  while (1)
  {
    
  }
}
