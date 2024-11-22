/*
 * led_display.c
 *
 *  Created on: Sep 27, 2024
 *      Author: Genki
 */
#include "main.h"
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
//void DisplayMAN_REDX(void){
//	HAL_GPIO_TogglePin(LED_RED_X_GPIO_Port, LED_RED_X_Pin);
//}
//void DisplayMAN_REDY(void){
//	HAL_GPIO_TogglePin(LED_RED_Y_GPIO_Port, LED_RED_Y_Pin);
//}
//void DisplayMAN_GREENX(void){
//	HAL_GPIO_TogglePin(LED_GREEN_X_GPIO_Port, LED_GREEN_X_Pin);
//}
//void DisplayMAN_GREENY(void){
//	HAL_GPIO_TogglePin(LED_GREEN_Y_GPIO_Port, LED_GREEN_Y_Pin);
//}
//void DisplayMAN_YELLOWX(void){
//	HAL_GPIO_TogglePin(LED_YELLOW_X_GPIO_Port, LED_YELLOW_X_Pin);
//}
//void DisplayMAN_YELLOWY(void){
//	HAL_GPIO_TogglePin(LED_YELLOW_Y_GPIO_Port, LED_YELLOW_Y_Pin);
//}
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
