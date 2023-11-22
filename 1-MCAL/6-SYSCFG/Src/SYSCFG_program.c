/*************************************************************/
/*************************************************************/
/**                                                         **/
/** LayerArchitect: MCAL                                    **/
/** File Name : SYSCFG_program.c                            **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/

#include <stdint.h>
#include "ErrType.h"
#include "BIT_MATH.h"
#include "Stm32F446xx.h"
#include "SYSCFG_private.h"
#include "SYSCFG_interface.h"

/**
 * @brief: This function to Set EXTI port
 * @param[in] Copy_EnumEXTI_Line : this enum to carry options of EXTI lines options from line 0 to line 22 totally 23 EXTI_lines
 * @param[in] Copy_EnumEXTI_PORT : this enum to carry options FROM PORTA TO PORTH
 * @return Local_u8ErrorState : this variable to carry ErrorState value
 */
uint8_t SYSCFG_u8SetEXTIPort(EXTI_Lines_t Copy_EnumEXTI_Line , EXTI_PORT_t Copy_EnumEXTI_PORT )
{
	/* define a variable to carry error state */
	uint8_t Local_u8ErrorState=OK;

	/* define a variable to carry register number */
	uint8_t Local_u8RegNumber = INIT_VALUE_BY_ZERO;

	/* define a variable to carry bit number */
	uint8_t Local_u8BitNumber = INIT_VALUE_BY_ZERO;

	/* Calculate the Register number */
	Local_u8RegNumber = Copy_EnumEXTI_Line / MASKED_FOUR_BITS ;

	/* Calculate the Bit number */
	Local_u8BitNumber = (Copy_EnumEXTI_Line % MASKED_FOUR_BITS) * MASKED_FOUR_BITS ;

	if((Copy_EnumEXTI_Line >= EXTI_Line0 ) && (Copy_EnumEXTI_Line <= EXTI_Line22))
	{
		/* clear bits before use it */
		SYSCFG->SYSCFG_EXTICR1[Local_u8RegNumber] &=(~((0xf) <<Local_u8BitNumber));

		if((Copy_EnumEXTI_PORT>= EXTI_PORTA) && (Copy_EnumEXTI_PORT <= EXTI_PORTH))
		{
			/* SET the value of the port inside our register */
			SYSCFG->SYSCFG_EXTICR1[Local_u8RegNumber] |=(Copy_EnumEXTI_PORT<<Local_u8BitNumber);
		}else
		{
			/* update Error state value  */
			Local_u8ErrorState=NOK;
		}

	}else
	{
		/* update Error state value  */
		Local_u8ErrorState=NOK;
	}

	/* return Error state value  and end the function */
	return Local_u8ErrorState;

}
