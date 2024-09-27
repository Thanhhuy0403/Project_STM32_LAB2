/*
 * software.c
 *
 *  Created on: Sep 27, 2024
 *      Author: phan thanh huy
 */

#include "softwear_timer.h"
#include "global.h"

int timer_counter[10] = {0};

void setTimer(int index, int duration){
	timer_counter[index] = duration;
	timer_flag[index] = 0;
}

void runTimer(){
	if(timer_counter[0] > 0){
		timer_counter[0]--;
		if(timer_counter[0] <= 0){
			timer_flag[0] = 1;
		}
	}

	if(timer_counter[1] > 0){
		timer_counter[1]--;
		if(timer_counter[1] <= 0){
			timer_flag[1] = 1;
		}
	}
}
