/*
 * fsm_automatic.h
 *
 *  Created on: Sep 28, 2024
 *      Author: Genki
 */

#ifndef INC_FSM_AUTOMATIC_H_
#define INC_FSM_AUTOMATIC_H_

#include "global.h"
#include "led_display.h"
#include "timer.h"
extern int number_clock1;
extern int number_clock2;
extern int save_counterTimeSet;
extern int DisplayCounter;
extern int mode2_flag;
extern int mode3_flag;
extern int mode4_flag;
extern int Time_red;
extern int Time_green;
extern int Time_yellow;
void fsm_clock(void);
void fsm_mode(void);
void fsm_automatic_runx(void);
void fsm_automatic_runy(void);
void SetMode(void);
void ChangeModeX(void);
void ChangeModeY(void);
#endif /* INC_FSM_AUTOMATIC_H_ */
