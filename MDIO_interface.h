/*
 * Name: MDIO_interface.h
 * Author: Ahmed Ashraf
 * Description: This file contains interfacing information of DIO module
 * Version: v1.0
 * */

/*Header file guard*/
#ifndef MDIO_INTERFACE_H_
#define MDIO_INTERFACE_H_

/************************************************************************************************/
/*                                        Interfacing macros                                    */
/************************************************************************************************/

/*DIO Ports*/
#define PORTA        (0)
#define PORTB        (1)
#define PORTC        (2)
#define PORTD        (3)

/*DIO Pins*/
#define PIN0         (0b00000001)
#define PIN1         (0b00000010)
#define PIN2         (0b00000100)
#define PIN3         (0b00001000)
#define PIN4         (0b00010000)
#define PIN5         (0b00100000)
#define PIN6         (0b01000000)
#define PIN7         (0b10000000)

/*DIO Pins' status*/
#define OUTPUT       (0)
#define INPUT_PULLUP (1)
#define INPUT_FLOAT  (2)

/*DIO Output pins' value*/
#define LOW          (0)
#define HIGH         (1)

/************************************************************************************************/
/*                                        Functions' prototypes                                 */
/************************************************************************************************/

/*This function is responsible for setting a specific status [OUTPUT - INPUT_FLOAT - INPUT_PULLUP] to a specific port pin*/
void mdio_setPinStatus(u8_t au8_port, u8_t au8_pin, u8_t au8_status);

/*This function is responsible for setting a specific value [HIGH - LOW] to a specific port pin*/
void mdio_setPinValue(u8_t au8_port, u8_t au8_pin, u8_t au8_value);

/*This function is responsible for toggling a specific port pin value [HIGH -> LOW, LOW -> HIGH]*/
void mdio_togglePinValue(u8_t au8_port, u8_t au8_pin);

/*This function is responsible for getting a specific port pin value [HIGH - LOW]*/
u8_t mdio_getPinValue(u8_t au8_port, u8_t au8_pin);

#endif /* MDIO_INTERFACE_H_ */
