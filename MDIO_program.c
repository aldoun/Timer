/*
 * Name: MDIO_program.c
 * Author: Ahmed Ashraf
 * Description: This file contains logical implementation of DIO module
 * Version: v1.0
 * */

/************************************************************************************************/
/*                                             Includes                                         */
/************************************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_private.h"
#include "MDIO_interface.h"

/************************************************************************************************/
/*                                        Functions' definitions                                */
/************************************************************************************************/

void mdio_setPinStatus(u8_t au8_port, u8_t au8_pin, u8_t au8_status)
{
	/*Switching over DIO Ports*/
	switch(au8_port)
	{
		/*In case of choosing PORTA*/
		case PORTA:

			/*Switching over port status*/
			switch(au8_status)
			{
				/*In case of output*/
				case OUTPUT:

					/*Set the selected pins to output*/
					MDIO_DDRA |= au8_pin;

					/*Break from this case*/
					break;

				/*In case of input floating*/
				case INPUT_FLOAT:

					/*Set the selected pins to input floating*/
					MDIO_DDRA &= ~au8_pin;

					/*Break from this case*/
					break;


				/*In case of input pull-up*/
				case INPUT_PULLUP:

					/*Set the selected pins to input floating*/
					MDIO_DDRA &= ~au8_pin;

					/*Activating the pull-up resistor*/
					MDIO_PORTA |= au8_pin;

					/*Break from this case*/
					break;

				/*In case of default case*/
				default:

					/*Do nothing*/

					/*Break from this case*/
					break;
			}

			/*Break from this case*/
			break;


		/*In case of choosing PORTB*/
		case PORTB:

			/*Switching over port status*/
			switch(au8_status)
			{
				/*In case of output*/
				case OUTPUT:

					/*Set the selected pins to output*/
					MDIO_DDRB |= au8_pin;

					/*Break from this case*/
					break;

				/*In case of input floating*/
				case INPUT_FLOAT:

					/*Set the selected pins to input floating*/
					MDIO_DDRB &= ~au8_pin;

					/*Break from this case*/
					break;


				/*In case of input pull-up*/
				case INPUT_PULLUP:

					/*Set the selected pins to input floating*/
					MDIO_DDRB &= ~au8_pin;

					/*Activating the pull-up resistor*/
					MDIO_PORTB |= au8_pin;

					/*Break from this case*/
					break;

				/*In case of default case*/
				default:

					/*Do nothing*/

					/*Break from this case*/
					break;
			}

			/*Break from this case*/
			break;


		/*In case of choosing PORTC*/
		case PORTC:

			/*Switching over port status*/
			switch(au8_status)
			{
				/*In case of output*/
				case OUTPUT:

					/*Set the selected pins to output*/
					MDIO_DDRC |= au8_pin;

					/*Break from this case*/
					break;

				/*In case of input floating*/
				case INPUT_FLOAT:

					/*Set the selected pins to input floating*/
					MDIO_DDRC &= ~au8_pin;

					/*Break from this case*/
					break;


				/*In case of input pull-up*/
				case INPUT_PULLUP:

					/*Set the selected pins to input floating*/
					MDIO_DDRC &= ~au8_pin;

					/*Activating the pull-up resistor*/
					MDIO_PORTC |= au8_pin;

					/*Break from this case*/
					break;

				/*In case of default case*/
				default:

					/*Do nothing*/

					/*Break from this case*/
					break;
			}

			/*Break from this case*/
			break;

		/*In case of choosing PORTD*/
		case PORTD:

			/*Switching over port status*/
			switch(au8_status)
			{
				/*In case of output*/
				case OUTPUT:

					/*Set the selected pins to output*/
					MDIO_DDRD |= au8_pin;

					/*Break from this case*/
					break;

				/*In case of input floating*/
				case INPUT_FLOAT:

					/*Set the selected pins to input floating*/
					MDIO_DDRD &= ~au8_pin;

					/*Break from this case*/
					break;


				/*In case of input pull-up*/
				case INPUT_PULLUP:

					/*Set the selected pins to input floating*/
					MDIO_DDRD &= ~au8_pin;

					/*Activating the pull-up resistor*/
					MDIO_PORTD |= au8_pin;

					/*Break from this case*/
					break;

				/*In case of default case*/
				default:

					/*Do nothing*/

					/*Break from this case*/
					break;
			}

			/*Break from this case*/
			break;

		/*In case of default case*/
		default:

			/*Do nothing*/

			/*Break from this case*/
			break;
	}


	/*Return from this function*/
	return;
}

