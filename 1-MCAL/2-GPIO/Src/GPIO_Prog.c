/*************************************************************/
/*************************************************************/
/**                                                         **/
/** @file GPIO_Prog.c                                       **/
/** @author MOHAMED BEDIER MOHAMED                          **/
/** @brief  the GPIO main source file,						**/
/**           Including function' definitions               **/
/** @version 1.00                                           **/
/**                                                         **/
/*************************************************************/
/*************************************************************/

#include <stdint.h>
#include "ErrType.h"
#include "BIT_MATH.h"
#include "Stm32F446xx.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"

/* according to least privilege make it static to save it private for this file only */
static GPIO_RegDef_t* GPIOPORT[GPIO_PERIPHERAL_NUM] = {GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOF,GPIOG,GPIOH};


/**
 * @fn GPIO_u8PinInit
 * @brief the function initializes the GPIO pin according to the input parameter
 * @param[in] PinConfig : the initialization value of the pin
 * @retval Local_u8ErrorState
 */

uint8_t  GPIO_u8PinInit(const PinConfig_t* PinConfig)
{
	/* define error state variable */
	uint8_t Local_u8ErrorState=OK;

	/* check on pointer not equal NULL */
	if(PinConfig != NULL)
	{
		if((PinConfig->Port <= PORTH) && (PinConfig->PinNum <= PIN15) )
		{
			/* Select GPIO mode : Input , Output , Analog , Alternate function  */
			(GPIOPORT[PinConfig->Port]->MODER) &= (~(MODER_MASK << ((PinConfig->PinNum) * MODER_PIN_ACCESS))); /* clear the mode bits */
			(GPIOPORT[PinConfig->Port]->MODER) |= ((PinConfig->Mode) << ((PinConfig->PinNum) * MODER_PIN_ACCESS));/* put mode in our register */

			/* Select GPIO Pull state : (Pull up , pull down ,No pull ) and there are in these mode only (input , output , Alternate function) */
			/* if we make it with analog don't worry HW ignored it */
			(GPIOPORT[PinConfig->Port]->PUPDR) &= (~(PUPDR_MASK << ((PinConfig->PinNum) * PUPDR_PIN_ACCESS))); /* clear the PUPDR bits */
			(GPIOPORT[PinConfig->Port]->PUPDR) |= ((PinConfig->PullType) << ((PinConfig->PinNum) * PUPDR_PIN_ACCESS));/* put PUPDR in our register */

			/* Select output type & output speed in case of general purpose output or alternate function */
			if((PinConfig->Mode == OUTPUT) || (PinConfig->Mode == ALTERNATE_FUNCTION))
			{
				/* Select output type : Push_pull or open drain  */
				(GPIOPORT[PinConfig->Port]->OTYPER) &= (~(OTYPER_MASK << (PinConfig->PinNum))); /* clear the OTYPER bits */
				(GPIOPORT[PinConfig->Port]->OTYPER) |= ((PinConfig->OutputType) << (PinConfig->PinNum));/* put OTYPER in our register */

				/* Select output speed : Low , Medium , High , Fast*/
				(GPIOPORT[PinConfig->Port]->OSPEEDR) &= (~(OSPEEDR_MASK << ((PinConfig->PinNum) * OSPEEDR_PIN_ACCESS))); /* clear the OSPEEDR bits */
				(GPIOPORT[PinConfig->Port]->OSPEEDR) |= ((PinConfig->Speed) << ((PinConfig->PinNum) * OSPEEDR_PIN_ACCESS));/* put OSPEEDR in our register */

				/* select the pin alternate function */
				if(PinConfig->Mode == ALTERNATE_FUNCTION)
				{
					uint8_t Local_u8RegNum =f(PinConfig->PinNum) / AFR_PIN_SHIFTING;
					uint8_t Local_u8BitNum =f(PinConfig->PinNum) % AFR_PIN_SHIFTING;

					(GPIOPORT[PinConfig->Port]->AFR[Local_u8RegNum] &= ~(AFR_MASK << (Local_u8BitNum  * AFR_PIN_ACCESS))); /* clear the AFR bits */
					(GPIOPORT[PinConfig->Port]->AFR[Local_u8RegNum] |= ((PinConfig->AltFunc) << (Local_u8BitNum * AFR_PIN_ACCESS)));/* put AFR in our register */

				}

			}else
			{
				/* update error state */
				Local_u8ErrorState=NOK;
			}

		}else
		{
			/* update error state */
			Local_u8ErrorState=NOK;
		}

	}else
	{
		/* pointer equal NULL update error state */
		Local_u8ErrorState=NULL_PTR_ERR;
	}

	/* return error state variable and end function */
	return Local_u8ErrorState;
}


