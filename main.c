/*
 * main.c
 *
 *  Created on: Oct 30, 2020
 *      Author: Mohamed
 */

#include "Std_Types.h"
#include "Utilites.h"
#include "Dio_Int.h"
#include "SPI_Int.h"
#include "Dio_Reg.h"
#include "UART_Int.h"
#define Button_Pressed  1
#define Button_Released 0


void main(void)
{
	u8 data2=0;
	Dio_SetPinDirection(GroupA, PIN0, INPUT);//init button
	Dio_SetPinValue(GroupA, PIN0, HIGH);//pullup
	UART_Init();
	SPI_initMaster();
	while(1)
     {
	data2=UART_RecieveByte();
	UART_SendByte(data2);


		if(Dio_GetPinValue(GroupA, PIN0)==0)//button pressed
			{
				SPI_sendByte(Button_Pressed);
			}
		else
			{
				SPI_sendByte(Button_Released);
			}
     }
}
