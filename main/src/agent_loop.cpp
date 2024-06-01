/*
 * agent_loop.cpp
 *
 *  Created on: Jun 28, 2020
 *      Author: Matuzalem Muller
 */

#include "agent/agent_comm.h"
#include "config/configuration.h"

#include <unistd.h>
#include <stdio.h>
#include "../data/functions.h"

extern "C" {
 	#include "../data/wifi_station.h"
	void app_main(void);
}

void app_main()
{
  AgentSettings agent_settings;

  BeliefBase * beliefs = agent_settings.get_belief_base();
  EventBase * events = agent_settings.get_event_base();
  PlanBase * plans = agent_settings.get_plan_base();
  IntentionBase * intentions = agent_settings.get_intention_base();
  Communicator * communicator = agent_settings.get_communicator();
  
  wifi_init_sta();
  communicator->initialize();
  
  AgentComm agent(beliefs, events, plans, intentions, communicator);
  
  
  while(true)
  {
    agent.run();
  }

  return;
}
