/*
 * exercise1.h
 *
 *  Created on: Sep 24, 2024
 *      Author: phan thanh huy
 */

#ifndef INC_EXERCISE1_H_
#define INC_EXERCISE1_H_

extern int index_led;
extern int hour;
extern int minute;
extern int second;

void display7SEG(int num);
void update7SEG(int index);
void updateClockBuffer();
void handleTime();

void initExercise1();
void runExercise1();

#endif /* INC_EXERCISE1_H_ */
