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
    if (update_dirty())
    {
      action_suck();
    }
    else
    {
      switch (pos)
      {
        case 1:
          action_right();
          break;
        case 2:
          action_down();
          break;
        case 3:
          action_up();
          break;
        case 4:
          action_left();
          break;
        default:
          break;
      }
      update_pos(pos);
    }
  }
}