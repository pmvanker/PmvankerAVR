/*
 * matrix.c
 *
 *  Created on: 02-Jan-2018
 *      Author: ccare
 */
# define F_CPU 1000000UL
#include<avr/io.h>
#include<util/delay.h>
#include"DATABASE.h"
#include"compare.h"

#define clk 0
#define data 1
#define lch 2

int p,fd[8];
int dataarray[8][8];
char d[9];

void datash(void);
void clock1(void);
void datalatch(void);
void default_msg(void);
void data_insert(void);
void dot_display(void);
char praful[]="PRAFUL";
int main()
{
	DDRB = DDRC = 0xFF;

	int i;
	for(i=0;praful[i];i++)
	{
		compare_C(praful[i]);
		fd[i]=dch;
	}
	data_insert();
	while(1)
	{
		dot_display();
	}
}

void datash()
{
	int i;
	clock1();
	for(i=0;i<7;i++)
	{
		if(((p>>i)&1)==1)
			PORTC|=(1<<data);
		else
			PORTC&=~(1<<data);
		clock1();
	}
}
void dot_display()
{
	int i,j;
		for (i=0;i<7;i++)
		for(j=0;j<7;j++)
		{
			p=~dataarray[i][j];
			datash();
			PORTB=1<<j;
			datalatch();
			_delay_ms(1);
		}
}
void default_msg()
{
	compare_C(' ');
	fd[0]=dch;
	compare_C(' ');
	fd[1]=dch;
	compare_C('L');
	fd[2]=dch;
	compare_C('U');
	fd[3]=dch;
	compare_C('F');
	fd[4]=dch;
	compare_C('A');
	fd[5]=dch;
	compare_C('R');
	fd[6]=dch;
	compare_C('P');
	fd[7]=dch;
	data_insert();
}

void clock1(void)
{
	PORTC |=(1<<clk);
	PORTC &=~(1<<clk);
}
void datalatch(void)
{
	PORTC &=~(1<<lch);
	PORTC |=(1<<lch);
}
void data_insert()
{
	int i,j;
	for (i=0;i<8;i++)
	for(j=0;j<8;j++)
		dataarray[i][j]=arr[fd[i]][j];
}



