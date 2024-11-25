/*
 * input_reading.c
 *
 *  Created on: Sep 27, 2024
 *      Author: Genki
 */


#include "main.h"
#define N0_OF_BUTTONS 3
#define DURATION_FOR_AUTO_INCREASING 100
#define DURATION_FOR_AUTO_INCREASING2 110
#define BUTTON_IS_PRESSED GPIO_PIN_RESET
#define BUTTON_IS_RELEASED GPIO_PIN_SET
static GPIO_PinState buttonBuffer[N0_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer1[N0_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[N0_OF_BUTTONS];
static uint8_t flagForButtonPress1s[N0_OF_BUTTONS];
static uint16_t counterForButtonPress1s[N0_OF_BUTTONS];
int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;
void Button1Run(void){
 	button1_flag = 1;
 }
int ProcessButton1(void){
	 if(button1_flag == 1){
		 button1_flag = 0;
		 return 1;
	 }
	 return 0;
 }
void Button2Run(void){
 	button2_flag = 1;
 }
int ProcessButton2(void){
	 if(button2_flag == 1){
		 button2_flag = 0;
		 return 1;
	 }
	 return 0;
 }
void Button3Run(void){
 	button3_flag = 1;
 }
int ProcessButton3(void){
	 if(button3_flag == 1){
		 button3_flag = 0;
		 return 1;
	 }
	 return 0;
 }
		void button_reading(void){
			 for(unsigned char i = 0;i < N0_OF_BUTTONS;i++){
				 debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
				 if(i == 0){
				 debounceButtonBuffer1[0] = HAL_GPIO_ReadPin(Button1_GPIO_Port,Button1_Pin);
				 }
				 else if(i == 1){
				 debounceButtonBuffer1[1] = HAL_GPIO_ReadPin(Button2_GPIO_Port,Button2_Pin);
				 }
				 else if(i == 2){
				 debounceButtonBuffer1[2] = HAL_GPIO_ReadPin(Button3_GPIO_Port,Button3_Pin);
				 }
				 if(debounceButtonBuffer1[i] == debounceButtonBuffer2[i]){
					 buttonBuffer[i] = debounceButtonBuffer1[i];
					 if(buttonBuffer[i] == BUTTON_IS_PRESSED){
						 if(i == 0){
							 Button1Run();
						 }
						 else if(i == 1){
							 Button2Run();
						 }
						 else if(i == 2){
							 Button3Run();
						 }
						 if(counterForButtonPress1s[i] < DURATION_FOR_AUTO_INCREASING && flagForButtonPress1s[i] == 0){
							 counterForButtonPress1s[i]++;
						 }
						 else{
							 flagForButtonPress1s[i] = 1;

							 if(counterForButtonPress1s[i] < DURATION_FOR_AUTO_INCREASING2){
								counterForButtonPress1s[i]++;
							 }
							 else{
								buttonBuffer[i] = BUTTON_IS_RELEASED;
								counterForButtonPress1s[i] = 100;
							 }

						 }
					 }
				 }
					 else{
						 counterForButtonPress1s[i] = 0;
						 flagForButtonPress1s[i] = 0;
					 }
				 }
			}
unsigned char is_button_pressed(uint8_t index){
	if(index >= N0_OF_BUTTONS) return 0;
	return (buttonBuffer[index] == BUTTON_IS_PRESSED);
}
unsigned char is_button_pressed_1s(unsigned char index){
	if(index >= N0_OF_BUTTONS) return 0xff;
	return (flagForButtonPress1s[index] == 1) ;
}
