/*
 * Motor_PWM.h
 *
 *  Created on: Oct 4, 2014
 *      Author: lau-Desktop
 */

#ifndef MOTOR_PWM_H_
#define MOTOR_PWM_H_

void Motor_PWM_Arrancar(unsigned char id);
void MOTOR_PWM_setVelocidad(unsigned char id,unsigned char velocidad);
void MOTOR_PWM_setDireccion(unsigned char id,unsigned char direccion);
void Motor_PWM_Parar(unsigned char id);

#endif /* MOTOR_PWM_H_ */
