/*************************************************************/
/*************************************************************/
/**                                                         **/
/** LayerArchitect: MCAL                                    **/
/** File Name : RCC_Program.c                               **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/

#include <stdint.h>
#include "ErrType.h"
#include "BIT_MATH.h"
#include "Stm32F446xx.h"
#include "RCC_Private.h"
#include "RCC_Interface.h"

/******************************    RCC Peripheral Base Addresses        ******************************/
#define  RCC_BASE_ADDRESS     (RCC_Reg_t*)0x40023800U


/* define a pointer from type of struct [RCC_Reg_t] which carry the base address of RCC
			   Don't forget to cast it to (RCC_Reg_t* ) */

static RCC_Reg_t* RCC = RCC_BASE_ADDRESS;

uint8_t RCC_u8SetClkSts(ClkType_t Copy_EnumCLkType ,ClkStatus_t Copy_EnumCLkStatus)
{
	/* define variable to carry ErrorState */
	uint8_t Local_u8ErrorState = OK;

	/* This variable for TimeOutCounter */
	uint32_t Local_u32TimeOutCounter=0u;

	if(Copy_EnumCLkType == HSE)
	{
		if(Copy_EnumCLkStatus == CLK_ON)
		{
			/* enable HSE */
			SET_BIT((RCC->RCC_CR),HSE_ON);

			/* Polling method : waiting until the HSE_RDY or the timeout is passed  */
			while((GET_BIT((RCC->RCC_CR),HSE_RDY) == 1) && (Local_u32TimeOutCounter < RCC_TIMEOUT))
			{
				/* increment by 1 */
				Local_u32TimeOutCounter++;
			}

			/* check if loop ended because RCC_TIMEOUT is passed or the flag is raised */
			if(Local_u32TimeOutCounter >= RCC_TIMEOUT)
			{
				/* loop is broken because flag isn't raised until timeout is passed */
				Local_u8ErrorState = TIMEOUT_ERR;
			}else
			{
				/* loop is broken because flag is raised , and we have another func to enable peripheral */
			}
		}else if (Copy_EnumCLkStatus == CLK_OFF)
		{
			/* disable HSE */
			CLR_BIT((RCC->RCC_CR),HSE_ON);

		}else
		{
			Local_u8ErrorState =NOK;/* if the user send invalid options */
		}
	}else if (Copy_EnumCLkType == HSI)
	{
		if(Copy_EnumCLkStatus == CLK_ON)
		{
			/* enable HSI */
			SET_BIT((RCC->RCC_CR),HSI_ON);

			/* Polling method : waiting until the HSI_RDY or the timeout is passed  */
			while((GET_BIT((RCC->RCC_CR),HSI_RDY) == 1) && (Local_u32TimeOutCounter < RCC_TIMEOUT))
			{
				/* increment by 1 */
				Local_u32TimeOutCounter++;
			}

			/* check if loop ended because RCC_TIMEOUT is passed or the flag is raised */
			if(Local_u32TimeOutCounter >= RCC_TIMEOUT)
			{
				/* loop is broken because flag isn't raised until timeout is passed */
				Local_u8ErrorState = TIMEOUT_ERR;
			}else
			{
				/* loop is broken because flag is raised , and we have another func to enable peripheral */
			}
		}else if (Copy_EnumCLkStatus == CLK_OFF)
		{
			/* disable HSI */
			CLR_BIT((RCC->RCC_CR),HSI_ON);

		}else
		{
			Local_u8ErrorState =NOK;/* if the user send invalid options */
		}
	}else if (Copy_EnumCLkType == PLL)
	{
		if(Copy_EnumCLkStatus == CLK_ON)
		{
			/* enable PLL */
			SET_BIT((RCC->RCC_CR),PLL_ON);

			/* Polling method : waiting until the PLL_RDY or the timeout is passed  */
			while((GET_BIT((RCC->RCC_CR),PLL_RDY) == 1) && (Local_u32TimeOutCounter < RCC_TIMEOUT))
			{
				/* increment by 1 */
				Local_u32TimeOutCounter++;
			}

			/* check if loop ended because RCC_TIMEOUT is passed or the flag is raised */
			if(Local_u32TimeOutCounter >= RCC_TIMEOUT)
			{
				/* loop is broken because flag isn't raised until timeout is passed */
				Local_u8ErrorState = TIMEOUT_ERR;
			}else
			{
				/* loop is broken because flag is raised , and we have another func to enable peripheral */
			}
		}else if (Copy_EnumCLkStatus == CLK_OFF)
		{
			/* disable PLL */
			CLR_BIT((RCC->RCC_CR),PLL_ON);

		}else
		{
			Local_u8ErrorState =NOK;/* if the user send invalid options */
		}
	}else
	{
		Local_u8ErrorState=NOK;/* if the user send invalid options */
	}

	return Local_u8ErrorState;
}


