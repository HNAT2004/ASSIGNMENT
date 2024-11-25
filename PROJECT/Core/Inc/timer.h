/*
 * timer.h
 *
 *  Created on: Sep 27, 2024
 *      Author: Genki
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_
#define MAX_COUNTER 10

extern int timer_flag[10];
extern int timer_counter[10];
void setTimer(int index, int duration);
void timerRun(void);
#endif /* INC_TIMER_H_ */
