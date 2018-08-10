/*
 * lcd_4bit.h
 *
 *  Created on: 21-Dec-2017
 *      Author: ccare
 */

#ifndef LCD_4BIT_H_
#define LCD_4BIT_H_

#define RS 0	//PORTb.0
#define RW 1	//PORTb.1
#define EN 2	//PORTb.2

#define lcd PORTB

void lcd_cmd(unsigned char cmd)
{
	lcd = (lcd & 0x0F) | (cmd & 0xF0 );			//send only 4bit data without distributing rest pin data
	lcd &= ~(1<<RS);							//rs = 0 cmd
	lcd &= ~(1<<RW);							//rw = 0 rw
	lcd |= (1<<EN);								//EN = 1 enable
	_delay_ms(2);								//delay
	lcd &= ~(1<<EN);							//EN = 0

	lcd = (lcd & 0x0F) | (cmd << 4 );			//send only 4bit data without distributing rest pin data
	lcd |= (1<<EN);								//EN = 1 enable
	_delay_ms(2);								//delay
	lcd &= ~(1<<EN);							//EN = 0
}

void lcd_data(unsigned char cmd)
{
	lcd = (lcd & 0x0F) | (cmd & 0xF0 );			//send only 4bit data without distributing rest pin data
	lcd |= (1<<RS);								//rs = 1 cmd
	lcd &= ~(1<<RW);							//rw = 0 rw
	lcd |= (1<<EN);								//EN = 1 enable
	_delay_ms(2);								//delay
	lcd &= ~(1<<EN);							//EN = 0

	lcd = (lcd & 0x0F) | (cmd << 4);			//send only 4bit data without distributing rest pin data
	lcd |= (1<<EN);								//EN = 1 enable
	_delay_ms(2);								//delay
	lcd &= ~(1<<EN);							//EN = 0
}

void lcd_init()
{
	DDRB = 0xff;				// port b as output
	lcd_cmd(0x28);				// 4 bit mode 16x2 lcd
	lcd_cmd(0x0c);
	lcd_cmd(0x06);
	lcd_cmd(0x01);
}

void lcd_string(char *d)
{
	while(*d)
	{
		lcd_data(*d++);
		_delay_ms(10);
	}
}

void lcd_2digit(unsigned int n)
{
	lcd_data(n/10 + 48);
	lcd_data(n%10 + 48);
}

void lcd_integer(int n)
{
	int a[20],i=0,c=0;
	if(n<0)
	{
		lcd_data('-');
		n=-n;
	}
	while(n)
	{
		a[i++]=n%10;
		n=n/10;
		c++;
	}
	for(i=c-1;i>=0;i--)
	{
		lcd_data(a[i]+48);
	}
}

#endif /* LCD_4BIT_H_ */
