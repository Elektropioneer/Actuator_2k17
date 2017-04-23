#ifndef CONTROL_H_
#define CONTROL_H_
#include "can.h"

#define MID							4

/*#define AX_SERVO1 					1
#define AX_SERVO2 					2
#define AX_SERVO3 					3
#define AX_SERVO4 					4*/

#define AX_SPEED_GRANNY				50
#define AX_SPEED_SLOW				100
#define AX_SPEED_FAST				240

#define ID_DISPENSER_LEFT			2
#define ID_DISPENSER_RIGHT			4

#define POS_DISPENSERLEFT_UP		244
#define POS_DISPENSERLEFT_DOWN		158
#define POS_DISPENSERLEFT_MID       168

#define POS_DISPENSERRIGHT_UP		50
#define POS_DISPENSERRIGHT_DOWN		142
#define POS_DISPENSERRIGHT_MID      130

#define ID_BALLGRABBER_LEFT			10
#define ID_BALLGRABBER_RIGHT		3

#define POS_BALLGRABBERLEFT_UP		264
#define POS_BALLGRABBERLEFT_DOWN	148
#define POS_BALLGRABBERLEFT_MID		235

#define POS_BALLGRABBERRIGHT_UP		144
#define POS_BALLGRABBERRIGHT_DOWN	240
#define POS_BALLGRABBERRIGHT_MID	160

void AX_UART_Init(void);
void AX_SendChar(unsigned char data);
unsigned char AX_ReadChar(void);
void AX_ReadStatus(void);
void AX_StopTransmitter(void);
void AX_ReleaseTransmitter(void);
void AX_StopReceiver(void);
void AX_ReleaseReceiver(void);
void AX_SetAngle(unsigned int angle, unsigned int speed, unsigned char direction, unsigned char id);
void AX_EndlessTurn(void);
void AX_SetSpeed(unsigned int direction, unsigned int speed);

#endif
