#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unistd.h>

#define CYCLE_DELAY 1000000
#define SUCK_DELAY 50000

bool action_start_coap_server();

// moves right (P1->P2)
bool action_right();

// moves down (P2->P4)
bool action_down();

// moves up (P3->P1)
bool action_up();

// moves left (P4->P3)
bool action_left();

// sucks dirty space
bool action_suck();

// updates 'dirty' belief
bool update_dirty(bool var);

// updates 'clean' belief
bool update_clean(bool var);

// updates 'pos_1' belief
bool update_pos_1(bool var);

// updates 'pos_2' belief
bool update_pos_2(bool var);

// updates 'pos_3' belief
bool update_pos_3(bool var);

// updates 'pos_4' belief
bool update_pos_4(bool var);

#endif /* FUNCTIONS_H_ */
