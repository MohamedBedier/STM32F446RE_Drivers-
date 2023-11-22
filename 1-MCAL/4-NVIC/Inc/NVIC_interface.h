/*************************************************************/
/*************************************************************/
/**                                                         **/
/** LayerArchitect: MCAL                                    **/
/** File Name : NVIC_interface.h                            **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

typedef enum
{
	WWDG=0,
	PVD,
	TAMP_STAMP,
	RTC_WKUP,
	FLASH,
	RCC_IRQ ,/* I change its name because in stm32f446xx.h i have a pointer its name is RCC  */
	EXTI0,
	EXTI1,
	EXTI2,
	EXTI3,
	EXTI4,
	DMA1_Stream0,
	DMA1_Stream1,
	DMA1_Stream2,
	DMA1_Stream3,
	DMA1_Stream4,
	DMA1_Stream5,
	DMA1_Stream6,
	ADC,
	CAN1_TX,
	CAN1_RX0,
	CAN1_RX1,
	CAN1_SCE,
	EXTI9_5,
	TIM1_BRK_TIM9,
	TIM1_UP_TIM10,
	TIM1_TRG_COM_TIM11,
	TIM1_CC,
	TIM2,
	TIM3,
	TIM4,
	I2C1_EV,
	I2C1_ER,
	I2C2_EV,
	I2C2_ER,
	SPI1,
	SPI2,
	USART1,
	USART2,
	USART3,
	EXTI15_10,
	RTC_Alarm,
	OTG_FS_WKUP,
	TIM8_BRK_TIM12,
	TIM8_UP_TIM13,
	TIM8_TRG_COM_TIM14,
	TIM8_CC,
	DMA1_Stream7,
	FMC,
	SDIO,
	TIM5,
	SPI3,
	UART4,
	UART5,
	TIM6_DAC,
	TIM7,
	DMA2_Stream0,
	DMA2_Stream1,
	DMA2_Stream2,
	DMA2_Stream3,
	DMA2_Stream4,
	CAN2_TX=63,
	CAN2_RX0,
	CAN2_RX1,
	CAN2_SCE,
	OTG_FS,
	DMA2_Stream5,
	DMA2_Stream6,
	DMA2_Stream7,
	USART6,
	I2C3_EV,
	I2C3_ER,
	OTG_HS_EP1_OUT,
	OTG_HS_EP1_IN,
	OTG_HS_WKUP,
	OTG_HS,
	DCMI,
	FPU=81,
	RESERVED5,
	RESERVED6,
	SPI4=84,
	SAI1=87,
	SAI2=91,
	QuadSPI,
	HDMI_CEC,
	SPDIF_Rx,
	FMPI2C1,
	FMPI2C1_error
}IRQNum_t;


/**
 * @name : PENDING_t
 * @brief  :This is an enum which carring pending state
 */
typedef enum
{
	NOT_PENDING = 0 ,
	PENDING

}PENDING_t;

/**
 * @name  :  @ACTIVE_t
 * @brief : This is an enum which carring Active STATUS
 *
 */
typedef enum
{
  NOT_ACTIVE = 0 ,
  ACTIVE

}ACTIVE_t;

/**
 * @brief: This function to enable Peripheral from NVIC
 * @param[IN] Copy_EnumIRQNum : this enum carries peripheral position in vector table (IRQ_Num)
 * @return Local_u8ErrorState : this variable to carry ErrorState value
 */
uint8_t NVIC_u8Enable(IRQNum_t Copy_EnumIRQNum);

/**
 * @brief: This function to Disable Peripheral from NVIC
 * @param[IN] Copy_EnumIRQNum : this enum carries peripheral position in vector table (IRQ_Num)
 * @return Local_u8ErrorState : this variable to carry ErrorState value
 */
uint8_t NVIC_u8Disable(IRQNum_t Copy_EnumIRQNum);
/**
 * @brief: This function to Set Pending Flag from NVIC
 * @param[IN] Copy_EnumIRQNum : this enum carries peripheral position in vector table (IRQ_Num)
 * @return Local_u8ErrorState : this variable to carry ErrorState value
 */

uint8_t NVIC_u8SetPendingFlag(IRQNum_t Copy_EnumIRQNum);
/**
 * @brief: This function to clear Pending Flag from NVIC
 * @param[IN] Copy_EnumIRQNum : this enum carries peripheral position in vector table (IRQ_Num)
 * @return Local_u8ErrorState : this variable to carry ErrorState value
 */

uint8_t NVIC_u8ClearPendingFlag(IRQNum_t Copy_EnumIRQNum);
/**
 * @brief: This function to read active Flag
 * @param[IN] Copy_EnumIRQNum : this enum carries peripheral position in vector table (IRQ_Num)
 * @param[OUT] Copy_u8ActiveFlag : this Pointer to carry ActiveFlag State
 * @return Local_u8ErrorState : this variable to carry ErrorState value
 */

uint8_t NVIC_u8GetActiveFlag(IRQNum_t Copy_EnumIRQNum,uint8_t* Copy_u8ActiveFlag);

/**
 * @brief: This function to set the priority from user [group and sub] by send Copy_u8Proirty
 * @param[IN] Copy_EnumIRQNum : this enum carries peripheral position in vector table (IRQ_Num)
 * @param[in] Copy_u8Proirty : this variable to carry priority
 * @return Local_u8ErrorState : this variable to carry ErrorState value
 */

uint8_t NVIC_u8SetIRQPriorty(IRQNum_t Copy_EnumIRQNum,uint8_t  Copy_u8Proirty);


#endif /* NVIC_INTERFACE_H_ */
