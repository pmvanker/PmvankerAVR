/*
 * main.c
 *
 *  Created on: 21-Dec-2017
 *      Author: ccare
 */
#include<util/delay.h>
#include<avr/io.h>

#define lowdata PORTC
#define highdata PORTA
#define seldata PORTD
#define SPEED 200

void print1(int);
int compare(char);
void print(char *);
//void test();
//void rotate(char *);

char mydata[20]="C_CARE";

int main()
{
	DDRC = DDRA = DDRD = 0xFF;
	while(1)
	{

//-------------------------------------------------------------------------------
		int i;
//		for(i=0;i<SPEED;i++)
//			print("praful");
//		for(i=0;i<SPEED;i++)
//			print("UTPAL ");
//		for(i=0;i<SPEED;i++)
//			print("MEHUL ");

//		for(i=0;i<SPEED;i++)
//		print("C_CARE");

		for(i=0;i<SPEED;i++)
		print(mydata);

		seldata=0x00;
		_delay_ms(1000);



//		seldata=1<<2;
//		for(i=0;i<100;i++)
//		print1(~compare('E'));
//
//		seldata<<=1;
//		for(i=0;i<100;i++)
//		print1(~compare('R'));
//
//		seldata<<=1;
//		for(i=0;i<100;i++)
//		print1(~compare('A'));
//
//		seldata<<=1;
//		for(i=0;i<100;i++)
//		print1(~compare('C'));
//
//		seldata<<=1;
//		for(i=0;i<100;i++)
//		print1(~compare('C'));



		//test();
//--------------------------------------------------------------------------------
//		char ch;
//		seldata=0x01;
//		for(ch='A';ch<='Z';ch++)
//		{
//			print1(compare(ch));
//			_delay_ms(2000);
//		}
//----------------------------------------------------------------------------------
	}

}
//void rotate(char *q)
//{
//	char temp[6];
//	int i;
//	for(i=0;i<6;i++)
//	{
//		temp[i]=q[i];
//		q[i]=q[i+1];
//	}
//	q[i]=temp[0];
//	for(i=0;i<SPEED;i++)
//	print(temp);
//}
//void test()
//{
//	int i,j;
//	seldata=1<<2;
//	for(j=0;j<6;j++)
//	{
//		for(lowdata=0xFE,i=0;i<8;i++)
//		{
//			lowdata=lowdata<<1;
//			_delay_ms(500);
//		}
//		for(highdata=0xFE,i=0;i<8;i++)
//		{
//			highdata=highdata<<1;
//			_delay_ms(500);
//		}
//	seldata=seldata<<1;
//	}
//}
void print(char *p)
{
		int j;
		for(seldata|=(1<<7),j=0;j<=5;j++)
		{
			if((p[j]>>5)&1)							//converting to UPERCASE
				p[j]&=~(1<<5);
			print1(~compare(p[j]));					//comparing char and printing
			_delay_ms(4);
			seldata>>=1;
		}
}
int compare(char ch)
{
	switch(ch)
	{
		case 'A':return 0x583E;break;
		case 'B':return 0X7E1A;break;
		case 'C':return 0x5B9B;break;
		case 'D':return 0xC9D2;break;
		case 'E':return 0x5A1B;break;
		case 'F':return 0x5A3F;break;
		case 'G':return 0x5A9A;break;
		case 'H':return 0x7C3E;break;
		case 'I':return 0xCBD3;break;
		case 'J':return 0xCB97;break;
		case 'K':return 0x773D;break;
		case 'L':return 0x7F9B;break;
		case 'M':return 0x35BE;break;
		case 'N':return 0x3DBC;break;
		case 'O':return 0x599A;break;
		case 'P':return 0x583F;break;
		case 'Q':return 0x587D;break;
		case 'R':return 0x583D;break;
		case 'S':return 0x5A5A;break;
		case 'T':return 0xCBF7;break;
		case 'U':return 0x7D9A;break;
		case 'V':return 0xBDFC;break;
		case 'W':return 0x7DAC;break;
		case 'X':return 0xB7ED;break;
		case 'Y':return 0x7C77;break;
		case 'Z':return 0xD3CB;break;
		//case ' ':return 0xffff;break;
		case '_':return 0xFFDF;break;
		default:
			return 0xFFFF;
	}
	return 0;
}

void print1(int x)
{
	int h,l;
	h=x&0xFF00;
	h>>=8;
	l=x&0x00ff;

	lowdata=l;
	highdata=h;
}

