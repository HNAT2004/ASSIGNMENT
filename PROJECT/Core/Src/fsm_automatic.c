/*
 * fsm_automatic.c
 *
 *  Created on: Sep 28, 2024
 *      Author: Genki
 */

#include "fsm_automatic.h"
#include "input_processing.h"
#include "main.h"
int DisplayCounter = 0;
int mode2_flag = 0;
int mode3_flag = 0;
int mode4_flag = 0;
int save_counterTimeSet = 0;
int Time_red = 5;
int Time_green = 3;
int Time_yellow = 2;
void SetMode(void){
	if(ProcessButton3() == 1){
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
//void fsm_clock(void){
//	if(timer_flag[2] == 1){
//		number_clock1--;
//		setTimer(2, 1000);
//	}
//	if(timer_flag[3] == 1){
//		number_clock2--;
//		setTimer(3, 1000);
//	}
//	if(timer_flag[6] == 1){
//		if(DisplayCounter == 0){
//			Display7Seg(number_clock2/10);
//		}
//		else if(DisplayCounter == 1){
//			Display7Seg(number_clock2%10);
//		}
//		else if(DisplayCounter == 2){
//
//			Display7Seg(number_clock1/10);
//		}
//		else if(DisplayCounter == 3){
//			Display7Seg(number_clock1%10);
//
//		}
//		Display(DisplayCounter);
//		DisplayCounter++;
//		if(DisplayCounter > 4){
//			DisplayCounter = 0;
//		}
//		setTimer(6, 100);
//	}
//}
//void fsm_mode(void){
//	if(timer_flag[6] == 1){
//		Display(DisplayCounter);
//		if(DisplayCounter == 0){
//			Display7Seg(0);
//		}
//		else if(DisplayCounter == 1){
//			Display7Seg(counterMode);
//		}
//		else if(DisplayCounter == 2){
//			Display7Seg(counterTimeSet/10);
//		}
//		else if(DisplayCounter == 3){
//			Display7Seg(counterTimeSet%10);
//		}
//		DisplayCounter++;
//		if(DisplayCounter > 4){
//			DisplayCounter = 0;
//		}
//		setTimer(6, 100);
//	}
//}
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
//		fsm_clock();
		SetMode();
		ChangeModeX();
		if(timer_flag[0] == 1){
			InitLED();
			statusx = AUTO_GREEN;
			number_clock1 = Time_green;
			setTimer(0,number_clock1 * 1000);
		}
		break;
	case AUTO_GREEN:
		DisplayGREENX();
//		fsm_clock();
		SetMode();
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
//		fsm_clock();
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
