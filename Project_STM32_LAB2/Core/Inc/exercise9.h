/*
 * exercise9.h
 *
 *  Created on: Sep 28, 2024
 *      Author: phan thanh huy
 */

#ifndef INC_EXERCISE9_H_
#define INC_EXERCISE9_H_

#include "main.h"

extern int index_led_matrix;
extern uint8_t matrix_buffer[8];

void updateLEDMatrix(int index);
void circularShiftRight(uint8_t* buffer, size_t size, uint8_t shift);
void initExercise9();
void runExercise9();

#endif /* INC_EXERCISE9_H_ */
