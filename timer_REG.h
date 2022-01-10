/*
 * timer_REG.h
 *
 *  Created on: Oct 8, 2021
 *      Author: Meme
 */

#ifndef TIMER_REG_H_
#define TIMER_REG_H_

#define TIMSK  *((volatile u8*)0x59)
#define TCCR0  *((volatile u8*)0x53)
#define TCNT0  *((volatile u8*)0x52)
#define SREG  *((volatile u8*)0x5F)
#define OCR0  *((volatile u8*)0x5C)

#endif /* TIMER_REG_H_ */
