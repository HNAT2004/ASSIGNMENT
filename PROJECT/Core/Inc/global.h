/*
 * global.h
 *
 *  Created on: Sep 28, 2024
 *      Author: Genki
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#include "input_reading.h"
#include "timer.h"

#define INIT 1
#define AUTO_RED 2
#define AUTO_GREEN 3
#define AUTO_YELLOW 4
#define MAN_RED 5
#define MAN_GREEN 6
#define MAN_YELLOW 7
#define MANUAL_REDX_GREENY 8
#define MANUAL_REDX_YELLOWY 9
#define MANUAL_GREENX_REDY 10
#define MANUAL_YELLOWX_REDY 11

extern int statusx;
extern int statusy;

#endif /* INC_GLOBAL_H_ */
