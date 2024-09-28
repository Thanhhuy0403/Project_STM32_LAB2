/*
 * exercise9.c
 *
 *  Created on: Sep 28, 2024
 *      Author: phan thanh huy
 */

#include "exercise9.h"
#include "main.h"

GPIO_TypeDef* ledMatrixCol_Ports[8] = {
	ENM0_GPIO_Port, ENM1_GPIO_Port, ENM2_GPIO_Port, ENM3_GPIO_Port,
	ENM4_GPIO_Port, ENM5_GPIO_Port, ENM6_GPIO_Port, ENM7_GPIO_Port
};

uint16_t ledMatrixCol_Pins[8] = {
	ENM0_Pin, ENM1_Pin, ENM2_Pin, ENM3_Pin,
	ENM4_Pin, ENM5_Pin, ENM6_Pin, ENM7_Pin
};

GPIO_TypeDef* ledMatrixRow_Ports[8] = {
	ROW0_GPIO_Port, ROW1_GPIO_Port, ROW2_GPIO_Port, ROW3_GPIO_Port,
	ROW4_GPIO_Port, ROW5_GPIO_Port, ROW6_GPIO_Port, ROW7_GPIO_Port
};

uint16_t ledMatrixRow_Pins[8] = {
	ROW0_Pin, ROW1_Pin, ROW2_Pin, ROW3_Pin,
	ROW4_Pin, ROW5_Pin, ROW6_Pin, ROW7_Pin
};
const int MAX_LED_MATRIX = 8;
int index_led_matrix = 0;
uint8_t matrix_buffer [8] = {0x18, 0x24, 0x42, 0x42, 0x7E, 0x42, 0x42, 0x42};

void initExercise9(){
	for(int i = 0; i < 8; i++){
		HAL_GPIO_WritePin(ledMatrixCol_Ports[i], ledMatrixCol_Pins[i], 1);
		HAL_GPIO_WritePin(ledMatrixRow_Ports[i], ledMatrixRow_Pins[i], 1);
	}
}

void updateLEDMatrix(int index){

	uint8_t byte = matrix_buffer[index];

	switch (index){
		case 0:
			HAL_GPIO_WritePin(ledMatrixRow_Ports[7], ledMatrixRow_Pins[7], GPIO_PIN_SET);
			for (int j = 0; j < 8; j++) {
				HAL_GPIO_WritePin(ledMatrixCol_Ports[j], ledMatrixCol_Pins[j], (byte & 0x80) ? GPIO_PIN_RESET : GPIO_PIN_SET);
				byte <<= 1;
			}
			break;
		case 1:
			HAL_GPIO_WritePin(ledMatrixRow_Ports[0], ledMatrixRow_Pins[0], GPIO_PIN_SET);
			for (int j = 0; j < 8; j++) {
				HAL_GPIO_WritePin(ledMatrixCol_Ports[j], ledMatrixCol_Pins[j], (byte & 0x80) ? GPIO_PIN_RESET : GPIO_PIN_SET);
				byte <<= 1;
			}
			break;
		case 2:
			HAL_GPIO_WritePin(ledMatrixRow_Ports[1], ledMatrixRow_Pins[1], GPIO_PIN_SET);
			for (int j = 0; j < 8; j++) {
				HAL_GPIO_WritePin(ledMatrixCol_Ports[j], ledMatrixCol_Pins[j], (byte & 0x80) ? GPIO_PIN_RESET : GPIO_PIN_SET);
				byte <<= 1;
			}
			break;
		case 3:
			HAL_GPIO_WritePin(ledMatrixRow_Ports[2], ledMatrixRow_Pins[2], GPIO_PIN_SET);
			for (int j = 0; j < 8; j++) {
				HAL_GPIO_WritePin(ledMatrixCol_Ports[j], ledMatrixCol_Pins[j], (byte & 0x80) ? GPIO_PIN_RESET : GPIO_PIN_SET);
				byte <<= 1;
			}
			break;
		case 4:
			HAL_GPIO_WritePin(ledMatrixRow_Ports[3], ledMatrixRow_Pins[3], GPIO_PIN_SET);
			for (int j = 0; j < 8; j++) {
				HAL_GPIO_WritePin(ledMatrixCol_Ports[j], ledMatrixCol_Pins[j], (byte& 0x80) ? GPIO_PIN_RESET : GPIO_PIN_SET);
				byte <<= 1;
			}
			break;
		case 5:
			HAL_GPIO_WritePin(ledMatrixRow_Ports[4], ledMatrixRow_Pins[4], GPIO_PIN_SET);
			for (int j = 0; j < 8; j++) {
				HAL_GPIO_WritePin(ledMatrixCol_Ports[j], ledMatrixCol_Pins[j], (byte & 0x80) ? GPIO_PIN_RESET : GPIO_PIN_SET);
				byte <<= 1;
			}
			break;
		case 6:
			HAL_GPIO_WritePin(ledMatrixRow_Ports[5], ledMatrixRow_Pins[5], GPIO_PIN_SET);
			for (int j = 0; j < 8; j++) {
				HAL_GPIO_WritePin(ledMatrixCol_Ports[j], ledMatrixCol_Pins[j], (byte & 0x80) ? GPIO_PIN_RESET : GPIO_PIN_SET);
				byte <<= 1;
			}
			break;
		case 7:
			HAL_GPIO_WritePin(ledMatrixRow_Ports[6], ledMatrixRow_Pins[6], GPIO_PIN_SET);
			for (int j = 0; j < 8; j++) {
				HAL_GPIO_WritePin(ledMatrixCol_Ports[j], ledMatrixCol_Pins[j], (matrix_buffer[index] & 0x80) ? GPIO_PIN_RESET : GPIO_PIN_SET);
				matrix_buffer[index] <<= 1;
			}
			break;
		default:
			break;
	}
	HAL_GPIO_WritePin(ledMatrixRow_Ports[index], ledMatrixRow_Pins[index], GPIO_PIN_RESET);
}

void runExercise9() {
	if(index_led_matrix >= MAX_LED_MATRIX){
		index_led_matrix = 0;
	}
	updateLEDMatrix(index_led_matrix++);
}
