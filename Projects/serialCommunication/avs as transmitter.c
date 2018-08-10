/*
 * main.c
 *
 *  Created on: 21-Dec-2017
 *      Author: ccare
 */
#include<util/delay.h>
#include<avr/io.h>
#include"../Headers/uart.h"

int main()
{
	uart_init();
	while(1)
	{
		uart_send('P');
		_delay_ms(500);
	}
}
