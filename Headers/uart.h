/*
 * uart.h
 *
 *  Created on: 23-Dec-2017
 *      Author: ccare
 */

#ifndef UART_H_
#define UART_H_

void uart_init(void)
{
	UCSRB = (1 << TXEN)|(1<<RXEN);
	UCSRC = (1<< UCSZ1)|(1<<UCSZ0)|(1<<URSEL);
	UBRRL = 0x33;
}
void uart_send(unsigned char data)
{
	while(!(UCSRA & (1<<UDRE)));
	UDR = data;
}
unsigned char uart_receave(void)
{
	while(!(UCSRA & (1<<RXC)));
	return UDR;
}
unsigned char*(int n)
{
	while(n--)
		uart_re
}
void uart_send_pktBCD(unsigned char data)
{
	uart_send('0'+ (data>>4));
	uart_send('0'+(data&0x0f));
}





#endif /* UART_H_ */
