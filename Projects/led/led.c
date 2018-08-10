/*
 * main.c
 *
 *  Created on: 21-Dec-2017
 *      Author: ccare
 */
#include<util/delay.h>
#include<avr/io.h>

#define led 0					//PORTB.0

int main()
{
	DDRB |= 1<<led;				// pin PORTB.0 output
	while(1)
	{
		PORTB &= ~(1<<led);		// clear
		_delay_ms(200);
		PORTB |= (1<<led);		//	set
		_delay_ms(200);
	}
}



