/*
 * AgentSpeak code:
 *
 * !init.
 * 
 * +!init <- !!clean.
 * 
 * +!clean : clean <- !move; !!clean.
 * +!clean : dirty <- suck;  !!clean.
 * -!clean         <- !!clean.
 * 
 * +!move : pos_1 <- right.
 * +!move : pos_2 <- down.
 * +!move : pos_3 <- up.
 * +!move : pos_4 <- left.
 */ 

#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include "bdi/belief_base.h"
#include "bdi/event_base.h"
#include "bdi/plan_base.h"
#include "bdi/intention_base.h"
#include "../../main/data/functions.h"

class AgentSettings
{
private:
  Body * body_0;
  Context * context_0;
  Body * body_1;
  Context * context_1;
  Body * body_2;
  Context * context_2;
  Body * body_3;
  Context * context_3;
  Body * body_4;
  Context * context_4;
  Body * body_5;
  Context * context_5;
  Body * body_6;
  Context * context_6;
  Body * body_7;
  Context * context_7;
  BeliefBase * belief_base;
  EventBase * event_base;
  PlanBase * plan_base;
  IntentionBase * intention_base;

public:
  AgentSettings()
  {
    belief_base = new BeliefBase(6);
    event_base = new EventBase(3);
    plan_base = new PlanBase(8);
    intention_base = new IntentionBase(1, 2);

    //--------------------------------------------------------------------------

    Belief belief_clean(0, update_clean, false);
    belief_base->add_belief(belief_clean);

    //--------------------------------------------------------------------------

    Belief belief_dirty(1, update_dirty, false);
    belief_base->add_belief(belief_dirty);

    //--------------------------------------------------------------------------

    Belief belief_pos_1(2, update_pos_1, false);
    belief_base->add_belief(belief_pos_1);

    //--------------------------------------------------------------------------

    Belief belief_pos_2(3, update_pos_2, false);
    belief_base->add_belief(belief_pos_2);

    //--------------------------------------------------------------------------

    Belief belief_pos_3(4, update_pos_3, false);
    belief_base->add_belief(belief_pos_3);

    //--------------------------------------------------------------------------

    Belief belief_pos_4(5, update_pos_4, false);
    belief_base->add_belief(belief_pos_4);

    //--------------------------------------------------------------------------

    Event event_6(EventOperator::GOAL_ADDITION, 6);
    event_base->add_event(event_6);

    //--------------------------------------------------------------------------

    Proposition prop_0(6);
    context_0 = new Context(0);
    body_0 = new Body(1);

    Proposition prop_0_body_0(0);
    BodyInstruction inst_0_0(BodyType::GOAL, prop_0_body_0, EventOperator::GOAL_ACHIEVE);
    body_0->add_instruction(inst_0_0);

    Plan plan_0(EventOperator::GOAL_ADDITION, prop_0, context_0, body_0);
    plan_base->add_plan(plan_0);

    //--------------------------------------------------------------------------

    Proposition prop_1(0);
    context_1 = new Context(1);
    body_1 = new Body(2);

    Proposition prop_1_clean(0);
    ContextCondition cond_1_0(prop_1_clean);
    context_1->add_context(cond_1_0);

    Proposition prop_1_body_0(7);
    BodyInstruction inst_0_1(BodyType::GOAL, prop_1_body_0, EventOperator::GOAL_ADDITION);
    body_1->add_instruction(inst_0_1);

    Proposition prop_1_body_1(0);
    BodyInstruction inst_1_1(BodyType::GOAL, prop_1_body_1, EventOperator::GOAL_ACHIEVE);
    body_1->add_instruction(inst_1_1);

    Plan plan_1(EventOperator::GOAL_ADDITION, prop_1, context_1, body_1);
    plan_base->add_plan(plan_1);

    //--------------------------------------------------------------------------

    Proposition prop_2(0);
    context_2 = new Context(1);
    body_2 = new Body(2);

    Proposition prop_2_dirty(1);
    ContextCondition cond_2_0(prop_2_dirty);
    context_2->add_context(cond_2_0);

    Proposition prop_2_body_0(8);
    BodyInstruction inst_0_2(BodyType::ACTION, prop_2_body_0, action_suck);
    body_2->add_instruction(inst_0_2);

    Proposition prop_2_body_1(0);
    BodyInstruction inst_1_2(BodyType::GOAL, prop_2_body_1, EventOperator::GOAL_ACHIEVE);
    body_2->add_instruction(inst_1_2);

    Plan plan_2(EventOperator::GOAL_ADDITION, prop_2, context_2, body_2);
    plan_base->add_plan(plan_2);

    //--------------------------------------------------------------------------

    Proposition prop_3(0);
    context_3 = new Context(0);
    body_3 = new Body(1);

    Proposition prop_3_body_0(0);
    BodyInstruction inst_0_3(BodyType::GOAL, prop_3_body_0, EventOperator::GOAL_ACHIEVE);
    body_3->add_instruction(inst_0_3);

    Plan plan_3(EventOperator::GOAL_DELETION, prop_3, context_3, body_3);
    plan_base->add_plan(plan_3);

    //--------------------------------------------------------------------------

    Proposition prop_4(7);
    context_4 = new Context(1);
    body_4 = new Body(1);

    Proposition prop_4_pos_1(2);
    ContextCondition cond_4_0(prop_4_pos_1);
    context_4->add_context(cond_4_0);

    Proposition prop_4_body_0(9);
    BodyInstruction inst_0_4(BodyType::ACTION, prop_4_body_0, action_right);
    body_4->add_instruction(inst_0_4);

    Plan plan_4(EventOperator::GOAL_ADDITION, prop_4, context_4, body_4);
    plan_base->add_plan(plan_4);

    //--------------------------------------------------------------------------

    Proposition prop_5(7);
    context_5 = new Context(1);
    body_5 = new Body(1);

    Proposition prop_5_pos_2(3);
    ContextCondition cond_5_0(prop_5_pos_2);
    context_5->add_context(cond_5_0);

    Proposition prop_5_body_0(10);
    BodyInstruction inst_0_5(BodyType::ACTION, prop_5_body_0, action_down);
    body_5->add_instruction(inst_0_5);

    Plan plan_5(EventOperator::GOAL_ADDITION, prop_5, context_5, body_5);
    plan_base->add_plan(plan_5);

    //--------------------------------------------------------------------------

    Proposition prop_6(7);
    context_6 = new Context(1);
    body_6 = new Body(1);

    Proposition prop_6_pos_3(4);
    ContextCondition cond_6_0(prop_6_pos_3);
    context_6->add_context(cond_6_0);

    Proposition prop_6_body_0(11);
    BodyInstruction inst_0_6(BodyType::ACTION, prop_6_body_0, action_up);
    body_6->add_instruction(inst_0_6);

    Plan plan_6(EventOperator::GOAL_ADDITION, prop_6, context_6, body_6);
    plan_base->add_plan(plan_6);

    //--------------------------------------------------------------------------

    Proposition prop_7(7);
    context_7 = new Context(1);
    body_7 = new Body(1);

    Proposition prop_7_pos_4(5);
    ContextCondition cond_7_0(prop_7_pos_4);
    context_7->add_context(cond_7_0);

    Proposition prop_7_body_0(12);
    BodyInstruction inst_0_7(BodyType::ACTION, prop_7_body_0, action_left);
    body_7->add_instruction(inst_0_7);

    Plan plan_7(EventOperator::GOAL_ADDITION, prop_7, context_7, body_7);
    plan_base->add_plan(plan_7);
  }

  ~AgentSettings()
  {
    delete body_0;
    delete context_0;
    delete body_1;
    delete context_1;
    delete body_2;
    delete context_2;
    delete body_3;
    delete context_3;
    delete body_4;
    delete context_4;
    delete body_5;
    delete context_5;
    delete body_6;
    delete context_6;
    delete body_7;
    delete context_7;
    delete belief_base;
    delete event_base;
    delete plan_base;
    delete intention_base;
}

  BeliefBase *  get_belief_base()
  {
    return belief_base;
  }

  EventBase * get_event_base()
  {
    return event_base;
  }

  PlanBase * get_plan_base()
  {
    return plan_base;
  }

  IntentionBase * get_intention_base()
  {
    return intention_base;
  }
};

#endif /*CONFIGURATION_H_ */