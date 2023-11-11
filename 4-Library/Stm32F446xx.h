/*************************************************************/
/*************************************************************/
/**                                                         **/
/** LayerArchitect: Library                                 **/
/** File Name : Stm32F446xx.h                               **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/


#ifndef  STM32F446XX_H_
#define  STM32F446XX_H_


/******************************    Various Memory Base Addresses    ******************************/

#define  FLASH_BASE_ADDRESS   0x08000000UL  
#define  SRAM_BASE_ADDRESS    0x20000000UL  
#define  ROM_BASE_ADDRESS     0x1FFF0000UL


/******************************    AHB1 Peripheral Base Addresses    ******************************/

#define  GPIOA_BASE_ADDRESS   0x40020000UL
#define  GPIOB_BASE_ADDRESS   0x40020400UL
#define  GPIOC_BASE_ADDRESS   0x40020800UL
#define  GPIOD_BASE_ADDRESS   0x40020C00UL
#define  GPIOE_BASE_ADDRESS   0x40021000UL
#define  GPIOF_BASE_ADDRESS   0x40021400UL
#define  GPIOG_BASE_ADDRESS   0x40021800UL
#define  GPIOH_BASE_ADDRESS   0x40021C00UL

#define  RCC_BASE_ADDRESS     0x40023800UL



/******************************    CORTEX-M4 Core Peripheral Base Addresses    ******************************/

#define    NVIC_BASE_ADDRESS   0xE000E100UL

#define    SYST_BASE_ADDRESS   0xE000E010UL

/******************************    AHB2 Peripheral Base Addresses       ******************************/


/******************************    AHB3 Peripheral Base Addresses       ******************************/


/******************************    APB1 Peripheral Base Addresses       ******************************/

/******************************    APB2 Peripheral Base Addresses       ******************************/


/******************************    RCC Register Definitions Structure  ******************************/

typedef struct
{
	volatile uint32_t RCC_CR;           /* Clock control register */
	volatile uint32_t RCC_PLLCFGR;      /* RCC PLL configuration register */
	volatile uint32_t RCC_CFGR;         /* RCC clock configuration register  */
	volatile uint32_t RCC_CIR;          /* Clock interrupt register */
	volatile uint32_t RCC_AHB1RSTR;     /* RCC AHB1 peripheral reset register   */
	volatile uint32_t RCC_AHB2RSTR;     /* RCC AHB2 peripheral reset register   */
	volatile uint32_t RCC_AHB3RSTR;     /* RCC AHB3 peripheral reset register   */
	volatile uint32_t Reserved;         /* Reserved */
	volatile uint32_t RCC_APB1RSTR;     /* APB1 peripheral reset register  */
	volatile uint32_t RCC_APB2RSTR;     /* APB2 peripheral reset register */
	volatile uint32_t Reserved1[2];         /* Reserved */
	volatile uint32_t RCC_AHB1ENR;      /* RCC AHB1 peripheral clock enable register  */
	volatile uint32_t RCC_AHB2ENR;      /* RCC AHB2 peripheral clock enable register */
	volatile uint32_t RCC_AHB3ENR;      /* RCC AHB3 peripheral clock enable register  */
	volatile uint32_t Reserved2;         /* Reserved  */
	volatile uint32_t RCC_APB1ENR;      /* RCC APB1 peripheral clock enable register  */
	volatile uint32_t RCC_APB2ENR;      /* RCC APB2 peripheral clock enable register */
	volatile uint32_t Reserved3[2];         /* Reserved  */
	volatile uint32_t RCC_AHB1LPENR;    /* RCC AHB1 peripheral clock enable in low power mode register */
	volatile uint32_t RCC_AHB2LPENR;    /* RCC AHB2 peripheral clock enable in low power mode register */
	volatile uint32_t RCC_AHB3LPENR;    /* RCC AHB3 peripheral clock enable in low power mode register */
	volatile uint32_t Reserved4;         /* Reserved */
	volatile uint32_t RCC_APB1LPENR;    /* RCC APB1 peripheral clock enable in low power mode register */
	volatile uint32_t RCC_APB2LPENR;    /* RCC APB2 peripheral clock enable in low power mode register  */
	volatile uint32_t Reserved5[2];         /* Reserved */
	volatile uint32_t RCC_BDCR;         /* RCC Backup domain control register  */
	volatile uint32_t RCC_CSR;          /* RCC clock control _ status register */
	volatile uint32_t Reserved6[2];         /* Reserved */
	volatile uint32_t RCC_SSCGR;        /* RCC spread spectrum clock generation register  */
	volatile uint32_t RCC_PLL12SCFGR;   /* RCC PLLI2S configuration register */
	volatile uint32_t RCC_PLLSAICFGR;   /* RCC PLL configuration register  */
	volatile uint32_t RCC_DCKCFGR;      /* RCC dedicated clock configuration register */
	volatile uint32_t RCC_CKGATENR;     /* RCC clocks gated enable register */
	volatile uint32_t RCC_DCKCFGR2;     /* RCC dedicated clocks configuration register 2  */

}RCC_Reg_t;

