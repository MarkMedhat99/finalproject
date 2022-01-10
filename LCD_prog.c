/*
 * LCD_prog.c
 *
 *  Created on: Sep 25, 2021
 *      Author: Meme
 */
#include "STD_type.h"
#include "utilites.h"
#include "DIO_REG.h"
#include "Dio_Int.h"
#include "avr/delay.h"
void LCD_init(void)
{
	Dio_SetPinDirection(GroupB,PIN1,OUTPUT);
	Dio_SetPinDirection(GroupB,PIN2,OUTPUT);
	Dio_SetPinDirection(GroupB,PIN3,OUTPUT);
	Dio_SetPinDirection(GroupA,PIN4,OUTPUT);
	Dio_SetPinDirection(GroupA,PIN5,OUTPUT);
	Dio_SetPinDirection(GroupA,PIN6,OUTPUT);
	Dio_SetPinDirection(GroupA,PIN7,OUTPUT);

	_delay_ms(40);
	LCD_write_command(0x02);
	LCD_write_command(0x2C);
	_delay_ms(50);
	LCD_write_command(0x0F);
	_delay_ms(50);
	LCD_write_command(0x01);
	_delay_ms(2);
	LCD_write_command(0x06);
}
void LCD_write_command (u8 command)
{
	Dio_SetPinValue(GroupB,PIN1,LOW);
	Dio_SetPinValue(GroupB,PIN2,LOW);

	PORTA=(PORTA & 0X0F) | (command & 0xF0);
	Dio_SetPinValue(GroupB,PIN3,HIGH);
	_delay_ms(2);
	Dio_SetPinValue(GroupB,PIN3,LOW);
	PORTA=(PORTA & 0X0F) | (command << 4); // 3shan may3'yrsh awl 4 pins
	Dio_SetPinValue(GroupB,PIN3,HIGH);
	_delay_ms(2);
	Dio_SetPinValue(GroupB,PIN3,LOW);

}
void LCD_write_data (u8 data)
{
	Dio_SetPinValue(GroupB,PIN1,HIGH);
	Dio_SetPinValue(GroupB,PIN2,LOW);

	PORTA=(PORTA & 0X0F) | (data & 0xF0);
	Dio_SetPinValue(GroupB,PIN3,HIGH);
	_delay_ms(2);
	Dio_SetPinValue(GroupB,PIN3,LOW);
	PORTA=(PORTA & 0X0F) | (data << 4); //
	Dio_SetPinValue(GroupB,PIN3,HIGH);
	_delay_ms(2);
	Dio_SetPinValue(GroupB,PIN3,LOW);

}

void LCD_writeword(u8 arr[],u8 x)
{
	for(u8 i=0;i<x;i++)
	{
		 LCD_write_data(arr[i]);
	}
}
