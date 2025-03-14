/*
 * agent.h
 *
 *  Created on: Sep 10, 2020
 *      Author: Matuzalem Muller
 */

#ifndef AGENT_COMM_H_
#define AGENT_COMM_H_

#include "../bdi/belief_base.h"
#include "../bdi/event_base.h"
#include "../bdi/intention_base.h"
#include "../bdi/plan_base.h"
#include "../communication/communicator.h"

/**
 * Implements the agent reasoning cycle.
 */
class AgentComm
{
private:
  BeliefBase * beliefs;
  EventBase * events;
  PlanBase * plans;
  IntentionBase * intentions;
  Plan * plan_to_act;
  Event event_to_process;
  Communicator * communicator; // Add communicator object

public:
  AgentComm(BeliefBase * beliefs,
        EventBase * events,
        PlanBase * plans,
        IntentionBase * intentions,
        Communicator * communicator);

  /**
   * Runs an iteration of the agent reasoning cycle
   */
  void run();
};

#endif /* AGENT_COMM_H_ */
