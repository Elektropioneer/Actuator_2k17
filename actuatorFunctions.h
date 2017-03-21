#ifndef ACTUATORFUNCTIONS_H_
#define ACTUATORFUNCTIONS_H_

#include "can.h"

#define UP				1
#define DOWN			0

#define LEFT			1
#define RIGHT			0

#define FIRST			1
#define SECOND			2

#define ON				1
#define OFF 			0

#define CW				0
#define CCW				1

void action(canMsg msg);

#endif
