/*
 * agent_loop.c
 *
 *  Created on: Feb 28, 2021
 *      Author: Matuzalem Muller
 */

#include <stdint.h>
#include "../data/functions.h"

uint8_t pos;

void app_main()
{
  setup();

  while (1)
  {
     action_connect_to_wifi();
         
  }
}
