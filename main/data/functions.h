#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <stdio.h>

bool action_action_1()
{
  printf("Action 1 - Successful\n");
  return true;
}

bool action_action_2()
{
  printf("Action 2 - Successful\n");
  return true;
}

bool action_action_3()
{
  printf("Action 3 - Successful\n");
  return true;
}

bool action_action_4()
{
  printf("Action 4 - Successful\n");
  return true;
}

bool action_action_5()
{
  printf("Action 5 - Successful\n");
  return true;
}

bool action_action_6()
{
  printf("Action 6 - Failure\n");
  return false;
}

bool action_action_7()
{
  printf("Action 7 - Failure handling\n");
  return true;
}

bool update_belief_1(bool var)
{
  return !var;
}

bool update_belief_2(bool var)
{
  return !var;
}

bool update_belief_3(bool var)
{
  return !var;
}

bool update_belief_4(bool var)
{
  return !var;
}

bool update_belief_5(bool var)
{
  return !var;
}

#endif /* FUNCTIONS_H_ */
