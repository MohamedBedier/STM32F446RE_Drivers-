/*************************************************************/
/*************************************************************/
/**                                                         **/
/** LayerArchitect: MCAL                                    **/
/** File Name : SYSCFG_interface.h                          **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/

#ifndef SYSCFG_INTERFACE_H_
#define SYSCFG_INTERFACE_H_


/**
 * @brief : this enum to carry EXTI lines options from line 0 to line 22 totally 23 EXTI_lines
 */
typedef enum
{
  SYSCFG_Line0=0,/**< SYSCFG_Line0 */
  SYSCFG_Line1,  /**< SYSCFG_Line1 */
  SYSCFG_Line2,  /**< SYSCFG_Line2 */
  SYSCFG_Line3,  /**< SYSCFG_Line3 */
  SYSCFG_Line4,  /**< SYSCFG_Line4 */
  SYSCFG_Line5,  /**< SYSCFG_Line5 */
  SYSCFG_Line6,  /**< SYSCFG_Line6 */
  SYSCFG_Line7,  /**< SYSCFG_Line7 */
  SYSCFG_Line8,  /**< SYSCFG_Line8 */
  SYSCFG_Line9,  /**< SYSCFG_Line9 */
  SYSCFG_Line10, /**< SYSCFG_Line10 */
  SYSCFG_Line11, /**< SYSCFG_Line11 */
  SYSCFG_Line12, /**< SYSCFG_Line12 */
  SYSCFG_Line13, /**< SYSCFG_Line13 */
  SYSCFG_Line14, /**< SYSCFG_Line14 */
  SYSCFG_Line15, /**< SYSCFG_Line15 */
  SYSCFG_Line16, /**< SYSCFG_Line16 */
  SYSCFG_Line17, /**< SYSCFG_Line17 */
  SYSCFG_Line18, /**< SYSCFG_Line18 */
  SYSCFG_Line19, /**< SYSCFG_Line19 */
  SYSCFG_Line20, /**< SYSCFG_Line20 */
  SYSCFG_Line21, /**< SYSCFG_Line21 */
  SYSCFG_Line22  /**< SYSCFG_Line22 */

}SYSCFG_Lines_t;

/**
 * @brief : this enum to carry PORT OPTIONS FROM PORTA TO PORTH
 */
typedef enum
{
	SYSCFG_PORTA=0,/**< EXTI_PORTA */
	SYSCFG_PORTB,  /**< EXTI_PORTB */
	SYSCFG_PORTC,  /**< EXTI_PORTC */
	SYSCFG_PORTD,  /**< EXTI_PORTD */
	SYSCFG_PORTE,  /**< EXTI_PORTE */
	SYSCFG_PORTF,  /**< EXTI_PORTF */
	SYSCFG_PORTG,  /**< EXTI_PORTG */
	SYSCFG_PORTH,  /**< EXTI_PORTH */
}SYSCFG_PORT_t;

/**
 * @brief: This function to Set EXTI port
 * @param[in] Copy_EnumEXTI_Line : this enum to carry options of EXTI lines options from line 0 to line 22 totally 23 EXTI_lines
 * @param[in] Copy_EnumEXTI_PORT : this enum to carry options FROM PORTA TO PORTH
 * @return Local_u8ErrorState : this variable to carry ErrorState value
 */
uint8_t SYSCFG_u8SetEXTIPort(SYSCFG_Lines_t Copy_EnumEXTI_Line , SYSCFG_PORT_t Copy_EnumEXTI_PORT );

#endif /* SYSCFG_INTERFACE_H_ */
