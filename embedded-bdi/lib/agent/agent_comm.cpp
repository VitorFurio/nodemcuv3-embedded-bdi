/*
 * agent.cpp
 *
 *  Created on: Sep 10, 2020
 *      Author: Matuzalem Muller
 */

#include "agent_comm.h"

AgentComm::AgentComm(BeliefBase * beliefs,
             EventBase * events,
             PlanBase * plans,
             IntentionBase * intentions,
             Communicator * communicator)
{
  this->beliefs = beliefs;
  this->events = events;
  this->plans = plans;
  this->intentions = intentions;
  this->plan_to_act = nullptr;
  this->communicator = communicator;
}

void AgentComm::run()
{
  // Update beliefs
  beliefs->update(events);
 
  communicator->update(beliefs, events); 
  
  // Checks if there are events to be processed
  if (!events->is_empty())
  {
    event_to_process = events->get_event();
    plan_to_act = plans->revise(&event_to_process, beliefs);
    if (plan_to_act) {
      intentions->add_intention(plan_to_act, &event_to_process);
    }
  }

  // Runs intention in case there are any
  if (!intentions->is_empty())
  {
    intentions->run_intention_base(beliefs, events, plans);
  }
}
