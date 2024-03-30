/*
 * AgentSpeak code:
 *
 * !init.
 * 
 * +!init <- !!clean; !!connect.
 * 
 * +!clean : clean <- !move; !!clean.
 * +!clean : dirty <- suck;  !!clean.
 * -!clean         <- !!clean.
 * 
 * +!connect : true <- connect_to_wifi.
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
  Body body_0;
  Context context_0;
  Body body_1;
  Context context_1;
  Body body_2;
  Context context_2;
  Body body_3;
  Context context_3;
  Body body_4;
  Context context_4;
  Body body_5;
  Context context_5;
  Body body_6;
  Context context_6;
  Body body_7;
  Context context_7;
  Body body_8;
  Context context_8;
  BeliefBase belief_base;
  EventBase event_base;
  PlanBase plan_base;
  IntentionBase intention_base;

public:
  AgentSettings()
  {
    belief_base = BeliefBase(6);
    event_base = EventBase(30);
    plan_base = PlanBase(9);
    intention_base = IntentionBase(10, 20);

    //--------------------------------------------------------------------------

    Belief belief_clean(0, update_clean, false);
    belief_base.add_belief(belief_clean);

    //--------------------------------------------------------------------------

    Belief belief_dirty(1, update_dirty, false);
    belief_base.add_belief(belief_dirty);

    //--------------------------------------------------------------------------

    Belief belief_pos_1(2, update_pos_1, false);
    belief_base.add_belief(belief_pos_1);

    //--------------------------------------------------------------------------

    Belief belief_pos_2(3, update_pos_2, false);
    belief_base.add_belief(belief_pos_2);

    //--------------------------------------------------------------------------

    Belief belief_pos_3(4, update_pos_3, false);
    belief_base.add_belief(belief_pos_3);

    //--------------------------------------------------------------------------

    Belief belief_pos_4(5, update_pos_4, false);
    belief_base.add_belief(belief_pos_4);

    //--------------------------------------------------------------------------

    Event event_6(EventOperator::GOAL_ADDITION, 6);
    event_base.add_event(event_6);

    //--------------------------------------------------------------------------

    Proposition prop_0(6);
    context_0 = Context(0);
    body_0 = Body(2);

    Proposition prop_0_body_0(0);
    BodyInstruction inst_0_0(BodyType::GOAL, prop_0_body_0, EventOperator::GOAL_ACHIEVE);
    body_0.add_instruction(inst_0_0);

    Proposition prop_0_body_1(7);
    BodyInstruction inst_1_0(BodyType::GOAL, prop_0_body_1, EventOperator::GOAL_ACHIEVE);
    body_0.add_instruction(inst_1_0);

    Plan plan_0(EventOperator::GOAL_ADDITION, prop_0, &context_0, &body_0);
    plan_base.add_plan(plan_0);

    //--------------------------------------------------------------------------

    Proposition prop_1(0);
    context_1 = Context(1);
    body_1 = Body(2);

    Proposition prop_1_clean(0);
    ContextCondition cond_1_0(prop_1_clean);
    context_1.add_context(cond_1_0);

    Proposition prop_1_body_0(8);
    BodyInstruction inst_0_1(BodyType::GOAL, prop_1_body_0, EventOperator::GOAL_ADDITION);
    body_1.add_instruction(inst_0_1);

    Proposition prop_1_body_1(0);
    BodyInstruction inst_1_1(BodyType::GOAL, prop_1_body_1, EventOperator::GOAL_ACHIEVE);
    body_1.add_instruction(inst_1_1);

    Plan plan_1(EventOperator::GOAL_ADDITION, prop_1, &context_1, &body_1);
    plan_base.add_plan(plan_1);

    //--------------------------------------------------------------------------

    Proposition prop_2(0);
    context_2 = Context(1);
    body_2 = Body(2);

    Proposition prop_2_dirty(1);
    ContextCondition cond_2_0(prop_2_dirty);
    context_2.add_context(cond_2_0);

    Proposition prop_2_body_0(9);
    BodyInstruction inst_0_2(BodyType::ACTION, prop_2_body_0, action_suck);
    body_2.add_instruction(inst_0_2);

    Proposition prop_2_body_1(0);
    BodyInstruction inst_1_2(BodyType::GOAL, prop_2_body_1, EventOperator::GOAL_ACHIEVE);
    body_2.add_instruction(inst_1_2);

    Plan plan_2(EventOperator::GOAL_ADDITION, prop_2, &context_2, &body_2);
    plan_base.add_plan(plan_2);

    //--------------------------------------------------------------------------

    Proposition prop_3(0);
    context_3 = Context(0);
    body_3 = Body(1);

    Proposition prop_3_body_0(0);
    BodyInstruction inst_0_3(BodyType::GOAL, prop_3_body_0, EventOperator::GOAL_ACHIEVE);
    body_3.add_instruction(inst_0_3);

    Plan plan_3(EventOperator::GOAL_DELETION, prop_3, &context_3, &body_3);
    plan_base.add_plan(plan_3);

    //--------------------------------------------------------------------------

    Proposition prop_4(7);
    context_4 = Context(0);
    body_4 = Body(1);

    Proposition prop_4_body_0(10);
    BodyInstruction inst_0_4(BodyType::ACTION, prop_4_body_0, action_connect_to_wifi);
    body_4.add_instruction(inst_0_4);

    Plan plan_4(EventOperator::GOAL_ADDITION, prop_4, &context_4, &body_4);
    plan_base.add_plan(plan_4);

    //--------------------------------------------------------------------------

    Proposition prop_5(8);
    context_5 = Context(1);
    body_5 = Body(1);

    Proposition prop_5_pos_1(2);
    ContextCondition cond_5_0(prop_5_pos_1);
    context_5.add_context(cond_5_0);

    Proposition prop_5_body_0(11);
    BodyInstruction inst_0_5(BodyType::ACTION, prop_5_body_0, action_right);
    body_5.add_instruction(inst_0_5);

    Plan plan_5(EventOperator::GOAL_ADDITION, prop_5, &context_5, &body_5);
    plan_base.add_plan(plan_5);

    //--------------------------------------------------------------------------

    Proposition prop_6(8);
    context_6 = Context(1);
    body_6 = Body(1);

    Proposition prop_6_pos_2(3);
    ContextCondition cond_6_0(prop_6_pos_2);
    context_6.add_context(cond_6_0);

    Proposition prop_6_body_0(12);
    BodyInstruction inst_0_6(BodyType::ACTION, prop_6_body_0, action_down);
    body_6.add_instruction(inst_0_6);

    Plan plan_6(EventOperator::GOAL_ADDITION, prop_6, &context_6, &body_6);
    plan_base.add_plan(plan_6);

    //--------------------------------------------------------------------------

    Proposition prop_7(8);
    context_7 = Context(1);
    body_7 = Body(1);

    Proposition prop_7_pos_3(4);
    ContextCondition cond_7_0(prop_7_pos_3);
    context_7.add_context(cond_7_0);

    Proposition prop_7_body_0(13);
    BodyInstruction inst_0_7(BodyType::ACTION, prop_7_body_0, action_up);
    body_7.add_instruction(inst_0_7);

    Plan plan_7(EventOperator::GOAL_ADDITION, prop_7, &context_7, &body_7);
    plan_base.add_plan(plan_7);

    //--------------------------------------------------------------------------

    Proposition prop_8(8);
    context_8 = Context(1);
    body_8 = Body(1);

    Proposition prop_8_pos_4(5);
    ContextCondition cond_8_0(prop_8_pos_4);
    context_8.add_context(cond_8_0);

    Proposition prop_8_body_0(14);
    BodyInstruction inst_0_8(BodyType::ACTION, prop_8_body_0, action_left);
    body_8.add_instruction(inst_0_8);

    Plan plan_8(EventOperator::GOAL_ADDITION, prop_8, &context_8, &body_8);
    plan_base.add_plan(plan_8);
  }

  BeliefBase * get_belief_base()
  {
    return &belief_base;
  }

  EventBase * get_event_base()
  {
    return &event_base;
  }

  PlanBase * get_plan_base()
  {
    return &plan_base;
  }

  IntentionBase * get_intention_base()
  {
    return &intention_base;
  }
};

#endif /*CONFIGURATION_H_ */