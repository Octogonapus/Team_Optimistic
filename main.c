#pragma config(UART_Usage, UART1, uartUserControl, baudRate9600, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(Sensor, in1,    intakePot,      sensorPotentiometer)
#pragma config(Sensor, dgtl1,  leftQuad,       sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightQuad,      sensorQuadEncoder)
#pragma config(Motor,  port1,           leftMotor,     tmotorVex393_HBridge, openLoop, reversed, driveLeft)
#pragma config(Motor,  port10,          rightMotor,    tmotorVex393_HBridge, openLoop, reversed, driveRight)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "BCI/Modules/Core/positionPID.c"
#include "BCI/Modules/Core/timer.c"

#include "motorControl.c"
#include "uartHandler.c"

task main()
{
	//Start reading from pi
	startTask(readBuffer);

	while (true)
	{
		//Send data to pi
		sendCurrentData();

		semaphoreLock(msgSem);
		if (bDoesTaskOwnSemaphore(msgSem))
		{
			writeDebugStreamLine("%d,%d,%d", msg[0], msg[1], msg[2]);

			if (bDoesTaskOwnSemaphore(msgSem))
			{
				semaphoreUnlock(msgSem);
			}
		}

		//Task wait
		wait1Msec(15);
	}
}
