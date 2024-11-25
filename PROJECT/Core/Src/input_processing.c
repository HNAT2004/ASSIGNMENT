/*
 * input_processing.c
 *
 *  Created on: Sep 27, 2024
 *      Author: Genki
 */
#include "main.h"
#include "led_display.h"
#include "input_reading.h"
#include "global.h"
#include "i2c-lcd.h"
enum ButtonState { BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND};
enum ButtonState buttonState1 = BUTTON_RELEASED;
enum ButtonState buttonState2 = BUTTON_RELEASED;
enum ButtonState buttonState3 = BUTTON_RELEASED;
int counterMode = 0;
int counterTimeSet = 0;
void fsm_for_input_processing1(void){
	switch(buttonState1){
		case BUTTON_RELEASED:
			if(is_button_pressed(0)){
				buttonState1 = BUTTON_PRESSED ;
				if(ProcessButton1() == 1){

					  counterMode++;
					  counterTimeSet = 0;
					  if(counterMode > 4){
						  counterMode = 1;
					  }
				}
			}
		break;
		case BUTTON_PRESSED:
			if(!is_button_pressed(0)){
				buttonState1 = BUTTON_RELEASED;
			}
			else{
				if(is_button_pressed_1s(0) == 1){
					buttonState1 = BUTTON_PRESSED_MORE_THAN_1_SECOND;
				}
			}
		break;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND:
			if(!is_button_pressed(0)){
				buttonState1 = BUTTON_RELEASED;
			}
		break;
		}
	}
void fsm_for_input_processing2(void){
	switch(buttonState2){
		case BUTTON_RELEASED:
			if(is_button_pressed(1)){
				buttonState2 = BUTTON_PRESSED ;
				if(ProcessButton2() == 1){
					  counterTimeSet++;
					  if(counterTimeSet > 99){
						  counterTimeSet = 0;
					  }
				}
			}
		break;
		case BUTTON_PRESSED:
			if(!is_button_pressed(1)){
				buttonState2 = BUTTON_RELEASED;
			}
			else{
				if(is_button_pressed_1s(1) == 1){
					buttonState2 = BUTTON_PRESSED_MORE_THAN_1_SECOND;

				}
			}
		break;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND:
			if(!is_button_pressed(1)){
				buttonState2 = BUTTON_RELEASED;
			}
		break;
		}
	}
void fsm_for_input_processing3(void){
	switch(buttonState3){
		case BUTTON_RELEASED:
			if(is_button_pressed(2)){
				buttonState3 = BUTTON_PRESSED ;
			}
		break;
		case BUTTON_PRESSED:
			if(!is_button_pressed(2)){
				buttonState3 = BUTTON_RELEASED;
			}
			else{
				if(is_button_pressed_1s(2) == 1){
					buttonState3 = BUTTON_PRESSED_MORE_THAN_1_SECOND;
				}
			}
		break;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND:
			if(!is_button_pressed(2)){
				buttonState3 = BUTTON_RELEASED;
			}
		break;
		}
	}
