/*
 * Motor.h
 *
 *  Created on: Oct 4, 2014
 *      Author: lau-Desktop
 */

#ifndef MOTOR_H_
#define MOTOR_H_

typedef enum DIRECCION_ {ADELANTE,ATRAS} DIRECCION ;
typedef enum ESTADO_ {ANDANDO,PARADO} ESTADO;

struct Motor{
	unsigned char id;
	ESTADO estado;
	DIRECCION direccion;
	unsigned char velocidad; /* La velocidad en un rango de [0..100] */
	LDD_TDeviceData *PWMdeviceData; /* LDD device para controlar PWM */
	LDD_TError (*SetRatio16)(LDD_TDeviceData*, uint16_t); /* Funcion para setear el ratio */
	LDD_TDeviceData *DIRdeviceData; /* LDD device para controlar la Direccion */
	void (*DirPutVal)(LDD_TDeviceData *, bool); /* Funcion para setear la Direccion */
};

typedef struct Motor Motor;


/*
 * Se arranca el motor: 
 * 
 * Velocidad = VelocidadDefault
 * Direccion = Adelante
 * 
 */
void Motor_ArrancarDefault(Motor *m);

/*
 *  Se arranca el motor
 *  
 *  Velocidad = cantVelocidad
 *  Direccion = Adelante
 */
void Motor_Arrancar(Motor *m,unsigned char cantVelocidad);

/*
 * Se cambia manda la direccion al motor
 * 
 */
void Motor_setDireccion(Motor *m,DIRECCION dir);

/*
 * Se cambia la direccion al motor
 * 
 */
void Motor_cambiarDireccion(Motor *m);

/*
 * 
 * Se setea la velocidad al motor
 * 
 */
void Motor_setVelocidad(Motor *m,unsigned char cantVelocidad);

/*
 * 
 * Se devuelve la corriente del motor
 *   **Todavia no esta implementado**
 * 
 */
int Motor_getCorriente();

/*
 * Se para el motor
 * 
 */
void Motor_Parar(Motor *m);

#endif /* MOTOR_H_ */
