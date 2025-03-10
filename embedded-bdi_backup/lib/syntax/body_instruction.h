/*
 * body_instruction.h
 *
 *  Created on: May 31, 2020
 *      Author: Matuzalem Muller
 */

#ifndef SYNTAX_BODY_BODY_INSTRUCTION_H_
#define SYNTAX_BODY_BODY_INSTRUCTION_H_

#include "body_type.h"
#include "cenumfor_ilf.h"
#include "body_return.h"
#include "../bdi/belief_base.h"
#include "../bdi/event_base.h"
#include "../bdi/belief.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Body instructions can be belief operations, goal operations (adopt/drop
 * intention) or action in the environment.
 */
class BodyInstruction
{
private:
  /// Function to act in the environment
  bool (*_take_action)();
  Proposition _proposition;
  EventOperator _operator;
  /// Identifies whether the instruction is an Action, Goal or Belief operation
  BodyType _type;
  
  // For internal actions:
  Proposition _internal_action_prop;
  CENUMFOR_ILF _ilf;
  std::string _dest;

public:
  /**
   * Constructor for Actions
   * @param type Type of body instruction
   * @param prop Proposition that represents the Plan name
   * @param take_action Function that acts in the environment
   */
  BodyInstruction(BodyType type, Proposition prop, bool (*take_action)());

  /**
   * Constructor for Belief and Goal events
   * @param type Type of body instruction
   * @param prop Proposition that represents the Plan name
   * @param event_operator Event that will be generated by instruction
   */
  BodyInstruction(BodyType type, Proposition prop, EventOperator event_operator);

  /**
   * Run instruction. For BodyTypes:
   *   * Action: acts in the environment
   *   * Belief: Updates Belief and creates Belief addition/deletion Event
   *   * Goal: Creates Goal addition/deletion Event
   * @param belief_base Agent's BeliefBase
   * @param event_base Agent's EventBase
   */
  BodyReturn run_instruction(BeliefBase * belief_base, EventBase * event_base);

  BodyType get_BodyType()
  {
    return _type;
  }
  
  
  // For internal actions:
  void add_arg(CENUMFOR_ILF ilf);
  void add_arg(Proposition prop);
  void add_arg(std::string dest);
  
};

#endif /* SYNTAX_BODY_BODY_INSTRUCTION_H_ */
