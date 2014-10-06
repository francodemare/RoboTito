/*
 * Motor.c
 *
 *  Created on: Oct 4, 2014
 *      Author: lau-Desktop
 */

#include "Motor_PWM.h"

#define VELOCIDADDEFAULT 50
#define VELOCIDADMIN 0
#define VELOCIDADMAX 100

void Motor_ArrancarDefault(Motor *m){
	m->estado = ANDANDO;
	m->direccion = 	ADELANTE;
	m->velocidad = VELOCIDADDEFAULT;
	Motor_PWM_Arrancar(m,VELOCIDADDEFAULT);
}

void Motor_Arrancar(Motor *m,unsigned char cantVelocidad){
	m->estado = ANDANDO;
	m->direccion = 	ADELANTE;
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

void Motor_setDireccion(Motor *m,DIRECCION dir){
	m->direccion = dir;
	if(direccion == ADELANTE){
		MOTOR_PWM_setDireccion(m,1);
	}else{
		MOTOR_PWM_setDireccion(m,0);
	}
}

void Motor_cambiarDireccion(Motor *m){
	if(m->direccion == ADELANTE){
		m->direccion = ATRAS;
		MOTOR_PWM_setDireccion(m,0);
	}else{
		m->direccion = ADELANTE;
		MOTOR_PWM_setDireccion(m,1);
	}
}

void Motor_setVelocidad(Motor *m,unsigned char cantVelocidad){
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
	m->estado = PARADO;
	Motor_PWM_Parar(m);
}

