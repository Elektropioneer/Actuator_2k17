#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include "actuatorFunctions.h"
#include "control.h"
#include "uart.h"
#include "can.h"
#include "system.h"



int main(void)
{

	AX_UART_Init();
	CAN_Init();
	CAN_InitRxMob(LIFT_IDE);
	systemInit();


	canMsg message;

    while(1)
    {
    	CAN_read(&message);
    	action(message);

    }

}
