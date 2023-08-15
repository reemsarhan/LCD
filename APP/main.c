#include "../MCAL/DIO/DIO.h"
#include "../HAL/LCD/LCD_int.h"


void main()
{
	MDIO_voidSetPortDirection(PORTA,0xff);
	MDIO_voidSetPortDirection(PORTB,0xff);

	HLCD_voidInit();

	HLCD_voidSendString("MY FIRST LCD ^_^");
	HLCD_voidCursor(LCD_LINE_2,1);
	/*HLCD_voidSendData('I');
	HLCD_voidSendData('T');
	HLCD_voidSendData('I');*/

	while(1)
	{

	}
}
