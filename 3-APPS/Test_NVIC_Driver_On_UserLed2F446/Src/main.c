/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "Stm32F446xx.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "RCC_Interface.h"

int main(void)
{
	PinConfig_t	UserLed2_t =
	{
			.Port= PORTA ,
			.PinNum =PIN5,
			.Mode = OUTPUT,
			.OutputType = PUSH_PULL,
	};
	RCC_voidAHB_1_EnableClk(GPIOA_EN);

	GPIO_u8PinInit(&UserLed2_t);
	NVIC_u8Enable(USART3);

	NVIC_u8SetPendingFlag(USART3);


    /* Loop forever */
	for(;;);
}

 void USART3_IRQHandler(void)
{
	GPIO_u8SetPinValue(PORTA, PIN5, PIN_HIGH );
}