void mdio_setPinValue(u8_t au8_port, u8_t au8_pin, u8_t au8_value)
{
	/*Switching over DIO Ports*/
	switch(au8_port)
	{
		/*In case of choosing PORTA*/
		case PORTA:

			/*Switching over port pin value*/
			switch(au8_value)
			{
				/*In case of high*/
				case HIGH:

					/*Set the selected pins to high*/
					MDIO_PORTA |= au8_pin;

					/*Break from this case*/
					break;

				/*In case of low*/
				case LOW:

					/*Set the selected pins to low*/
					MDIO_PORTA &= ~au8_pin;

					/*Break from this case*/
					break;

				/*In case of default case*/
				default:

					/*Do nothing*/

					/*Break from this case*/
					break;
			}

			/*Break from this case*/
			break;

		/*In case of choosing PORTB*/
		case PORTB:

			/*Switching over port pin value*/
			switch(au8_value)
			{
				/*In case of high*/
				case HIGH:

					/*Set the selected pins to high*/
					MDIO_PORTB |= au8_pin;

					/*Break from this case*/
					break;

				/*In case of low*/
				case LOW:

					/*Set the selected pins to low*/
					MDIO_PORTB &= ~au8_pin;

					/*Break from this case*/
					break;

				/*In case of default case*/
				default:

					/*Do nothing*/

					/*Break from this case*/
					break;
			}

			/*Break from this case*/
			break;

		/*In case of choosing PORTC*/
		case PORTC:

			/*Switching over port pin value*/
			switch(au8_value)
			{
				/*In case of high*/
				case HIGH:

					/*Set the selected pins to high*/
					MDIO_PORTC |= au8_pin;

					/*Break from this case*/
					break;

				/*In case of low*/
				case LOW:

					/*Set the selected pins to low*/
					MDIO_PORTC &= ~au8_pin;

					/*Break from this case*/
					break;

				/*In case of default case*/
				default:

					/*Do nothing*/

					/*Break from this case*/
					break;
			}

			/*Break from this case*/
			break;

		/*In case of choosing PORTD*/
		case PORTD:

			/*Switching over port pin value*/
			switch(au8_value)
			{
				/*In case of high*/
				case HIGH:

					/*Set the selected pins to high*/
					MDIO_PORTD |= au8_pin;

					/*Break from this case*/
					break;

				/*In case of low*/
				case LOW:

					/*Set the selected pins to low*/
					MDIO_PORTD &= ~au8_pin;

					/*Break from this case*/
					break;

				/*In case of default case*/
				default:

					/*Do nothing*/

					/*Break from this case*/
					break;
			}

			/*Break from this case*/
			break;

		/*In case of default case*/
		default:

			/*Do nothing*/

			/*Break from this case*/
			break;
	}

	/*Return from this function*/
	return;
}

void mdio_togglePinValue(u8_t au8_port, u8_t au8_pin)
{
	/*Switching over DIO Ports*/
	switch(au8_port)
	{
		/*In case of choosing PORTA*/
		case PORTA:

			/*Toggling the selected pins*/
			MDIO_PORTA ^= au8_pin;

			/*Break from this case*/
			break;

		/*In case of choosing PORTB*/
		case PORTB:

			/*Toggling the selected pins*/
			MDIO_PORTB ^= au8_pin;

			/*Break from this case*/
			break;

		/*In case of choosing PORTC*/
		case PORTC:

			/*Toggling the selected pins*/
			MDIO_PORTC ^= au8_pin;

			/*Break from this case*/
			break;

		/*In case of choosing PORTD*/
		case PORTD:

			/*Toggling the selected pins*/
			MDIO_PORTD ^= au8_pin;

			/*Break from this case*/
			break;
	}

	/*Return from this function*/
	return;
}


u8_t mdio_getPinValue(u8_t au8_port, u8_t au8_pin)
{
	/*Local variable used to get the selected pin value*/
	u8_t au8_pinValue = 0;

	/*Switching over DIO Ports*/
	switch(au8_port)
	{
		/*In case of choosing PORTA*/
		case PORTA:

			/*Checking the pin value*/
			if( MDIO_PINA & au8_pin )
			{
				/*Setting the pin value to high*/
				au8_pinValue = HIGH;
			}
			else
			{
				/*Setting the pin value to low*/
				au8_pinValue = LOW;
			}

			/*Break from this case*/
			break;

		/*In case of choosing PORTB*/
		case PORTB:

			/*Checking the pin value*/
			if( MDIO_PINB & au8_pin )
			{
				/*Setting the pin value to high*/
				au8_pinValue = HIGH;
			}
			else
			{
				/*Setting the pin value to low*/
				au8_pinValue = LOW;
			}

			/*Break from this case*/
			break;

		/*In case of choosing PORTC*/
		case PORTC:

			/*Checking the pin value*/
			if( MDIO_PINC & au8_pin )
			{
				/*Setting the pin value to high*/
				au8_pinValue = HIGH;
			}
			else
			{
				/*Setting the pin value to low*/
				au8_pinValue = LOW;
			}

			/*Break from this case*/
			break;

		/*In case of choosing PORTD*/
		case PORTD:

			/*Checking the pin value*/
			if( MDIO_PIND & au8_pin )
			{
				/*Setting the pin value to high*/
				au8_pinValue = HIGH;
			}
			else
			{
				/*Setting the pin value to low*/
				au8_pinValue = LOW;
			}

			/*Break from this case*/
			break;
	}


	/*Return the selected pin value*/
	return au8_pinValue;
}