/******************************    RCC Peripheral Definitions       ******************************/
#define   RCC  ((RCC_Reg_t*)RCC_BASE_ADDRESS)

/******************************    GPIO Register Definitions Structure  ******************************/

typedef  struct
{
	volatile  uint32_t  MODER;            /*GPIO PORT Mode Register*/
	volatile  uint32_t  OTYPER;           /*GPIO PORT Output Type Register*/
	volatile  uint32_t  OSPEEDR;          /*GPIO PORT Output speed Register*/
	volatile  uint32_t  PUPDR;            /*GPIO PORT Pull up/down Register*/
	volatile  uint32_t  IDR;              /*GPIO PORT input data Register*/
	volatile  uint32_t  ODR;              /*GPIO PORT Output data Register*/
	volatile  uint32_t  BSRR;             /*GPIO PORT Bit set/Reset Register*/
	volatile  uint32_t  LCKR;             /*GPIO PORT Lock Register*/
	volatile  uint32_t  AFR[2];           /*GPIO PORT Alternate function Register*/

}GPIO_RegDef_t;

/******************************    GPIO Peripheral Definitions       ******************************/

#define   GPIOA     ((GPIO_RegDef_t*)GPIOA_BASE_ADDRESS)
#define   GPIOB     ((GPIO_RegDef_t*)GPIOB_BASE_ADDRESS)
#define   GPIOC     ((GPIO_RegDef_t*)GPIOC_BASE_ADDRESS)
#define   GPIOD     ((GPIO_RegDef_t*)GPIOD_BASE_ADDRESS)
#define   GPIOE     ((GPIO_RegDef_t*)GPIOE_BASE_ADDRESS)
#define   GPIOF     ((GPIO_RegDef_t*)GPIOF_BASE_ADDRESS)
#define   GPIOG     ((GPIO_RegDef_t*)GPIOG_BASE_ADDRESS)
#define   GPIOH     ((GPIO_RegDef_t*)GPIOH_BASE_ADDRESS)



/******************************    Systick Register Definitions Structure  ******************************/

typedef  struct
{
	volatile  uint32_t  SYST_CSR;            /*SysTick Control and Status Register*/
	volatile  uint32_t  SYST_RVR;            /*SysTick Reload Value Register*/
	volatile  uint32_t  SYST_CVR;            /* SysTick Current Value Register */
	volatile  uint32_t   SYST_CALIB;         /* SysTick Calibration Value Register */

}SYSTICK_RegDef_t;

/******************************    SYSTICK Peripheral Definitions       ******************************/
#define   SYSTICK  ((SYSTICK_RegDef_t*)SYST_BASE_ADDRESS)

/******************************    NVIC Register Definitions   ******************************/

#define  ISER    ((volatile uint32_t*)0xE000E100) /* Interrupt Set-enable Registers */
#define  ICER    ((volatile uint32_t*)0XE000E180) /* Interrupt Clear-enable Registers */
#define  ISPR    ((volatile uint32_t*)0XE000E200) /* Interrupt Set-pending Registers */
#define  ICPR    ((volatile uint32_t*)0XE000E280) /* Interrupt Clear-pending Registers */
#define  IABR    ((volatile uint32_t*)0xE000E300) /* Interrupt Active Bit Registers */
#define  IPR     ((volatile uint32_t*)0xE000E400) /* Interrupt Priority Registers */
#define  STIR    ((volatile uint32_t*)0xE000EF00) /* Software Trigger Interrupt Register*/

/* if you want to work by Struct ,but you change in our code */

//typedef struct
//{
//	volatile uint32_t ISER[8]; /* Interrupt Set-enable Registers */
//	volatile uint32_t Reserved_1[24]; /* Offset */
//	volatile uint32_t ICER[8]; /* Interrupt Clear-enable Registers */
//	volatile uint32_t Reserved_2[24]; /* Offset */
//	volatile uint32_t ISPR[8]; /* Interrupt Set-pending Registers */
//	volatile uint32_t Reserved_3[24]; /* Offset */
//	volatile uint32_t ICPR[8]; /* Interrupt Clear-pending Registers */
//	volatile uint32_t Reserved_4[24]; /* Offset */
//	volatile uint32_t IABR[8]; /* Interrupt Active Bit Registers */
//	volatile uint32_t Reserved_5[56]; /* Offset */
//	volatile uint8_t  IPR[240] ; /* Interrupt Priority Registers */
//	volatile uint32_t Reserved_6[643]; /* Offset */
//	volatile uint32_t STIR; /* Software Trigger Interrupt Register*/
//
//}NVIC_Reg_t;
/******************* NVIC structure pointer **********************/
//#define NVIC					((NVIC_Reg_t *)(NVIC_BASE_ADDRESS))



#endif