/**
/*   @fn         GPIO_u8SetPinValue
 *   @brief      The function puts a value on a specific output pin
 *   @param[in]  Port: The port number, get options @Port_t enum
 *   @param[in]  PinNum: The pin number, get options @pin_t enum
 *   @param[in]  PinVal: The output value, get options @PinVal_t enum
 *   @retVal     Local_u8ErrorState
 */
uint8_t  GPIO_u8SetPinValue(Port_t Port , Pin_t PinNum ,PinVal_t PinVal)
{
	/* define error state variable */
	uint8_t Local_u8ErrorState=OK;

	if((Port <= PORTH) && (PinNum <= PIN15) )
	{
		if(PinVal == PIN_LOW)
		{
			/* put in PinNum in ODR  0 */
			GPIOPORT[Port]->ODR &= ~(1<< PinNum );
			/* another method and it is faster than method one bec it is an assignment operation only */
			/* GPIOPORT[Port]->BSRR = 1 << (16 + PinNum); */

		}else if(PinVal == PIN_HIGH)
		{
			/* put in  PinNum in ODR 1 */
			GPIOPORT[Port]->ODR |= (1<< PinNum );
			/* another method and it is faster than method one bec it is an assignment operation only */
			/* GPIOPORT[Port]->BSRR = 1 << PinNum; */
		}else
		{
			/* update error state */
			Local_u8ErrorState=NOK;
		}

	}else
	{
		/* update error state */
		Local_u8ErrorState=NOK;
	}

	/* return error state variable and end function */
	return Local_u8ErrorState;
}

/**
/*   @fn         GPIO_u8SetPinValue
 *   @brief      The function Toggles a value on a specific output pin
 *   @param[in]  Port: The port number, get options @Port_t enum
 *   @param[in]  PinNum: The pin number, get options @Pin_t enum
 *   @retVal     Local_u8ErrorState
 */

uint8_t  GPIO_u8TogglePinValue(Port_t Port , Pin_t PinNum )
{
	/* define error state variable */
	uint8_t Local_u8ErrorState=OK;

	if((Port <= PORTH) && (PinNum <= PIN15) )
	{
		GPIOPORT[Port]->ODR ^= (ODR_MASK<<PinNum);

	}else
	{
		/* update error state */
		Local_u8ErrorState=NOK;
	}

	/* return error state variable and end function */
	return Local_u8ErrorState;
}

/**
/*   @fn         GPIO_u8SetPinValue
 *   @brief      The function Toggles a value on a specific output pin
 *   @param[in]  Port: The port number, get options @Port_t enum
 *   @param[in]  PinNum: The pin number, get options @Pin_t enum
 *   @param[out] PinVal: this is var pass by reference to carry the value of a specific bit
 *   @retVal     Local_u8ErrorState
 */
uint8_t  GPIO_u8ReadPinValue(Port_t Port , Pin_t PinNum ,PinVal_t* PinVal)
{
	/* define error state variable */
	uint8_t Local_u8ErrorState=OK;

	if((Port <= PORTH) && (PinNum <= PIN15) )
	{
		if(PinVal != NULL)
		{
			*PinVal =((GPIOPORT[Port]->IDR >>PinNum)&IDR_MASK);
		}else
		{
			/* update error state */
			Local_u8ErrorState=NOK;
		}

	}else
	{
		/* update error state */
		Local_u8ErrorState=NOK;
	}

	/* return error state variable and end function */
	return Local_u8ErrorState;
}
