/*

 * Movimiento.c
 *
 *  Created on: Oct 3, 2014
 *      Author: Franco
 */

void Movimeinto_irHaciaAdelate(){
	PWM_TraccionTrasera_Enable();
	PWM_TraccionTrasera_SetDutyMS(NULL,50);
	PWM_TraccionTrasera_Disable();
}

void Movimiento_irHaciaAtras(){
	PWM_TraccionTrasera_Enable();
	// Invertir la marcha
	PWM_TraccionTrasera_SetDutyMS(NULL,50);
	// Avanzar por un determinado tiempo
	PWM_TraccionTrasera_Disable();
}

void Movimiento_DoblarDerecha(){
	PWM_TraccionDelantera_Enable();				// Suponemos que el ciclio al 50% doblaria toda la rueda
	// Mandar señal de manera tal de girar el motor para colocar las ruedas mirando a la derecha
	PWM_TraccionDelantera_SetDutyMS(NULL,50);
	PWM_TraccionTrasera_Enable();
	PWM_TraccionTrasera_SetDutyMS(NULL,30);
	// Avanzar por un determinado tiempo hasta que el auta alla doblado del todo
	PWM_TraccionTrasera_Disable();
	// Poner la rueda derecho
	PWM_TraccionDelantera_Disable();
}

void Movimiento_DoblarIzquierda(){
	PWM_TraccionDelantera_Enable();				// Suponemos que el ciclio al 50% doblaria toda la rueda
	// Mandar señal de manera tal de girar el motor para colocar las ruedas mirando a la izquierda
	PWM_TraccionDelantera_SetDutyMS(NULL,50);
	PWM_TraccionTrasera_Enable();
	PWM_TraccionTrasera_SetDutyMS(NULL,30);
	// Avanzar por un determinado tiempo hasta que el auta alla doblado del todo
	PWM_TraccionTrasera_Disable();
	// Poner la rueda derecho
	PWM_TraccionDelantera_Disable();
}
