/*
 * fsm_automatic.c
 *
 *  Created on: Sep 28, 2024
 *      Author: Genki
 */

#include "fsm_automatic.h"
#include "input_processing.h"
#include "main.h"
#include "i2c-lcd.h"
#include "stdio.h"
int DisplayCounter = 0;
int mode2_flag = 0;
int mode3_flag = 0;
int mode4_flag = 0;
int save_counterTimeSet = 0;
int Time_red = 8;
int Time_green = 6;
int Time_yellow = 2;
void SetMode(void){
	if(ProcessButton3() == 1){
		if(counterMode == 1){
//			if(statusx == AUTO_RED && statusy == AUTO_GREEN){
				char stry[16];
				char strx[16];
				sprintf(stry, "  Manual Mode ");
				sprintf(strx, "          ");
				lcd_goto_XY(1, 0);
				lcd_send_string(strx);
				lcd_goto_XY(2, 0);
				lcd_send_string(stry);
				statusx = MANUAL_REDX_GREENY;
				statusy = MANUAL_REDX_GREENY;
				counterMode = 1;
				InitLED();
//			}
//			else if(statusx == AUTO_RED && statusy == AUTO_YELLOW){
//				statusx = MANUAL_REDX_YELLOWY;
//				statusy = MANUAL_REDX_GREENY;
//				counterMode = 1;
//				InitLED();
//			}
//			else if(statusx == AUTO_GREEN && statusy == AUTO_RED){
//				statusx = MANUAL_GREENX_REDY;
//				statusy = MANUAL_REDX_GREENY;
//				counterMode = 1;
//				InitLED();
//			}
//			else if(statusx == AUTO_YELLOW && statusy == AUTO_RED){
//				statusx = MANUAL_YELLOWX_REDY;
//				statusy = MANUAL_REDX_GREENY;
//				counterMode = 1;
//				InitLED();
//			}
		}
		if(counterMode == 2){
			Time_red = counterTimeSet;
			if(Time_red <= Time_green || Time_red <= Time_yellow){
				Time_red = Time_green + Time_yellow;
			}
			else{
				Time_green = Time_red - Time_yellow;
			}
			number_clock1 = Time_red;
			number_clock2 = Time_green;
		}
		if(counterMode == 3){
			Time_green = counterTimeSet;
			if(Time_red <= Time_green){
				Time_red =  Time_yellow + Time_green;
			}
			else{
				Time_yellow = Time_red - Time_green;
			}
			number_clock1 = Time_red;
			number_clock2 = Time_green;
		}
		if(counterMode == 4){
			Time_yellow = counterTimeSet;
			if(Time_red <= Time_yellow){
				Time_red =  Time_yellow + Time_green;
			}
			else{
				Time_green = Time_red - Time_yellow;
			}
			number_clock1 =  Time_red;
			number_clock2 = Time_green;
		}
	}
}
void ChangeModeX(void){
	if(counterMode == 1){
		mode4_flag = 0;
	}
	if(counterMode == 2){
		statusx = MAN_RED;
		InitLED();
	}
	if(counterMode == 3){
		mode2_flag = 0;
		statusx = MAN_GREEN;
		InitLED();
	}
	if(counterMode == 4){
		mode3_flag = 0;
		statusx = MAN_YELLOW;
		InitLED();
	}
}
void ChangeModeY(void){
	if(counterMode == 1){
		mode4_flag = 0;
	}
	if(counterMode == 2){
		statusy = MAN_RED;
		InitLED();
	}
	if(counterMode == 3){
		mode2_flag = 0;
		statusy = MAN_GREEN;
		InitLED();
	}
	if(counterMode == 4){
		mode3_flag = 0;
		statusy = MAN_YELLOW;
		InitLED();
	}
}
void fsm_clock(void) {
    if (timer_flag[2] == 1) {
        number_clock1--;
        number_clock2--;
        setTimer(2, 1000);
    }
    if (timer_flag[3] == 1) {
        char stry[16];
        char strx[16];
        sprintf(strx, "Road X: %d    ", number_clock1);
        sprintf(stry, "Road Y: %d    ", number_clock2);
        lcd_goto_XY(1, 0);
        lcd_send_string(strx);
        lcd_goto_XY(2, 0);
        lcd_send_string(stry);
        setTimer(3, 1000);
    }
}
void fsm_mode(void) {
    if (timer_flag[6] == 1) {
        char stry[16];
        char strx[16];
        sprintf(stry, "Time:   %d ", counterTimeSet);
        sprintf(strx, "Mode:   %d ", counterMode);
        lcd_goto_XY(1, 0);
        lcd_send_string(strx);
        lcd_goto_XY(2, 0);
        lcd_send_string(stry);
        setTimer(6, 100);
    }
}
void fsm_automatic_runx(){
	switch(statusx){
	case INIT:
		statusx = AUTO_RED;
		number_clock1 = Time_red;
		setTimer(0,number_clock1 * 1000);
		setTimer(2,100);
		break;
	case AUTO_RED:
		DisplayREDX();
		fsm_clock();
		SetMode();
		ChangeModeX();
		if(statusy == AUTO_YELLOW && number_clock2 <= 3){
			if(timer_flag[4] == 1){
				WalkingX_Blinking();
				setTimer(4, 250);
			}
		}
		else{
			WalkingX();
		}
		if(timer_flag[0] == 1){
			InitLED();
			statusx = AUTO_GREEN;
			number_clock1 = Time_green;
			setTimer(0,number_clock1 * 1000);
		}
		break;
	case AUTO_GREEN:
		DisplayGREENX();
		fsm_clock();
		SetMode();
		StopX();
		ChangeModeX();
		if(timer_flag[0] == 1){
			InitLED();
			statusx = AUTO_YELLOW;
			number_clock1 = Time_yellow;
			setTimer(0,number_clock1 * 1000);
		}
		break;
	case AUTO_YELLOW:
		DisplayYELLOWX();
		fsm_clock();
		SetMode();
		ChangeModeX();
		if(timer_flag[0] == 1){
			InitLED();
			statusx = AUTO_RED;
			number_clock1 = Time_red;
			setTimer(0,number_clock1 * 1000);
		}
		break;
	default:
		break;
	}
}
void fsm_automatic_runy(){
	switch(statusy){
	case INIT:
		DisplayGREENY();
		statusy = AUTO_GREEN;
		number_clock2 = Time_green;
		setTimer(1,number_clock2 * 1000);
		setTimer(3,100);
		break;
	case AUTO_RED:
		DisplayREDY();
		SetMode();
		ChangeModeY();
		if(statusx == AUTO_YELLOW && number_clock1 <= 3){
			if(timer_flag[4] == 1){
				WalkingY_Blinnking();
				setTimer(4, 250);
			}
		}
		else{
			WalkingY();
		}
		if(mode2_flag == 1){
			InitLED();
			statusy = MAN_RED;
			setTimer(1, save_counterTimeSet*1000);
			number_clock2 = timer_counter[1]/100;
		}
		if(timer_flag[1] == 1){
			InitLED();
			statusy = AUTO_GREEN;
			number_clock2 = Time_green;
			setTimer(1,number_clock2 * 1000);
		}
		break;
	case AUTO_GREEN:
		DisplayGREENY();
		StopY();
		SetMode();
		ChangeModeY();
		if(mode3_flag == 1){
			InitLED();
			statusy = MAN_GREEN;
			setTimer(1, save_counterTimeSet*1000);
			number_clock2 = timer_counter[1]/100;
		}
		if(timer_flag[1] == 1){
			InitLED();
			statusy = AUTO_YELLOW;
			number_clock2 = Time_yellow;
			setTimer(1,number_clock2 * 1000);
		}
		break;
	case AUTO_YELLOW:
		DisplayYELLOWY();
		SetMode();
		ChangeModeY();
		if(mode4_flag == 1){
			InitLED();
			statusy = MAN_YELLOW;
			setTimer(1, save_counterTimeSet*1000);
			number_clock2 = timer_counter[1]/100;
		}
		if(timer_flag[1] == 1){
			InitLED();
			statusy = AUTO_RED;
			number_clock2 = Time_red;
			setTimer(1,number_clock2 * 1000);
		}
		break;
	default:
		break;
	}
}
