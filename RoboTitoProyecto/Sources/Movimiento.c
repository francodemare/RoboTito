/*

 * Movimiento.c
 *
 *  Created on: Oct 3, 2014
 *      Author: Franco
 */

#include "Motor.h"

void Movimiento_irHaciaAdelate(Motor *motor,uint8_t cantVelocidad){
	Motor_setDireccion(motor,ADELANTE);
	Motor_setVelocidad(motor,cantVelocidad);
}

void Movimiento_irHaciaAtras(Motor *motor,uint8_t cantVelocidad){
	Motor_setDireccion(motor,ADELANTE);
	Motor_setVelocidad(motor,cantVelocidad);
}

void Movimiento_DoblarDerecha(){
	/*// Suponemos que el ciclio al 50% doblaria toda la rueda
	// Mandar se�al de manera tal de girar el motor para colocar las ruedas mirando a la derecha
	PWM_TraccionDelantera_SetDutyMS(NULL,50);
	PWM_TraccionTrasera_Enable();
	PWM_TraccionTrasera_SetDutyMS(NULL,30);
	// Avanzar por un determinado tiempo hasta que el auta alla doblado del todo
	PWM_TraccionTrasera_Disable();
	// Poner la rueda derecho
	PWM_TraccionDelantera_Disable();*/
}

void Movimiento_DoblarIzquierda(){
	/*PWM_TraccionDelantera_Enable();				// Suponemos que el ciclio al 50% doblaria toda la rueda
	// Mandar se�al de manera tal de girar el motor para colocar las ruedas mirando a la izquierda
	PWM_TraccionDelantera_SetDutyMS(NULL,50);
	PWM_TraccionTrasera_Enable();
	PWM_TraccionTrasera_SetDutyMS(NULL,30);
	// Avanzar por un determinado tiempo hasta que el auta alla doblado del todo
	PWM_TraccionTrasera_Disable();
	// Poner la rueda derecho
	PWM_TraccionDelantera_Disable();*/
}

void Movimiento_IniciarDefault(Motor *motor){
	Motor_ArrancarDefault(motor);
}

void Movimiento_Iniciar(Motor *motor,uint8_t cantVelocidad){
	Motor_Arrancar(motor,cantVelocidad);
}

void Movimiento_Frenar(Motor *motor){
	Motor_Parar(motor);
}

