/*************************************************************/
/*************************************************************/
/**                                                         **/
/** LayerArchitect: MCAL                                    **/
/** File Name : RCC_Interface.h                             **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_


/**
 * @brief: define enum to Config PLL CLOCK SRC
 */
typedef enum
{
	PLL_HSI=0,
	PLL_HSE

}PLL_CLK_SRC_t;


/**
 * @brief: define struct to carry PLL configuration (PLL_M_Factor,PLL_N_Factor,PLL_P_Factor,PLL_CLK_SRC_t)
 */

typedef struct
{
	uint16_t PLL_M_Factor;
	uint8_t  PLL_N_Factor;
	uint8_t  PLL_P_Factor;
	PLL_CLK_SRC_t  PLL_CLK_SRC;

}PLLCLK_Cfg_t;




/**
 * @brief: define enum to carry Type of CLock source
 */
typedef enum
{
	HSE=0,
	HSI,
	PLL
}ClkType_t;

/**
 * @brief: define enum to carry system CLock source
 */
typedef enum
{
	HSE_AS_SYSCLK=0,
	HSI_AS_SYSCLK,
	PLL_P,
	PLL_R
}SysClk_t;


/**
 * @brief: define enum to carry Type of CLock status
 */
typedef enum
{
	CLK_ON=0,
	CLK_OFF

}ClkStatus_t;


/**
 * @brief: define enum to Config CSS Status
 */
typedef enum
{
	CSS_ENABLED=0,
	CSS_DISABLED

}CSS_Sts_t;

/**
 * @brief: define enum to configure APB2 high-speed prescaler
 */
typedef enum
{
	APB2_HCLK_NOT_DIVIDED=3,
	APB2_HCLK_DIVIDED_BY_2,
	APB2_HCLK_DIVIDED_BY_4,
	APB2_HCLK_DIVIDED_BY_8,
	APB2_HCLK_DIVIDED_BY_16,

}APB_2_Precaler_t;

/**
 * @brief: define enum to configure APB1 high-speed prescaler
 */
typedef enum
{
	APB1_HCLK_NOT_DIVIDED=3,
	APB1_HCLK_DIVIDED_BY_2,
	APB1_HCLK_DIVIDED_BY_4,
	APB1_HCLK_DIVIDED_BY_8,
	APB1_HCLK_DIVIDED_BY_16,

}APB1_Precaler_t;

/**
 * @brief: define enum to configure AHB prescaler
 */
typedef enum
{
	SYSCLK_NOT_DIVIDED=7,
	SYSCLK_DIVIDED_BY_2,
	SYSCLK_DIVIDED_BY_4,
	SYSCLK_DIVIDED_BY_8,
	SYSCLK_DIVIDED_BY_16,
	SYSCLK_DIVIDED_BY_64,
	SYSCLK_DIVIDED_BY_128,
	SYSCLK_DIVIDED_BY_256,
	SYSCLK_DIVIDED_BY_512

}AHB_Precaler_t;

/**
 * @brief: define enum to configure RCC_CR BITS
 */
typedef enum
{
	HSI_ON=0,
	HSI_RDY,
	HSI_TRIM0=3,
	HSI_TRIM1,
	HSI_TRIM2,
	HSI_TRIM3,
	HSI_TRIM4,
	HSICAL0,
	HSICAL1,
	HSICAL2,
	HSICAL3,
	HSICAL4,
	HSICAL5,
	HSICAL8,
	HSICAL7,
	HSE_ON,
	HSE_RDY,
	HSE_BYP,
	CSS_ON ,
	PLL_ON=24,
	PLL_RDY,
	PLL12S_ON,
	PLL12S_RDY,
	PLLSAI_ON,
	PLLSAI_RDY
}RCC_CR_t;

/**
 * @brief: define enum to configure RCC_CFGR BITS
 */
typedef enum
{
	SW0=0,
	SW1,
	SWS0,
	SWS1,
	HPRE0,
	HPRE1,
	HPRE2,
	HPRE3,
	PPRE1_BIT0=10,
	PPRE1_BIT1,
	PPRE1_BIT2,
	PPRE2_BIT0,
	PPRE2_BIT1,
	PPRE2_BIT2,
	RTCPRE_BIT0,
	RTCPRE_BIT1,
	RTCPRE_BIT2,
	RTCPRE_BIT3,
	RTCPRE_BIT4,
	MCO1_BIT0,
	MCO1_BIT1,
	MCO1_PRE_BIT0=24,
	MCO1_PRE_BIT1,
	MCO1_PRE_BIT2,
	MCO2_PRE_BIT0,
	MCO2_PRE_BIT1,
	MCO2_PRE_BIT2,
	MCO2_BIT0,
	MCO2_BIT1,

}RCC_CFGR_t;



