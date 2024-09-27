/*
 * softwear_timer.h
 *
 *  Created on: Sep 27, 2024
 *      Author: phan thanh huy
 */

#ifndef INC_SOFTWEAR_TIMER_H_
#define INC_SOFTWEAR_TIMER_H_

extern int timer_counter[10];
extern int TIMER_CYCLE;

void setTimer(int index, int duration);
void runTimer();

#endif /* INC_SOFTWEAR_TIMER_H_ */
