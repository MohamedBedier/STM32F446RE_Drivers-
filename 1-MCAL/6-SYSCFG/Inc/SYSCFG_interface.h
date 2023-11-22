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
  EXTI_Line0=0,/**< EXTI_Line0 */
  EXTI_Line1,  /**< EXTI_Line1 */
  EXTI_Line2,  /**< EXTI_Line2 */
  EXTI_Line3,  /**< EXTI_Line3 */
  EXTI_Line4,  /**< EXTI_Line4 */
  EXTI_Line5,  /**< EXTI_Line5 */
  EXTI_Line6,  /**< EXTI_Line6 */
  EXTI_Line7,  /**< EXTI_Line7 */
  EXTI_Line8,  /**< EXTI_Line8 */
  EXTI_Line9,  /**< EXTI_Line9 */
  EXTI_Line10, /**< EXTI_Line10 */
  EXTI_Line11, /**< EXTI_Line11 */
  EXTI_Line12, /**< EXTI_Line12 */
  EXTI_Line13, /**< EXTI_Line13 */
  EXTI_Line14, /**< EXTI_Line14 */
  EXTI_Line15, /**< EXTI_Line15 */
  EXTI_Line16, /**< EXTI_Line16 */
  EXTI_Line17, /**< EXTI_Line17 */
  EXTI_Line18, /**< EXTI_Line18 */
  EXTI_Line19, /**< EXTI_Line19 */
  EXTI_Line20, /**< EXTI_Line20 */
  EXTI_Line21, /**< EXTI_Line21 */
  EXTI_Line22  /**< EXTI_Line22 */

}EXTI_Lines_t;

/**
 * @brief : this enum to carry PORT OPTIONS FROM PORTA TO PORTH
 */
typedef enum
{
	EXTI_PORTA=0,/**< EXTI_PORTA */
	EXTI_PORTB,  /**< EXTI_PORTB */
	EXTI_PORTC,  /**< EXTI_PORTC */
	EXTI_PORTD,  /**< EXTI_PORTD */
	EXTI_PORTE,  /**< EXTI_PORTE */
	EXTI_PORTF,  /**< EXTI_PORTF */
	EXTI_PORTG,  /**< EXTI_PORTG */
	EXTI_PORTH,  /**< EXTI_PORTH */
}EXTI_PORT_t;

/**
 * @brief: This function to Set EXTI port
 * @param[in] Copy_EnumEXTI_Line : this enum to carry options of EXTI lines options from line 0 to line 22 totally 23 EXTI_lines
 * @param[in] Copy_EnumEXTI_PORT : this enum to carry options FROM PORTA TO PORTH
 * @return Local_u8ErrorState : this variable to carry ErrorState value
 */
uint8_t SYSCFG_u8SetEXTIPort(EXTI_Lines_t Copy_EnumEXTI_Line , EXTI_PORT_t Copy_EnumEXTI_PORT );

#endif /* SYSCFG_INTERFACE_H_ */
