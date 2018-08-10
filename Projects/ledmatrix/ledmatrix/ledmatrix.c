/*
 * ledmatrix.c
 *
 * Created: 07-01-2018 13:53:38
 *  Author: ccare
 */ 


#include <avr/io.h>

int main(void)
{
    while(1)
    {
        DDRB = 0xff;
    }
}