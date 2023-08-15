
#define F_CPU   8000000UL

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BITMATH.h"
#include "../../MCAL/DIO/DIO.h"
#include <util/delay.h>
#include "LCD_int.h"

void HLCD_voidSendCommand(u8 A_u8cmd)
{
	//control RS and RW pins
	MDIO_voidSetPinValue(Control_Port,PIN0,LOW);
	MDIO_voidSetPinValue(Control_Port,PIN1,LOW);

	//write command on data pins
	MDIO_voidSetPortValue(Data_Port,A_u8cmd);

	//pulse on enable pin
	MDIO_voidSetPinValue(Control_Port ,PIN2,HIGH);
	_delay_ms(1);

	MDIO_voidSetPinValue(Control_Port,PIN2,LOW);
	_delay_ms(1);

}

void HLCD_voidSendData(u8 A_u8Data)
{

		//control RS and RW pins
		MDIO_voidSetPinValue(Control_Port,PIN0,HIGH);
		MDIO_voidSetPinValue(Control_Port,PIN1,LOW);

		//write command on data pins
		MDIO_voidSetPortValue(Data_Port,A_u8Data);

		//pulse on enable pin
		MDIO_voidSetPinValue(Control_Port ,PIN2,HIGH);
		_delay_ms(1);

		MDIO_voidSetPinValue(Control_Port,PIN2,LOW);
		_delay_ms(1);
}

void HLCD_voidInit()
{

	_delay_ms(30);
	HLCD_voidSendCommand(LCD_functionset);
	_delay_ms(1);

	//display on/off 0b00001100

	HLCD_voidSendCommand(LCD_DisplayONOFF);
	_delay_ms(1);

	//display clear  0b00000001
	HLCD_voidSendCommand(LCD_Clear);
	_delay_ms(1);


	_delay_ms(2);
	//entry mode     0b00000110
	HLCD_voidSendCommand(LCD_EntryMode);


}



void HLCD_voidClear()
{

	//display clear  0b00000001
	HLCD_voidSendCommand(LCD_Clear);
	_delay_ms(2);
}

void HLCD_voidSendString(u8 *A_u8PtrString)
{
	while(*A_u8PtrString >0)
	{
		HLCD_voidSendData(*A_u8PtrString ++);
	}

}


void HLCD_voidDisplay()
{


}

void HLCD_voidCursor(u8 A_u8RowNum , u8 A_u8ColNum)
{

	switch(A_u8RowNum)
	{

	case LCD_LINE_1 : HLCD_voidSendCommand(LCD_ROW_1+A_u8RowNum);break;
	case LCD_LINE_2 : HLCD_voidSendCommand(LCD_ROW_2+A_u8RowNum);break;
	}
}

