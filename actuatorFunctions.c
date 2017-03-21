#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include "actuatorFunctions.h"
#include "control.h"
#include "uart.h"
#include "can.h"
#include "system.h"

/*
 *	Function: 		static void ball_grabbers(unsigned char side, unsigned char state)
 *	Parameters: 	unsigned char side 	- which side ball grabber to control
 *					unsigned char state	- UP or DOWN
 *	Description: 	controls the ball grabbers servos
 *	Help: 			to adjust parameters go to control.h
 */
static void ball_grabbers(unsigned char side, unsigned char state)
{
	// check CW and CCW
	// change variables in control.h
	if(side == LEFT)
	{
		if(state == UP)
		{
			AX_SetAngle(POS_BALLGRABBERLEFT_UP, AX_SPEED_FAST, CW, ID_BALLGRABBER_LEFT);
		}
		else
		{
			AX_SetAngle(POS_BALLGRABBERLEFT_DOWN, AX_SPEED_FAST, CCW, ID_BALLGRABBER_LEFT);
		}
	}
	else
	{
		if(state == UP)
		{
			AX_SetAngle(POS_BALLGRABBERRIGHT_UP, AX_SPEED_FAST, CW, ID_BALLGRABBER_RIGHT);
		}
		else
		{
			AX_SetAngle(POS_BALLGRABBERRIGHT_DOWN, AX_SPEED_FAST, CCW, ID_BALLGRABBER_RIGHT);
		}
	}
}

/*
 *	Function: 		static void dispenser(unsigned char side, unsigned char state)
 *	Parameters: 	unsigned char side 	- which side dispenser
 *					unsigned char state	- UP or DOWN
 *	Description: 	controls the dispensers position
 *	Help: 			to adjust parameters go to control.h
 */
static void dispenser(unsigned char side, unsigned char state)
{
	// ! configure the ax servo id's in control.h file !
	// check CW and CCW
	// change variables in control.h
	if(side == LEFT)
	{
		if(state == UP)
		{
			AX_SetAngle(POS_DISPENSERLEFT_UP, AX_SPEED_SLOW, CCW, ID_DISPENSER_LEFT);
		}
		else
		{
			AX_SetAngle(POS_DISPENSERLEFT_DOWN, AX_SPEED_SLOW, CW, ID_DISPENSER_LEFT);
		}
	}
	else
	{
		if(state == UP)
		{
			AX_SetAngle(POS_DISPENSERRIGHT_UP, AX_SPEED_SLOW, CW, ID_DISPENSER_RIGHT);
		}
		else
		{
			AX_SetAngle(POS_DISPENSERRIGHT_DOWN, AX_SPEED_SLOW, CW, ID_DISPENSER_RIGHT);
		}
	}
}

/*
 *	Function: static void mosfet(unsigned char side, unsigned char state)
 *	Parameters: unsigned char side 	- which side diafram to control
 *				unsigned char state	- ON or OFF state
 *	Description: controls the mosfets that turn 12V on or off
 */
static void mosfet(unsigned char side, unsigned char state)
{
	if(side == LEFT)
	{
		if(state == ON)
		{
			GPIO_OutputSet(pinE4);
		}
		else
		{
			GPIO_OutputReset(pinE4);
		}
	}
	else
	{
		if(state == ON)
		{
			GPIO_OutputSet(pinE5);
		}
		else
		{
			GPIO_OutputReset(pinE5);
		}
	}
}

static void motor(unsigned char direction, int8_t pwm)
{
	if(direction == CW)
	{

	}
	else
	{

	}
}

/*
 *	Function: 		void action(canMsg msg)
 *	Parameters: 	canMsg msg
 *	Description: 	decides actions on can msg received
 */
void action(canMsg msg)
{
	/*
	unsigned char command = msg.data[0];
	unsigned char side, state;
	uint8_t pwm;

	switch(command)
	{
		// "ball grabbers"
		case 'A':
			// side 	- LEFT or RIGHT
			// state 	- UP or DOWN
			side 	= msg.data[1];
			state 	= msg.data[2];
			ball_grabbers(side, state);
			break;
		// "dispenser"
		case 'B':
			// side 	- LEFT or RIGHT
			// state 	- UP or DOWN
			side 	= msg.data[1];
			state 	= msg.data[2];
			dispenser(side, state);
			break;
		// "diafram"
		case 'C':
			// side 	- FIRST or SECOND
			// state 	- ON or OFF
			side 	= msg.data[1];
			state 	= msg.data[2];
			mosfet(side, state);
			break;
		// "motor"
		case 'D':
			// state 	- CW or CCW
			// pwm		- 0-255
			state 	= msg.data[1];
			pwm		= msg.data[2];
			motor(state, pwm);

			break;
	}*/
}