/**
 * @brief: define enum to configure RCC_AHB_1_RSTR BITS
 */

typedef enum
{

	GPIOA_RST=0,
	GPIOB_RST,
	GPIOC_RST,
	GPIOD_RST,
	GPIOE_RST,
	GPIOF_RST,
	GPIOG_RST,
	GPIOH_RST,
	CRC_RST=12,
	DMA1_RST=21,
	DMA2_RST,
	OTGHS_RST=29

}RCC_AHB_1_RSTR_t;



/**
 * @brief: define enum to configure RCC_AHB_2_RSTR BITS
 */

typedef enum
{
	DCMI_RST=0,
	OTGFS_RST=7

}RCC_AHB_2_RSTR_t;


/**
 * @brief: define enum to configure RCC_AHB_3_RSTR BITS
 */

typedef enum
{
	FMC_RST=0,
	QSPI_RST

}RCC_AHB_3_RSTR_t;



/**
 * @brief: define enum to configure RCC_APB_1_RSTR BITS
 */

typedef enum
{
	TIM2_RST=0,
	TIM3_RST,
	TIM4_RST,
	TIM5_RST,
	TIM6_RST,
	TIM7_RST,
	TIM12_RST,
	TIM13_RST,
	TIM14_RST,
	WWDG_RST=11,
	SPI2_RST=14,
	SPI3_RST,
	SPDIFRX_RST,
	UART2_RST,
	UART3_RST,
	UART4_RST,
	UART5_RST,
	I2C1_RST,
	I2C2_RST,
	I2C3_RST,
	FMPI2C1_RST,
	CAN1_RST,
	CAN2_RST,
	CEC_RST,
	PWP_RST,
	DAC_RST

}RCC_APB_1_RSTR_t;


/**
 * @brief: define enum to configure RCC_APB_2_RSTR BITS
 */

typedef enum
{
	TIM1_RST=0,
	TIM8_RST,
	USART1_RST=4,
	USART6_RST,
	ADC_RST=8,
	SDIO_RST=11,
	SPI1_RST,
	SPI4_RST,
	SYSCFG_RST,
	TIM9_RST=16,
	TIM10_RST,
	TIM11_RST,
	SAI1_RST=22,
	SAI2_RST
}RCC_APB_2_RSTR_t;



/**
 * @brief: define enum to configure RCC_AHB_1_ENR BITS
 */


typedef enum
{
	GPIOA_EN=0,
	GPIOB_EN,
	GPIOC_EN,
	GPIOD_EN,
	GPIOE_EN,
	GPIOF_EN,
	GPIOG_EN,
	GPIOH_EN,
	CRC_EN=12,
	DMA1_EN=21,
	DMA2_EN,
	OTGHS_EN=29

}RCC_AHB_1_ENR_t;


/**
 * @brief: define enum to configure RCC_AHB_2_ENR BITS
 */

typedef enum
{
	DCMI_ENR=0,
	OTGFS_ENR=7

}RCC_AHB_2_ENR_t;


/**
 * @brief: define enum to configure RCC_AHB_3_ENR BITS
 */

typedef enum
{
	FMC_ENR=0,
	QSPI_ENR

}RCC_AHB_3_ENR_t;


/**
 * @brief: define enum to configure RCC_APB_1_ENR BITS
 */

typedef enum
{
	TIM2_ENR=0,
	TIM3_ENR,
	TIM4_ENR,
	TIM5_ENR,
	TIM6_ENR,
	TIM7_ENR,
	TIM12_ENR,
	TIM13_ENR,
	TIM14_ENR,
	WWDG_ENR=11,
	SPI2_ENR=14,
	SPI3_ENR,
	SPDIFRX_ENR,
	UART2_ENR,
	UART3_ENR,
	UART4_ENR,
	UART5_ENR,
	I2C1_ENR,
	I2C2_ENR,
	I2C3_ENR,
	FMPI2C1_ENR,
	CAN1_ENR,
	CAN2_ENR,
	CEC_ENR,
	PWP_ENR,
	DAC_ENR

}RCC_APB_1_ENR_t;


/**
 * @brief: define enum to configure RCC_APB_2_ENR BITS
 */

typedef enum
{
	TIM1_ENR=0,
	TIM8_ENR,
	USART1_ENR=4,
	USART6_ENR,
	ADC_ENR=8,
	SDIO_ENR=11,
	SPI1_ENR,
	SPI4_ENR,
	SYSCFG_ENR,
	TIM9_ENR=16,
	TIM10_ENR,
	TIM11_ENR,
	SAI1_ENR=22,
	SAI2_ENR
}RCC_APB_2_ENR_t;


