/*
 * matrix.c
 *
 *  Created on: 02-Jan-2018
 *      Author: ccare
 */
#include<avr/io.h>
#include<util/delay.h>
#include"../AVRmatrix/DATABASE.h"
#include"../AVRmatrix/compare.h"

#define clk 0
#define data 1
#define lch 2

int p,fd[8];
int dataarray[8][8];
char d[9];

void datash(void);
void clock1(void);
void datalatch(void);
void data_compare(void);
void data_compare1(void);
void default_msg(void);
void data_insert(void);
void dot_display(void);

int main()
{
	DDRB = DDRC = 0xFF;

	default_msg();
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
	int n;
		for(n=0;n<7;n++)
		{
			p=~dataarray[0][n];
			datash();
			p=~dataarray[1][n];
			datash();
			p=~dataarray[2][n];
			datash();
			p=~dataarray[3][n];
			datash();
			p=~dataarray[4][n];
			datash();
			p=~dataarray[5][n];
			datash();
			p=~dataarray[6][n];
			datash();
			p=~dataarray[7][n];
			datash();

			PORTB=1<<n;
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
void data_compare()
{
	compare_C(d[1]);
	fd[0]=dch;
	compare_C(d[2]);
	fd[1]=dch;
	compare_C(d[3]);
	fd[2]=dch;
	compare_C(d[4]);
	fd[3]=dch;
	compare_C(d[5]);
	fd[4]=dch;
	compare_C(d[6]);
	fd[5]=dch;
	compare_C(d[7]);
	fd[6]=dch;
	compare_C(d[8]);
	fd[7]=dch;
	data_insert();
}
void data_compare1()
{
	compare_C(d[0]);
	fd[0]=dch;
	compare_C(d[1]);
	fd[1]=dch;
	compare_C(d[2]);
	fd[2]=dch;
	compare_C(d[3]);
	fd[3]=dch;
	compare_C(d[4]);
	fd[4]=dch;
	compare_C(d[5]);
	fd[5]=dch;
	compare_C(d[6]);
	fd[6]=dch;
	compare_C(d[7]);
	fd[7]=dch;
	data_insert();
}
void data_insert()
{
	int j;
	for(j=0;j<8;j++)
	{dataarray[0][j]=arr[fd[0]][j];}
	for(j=0;j<8;j++)
	{dataarray[1][j]=arr[fd[1]][j];}
	for(j=0;j<8;j++)
	{dataarray[2][j]=arr[fd[2]][j];}
	for(j=0;j<8;j++)
	{dataarray[3][j]=arr[fd[3]][j];}
	for(j=0;j<8;j++)
	{dataarray[4][j]=arr[fd[4]][j];}
	for(j=0;j<8;j++)
	{dataarray[5][j]=arr[fd[5]][j];}
	for(j=0;j<8;j++)
	{dataarray[6][j]=arr[fd[6]][j];}
	for(j=0;j<8;j++)
	{dataarray[7][j]=arr[fd[7]][j];}
}



