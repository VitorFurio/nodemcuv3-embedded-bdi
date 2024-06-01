
#include "functions.h"

bool action_say_start()
{
  putchar('\n');
  printf("Hey, I'm Alice and I'm running...\n\n");
  return true;
}

bool action_say_hello()
{
  putchar('\n');
  printf("Hello Everyone, I'm Alice!\n");
  printf("[Question to Bob] Is it day or night now?\n");
  return true;
}

bool action_say_its_day()
{
  putchar('\n');
  printf("Ohh, it's day, I'm going for a walk in the park!\n");
  return true;
}

bool action_say_its_night()
{
  putchar('\n');
  printf("Meh, it's night, I'm going to sleep...\n");
  return true;
}

