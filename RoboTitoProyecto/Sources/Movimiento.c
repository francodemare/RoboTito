/*

 * Movimiento.c
 *
 *  Created on: Oct 3, 2014
 *      Author: Franco
 */

#include"Movimiento.h"

//Tiempo que tarda en girar 90 grados
#define TIEMPO_GIRO_90_TIME_MS 26
//Velocidad del motor al realizar giro
#define VELOCIDAD_GIRO_MOTOR 26

void Movimiento_irHaciaAdelate(uint8_t cantVelocidad){
	Motor_setDireccion(Motor_getMotor(TRASERO),1); //Direccion hacia adelante
	Motor_setVelocidad(Motor_getMotor(DELANTERO),cantVelocidad);
}

void Movimiento_irHaciaAtras(Motor *motor,uint8_t cantVelocidad){
	Motor_setDireccion(Motor_getMotor(TRASERO),0); //Direccion hacia atras
	Motor_setVelocidad(Motor_getMotor(TRASERO),cantVelocidad);
}

void Movimiento_Girar(TIPO_GIRO tipoGiro){
	switch(tipoGiro){
	case GIRO_DERECHA45 : {
		Motor_Parar(Motor_getMotor(TRASERO));
		Motor_setVelocidad(Motor_getMotor(DELANTERO),(TIEMPO_GIRO_90_TIME_MS/2));
		Motor_setDireccion(Motor_getMotor(DELANTERO),1); //Direccion de giro a la derecha
		WAIT1_WaitOSms(2);
		Motor_Parar(Motor_getMotor(DELANTERO));
		break;
	}
	case GIRO_IZQUIERDA45 : {
		Motor_Parar(Motor_getMotor(TRASERO));
		Motor_setVelocidad(Motor_getMotor(DELANTERO),(TIEMPO_GIRO_90_TIME_MS/2));
		Motor_setDireccion(Motor_getMotor(DELANTERO),0); //Direccion de giro a la izquierda
		WAIT1_WaitOSms(2);
		Motor_Parar(Motor_getMotor(DELANTERO));
		break;
	}
	}
}

void Movimiento_Frenar(Motor *motor){
	Motor_Parar(Motor_getMotor(TRASERO));
}
