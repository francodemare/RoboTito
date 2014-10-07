/*
 * Motor.c
 *
 *  Created on: Oct 4, 2014
 *      Author: lau-Desktop
 */

#include "Motor.h"
#include "Motor_PWM.h"
#include "PWM_TraccionTrasera.h"
#include "PWM_TraccionDelantera.h"
#include "TraccionTrasera_Direccion.h"
#include "TraccionDelantera_Direccion.h"

//#define VELOCIDADDEFAULT 50
#define VELOCIDADMIN 0
#define VELOCIDADMAX 100

/*void Motor_ArrancarDefault(Motor *m){
	m->direccion = 	1;
	m->velocidad = VELOCIDADDEFAULT;
	Motor_PWM_Arrancar(m,VELOCIDADDEFAULT);
}*/

static Motor motorTrasero,motorDelantero;

void Motor_Arrancar(Motor *m,uint8_t cantVelocidad,uint8_t dir){
	m->direccion = 	dir;
	if(cantVelocidad > VELOCIDADMAX){
		m->velocidad = VELOCIDADMAX;
		Motor_PWM_Arrancar(m,VELOCIDADMAX);
	}else{
		if(cantVelocidad < VELOCIDADMIN){
			m->velocidad = VELOCIDADMIN;
			Motor_PWM_Arrancar(m,VELOCIDADMIN);
		}else{
			Motor_PWM_Arrancar(m,cantVelocidad);
		}
	}
}

void Motor_setDireccion(Motor *m,uint8_t dir){
	m->direccion = dir;
	if(dir == 1){
		MOTOR_PWM_setDireccion(m,1);
	}else{
		MOTOR_PWM_setDireccion(m,0);
	}
}

void Motor_cambiarDireccion(Motor *m){
	if(m->direccion == 1){
		m->direccion = 0;
		MOTOR_PWM_setDireccion(m,0);
	}else{
		m->direccion = 1;
		MOTOR_PWM_setDireccion(m,1);
	}
}

void Motor_setVelocidad(Motor *m,uint8_t cantVelocidad){
	if(cantVelocidad > VELOCIDADMAX){
		m->velocidad = VELOCIDADMAX;
		MOTOR_PWM_setVelocidad(m,VELOCIDADMAX);
	}else{
		if(cantVelocidad < VELOCIDADMIN){
			m->velocidad = VELOCIDADMIN;
			MOTOR_PWM_setVelocidad(m,VELOCIDADMIN);
		}else{
			m->velocidad = cantVelocidad;
			MOTOR_PWM_setVelocidad(m,cantVelocidad);
		}
	}
}

int Motor_getCorriente(){
	/*Por el momento no tenemos para sensar la corriente del motor*/
}

void Motor_Parar(Motor *m){
	Motor_PWM_Parar(m);
}

Motor * Motor_getMotor(TIPO_MOTOR tipoMotor){
	if(tipoMotor = TRASERO){
		return &motorTrasero;
	}else{
		return &motorDelantero;
	}
}

void Motor_Init(){
	//Se inicializa Motor Trasero
	motorTrasero.PWMdeviceData = PWM_TraccionTrasera_Init(NULL);
	motorTrasero.SetRatio16 = PWM_TraccionTrasera_SetRatio16;
	motorTrasero.DIRdeviceData = TraccionTrasera_Direccion_Init(NULL);
	motorTrasero.DirPutVal = TraccionTrasera_Direccion_PutVal;
	//Se inicializa Motor Delantero
	motorDelantero.PWMdeviceData = PWM_TraccionDelantera_Init(NULL);
	motorDelantero.SetRatio16 = PWM_TraccionDelantera_SetRatio16;
	motorDelantero.DIRdeviceData = TraccionDelantera_Direccion_Init(NULL);
	motorDelantero.DirPutVal = TraccionDelantera_Direccion_PutVal;
    //Se activan los PWM
	PWM_TraccionDelantera_Enable(motorDelantero.PWMdeviceData);
	PWM_TraccionTrasera_Enable(motorTrasero.PWMdeviceData);
}
