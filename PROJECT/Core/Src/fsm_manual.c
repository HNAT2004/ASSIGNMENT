/*
 * fsm_manual.c
 *
 *  Created on: 29 Sep 2024
 *      Author: Genki
 */

#include "fsm_manual.h"
#include "led_display.h"
#include "input_processing.h"
#include "fsm_automatic.h"
void fsm_manual_run1(void){
	switch(statusx){
	case MAN_RED:
		if(timer_flag[4] == 1){
			DisplayMAN_REDX();
			setTimer(4, 500);
		}
		if(counterMode == 3){
			statusx = MAN_GREEN;
			InitLED();
		}
		fsm_mode();
		SetMode();
		break;
	case MAN_GREEN:
		if(timer_flag[4] == 1){
			DisplayMAN_GREENX();
			setTimer(4, 500);
		}
		if(counterMode == 4){
			statusx = MAN_YELLOW;
			InitLED();
		}
		fsm_mode();
		SetMode();
		break;
	case MAN_YELLOW:
		if(timer_flag[4] == 1){
			DisplayMAN_YELLOWX();
			setTimer(4, 500);
		}
		if(counterMode == 1){
			statusx = AUTO_RED;
			number_clock1 = Time_red;
			number_clock2 = Time_green;
			setTimer(0,number_clock1 * 1000);
			setTimer(1,number_clock2 * 1000);
			setTimer(2,100);
			setTimer(3,100);
			InitLED();
		}
		fsm_mode();
		SetMode();
		break;
	default:
		break;
	}
}
void fsm_manual_run2(void){
	switch(statusy){
	case MAN_RED:
		fsm_mode();
		if(timer_flag[5] == 1){
			DisplayMAN_REDY();
			setTimer(5, 500);
		}
		if(counterMode == 3){
			statusy = MAN_GREEN;
			InitLED();
		}
		break;
	case MAN_GREEN:
		fsm_mode();
		if(timer_flag[5] == 1){
			DisplayMAN_GREENY();
			setTimer(5, 500);
		}
		if(counterMode == 4){
			statusy = MAN_YELLOW;
			InitLED();
		}
		break;
	case MAN_YELLOW:
		fsm_mode();
		if(timer_flag[5] == 1){
			DisplayMAN_YELLOWY();
			setTimer(5, 500);
		}
		if(counterMode == 1){
			InitLED();
			statusy = AUTO_GREEN;
		}
		break;
	default:
		break;
	}
}