/**
 * @brief: define enum to configure BusName
 */

typedef enum
{
	APB1=0,
	APB2,
	AHB1,
	AHB2,
	AHB3
}BusName_t;


/**
 * @brief this function to set clock type(HSE,HSI,PLL,PLL12S,PLLSAI) and its status (on or off)
 * @param Copy_EnumCLkType
 * @param Copy_EnumCLkStatus
 * @return Local_u8ErrorState
 */

uint8_t RCC_u8SetClkSts(ClkType_t Copy_EnumCLkType ,ClkStatus_t Copy_EnumCLkStatus );

/**
 * @brief this function to set system clock type(HSE,HSI,PLL)
 * @param Copy_EnumCLkType
 * @return Local_u8ErrorState
 */
uint8_t RCC_u8SetSysClk(SysClk_t Copy_EnumCLkType);


/**
 * @brief this function to configure (PLL_M_Factor,PLL_N_Factor,PLL_P_Factor,PLL_CLK_SRC_t)
 * @param Copy_PS_PLLCLK_Cfg
 * @return Local_u8ErrorState
 */
uint8_t RCC_u8PLLCLKConfig(const PLLCLK_Cfg_t* Copy_PS_PLLCLK_Cfg);

/**
 * @brief this function to ENABLE peripheral clk on AHB1
 * @param Copy_EnumAHB1Peripheral
 *
 */
void RCC_voidAHB_1_EnableClk(RCC_AHB_1_ENR_t  Copy_EnumAHB1Peripheral);
/**
 * @brief this function to DISABLE peripheral clk on AHB1
 * @param Copy_EnumAHB1Peripheral
 *
 */
void RCC_voidAHB_1_DisableClk(RCC_AHB_1_ENR_t  Copy_EnumAHB1Peripheral);

/**
 * @brief this function to ENABLE peripheral clk on AHB2
 * @param Copy_EnumAHB2Peripheral
 *
 */
void RCC_voidAHB_2_EnableClk(RCC_AHB_2_ENR_t  Copy_EnumAHB2Peripheral);

/**
 * @brief this function to DISABLE peripheral clk on AHB2
 * @param Copy_EnumAHB1Peripheral
 *
 */
void RCC_voidAHB_2_DisableClk(RCC_AHB_2_ENR_t  Copy_EnumAHB2Peripheral);

/**
 * @brief this function to ENABLE peripheral clk on AHB3
 * @param Copy_EnumAHB3Peripheral
 *
 */
void RCC_voidAHB_3_EnableClk(RCC_AHB_3_ENR_t  Copy_EnumAHB3Peripheral);

/**
 * @brief this function to DISABLE peripheral clk on AHB3
 * @param Copy_EnumAHB3Peripheral
 *
 */
void RCC_voidAHB_3_DisableClk(RCC_AHB_3_ENR_t  Copy_EnumAHB3Peripheral);


/**
 * @brief this function to ENABLE peripheral clk on APB1
 * @param Copy_EnumAPB_1_Peripheral
 *
 */
void RCC_voidAPB_1_EnableClk(RCC_APB_1_ENR_t  Copy_EnumAPB_1_Peripheral);

/**
 * @brief this function to DISABLE peripheral clk on APB1
 * @param Copy_EnumAPB_1_Peripheral
 *
 */
void RCC_voidAPB_1_DisableClk(RCC_APB_1_ENR_t  Copy_EnumAPB_1_Peripheral);

/**
 * @brief this function to ENABLE peripheral clk on APB2
 * @param Copy_EnumAPB_2_Peripheral
 *
 */
void RCC_voidAPB_2_EnableClk(RCC_APB_2_ENR_t  Copy_EnumAPB_2_Peripheral);
/**
 * @brief this function to DISABLE peripheral clk on APB2
 * @param Copy_EnumAPB_2_Peripheral
 *
 */
void RCC_voidAPB_2_DisableClk(RCC_APB_2_ENR_t  Copy_EnumAPB_2_Peripheral);

/**
 * @brief this function to ENABLE CSS Pin
 * @param Copy_EnumCSS_Sts
 *
 */
void RCC_voidCSSPin_Enable(CSS_Sts_t Copy_EnumCSS_Sts);


/**
 * @brief this function to Disable CSS Pin
 * @param Copy_EnumCSS_Sts
 *
 */
void RCC_voidCSSPin_Disable(CSS_Sts_t Copy_EnumCSS_Sts);


#endif /* RCC_INTERFACE_H_ */
