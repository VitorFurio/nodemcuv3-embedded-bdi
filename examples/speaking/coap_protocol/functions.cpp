#include "functions.h"
#include "coap_server.h"

// vacuum position
int pos = 1;
// dirty space
bool dirty = true;
// if program is running for the first time, initialize srand
bool first_run = true;

/*---------------------------------------------------------------------------*/

void randomize_dirty()
{
  if (first_run)
  {
    srand(time(NULL));
    first_run = false;
  }
  dirty = rand()%2;
}

/*---------------------------------------------------------------------------*/

bool action_start_coap_server()
{
  std::cout << "Starting CoAP Server..." << std::endl;
  coap_server();
  return true;
}

bool action_right()
{
  std::cout << "Moving right...\t(P1->P2)" << std::endl;
  pos = 2;
  usleep(CYCLE_DELAY);
  randomize_dirty();
  return true;
}

bool action_down()
{
  std::cout << "Moving down...\t(P2->P4)" << std::endl;
  pos = 4;
  usleep(CYCLE_DELAY);
  randomize_dirty();
  return true;
}

bool action_up()
{
  std::cout << "Moving up...\t(P3->P1)" << std::endl;
  pos = 1;
  usleep(CYCLE_DELAY);
  randomize_dirty();
  return true;
}

bool action_left()
{
  std::cout << "Moving left...\t(P4->P3)" << std::endl;
  pos = 3;
  usleep(CYCLE_DELAY);
  randomize_dirty();
  return true;
}

bool action_suck()
{
  std::cout << "It's dirty!\tSucking..." << std::endl;
  usleep(CYCLE_DELAY);
  dirty = false;
  return true;
}

/*---------------------------------------------------------------------------*/

bool update_dirty(bool var)
{
  return dirty;
}

bool update_clean(bool var)
{
  return !dirty;
}

bool update_pos_1(bool var)
{
  return pos == 1;
}

bool update_pos_2(bool var)
{
  return pos == 2;
}

bool update_pos_3(bool var)
{
  return pos == 3;
}

bool update_pos_4(bool var)
{
  return pos == 4;
}
