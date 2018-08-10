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
	unsigned char ss,mm,hh;
	ss=mm=hh=0;
	lcd_init();
	lcd_cmd(0x80);
	lcd_string("00:00:00"); //80h  83m  86s
	while(1)
	{
		ss++;
		lcd_cmd(0x86);
		lcd_2digit(ss);
		_delay_ms(1000);
		if(ss==59)
		{
			mm++;
			lcd_cmd(0x83);
			lcd_2digit(mm);
			ss=0;

			if(mm==59)
			{
				hh++;
				lcd_cmd(0x80);
				lcd_2digit(hh);
				mm=0;

				if(hh==24)
					hh=0;
			}
		}
	}
}




