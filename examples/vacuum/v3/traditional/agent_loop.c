/*
 * agent_loop.c
 *
 *  Created on: Feb 28, 2021
 *      Author: Matuzalem Muller
 */

#include <stdint.h>
#include "../data/functions.h"

uint8_t pos;
uint8_t stop;

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
        if (update_full_deposit())
        {
          action_empty();
        }
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
              stop = 1;
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
  }
}