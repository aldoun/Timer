/*
 * Name: MTIMER_private.h
 * Author: Ahmed Ashraf
 * Description: This file contains private information of TIMER module
 * Version: v1.0
 * */

/*Header file guard*/
#ifndef MTIMER_PRIVATE_H_
#define MTIMER_PRIVATE_H_

/************************************************************************************************/
/*                                        Timer registers                                       */
/************************************************************************************************/

/*Status register*/
#define SREG                       (*(volatile u8_t*)(0x5F))

/*General timer registers*/
#define MTIMER_TIMSK               (*(volatile u8_t*)(0x59))
#define MTIMER_TIFR                (*(volatile u8_t*)(0x58))

/*Timer0 registers*/
#define MTIMER_OCR0           	   (*(volatile u8_t*)(0x5C))
#define MTIMER_TCCR0           	   (*(volatile u8_t*)(0x53))
#define MTIMER_TCNT0           	   (*(volatile u8_t*)(0x52))

/*Timer1 registers*/
#define MTIMER_TCCR1               (*(volatile u16_t*)(0x4E))
#define MTIMER_TCNT1               (*(volatile u16_t*)(0x4C))
#define MTIMER_OCR1A               (*(volatile u16_t*)(0x4A))
#define MTIMER_OCR1B               (*(volatile u16_t*)(0x48))
#define MTIMER_ICR1                (*(volatile u16_t*)(0x46))



#endif /* MTIMER_PRIVATE_H_ */
