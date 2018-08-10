/*
 * main.c
 *
 *  Created on: 21-Dec-2017
 *      Author: ccare
 */
#include<util/delay.h>
#include<avr/io.h>
#include"lcd_4bit.h"

#define led 0					//PORTB.0

int main()
{
	lcd_init();
	while(1)
	{
	lcd_cmd(0x80);
	lcd_string("praful");
	_delay_ms(200);
	}
}




