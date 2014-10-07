/*
 * Motor_PWM.c
 *
 *  Created on: Oct 4, 2014
 *      Author: lau-Desktop
 */

#include "Motor.h"
#include "PE_Types.h"

void Motor_PWM_Arrancar(Motor *m,uint8_t cantVelocidad){
	uint16_t ratio;

	//La velocidad esta de 0 a 100 y el ratio es de 0 a 0xFFFF
	ratio = (65535/100) * cantVelocidad;
	m->SetRatio16(m->PWMdeviceData,ratio);
	m->DirPutVal(m->DIRdeviceData,1); //Adelante dir = 1, Atras dir = 0
}

void MOTOR_PWM_setVelocidad(Motor *m,uint8_t cantVelocidad){
	uint32_t ratio;

	//La velocidad de 0 a 100 y el ratio es de 0 a 0xFFFF
	ratio = (65535/100) * cantVelocidad;
	m->SetRatio16(m->PWMdeviceData,(uint16_t)ratio);
}

void MOTOR_PWM_setDireccion(Motor *m,uint8_t direccion){
	m->DirPutVal(m->DIRdeviceData,direccion); //Adelante dir = 1, Atras dir = 0
}

void Motor_PWM_Parar(Motor *m){
	m->SetRatio16(m->PWMdeviceData,0);
}


