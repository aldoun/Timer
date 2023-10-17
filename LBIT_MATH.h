
/*
 * Name: LSTD_TYPES.h
 * Author: Mahmoud Adel
 * Description: This file contains the bit mathematical operations
 * version: v1.0
 * */

/*Header file guard*/
#ifndef LBIT_MATH_H_
#define LBIT_MATH_H_

/************************************************************************************************/
/*                                    Bit math operations                                       */
/************************************************************************************************/

/*Setting a specific register bit to 1*/
#define SET_BIT(REG, BIT)       REG |= (1 << BIT)

/*Setting a specific register bit to 0*/
#define CLEAR_BIT(REG, BIT)     REG &= ~(1 << BIT)

/*Toggling a specific register bit*/
#define TOGGLE_BIT(REG, BIT)    REG ^= (1 << BIT)

/*Getting a specific register bit value*/
#define GET_BIT(REG, BIT)       ((REG >> BIT) & 1)

#endif /* LBIT_MATH_H_ */
