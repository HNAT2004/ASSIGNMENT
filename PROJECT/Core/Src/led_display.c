/*
 * led_display.c
 *
 *  Created on: Sep 27, 2024
 *      Author: Genki
 */
#include "main.h"
#include "global.h"
int statusledx = 0;
int statusledy = 0;
void DisplayREDX(void){
	HAL_GPIO_WritePin(LEDX1_A_GPIO_Port, LEDX1_A_Pin, SET);
	HAL_GPIO_WritePin(LEDX1_B_GPIO_Port, LEDX1_B_Pin, SET);
	HAL_GPIO_WritePin(LEDX2_A_GPIO_Port, LEDX2_A_Pin, SET);
	HAL_GPIO_WritePin(LEDX2_B_GPIO_Port, LEDX2_B_Pin, SET);
}
void DisplayYELLOWX(void){
	HAL_GPIO_WritePin(LEDX1_A_GPIO_Port, LEDX1_A_Pin, RESET);
	HAL_GPIO_WritePin(LEDX1_B_GPIO_Port, LEDX1_B_Pin, SET);
	HAL_GPIO_WritePin(LEDX2_A_GPIO_Port, LEDX2_A_Pin, RESET);
	HAL_GPIO_WritePin(LEDX2_B_GPIO_Port, LEDX2_B_Pin, SET);
}
void DisplayGREENX(void){
	HAL_GPIO_WritePin(LEDX1_A_GPIO_Port, LEDX1_A_Pin, SET);
	HAL_GPIO_WritePin(LEDX1_B_GPIO_Port, LEDX1_B_Pin, RESET);
	HAL_GPIO_WritePin(LEDX2_A_GPIO_Port, LEDX2_A_Pin, SET);
	HAL_GPIO_WritePin(LEDX2_B_GPIO_Port, LEDX2_B_Pin, RESET);
}
void DisplayREDY(void){
	HAL_GPIO_WritePin(LEDY1_A_GPIO_Port, LEDY1_A_Pin, SET);
	HAL_GPIO_WritePin(LEDY1_B_GPIO_Port, LEDY1_B_Pin, SET);
	HAL_GPIO_WritePin(LEDY2_A_GPIO_Port, LEDY2_A_Pin, SET);
	HAL_GPIO_WritePin(LEDY2_B_GPIO_Port, LEDY2_B_Pin, SET);
}
void DisplayYELLOWY(void){
	HAL_GPIO_WritePin(LEDY1_A_GPIO_Port, LEDY1_A_Pin, RESET);
	HAL_GPIO_WritePin(LEDY1_B_GPIO_Port, LEDY1_B_Pin, SET);
	HAL_GPIO_WritePin(LEDY2_A_GPIO_Port, LEDY2_A_Pin, RESET);
	HAL_GPIO_WritePin(LEDY2_B_GPIO_Port, LEDY2_B_Pin, SET);
}
void DisplayGREENY(void){
	HAL_GPIO_WritePin(LEDY1_A_GPIO_Port, LEDY1_A_Pin, SET);//chân đúng
	HAL_GPIO_WritePin(LEDY1_B_GPIO_Port, LEDY1_B_Pin, RESET);
	HAL_GPIO_WritePin(LEDY2_A_GPIO_Port, LEDY2_A_Pin, SET);
	HAL_GPIO_WritePin(LEDY2_B_GPIO_Port, LEDY2_B_Pin, RESET);
}
void InitLED(void){
	HAL_GPIO_WritePin(LEDX1_A_GPIO_Port, LEDX1_A_Pin, RESET);
	HAL_GPIO_WritePin(LEDX1_B_GPIO_Port, LEDX1_B_Pin, RESET);
	HAL_GPIO_WritePin(LEDX2_A_GPIO_Port, LEDX2_A_Pin, RESET);
	HAL_GPIO_WritePin(LEDX2_B_GPIO_Port, LEDX2_B_Pin, RESET);
	HAL_GPIO_WritePin(LEDY1_A_GPIO_Port, LEDY1_A_Pin, RESET);
	HAL_GPIO_WritePin(LEDY1_B_GPIO_Port, LEDY1_B_Pin, RESET);
	HAL_GPIO_WritePin(LEDY2_A_GPIO_Port, LEDY2_A_Pin, RESET);
	HAL_GPIO_WritePin(LEDY2_B_GPIO_Port, LEDY2_B_Pin, RESET);
}
void DisplayMAN_REDX(void){
	switch(statusledx){
	case 0:
		DisplayREDX();
		break;
	case 1:
		InitLED();
		break;
	}
	if(statusledx == 0){
		statusledx = 1;
	}
	else{
		statusledx = 0;
	}
}
void DisplayMAN_REDY(void){
	switch(statusledy){
	case 0:
		DisplayREDY();
		break;
	case 1:
		InitLED();
		break;
	}
	if(statusledy == 0){
		statusledy = 1;
	}
	else{
		statusledy = 0;
	}
}
void DisplayMAN_GREENX(void){
	switch(statusledx){
	case 0:
		DisplayGREENX();
		break;
	case 1:
		InitLED();
		break;
	}
	if(statusledx == 0){
		statusledx = 1;
	}
	else{
		statusledx = 0;
	}
}
void DisplayMAN_GREENY(void){
	switch(statusledy){
	case 0:
		DisplayGREENY();
		break;
	case 1:
		InitLED();
		break;
	}
	if(statusledy == 0){
		statusledy = 1;
	}
	else{
		statusledy = 0;
	}
}
void DisplayMAN_YELLOWX(void){
	switch(statusledx){
	case 0:
		DisplayYELLOWX();
		break;
	case 1:
		InitLED();
		break;
	}
	if(statusledx == 0){
		statusledx = 1;
	}
	else{
		statusledx = 0;
	}
}
void DisplayMAN_YELLOWY(void){
	switch(statusledy){
	case 0:
		DisplayYELLOWY();
		break;
	case 1:
		InitLED();
		break;
	}
	if(statusledy == 0){
		statusledy = 1;
	}
	else{
		statusledy = 0;
	}
}

