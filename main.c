/*
 * main.c
 *
 *  Created on: Oct 8, 2021
 *      Author: Meme
 */

#include "STD_type.h"
#include "utilites.h"
#include "DIO_REG.h"
#include "Dio_Int.h"
#include "avr/interrupt.h"
#include "avr/delay.h"
#include "timer_REG.h"
#include "timer_int.h"



static volatile int pulse = 0;
static volatile int i = 0;

void main()
{ int count ;

//timer on pinD4,5
Dio_SetPinDirection(GroupD,PIN5,OUTPUT);
Dio_SetPinDirection(GroupD,PIN4,OUTPUT);
Dio_SetPinDirection(GroupA,PIN1,OUTPUT);
Dio_SetPinValue(GroupA,PIN1,HIGH);  //5V
Dio_SetPinDirection(GroupA,PIN3,OUTPUT);
Dio_SetPinValue(GroupA,PIN3,LOW);  //Ground
Dio_SetPinDirection(GroupA,PIN5,OUTPUT); //test
Dio_SetPinValue(GroupA,PIN5,LOW); //test initialize
Dio_SetPinDirection(GroupD,PIN0,OUTPUT);
Dio_SetPinDirection(GroupD,PIN2,INPUT);
//Trigger
 //Echo INT0
sei();
GICR = 0b01000000;
 MCUCR = 0b00000011;
 SREG = 0b10000000;
TCCR1A=0b10101101;
TCCR1B=0b00001011;

TIMSK=0b00000000;

OCR1A=178;
OCR1B=178;

 Dio_SetPinDirection(GroupA,PIN1,OUTPUT);
 Dio_SetPinValue(GroupA,PIN1,HIGH);

	while(1){
Dio_SetPinValue(GroupD,PIN0,HIGH);
 _delay_us(15);
Dio_SetPinValue(GroupD,PIN0,LOW);  //trigger the sensor
 count = pulse/58;


if (count == 5)

       {

	OCR1A=178;
		OCR1B=0;
             }

if (count <1)
{OCR1A=0;
 OCR1B=0;
	}
       }
	}
ISR(INT0_vect)
{
 if(i == 0)
 {
   TCCR0 = 0b00000001;
   i = 1;
 }
 else
 {
   TCCR0 = 0b00000000;
   pulse = TCNT0;
   TCNT0 = 0;
   i = 0;
 }}

