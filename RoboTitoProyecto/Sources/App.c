/*
 * App.c
 *
 *  Created on: Oct 7, 2014
 *      Author: lau-Desktop
 */

#include "Movimiento.h"
#include "Motor.h"
#include "FRTOS1.h"

#define VELOCIDAD_MAX
#define VELOCIDAD_MEDIA
#define VELOCIDAD_MIN

static portTASK_FUNCTION(MainTask, pvParameters) {
	(void)pvParameters; /* not used */

	
	FRTOS1_vTaskDelay(10/portTICK_RATE_MS);
}


void App_run(){
	Motor_Init();
	//SHELL_Init();

	if (FRTOS1_xTaskCreate(MainTask, "Main", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY+1, NULL) != pdPASS) {
		for(;;){} /* error */
	}
	FRTOS1_vTaskStartScheduler();
}
