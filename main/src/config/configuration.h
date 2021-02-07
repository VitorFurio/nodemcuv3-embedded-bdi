/*
 * AgentSpeak code:
 *
 * !init.
 * 
 * +!init : button_start <- !!clean.
 * +!init <- !!init.
 * 
 * +!clean : full_deposit <- empty; !!clean.
 * +!clean : stop  <- -stop; !!init. 
 * +!clean : clean <- !move; !!clean.
 * +!clean : dirty <- suck;  !!clean.
 * -!clean         <- !!clean.
 * 
 * +!move : pos_1 <- right.
 * +!move : pos_2 <- down.
 * +!move : pos_3 <- +stop; up.
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
  Body * body_8;
  Context * context_8;
  Body * body_9;
  Context * context_9;
  Body * body_10;
  Context * context_10;
  BeliefBase * belief_base;
  EventBase * event_base;
  PlanBase * plan_base;
  IntentionBase * intention_base;

public:
  AgentSettings()
  {
    belief_base = new BeliefBase(9);
    event_base = new EventBase(6);
    plan_base = new PlanBase(11);
    intention_base = new IntentionBase(10, 4);

    //--------------------------------------------------------------------------

    Belief belief_button_start(0, update_button_start, false);
    belief_base->add_belief(belief_button_start);

    //--------------------------------------------------------------------------

    Belief belief_clean(1, update_clean, false);
    belief_base->add_belief(belief_clean);

    //--------------------------------------------------------------------------

    Belief belief_dirty(2, update_dirty, false);
    belief_base->add_belief(belief_dirty);

    //--------------------------------------------------------------------------

    Belief belief_full_deposit(3, update_full_deposit, false);
    belief_base->add_belief(belief_full_deposit);

    //--------------------------------------------------------------------------

    Belief belief_pos_1(4, update_pos_1, false);
    belief_base->add_belief(belief_pos_1);

    //--------------------------------------------------------------------------

    Belief belief_pos_2(5, update_pos_2, false);
    belief_base->add_belief(belief_pos_2);

    //--------------------------------------------------------------------------

    Belief belief_pos_3(6, update_pos_3, false);
    belief_base->add_belief(belief_pos_3);

    //--------------------------------------------------------------------------

    Belief belief_pos_4(7, update_pos_4, false);
    belief_base->add_belief(belief_pos_4);

    //--------------------------------------------------------------------------

    Belief belief_stop(8, nullptr, false);
    belief_base->add_belief(belief_stop);

    //--------------------------------------------------------------------------

    Event event_9(EventOperator::GOAL_ADDITION, 9);
    event_base->add_event(event_9);

    //--------------------------------------------------------------------------

    Statement stm_0(9);
    context_0 = new Context(1);
    body_0 = new Body(1);

    Statement stm_0_button_start(0);
    ContextCondition cond_0_0(stm_0_button_start);
    context_0->add_context(cond_0_0);

    Statement stm_0_body_0(1);
    BodyInstruction inst_0_0(BodyType::GOAL, stm_0_body_0, EventOperator::GOAL_ACHIEVE);
    body_0->add_instruction(inst_0_0);

    Plan plan_0(EventOperator::GOAL_ADDITION, stm_0, context_0, body_0);
    plan_base->add_plan(plan_0);

    //--------------------------------------------------------------------------

    Statement stm_1(9);
    context_1 = new Context(0);
    body_1 = new Body(1);

    Statement stm_1_body_0(9);
    BodyInstruction inst_0_1(BodyType::GOAL, stm_1_body_0, EventOperator::GOAL_ACHIEVE);
    body_1->add_instruction(inst_0_1);

    Plan plan_1(EventOperator::GOAL_ADDITION, stm_1, context_1, body_1);
    plan_base->add_plan(plan_1);

    //--------------------------------------------------------------------------

    Statement stm_2(1);
    context_2 = new Context(1);
    body_2 = new Body(2);

    Statement stm_2_full_deposit(3);
    ContextCondition cond_2_0(stm_2_full_deposit);
    context_2->add_context(cond_2_0);

    Statement stm_2_body_0(10);
    BodyInstruction inst_0_2(BodyType::ACTION, stm_2_body_0, action_empty);
    body_2->add_instruction(inst_0_2);

    Statement stm_2_body_1(1);
    BodyInstruction inst_1_2(BodyType::GOAL, stm_2_body_1, EventOperator::GOAL_ACHIEVE);
    body_2->add_instruction(inst_1_2);

    Plan plan_2(EventOperator::GOAL_ADDITION, stm_2, context_2, body_2);
    plan_base->add_plan(plan_2);

    //--------------------------------------------------------------------------

    Statement stm_3(1);
    context_3 = new Context(1);
    body_3 = new Body(2);

    Statement stm_3_stop(8);
    ContextCondition cond_3_0(stm_3_stop);
    context_3->add_context(cond_3_0);

    Statement stm_3_body_0(8);
    BodyInstruction inst_0_3(BodyType::BELIEF, stm_3_body_0, EventOperator::BELIEF_DELETION);
    body_3->add_instruction(inst_0_3);

    Statement stm_3_body_1(9);
    BodyInstruction inst_1_3(BodyType::GOAL, stm_3_body_1, EventOperator::GOAL_ACHIEVE);
    body_3->add_instruction(inst_1_3);

    Plan plan_3(EventOperator::GOAL_ADDITION, stm_3, context_3, body_3);
    plan_base->add_plan(plan_3);

    //--------------------------------------------------------------------------

    Statement stm_4(1);
    context_4 = new Context(1);
    body_4 = new Body(2);

    Statement stm_4_clean(1);
    ContextCondition cond_4_0(stm_4_clean);
    context_4->add_context(cond_4_0);

    Statement stm_4_body_0(11);
    BodyInstruction inst_0_4(BodyType::GOAL, stm_4_body_0, EventOperator::GOAL_ADDITION);
    body_4->add_instruction(inst_0_4);

    Statement stm_4_body_1(1);
    BodyInstruction inst_1_4(BodyType::GOAL, stm_4_body_1, EventOperator::GOAL_ACHIEVE);
    body_4->add_instruction(inst_1_4);

    Plan plan_4(EventOperator::GOAL_ADDITION, stm_4, context_4, body_4);
    plan_base->add_plan(plan_4);

    //--------------------------------------------------------------------------

    Statement stm_5(1);
    context_5 = new Context(1);
    body_5 = new Body(2);

    Statement stm_5_dirty(2);
    ContextCondition cond_5_0(stm_5_dirty);
    context_5->add_context(cond_5_0);

    Statement stm_5_body_0(12);
    BodyInstruction inst_0_5(BodyType::ACTION, stm_5_body_0, action_suck);
    body_5->add_instruction(inst_0_5);

    Statement stm_5_body_1(1);
    BodyInstruction inst_1_5(BodyType::GOAL, stm_5_body_1, EventOperator::GOAL_ACHIEVE);
    body_5->add_instruction(inst_1_5);

    Plan plan_5(EventOperator::GOAL_ADDITION, stm_5, context_5, body_5);
    plan_base->add_plan(plan_5);

    //--------------------------------------------------------------------------

    Statement stm_6(1);
    context_6 = new Context(0);
    body_6 = new Body(1);

    Statement stm_6_body_0(1);
    BodyInstruction inst_0_6(BodyType::GOAL, stm_6_body_0, EventOperator::GOAL_ACHIEVE);
    body_6->add_instruction(inst_0_6);

    Plan plan_6(EventOperator::GOAL_DELETION, stm_6, context_6, body_6);
    plan_base->add_plan(plan_6);

    //--------------------------------------------------------------------------

    Statement stm_7(11);
    context_7 = new Context(1);
    body_7 = new Body(1);

    Statement stm_7_pos_1(4);
    ContextCondition cond_7_0(stm_7_pos_1);
    context_7->add_context(cond_7_0);

    Statement stm_7_body_0(13);
    BodyInstruction inst_0_7(BodyType::ACTION, stm_7_body_0, action_right);
    body_7->add_instruction(inst_0_7);

    Plan plan_7(EventOperator::GOAL_ADDITION, stm_7, context_7, body_7);
    plan_base->add_plan(plan_7);

    //--------------------------------------------------------------------------

    Statement stm_8(11);
    context_8 = new Context(1);
    body_8 = new Body(1);

    Statement stm_8_pos_2(5);
    ContextCondition cond_8_0(stm_8_pos_2);
    context_8->add_context(cond_8_0);

    Statement stm_8_body_0(14);
    BodyInstruction inst_0_8(BodyType::ACTION, stm_8_body_0, action_down);
    body_8->add_instruction(inst_0_8);

    Plan plan_8(EventOperator::GOAL_ADDITION, stm_8, context_8, body_8);
    plan_base->add_plan(plan_8);

    //--------------------------------------------------------------------------

    Statement stm_9(11);
    context_9 = new Context(1);
    body_9 = new Body(2);

    Statement stm_9_pos_3(6);
    ContextCondition cond_9_0(stm_9_pos_3);
    context_9->add_context(cond_9_0);

    Statement stm_9_body_0(8);
    BodyInstruction inst_0_9(BodyType::BELIEF, stm_9_body_0, EventOperator::BELIEF_ADDITION);
    body_9->add_instruction(inst_0_9);

    Statement stm_9_body_1(15);
    BodyInstruction inst_1_9(BodyType::ACTION, stm_9_body_1, action_up);
    body_9->add_instruction(inst_1_9);

    Plan plan_9(EventOperator::GOAL_ADDITION, stm_9, context_9, body_9);
    plan_base->add_plan(plan_9);

    //--------------------------------------------------------------------------

    Statement stm_10(11);
    context_10 = new Context(1);
    body_10 = new Body(1);

    Statement stm_10_pos_4(7);
    ContextCondition cond_10_0(stm_10_pos_4);
    context_10->add_context(cond_10_0);

    Statement stm_10_body_0(16);
    BodyInstruction inst_0_10(BodyType::ACTION, stm_10_body_0, action_left);
    body_10->add_instruction(inst_0_10);

    Plan plan_10(EventOperator::GOAL_ADDITION, stm_10, context_10, body_10);
    plan_base->add_plan(plan_10);
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
    delete body_8;
    delete context_8;
    delete body_9;
    delete context_9;
    delete body_10;
    delete context_10;
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