uint8_t RCC_u8SetSysClk(SysClk_t Copy_EnumCLkType)
{
	/* define variable to carry ErrorState */
	uint8_t Local_u8ErrorState = OK;

	/* configure system clk */
	switch(Copy_EnumCLkType)
	{
	case HSE_AS_SYSCLK:CLR_BIT((RCC->RCC_CFGR),SW1);CLR_BIT((RCC->RCC_CFGR),SW0);break;
	case HSI_AS_SYSCLK:CLR_BIT((RCC->RCC_CFGR),SW1);SET_BIT((RCC->RCC_CFGR),SW0);break;
	case PLL_P:SET_BIT((RCC->RCC_CFGR),SW1);CLR_BIT((RCC->RCC_CFGR),SW0);break;
	case PLL_R:SET_BIT((RCC->RCC_CFGR),SW1);SET_BIT((RCC->RCC_CFGR),SW0);break;
	default:Local_u8ErrorState=NOK;break;/* if the user send invalid options */
	}

	return Local_u8ErrorState;
}



uint8_t RCC_u8PLLCLKConfig(const PLLCLK_Cfg_t* Copy_PS_PLLCLK_Cfg)
{
	/* define variable to carry ErrorState */
	uint8_t Local_u8ErrorState = OK;

	/* check if the not equal NULL or not  */
	if(Copy_PS_PLLCLK_Cfg != NULL)
	{
		/* if pointer not equal NULL check on the factor if anyone of them not equal its micro change the Local_u8ErrorState to NOK */
		if(((Copy_PS_PLLCLK_Cfg -> PLL_M_Factor) < PLLM_FACT_MIN) || ((Copy_PS_PLLCLK_Cfg -> PLL_M_Factor) > PLLM_FACT_MAX)
				||((Copy_PS_PLLCLK_Cfg -> PLL_N_Factor) < PLLM_FACT_MIN) ||((Copy_PS_PLLCLK_Cfg -> PLL_N_Factor) > PLLN_FACT_MAX)
				||((Copy_PS_PLLCLK_Cfg -> PLL_P_Factor) != PLLP_DIV2) ||((Copy_PS_PLLCLK_Cfg -> PLL_P_Factor) != PLLP_DIV4)
				||((Copy_PS_PLLCLK_Cfg -> PLL_P_Factor) != PLLP_DIV6)||((Copy_PS_PLLCLK_Cfg -> PLL_P_Factor) != PLLP_DIV8))
		{
			Local_u8ErrorState =NOK;/* if the user send invalid options */
		}else
		{
			/* Configure PLL M Factor using pointer from struct Copy_PS_PLLCLK_Cfg */
			(RCC ->RCC_PLLCFGR) &= (~PLLM_MASK);
			(RCC ->RCC_PLLCFGR) |= (Copy_PS_PLLCLK_Cfg -> PLL_M_Factor);

			/* Configure PLL N Factor using pointer from struct Copy_PS_PLLCLK_Cfg */
			(RCC ->RCC_PLLCFGR) &= (~(PLLN_MASK << PLLN_POS_IN_CFGR));
			(RCC ->RCC_PLLCFGR) |= ((Copy_PS_PLLCLK_Cfg -> PLL_N_Factor) << PLLN_POS_IN_CFGR);

			/* Configure PLL P Factor using pointer from struct Copy_PS_PLLCLK_Cfg */
			(RCC ->RCC_PLLCFGR) &= (~(PLLP_MASK << PLLP_POS_IN_CFGR));
			(RCC ->RCC_PLLCFGR) |= ((Copy_PS_PLLCLK_Cfg -> PLL_P_Factor) << PLLP_POS_IN_CFGR);

			/* Configure PLL Clock source if it HSE OR HSI using pointer from struct Copy_PS_PLLCLK_Cfg */
			(RCC ->RCC_PLLCFGR) &= (~(1<< PLLSRC_POS_IN_CFGR));
			//(RCC ->RCC_PLLCFGR) |= ((Copy_PS_PLLCLK_Cfg -> PLL_CLK_SRC) << PLLSRC_POS_IN_CFGR);

		}
	}else
	{
		/* POINTER equal NULL */
		Local_u8ErrorState =NULL_PTR_ERR;/* if the Pointer refer to NULL*/
	}

	return Local_u8ErrorState;
}

