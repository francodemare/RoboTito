/*
 * MotorDelantero.c
 *
 *  Created on: Oct 4, 2014
 *      Author: lau-Desktop
 */


typedef enum Direction {DERECHA,IZQUIERDA} DIRECCION ;
typedef enum State {ANDANDO,PARADO} ESTADO;

struct Servo{
	unsigned char id;
	ESTADO estado;
	DIRECCION direccion;
	signed char grados; //La velocida es en un rango de [-45..45]
};

void Servo_Arrancar(){
	
}




