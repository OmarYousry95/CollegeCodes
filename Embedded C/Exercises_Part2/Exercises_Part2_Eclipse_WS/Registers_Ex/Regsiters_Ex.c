/*
 ============================================================================
 Name        : Registers_Ex.c
 Author      : Mohamed Tarek
 Description : Example to use the defined Memory Mapped Registers
 Date        : 31/3/2019
 ============================================================================
 */

#include "Atmega16_Regs.h"

int main()
{
	/********** Initialization Code **********/
	DDRA_REG &= ~(1<<3); // configure pin 3 in PORTA as input pin

	DDRC_REG |= (1<<5); // configure pin 5 in PORTC as output pin
	PORTC_REG &= ~(1<<5); // LED OFF

	while(1)
	{
		/********** Application Code **********/
		if(PINA_REG & (1<<3)) // Check the button status pressed or not
		{
			PORTC_REG |= (1<<5); // LED ON
		}
		else
		{
			PORTC_REG &= (~(1<<5)); // LED OFF
		}
	}
}
