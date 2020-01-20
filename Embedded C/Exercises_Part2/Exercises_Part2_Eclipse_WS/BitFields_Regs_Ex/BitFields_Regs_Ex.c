/*
 ============================================================================================
 Name        : BitFields_Regs_Ex.c
 Author      : Mohamed Tarek
 Description : Example to illustrate the idea of bit-fields with Memory Mapped Regsiters
 Date        : 31/3/2019
 ============================================================================================
 */

#include <util/delay.h>

/***************************** Register type structure declaration *****************************/
typedef union
{
	unsigned char Data;
	struct
	{
		unsigned char BIT0:1;
		unsigned char BIT1:1;
		unsigned char BIT2:1;
		unsigned char BIT3:1;
		unsigned char BIT4:1;
		unsigned char BIT5:1;
		unsigned char BIT6:1;
		unsigned char BIT7:1;
	}BITS;
}Reg_8bit;
/***********************************************************************************************/

/***************************** PORTA & PORTC Registers Definitions *****************************/
#define PINA_REG  (*(volatile Reg_8bit *)0x0039)
#define DDRA_REG  (*(volatile Reg_8bit *)0x003A)
#define PORTA_REG (*(volatile Reg_8bit *)0x003B)

#define PINC_REG  (*(volatile Reg_8bit *)0x0033)
#define DDRC_REG  (*(volatile Reg_8bit *)0x0034)
#define PORTC_REG (*(volatile Reg_8bit *)0x0035)
/***********************************************************************************************/

int main(void)
{
	DDRA_REG.BITS.BIT2 = 0; /* PA2 Input Pin */
	DDRA_REG.BITS.BIT3 = 0; /* PA3 Input Pin */
	DDRC_REG.Data = 0xFF; /* All PORTC pins are o/p pins */
	PORTC_REG.Data = 0; /* All LEDS OFF */
	while(1)
	{
		/* Read PA2 Pin Value */
		if(PINA_REG.BITS.BIT2 == 1)
		{
			PORTC_REG.Data ^= 0xFF; /* Toggle All LEDs*/
			_delay_ms(500);
		}
		/* Read PA3 Pin Value */
		else if(PINA_REG.BITS.BIT3 == 1)
		{
			PORTC_REG.Data = 0xFF; /* All LEDS ON */
		}
		else
		{
			PORTC_REG.Data = 0; /* All LEDS OFF */
		}

	}
}