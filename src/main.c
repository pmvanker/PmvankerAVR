/*
 * main.c
 *
 *  Created on: 21-Dec-2017
 *      Author: ccare
 */
#include<util/delay.h>
#include<avr/io.h>

#define lowdata PORTC
#define highdata PORTD
#define seldata PORTA

void print(int[5][2]);

int ccare[6][2]={
					{0x5b,0x9b},	//c
					{0x5b,0x9b},	//c
					{0x58,0x3e},	//a
					{0x58,0x3d}, 	//r
					{0x5a,0x1b},    //e
					{0xff,0xff}
				};
int main()
{
	DDRB = DDRC = DDRA = 0xFF;
	while(1)
	{
		print(ccare);
	}
}

void print(int p[6][2])
{
	int i,j;
	for(seldata |=(1<<5),j=0;j<=6;j++)
	{

		for(i=0;i<=1;i++)
		{
			if(i==0)
				highdata = p[j][i];
			lowdata = p[j][i];
		}
		_delay_ms(1);
		seldata>>=1;

	}
}
//int[5][2] rotate(int q[5][2])
//{
//	int i,j,temp[5][2];
//	for(i=0;i<=6;i++)
//	{
//		for(j=0;j<2;j++)
//		{
//			temp[i][j]=[q][j];
//			q[i][j]=q[i][j+1];
//		}
//	}
//}


