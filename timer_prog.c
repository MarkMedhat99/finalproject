/*
 * timer_prog.c
 *
 *  Created on: Oct 8, 2021
 *      Author: Meme
 */

#include "STD_type.h"
#include "utilites.h"
#include "DIO_REG.h"
#include "Dio_Int.h"
#include "timer_REG.h"
#include "timer_int.h"
#include "avr/interrupt.h"
void timer_init (void)
{

	TCCR0 =0b01110101;
		TIMSK=0b00000000;
		OCR0=255;
   Dio_SetPinDirection(GroupC,2,OUTPUT);

}

u16 counter=0;
ISR (TIMER0_OVF_vect)
{


		TCNT0=254;

		tog_bit(PORTC,2);





}
