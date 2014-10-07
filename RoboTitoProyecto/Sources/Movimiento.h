/*
 * Movimiento.h
 *
 *  Created on: Oct 3, 2014
 *      Author: Franco
 */

#ifndef MOVIMIENTO_H_
#define MOVIMIENTO_H_


#include "Motor.h"
#include "PE_Types.h"
typedef enum TIPO_GIRO_ {GIRO_DERECHA45,GIRO_IZQUIERDA45,GIRO_DERECHA90,GIRO_IZQUIERDA90} TIPO_GIRO;

void Movimiento_irHaciaAdelante(Motor *,unsigned char);

void Movimiento_irHaciaAtras(Motor *,unsigned char);

void Movimiento_DoblarDerecha();

void Movimiento_DoblarIzquierda();

void Movimiento_IniciarDefault(Motor *);

void Movimiento_Iniciar(Motor *,unsigned char);

void Movimiento_Frenar(Motor *);

#endif /* MOVIMIENTO_H_ */
