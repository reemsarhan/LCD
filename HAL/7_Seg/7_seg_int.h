

#ifndef HAL_7_SEG_7_SEG_INT_H_
#define HAL_7_SEG_7_SEG_INT_H_




#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BITMATH.h"

#define Cathode 1
#define Anode   2

#define SSD_Type	Cathode

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

#define Zero  0
#define one   1
#define Two   2
#define Three 3
#define Four  4
#define Five  5
#define Six   6
#define Seven 7
#define eight 8
#define Nine  9

void HSS_voidInit(u8 A_u8Port) ;
void HSS_viodDisplayValue(u8 A_u8Port , u8 A_u8Value) ;
void HSS_voidCountUp(u8 A_u8Port , u8 A_u8Value) ;
void HSS_voidCountDown(u8 A_u8Port , u8 A_u8Value) ;
void HSS_voidTurnOff(u8 A_u8Port) ;



#endif /* HAL_7_SEG_7_SEG_INT_H_ */