/*static void Motor_Ayuda(const CLS1_StdIOType *io) {
  CLS1_SendHelpStr((unsigned char*)"motor", (unsigned char*)"Group of motor commands\r\n", io->stdOut);
  CLS1_SendHelpStr((unsigned char*)"  help|status", (unsigned char*)"Shows motor help or status\r\n", io->stdOut);
  CLS1_SendHelpStr((unsigned char*)"  (A|B) forward|backward", (unsigned char*)"Change motor direction\r\n", io->stdOut);
  CLS1_SendHelpStr((unsigned char*)"  (A|B) duty <number>", (unsigned char*)"Change motor PWM (-100..+100)%\r\n", io->stdOut);
  CLS1_SendHelpStr((unsigned char*)"  (A|B) brake (on|off)", (unsigned char*)"Enable/disable brake on motor\r\n", io->stdOut);
}

uint8_t Motor_Comandos(const unsigned char *cmd, bool *handled, const CLS1_StdIOType *io) {
  uint8_t res = ERR_OK;
  long val;
  const unsigned char *p;

  if (UTIL1_strcmp((char*)cmd, (char*)CLS1_CMD_HELP)==0 || UTIL1_strcmp((char*)cmd, (char*)"motor help")==0) {
    Motor_Ayuda(io);
    *handled = TRUE;
  } else if (UTIL1_strcmp((char*)cmd, (char*)CLS1_CMD_STATUS)==0 || UTIL1_strcmp((char*)cmd, (char*)"motor status")==0) {
    Motor_printfEstado(io);
    *handled = TRUE;
  } else if (UTIL1_strcmp((char*)cmd, (char*)"Motor Adelante")==0) {
    
    *handled = TRUE;
  } else if (UTIL1_strcmp((char*)cmd, (char*)"motor B forward")==0) {
    MOT_SetDirection(&motorB, MOT_DIR_FORWARD);
    *handled = TRUE;
  } else if (UTIL1_strcmp((char*)cmd, (char*)"motor A backward")==0) {
    MOT_SetDirection(&motorA, MOT_DIR_BACKWARD);
    *handled = TRUE;
  } else if (UTIL1_strcmp((char*)cmd, (char*)"motor B backward")==0) {
    MOT_SetDirection(&motorB, MOT_DIR_BACKWARD);
    *handled = TRUE;
  } else if (UTIL1_strcmp((char*)cmd, (char*)"motor A brake on")==0) {
    MOT_SetBrake(&motorA, TRUE);
    *handled = TRUE;
  } else if (UTIL1_strcmp((char*)cmd, (char*)"motor A brake off")==0) {
    MOT_SetBrake(&motorA, FALSE);
    *handled = TRUE;
  } else if (UTIL1_strcmp((char*)cmd, (char*)"motor B brake on")==0) {
    MOT_SetBrake(&motorB, TRUE);
    *handled = TRUE;
  } else if (UTIL1_strcmp((char*)cmd, (char*)"motor B brake off")==0) {
    MOT_SetBrake(&motorB, FALSE);
    *handled = TRUE;
  } else if (UTIL1_strncmp((char*)cmd, (char*)"motor A duty", sizeof("motor duty")-1)==0) {
    p = cmd+sizeof("motor A duty");
    if (UTIL1_xatoi(&p, &val)==ERR_OK && val >=-100 && val<=100) {
      MOT_SetSpeedPercent(&motorA, (MOT_SpeedPercent)val);
      *handled = TRUE;
    } else {
      CLS1_SendStr((unsigned char*)"Wrong argument, must be in the range -100..100\r\n", io->stdErr);
      res = ERR_FAILED;
    }
  } else if (UTIL1_strncmp((char*)cmd, (char*)"motor B duty", sizeof("motor B duty")-1)==0) {
    p = cmd+sizeof("motor B duty");
    if (UTIL1_xatoi(&p, &val)==ERR_OK && val >=-100 && val<=100) {
      MOT_SetSpeedPercent(&motorB, (MOT_SpeedPercent)val);
      *handled = TRUE;
    } else {
      CLS1_SendStr((unsigned char*)"Wrong argument, must be in the range -100..100\r\n", io->stdErr);
      res = ERR_FAILED;
    }
  }
  return res;
}

static void Motor_printfEstado(const CLS1_StdIOType *io) {
  unsigned char buf[32];

  MOT_MeasureCurrent(&motorA, &motorB);
  CLS1_SendStatusStr((unsigned char*)"Motor", (unsigned char*)"\r\n", io->stdOut);

  CLS1_SendStatusStr((unsigned char*)"  motor A", (unsigned char*)"", io->stdOut);
  buf[0] = '\0';
  UTIL1_Num16sToStrFormatted(buf, sizeof(buf), (int16_t)motorA.currSpeedPercent, ' ', 4);
  UTIL1_strcat(buf, sizeof(buf), (unsigned char*)"% 0x");
  UTIL1_strcatNum16Hex(buf, sizeof(buf), MOT_GetVal(&motorA));
  UTIL1_strcat(buf, sizeof(buf),(unsigned char*)(MOT_GetDirection(&motorA)==MOT_DIR_FORWARD?", fw":", bw"));
  UTIL1_strcat(buf, sizeof(buf),(unsigned char*)(MOT_GetBrake(&motorA)?", brake on":", brake off"));
  CLS1_SendStr(buf, io->stdOut);

  WriteCurrent(&motorA, io);
  CLS1_SendStr((unsigned char*)"\r\n", io->stdOut);

  CLS1_SendStatusStr((unsigned char*)"  motor B", (unsigned char*)"", io->stdOut);
  buf[0] = '\0';
  UTIL1_Num16sToStrFormatted(buf, sizeof(buf), (int16_t)motorB.currSpeedPercent, ' ', 4);
  UTIL1_strcat(buf, sizeof(buf), (unsigned char*)"% 0x");
  UTIL1_strcatNum16Hex(buf, sizeof(buf), MOT_GetVal(&motorB));
  UTIL1_strcat(buf, sizeof(buf),(unsigned char*)(MOT_GetDirection(&motorB)==MOT_DIR_FORWARD?", fw":", bw"));
  UTIL1_strcat(buf, sizeof(buf),(unsigned char*)(MOT_GetBrake(&motorB)?", brake on":", brake off"));
  CLS1_SendStr(buf, io->stdOut);

  WriteCurrent(&motorB, io);
  CLS1_SendStr((unsigned char*)"\r\n", io->stdOut);
} */

