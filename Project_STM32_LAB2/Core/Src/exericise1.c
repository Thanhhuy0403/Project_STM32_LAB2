/*
 * exericise1.c
 *
 *  Created on: Sep 27, 2024
 *      Author: phan thanh huy
 */

#include "main.h"
#include <stdbool.h>
#include "exercise1.h"

GPIO_TypeDef* led7SEG_GPIO_Ports[7] = {
	SEG0_GPIO_Port, SEG1_GPIO_Port, SEG2_GPIO_Port, SEG3_GPIO_Port,
	SEG4_GPIO_Port, SEG5_GPIO_Port, SEG6_GPIO_Port
};

uint16_t led7SEG_Pins[7] = {
	SEG0_Pin, SEG1_Pin, SEG2_Pin, SEG3_Pin,
	SEG4_Pin, SEG5_Pin, SEG6_Pin
};

bool numLed7SEG[10][7] = {{0,0,0,0,0,0,1},
						 {1,0,0,1,1,1,1},
						 {0,0,1,0,0,1,0},
						 {0,0,0,0,1,1,0},
						 {1,0,0,1,1,0,0},
						 {0,1,0,0,1,0,0},
						 {0,1,0,0,0,0,0},
						 {0,0,0,1,1,1,1},
						 {0,0,0,0,0,0,0},
						 {0,0,0,0,1,0,0}
						};

void display7SEG(int num){
	if(num < 0 && num >= 10) return;
	for(int i = 0; i < 7; i++){
		HAL_GPIO_WritePin(led7SEG_GPIO_Ports[i], led7SEG_Pins[i], numLed7SEG[num][i]);
	}
}
void initExercise1(){
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
}

static int status_led = 1; // exercise2

void runExercise1(){
	if(status_led > 4){
		status_led = 1;
	}
	switch (status_led){
		case 1:
			display7SEG(1);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
			break;
		case 2:
			display7SEG(2);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
			break;
		case 3:
			display7SEG(3);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
			break;
		default:
			display7SEG(0);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 0);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
			break;
	}
	status_led++;
}
