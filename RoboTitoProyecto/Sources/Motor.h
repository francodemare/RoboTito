/*
 * Motor.h
 *
 *  Created on: Oct 4, 2014
 *      Author: lau-Desktop
 */

#ifndef MOTOR_H_
#define MOTOR_H_

typedef enum Direction {ADELANTE,ATRAS} DIRECCION ;
typedef enum State {ANDANDO,PARADO} ESTADO;

struct Motor{
	unsigned char id;
	ESTADO estado;
	DIRECCION direccion;
	unsigned char velocidad; //La velocida es en un rango de [0..100]
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
