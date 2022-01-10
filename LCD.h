/*
 * LCD.h
 *
 *  Created on: Sep 25, 2021
 *      Author: Meme
 */

#ifndef LCD_H_
#define LCD_H_

void LCD_init(void);
void LCD_write_command (u8 command);
void LCD_write_data (u8 data);
void LCD_writeword(u8 arr[],u8 x);

#endif /* LCD_H_ */
