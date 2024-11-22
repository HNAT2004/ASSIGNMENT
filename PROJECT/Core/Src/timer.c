/*
 * timer.c
 *
 *  Created on: Sep 27, 2024
 *      Author: Genki
 */
#include "main.h"
#include "timer.h"
//#include "input_reading.h"
#define MAX_COUNTER 10
int TIME_CYCLE = 10;
int timer_counter[MAX_COUNTER];
int timer_flag[MAX_COUNTER];
void setTimer(int index, int duration){
	timer_counter[index] = duration/TIME_CYCLE;
	timer_flag[index] = 0;
}
void timerRun(void){
	for(int i = 0; i < MAX_COUNTER; i++){
		if(timer_counter[i] > 0){
			timer_counter[i]--;
			if(timer_counter[i] <= 0){
				timer_flag[i] = 1;
			}
		}
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim -> Instance == TIM2){
		button_reading() ;
		timerRun();
	}
}
