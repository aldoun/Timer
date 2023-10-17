/*
 * Name: MDIO_private.h
 * Author: Ahmed Ashraf
 * Description: This file contains private information of DIO module
 * Version: v1.0
 * */

/*Header file guard*/
#ifndef MDIO_PRIVATE_H_
#define MDIO_PRIVATE_H_

/************************************************************************************************/
/*                                        DIO registers                                         */
/************************************************************************************************/

/*PORTA registers*/
#define MDIO_PORTA            (*(volatile u8_t*)(0x3B))
#define MDIO_DDRA             (*(volatile u8_t*)(0x3A))
#define MDIO_PINA             (*(volatile u8_t*)(0x39))

/*PORTB registers*/
#define MDIO_PORTB            (*(volatile u8_t*)(0x38))
#define MDIO_DDRB             (*(volatile u8_t*)(0x37))
#define MDIO_PINB             (*(volatile u8_t*)(0x36))

/*PORTC registers*/
#define MDIO_PORTC            (*(volatile u8_t*)(0x35))
#define MDIO_DDRC             (*(volatile u8_t*)(0x34))
#define MDIO_PINC             (*(volatile u8_t*)(0x33))

/*PORTD registers*/
#define MDIO_PORTD            (*(volatile u8_t*)(0x32))
#define MDIO_DDRD             (*(volatile u8_t*)(0x31))
#define MDIO_PIND             (*(volatile u8_t*)(0x30))

#endif /* MDIO_PRIVATE_H_ */
