

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BITMATH.h"
#include <util/delay.h>
#include "../../MCAL/DIO/DIO.h"
#include "7_seg_int.h"

/* Following This Table For Common Cathode */
/***********************************************/
/* Decimal | Dot | g | f | e | d | c | b | a | */
/*    0    |  0  | 0 | 1 | 1 | 1 | 1 | 1 | 1 | */
/*    1    |  0  | 0 | 0 | 0 | 0 | 1 | 1 | 0 | */
/*    2    |  0  | 1 | 0 | 1 | 1 | 0 | 1 | 1 | */
/*    3    |  0  | 1 | 0 | 0 | 1 | 1 | 1 | 1 | */
/*    4    |  0  | 1 | 1 | 0 | 0 | 1 | 1 | 0 | */
/*    5    |  0  | 1 | 1 | 0 | 1 | 1 | 0 | 1 | */
/*    6    |  0  | 1 | 1 | 1 | 1 | 1 | 0 | 1 | */
/*    7    |  0  | 0 | 0 | 0 | 0 | 1 | 1 | 1 | */
/*    8    |  0  | 1 | 1 | 1 | 1 | 1 | 1 | 1 | */
/*    9    |  0  | 1 | 1 | 0 | 1 | 1 | 1 | 1 | */
/***********************************************/

static const u8 G_u8Ssd_NUMs[10]= {
		0b00111111 , //Zero
		0b00000110 , //one
		0b01011011 , //Two
		0b01001111 , //Three
		0b01100110 , //4
		0b01101101 , //5
		0b01111101 , //6
		0b00000111 , //7
		0b01111111 , //8
		0b01101111   //9
};


void HSSD_voidInit(u8 A_PortNum){

	MDIO_voidSetPortDirection(A_PortNum,0xff);

}

void HSSD_VoidDisplayNumber(u8 A_u8SSD_PORT ,u8 A_u8Num){
		if(A_u8Num <=9){
#if SSD_Type==1
	MDIO_voidSetPortValue(A_u8SSD_PORT,G_u8Ssd_NUMs[A_u8Num]);
#elif SSD_Type==2
	MDIO_voidSetPortValue(A_u8SSD_PORT, ~G_u8Ssd_NUMs[A_u8Num]);
#endif
	//HSSD_VoidDisplayNumber(0);
	}
}

void HSSD_voidTurnOff(u8 A_u8SSD_PORT){

#if SSD_Type==1
	MDIO_voidSetPortValue(A_u8SSD_PORT, 0x00);
#elif SSD_Type==2
	MDIO_voidSetPortValue(A_u8SSD_PORT, 0xff);
#endif

}


void HSSD_voidCountUp(u8 A_u8SSD_PORT ,u8 A_u8Num){

	for(u8 counter=A_u8Num ; counter<=9; counter++){
		HSSD_VoidDisplayNumber(A_u8SSD_PORT,counter);
		_delay_ms(1000);
	}

}

void HSSD_voidCountdown(u8 A_u8SSD_PORT,u8 A_u8Num){

	for(u8 counter=A_u8Num ; counter>=0 ; counter--){
		HSSD_VoidDisplayNumber(A_u8SSD_PORT,counter);
		_delay_ms(1000);
	}

}
