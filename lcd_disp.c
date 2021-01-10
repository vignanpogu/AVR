// ***********************************************************
// Project:
// Author:
// Module description:
// ***********************************************************

#include <avr\io.h>              // Most basic include files
#include <avr\interrupt.h>       // Add the necessary ones
#include <avr\signal.h>          // here
#include <util\delay.h>
// define variables with constants
#define data_PORT PORTB
#define data_DDR DDRB

#define comand_PORT PORTD
#define comand_DDR DDRD

#define RS PD6
#define EN PD7

#define LCD_clear 0x01
#define LCD_8bit 0x38
#define LCD_cursorOn 0x0f
#define LCD_seek00 0x80
// ***********************************************************
// Main program
//
void LCD_comand(char);
void LCDdisplay(char);
void LCD_init();
int main(void) {
						data_DDR=0xFF;
						comand_DDR=0xE0;
                LCD_init();
                LCDdisplay('R');
                LCD_comand(0x06);
                LCDdisplay('A');
                LCD_comand(0x06);
                LCDdisplay('J');
                LCD_comand(0x06);
                LCDdisplay('E');
                LCD_comand(0x06);
                LCDdisplay('E');
                LCD_comand(0x06);
                LCDdisplay('V');
                LCD_comand(0x06);
                LCDdisplay(' ');
                LCD_comand(0x06);
                LCDdisplay('K');
                LCD_comand(0x06);
                LCDdisplay('U');
                LCD_comand(0x06);
                LCDdisplay('M');
                LCD_comand(0x06);
                LCDdisplay('A');
                LCD_comand(0x06);
                LCDdisplay('R');


}

void LCD_init(void)
{
	LCD_comand(LCD_8bit);
	LCD_comand(LCD_cursorOn);
	LCD_comand(LCD_clear);
	LCD_comand(LCD_seek00);
}

void LCD_comand(char ch)
{
 	data_PORT=ch;
 	comand_PORT=(0<<RS)|(1<<EN);  //signaling to send commands
 	_delay_ms(10);
 	comand_PORT=(0<<RS)|(0<<EN);
 	_delay_ms(45);
 	if(ch==0x01 || ch==0x02)
 		_delay_ms(2);
}

void LCDdisplay(char ch)
{
  data_PORT=ch;
  comand_PORT=(1<<RS)|(1<<EN); //signaling to display
  _delay_us(10);
  comand_PORT=(1<<RS)|(0<<EN);
  _delay_us(1);
}

