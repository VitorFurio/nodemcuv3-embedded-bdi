#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include "driver/gpio.h"
#include <stdio.h>

#define D0 GPIO_NUM_16

int pos;

bool action_configure()
{
  gpio_set_direction(D0, GPIO_MODE_INPUT);
  pos = 1;
  return true;
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
  printf("It's dirty!\tSucking...\n");
  return true;
}

bool update_dirty(bool var)
{
  return gpio_get_level(D0);
}

bool update_clean(bool var)
{
  return !gpio_get_level(D0);
}

bool update_pos_1(bool var)
{
  if (pos == 1)
  {
    return true;
  }
  return false;
}

bool update_pos_2(bool var)
{
  if (pos == 2)
  {
    return true;
  }
  return false;
}

bool update_pos_3(bool var)
{
  if (pos == 3)
  {
    return true;
  }
  return false;
}

bool update_pos_4(bool var)
{
  if (pos == 4)
  {
    return true;
  }
  return false;
}

#endif /* FUNCTIONS_H_ */
