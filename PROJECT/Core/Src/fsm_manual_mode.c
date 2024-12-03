/*
 * fsm_manual_mode.c
 *
 *  Created on: Dec 2, 2024
 *      Author: ADMIN
 */


/*
 * fsm_manual.c
 *
 *  Created on: Oct 21, 2024
 *      Author: ADMIN
 */
#include "fsm_manual_mode.h"
#include "global.h"
#include "led_display.h"
#include "input_processing.h"
#include "fsm_automatic.h"

void change_fsm(void){
	if(ProcessButton2()){
		counterMode = 1;
		statusx = AUTO_RED;
		statusy = AUTO_GREEN;
		InitLED();
		number_clock1 = Time_red;
		number_clock2 = Time_green;
		setTimer(0,number_clock1  * 1000);
		setTimer(1,number_clock2 * 1000);
		setTimer(2,100);
		setTimer(3,100);
	}
}
void fsm_manual_run(void){
	switch(statusx){
	case MANUAL_REDX_GREENY:
		//TODO
		DisplayREDX();
		DisplayGREENY();
		change_fsm();
		WalkingX();
		StopY();
		if (counterMode == 2){
			statusx = MANUAL_REDX_YELLOWY;
			InitLED();
			setTimer(0, 5000);
		}
		break;
	case MANUAL_REDX_YELLOWY:
		DisplayREDX();
		DisplayYELLOWY();
		change_fsm();
		if(timer_flag[4] == 1){
			WalkingX_Blinking();
			setTimer(4, 250);
		}
		if (counterMode == 3){
			statusx = MANUAL_GREENX_REDY;
			InitLED();
		}
		if(timer_counter[0] == 1){
			statusx = MANUAL_GREENX_REDY;
			counterMode = 3;
			InitLED();
		}
		break;
	case MANUAL_GREENX_REDY:
		DisplayGREENX();
		DisplayREDY();
		change_fsm();
		StopX();
		WalkingY();
		if (counterMode == 4){
			statusx = MANUAL_YELLOWX_REDY;
			InitLED();
			setTimer(0, 5000);
		}
		break;
	case MANUAL_YELLOWX_REDY:
		DisplayYELLOWX();
		DisplayREDY();
		change_fsm();
		if(timer_flag[4] == 1){
			WalkingY_Blinnking();
			setTimer(4, 250);
		}
		if (counterMode == 1){
			statusx = MANUAL_REDX_GREENY;
			InitLED();
		}
		if(timer_counter[0] == 1){
			statusx = MANUAL_REDX_GREENY;
			counterMode = 1;
			InitLED();
		}
		break;
	default:
		break;
	}
}