void RCC_voidAHB_1_EnableClk(RCC_AHB_1_ENR_t  Copy_EnumAHB1Peripheral)
{
	/* enable the clk on this peripheral */
	SET_BIT((RCC->RCC_AHB1ENR),Copy_EnumAHB1Peripheral);
}

void RCC_voidAHB_1_DisableClk(RCC_AHB_1_ENR_t  Copy_EnumAHB1Peripheral)
{
	/* Disable the clk on this peripheral */
	CLR_BIT((RCC->RCC_AHB1ENR),Copy_EnumAHB1Peripheral);
}

void RCC_voidAHB_2_EnableClk(RCC_AHB_2_ENR_t  Copy_EnumAHB2Peripheral)
{
	/* enable the clk on this peripheral */
	SET_BIT((RCC->RCC_AHB2ENR),Copy_EnumAHB2Peripheral);
}

void RCC_voidAHB_2_DisableClk(RCC_AHB_2_ENR_t  Copy_EnumAHB2Peripheral)
{
	/* Disable the clk on this peripheral */
	CLR_BIT((RCC->RCC_AHB2ENR),Copy_EnumAHB2Peripheral);
}

void RCC_voidAHB_3_EnableClk(RCC_AHB_3_ENR_t  Copy_EnumAHB3Peripheral)
{
	/* enable the clk on this peripheral */
	SET_BIT((RCC->RCC_AHB3ENR),Copy_EnumAHB3Peripheral);
}

void RCC_voidAHB_3_DisableClk(RCC_AHB_3_ENR_t  Copy_EnumAHB3Peripheral)
{
	/* Disable the clk on this peripheral */
	CLR_BIT((RCC->RCC_AHB3ENR),Copy_EnumAHB3Peripheral);
}

void RCC_voidAPB_1_EnableClk(RCC_APB_1_ENR_t  Copy_EnumAPB_1_Peripheral)
{
	/* enable the clk on this peripheral */
	SET_BIT((RCC->RCC_APB1ENR),Copy_EnumAPB_1_Peripheral);
}

void RCC_voidAPB_1_DisableClk(RCC_APB_1_ENR_t  Copy_EnumAPB_1_Peripheral)
{
	/* Disable the clk on this peripheral */
	CLR_BIT((RCC->RCC_APB1ENR),Copy_EnumAPB_1_Peripheral);
}

void RCC_voidAPB_2_EnableClk(RCC_APB_2_ENR_t  Copy_EnumAPB_2_Peripheral)
{
	/* enable the clk on this peripheral */
	SET_BIT((RCC->RCC_APB2ENR),Copy_EnumAPB_2_Peripheral);
}

void RCC_voidAPB_2_DisableClk(RCC_APB_2_ENR_t  Copy_EnumAPB_2_Peripheral)
{
	/* Disable the clk on this peripheral */
	CLR_BIT((RCC->RCC_APB2ENR),Copy_EnumAPB_2_Peripheral);
}


