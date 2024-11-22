/*
 * input_reading.h
 *
 *  Created on: Sep 27, 2024
 *      Author: Genki
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_
void button_reading(void);
unsigned char is_button_pressed(unsigned char index);
unsigned char is_button_pressed_1s(unsigned char index);
void Button1Run(void);
int ProcessButton1(void);
void Button2Run(void);
int ProcessButton2(void);
void Button3Run(void);
int ProcessButton3(void);
#endif /* INC_INPUT_READING_H_ */
