/*
 * Name: MTIMER_program.c
 * Author: Ahmed Ashraf
 * Description: This file contains logical implementation of TIMER module
 * Version: v1.0
 * */

/************************************************************************************************/
/*                                             Includes                                         */
/************************************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MTIMER_private.h"
#include "MTIMER_interface.h"

/************************************************************************************************/
/*                                      Important global variables                              */
/************************************************************************************************/

/*Global variable used to carry pre-scaler value of timer0*/
static u8_t gu8_timer0_prescaler;

/*Global variable used to carry pre-scaler value of timer1*/
static u8_t gu8_timer1_prescaler;

/*Global variable used to carry pre-scaler value of timer2*/
static u8_t gu8_timer2_prescaler;

/*Global variable used to save delay period in asynchronous operation for timer0*/
static u32_t gu32_timer0_delayPeriod;

/*Global variable used to save delay period in asynchronous operation for timer1*/
static u32_t gu32_timer1_delayPeriod;

/*Global variable used to save delay period in asynchronous operation for timer2*/
static u32_t gu32_timer2_delayPeriod;

/*Global pointer to function used to process timer0 callback function*/
static void(*gpfunc_timer0_isr)(void) = NULL;

/*Global pointer to function used to process timer1 callback function*/
static void(*gpfunc_timer1_isr)(void) = NULL;

/*Global pointer to function used to process timer2 callback function*/
static void(*gpfunc_timer2_isr)(void) = NULL;

/************************************************************************************************/
/*                                        Functions' definitions                                */
/************************************************************************************************/

static void mtimer_timerStart(u8_t au8_channel)
{
	/*Switching over timer channels*/
	switch(au8_channel)
	{
		/*In case of timer0 channel*/
		case TIMER_CHANNEL_0:

			/*Stopping timer0*/
			MTIMER_TCCR0 &= TIMER_PRE_STOP;

			/*Resetting timer/counter register*/
			MTIMER_TCNT0 = 0;

			/*Starting timer0*/
			MTIMER_TCCR0 |= gu8_timer0_prescaler;

			/*Breaking from this case*/
			break;

		/*In case of timer1 channel*/
		case TIMER_CHANNEL_1:

			/*Stopping timer1*/
			MTIMER_TCCR1 &= 0xFFF8;

			/*Resetting timer/counter register*/
			MTIMER_TCNT1 = 0;

			/*Starting timer1*/
			MTIMER_TCCR1 |= gu8_timer1_prescaler;

			/*Breaking from this case*/
			break;

		/*In case of timer2 channel*/
		case TIMER_CHANNEL_2:

			/*Breaking from this case*/
			break;

		/*In case of default*/
		default:

			/*Breaking from default case*/
			break;
	}

	/*Return from this function*/
	return;
}

static void mtimer_timerStop(u8_t au8_channel)
{
	/*Switching over timer channels*/
	switch(au8_channel)
	{
		/*In case of timer0 channel*/
		case TIMER_CHANNEL_0:

			/*Stopping timer0*/
			MTIMER_TCCR0 &= TIMER_PRE_STOP;

			/*Breaking from this case*/
			break;

		/*In case of timer1 channel*/
		case TIMER_CHANNEL_1:

			/*Stopping timer1*/
			MTIMER_TCCR1 &= 0xFFF8;

			/*Breaking from this case*/
			break;

		/*In case of timer2 channel*/
		case TIMER_CHANNEL_2:

			/*Breaking from this case*/
			break;

		/*In case of default*/
		default:

			/*Breaking from default case*/
			break;
	}

	/*Return from this function*/
	return;
}

void mtimer_delayInit(u8_t au8_channel)
{
	/*Switching over timer channels*/
	switch(au8_channel)
	{
		/*In case of timer0 channel*/
		case TIMER_CHANNEL_0:

			/*Setting the timer0 pre-scaler to be used in start timer function*/
			gu8_timer0_prescaler = TIMER_PRESCALER_64;

			/*Activation of CTC mode*/
			MTIMER_TCCR0 = 0x08;

			/*Setting OCR value to make a delay by 1ms at 64 pre-scaler and clock frequency 8MHz*/
			MTIMER_OCR0 = 125;

			/*Breaking from this case*/
			break;

		/*In case of timer1 channel*/
		case TIMER_CHANNEL_1:

			/*Setting the timer1 pre-scaler to be used in start timer function*/
			gu8_timer1_prescaler = TIMER_PRESCALER_64;

			/*Breaking from this case*/
			break;

		/*In case of timer2 channel*/
		case TIMER_CHANNEL_2:

			/*Setting the timer2 pre-scaler to be used in start timer function*/
			gu8_timer2_prescaler = TIMER_PRESCALER_64;

			/*Breaking from this case*/
			break;

		/*In case of default*/
		default:

			/*Breaking from default case*/
			break;
	}

	/*Return from this function*/
	return;
}

void mtimer_pwmInit(u8_t au8_channel, u8_t au8_frequency)
{
	/*Switching over timer channels*/
	switch(au8_channel)
	{
		/*In case of timer0 channel*/
		case TIMER_CHANNEL_0:

			/*Setting the timer0 pre-scaler to be used in start timer function*/
			gu8_timer0_prescaler = au8_frequency;

			/*Switching over frequency value*/
			switch(au8_frequency)
			{
				/*In case of choosing fast PWM*/
				case TIMER_FREQ_31_25KHZ ... TIMER_FREQ_30HZ:

					/*Choosing fast PWM mode with non-inversion*/
					MTIMER_TCCR0 = 0x68;

					/*Break from this case*/
					break;

				/*In case of choosing phase correct PWM*/
				case TIMER_FREQ_15_6KHZ ... TIMER_FREQ_15HZ:

					/*Removing the phase correct offset*/
					gu8_timer0_prescaler -= PHASE_CORRECT_OFFSET;

					/*Choosing phase correct PWM mode with non-inversion*/
					MTIMER_TCCR0 = 0x60;

					/*Break from this case*/
					break;

				/*In case of default*/
				default:

					/*Breaking from default case*/
					break;

			}

			/*Breaking from this case*/
			break;

		/*In case of timer1 channel*/
		case TIMER_CHANNEL_1:


			/*Breaking from this case*/
			break;

		/*In case of timer2 channel*/
		case TIMER_CHANNEL_2:


			/*Breaking from this case*/
			break;

		/*In case of default*/
		default:

			/*Breaking from default case*/
			break;
	}

	/*Return from this function*/
	return;
}

void mtimer_customFreqPWMInit(u16_t au16_periodicTime_us)
{
	/*Setting non-inversion mode in channel A and B, selecting phase correct PWM with top at ICR1 (mode 10)*/
	MTIMER_TCCR1 = 0xA210;

	/*Setting the periodic time of the signal*/
	MTIMER_ICR1 = au16_periodicTime_us / 2;

	/*Setting timer1 prescaler to get 1us tick*/
	gu8_timer1_prescaler = TIMER_PRESCALER_8;

	/*Return from this function*/
	return;
}

void mtimer_pwmCaptureInit(void)
{
	/*Enable normal mode and rising edge for ICU*/
	MTIMER_TCCR1 = 0x0040;

	/*Reset ICR register*/
	MTIMER_ICR1 = 0;

	/*Choosing prescaler 8 to provide 1us tick*/
	gu8_timer1_prescaler = TIMER_PRESCALER_8;

	/*Return from this function*/
	return;
}

void mtimer_delayMs_sync(u8_t au8_channel, u32_t au32_delayPeriodMs)
{
	/*Switching over timer channels*/
	switch(au8_channel)
	{
		/*In case of timer0 channel*/
		case TIMER_CHANNEL_0:

			/*Starting timer channel 0*/
			mtimer_timerStart(TIMER_CHANNEL_0);

			/*Looping over delay period*/
			while(au32_delayPeriodMs--)
			{
				/*Waiting until 1ms of delay passes*/
				while(!GET_BIT(MTIMER_TIFR, 1));

				/*CLearing compare match flag bit*/
				SET_BIT(MTIMER_TIFR, 1);
			}

			/*Stopping timer channel 0*/
			mtimer_timerStop(TIMER_CHANNEL_0);

			/*Breaking from this case*/
			break;

		/*In case of timer1 channel*/
		case TIMER_CHANNEL_1:

			/*Breaking from this case*/
			break;

		/*In case of timer2 channel*/
		case TIMER_CHANNEL_2:

			/*Breaking from this case*/
			break;

		/*In case of default*/
		default:

			/*Breaking from default case*/
			break;
	}


	/*Return from this function*/
	return;
}

void mtimer_delayMs_async(u8_t au8_channel, u32_t au32_delayPeriodMs, void(*pfunc)(void))
{
	/*Enable global interrupts*/
	SET_BIT(SREG, 7);

	/*Switching over timer channels*/
	switch(au8_channel)
	{
		/*In case of timer0 channel*/
		case TIMER_CHANNEL_0:

			/*Saving the delay period to check over it at the ISR*/
			gu32_timer0_delayPeriod = au32_delayPeriodMs;

			/*Setting the call back function address*/
			gpfunc_timer0_isr = pfunc;

			/*Enable compare match interrupt*/
			SET_BIT(MTIMER_TIMSK, 1);

			/*Starting timer channel 0*/
			mtimer_timerStart(TIMER_CHANNEL_0);

			/*Breaking from this case*/
			break;

		/*In case of timer1 channel*/
		case TIMER_CHANNEL_1:

			/*Saving the delay period to check over it at the ISR*/
			gu32_timer1_delayPeriod = au32_delayPeriodMs;

			/*Setting the call back function address*/
			gpfunc_timer1_isr = pfunc;

			/*Breaking from this case*/
			break;

		/*In case of timer2 channel*/
		case TIMER_CHANNEL_2:

			/*Saving the delay period to check over it at the ISR*/
			gu32_timer2_delayPeriod = au32_delayPeriodMs;

			/*Setting the call back function address*/
			gpfunc_timer2_isr = pfunc;

			/*Breaking from this case*/
			break;

		/*In case of default*/
		default:

			/*Breaking from default case*/
			break;
	}


	/*Return from this function*/
	return;
}

void mtimer_pwmRun(u8_t au8_channel, u8_t au8_dutyCycle)
{
	/*Switching over timer channels*/
	switch(au8_channel)
	{
		/*In case of timer0 channel*/
		case TIMER_CHANNEL_0:

			/*Setting the duty cycle*/
			MTIMER_OCR0 = au8_dutyCycle;

			/*Starting timer channel 0*/
			mtimer_timerStart(TIMER_CHANNEL_0);

			/*Breaking from this case*/
			break;

		/*In case of timer1 channel*/
		case TIMER_CHANNEL_1:

			/*Breaking from this case*/
			break;

		/*In case of timer2 channel*/
		case TIMER_CHANNEL_2:

			/*Breaking from this case*/
			break;

		/*In case of default*/
		default:

			/*Breaking from default case*/
			break;
	}

	/*Return from this function*/
	return;
}


void mtimer_pwmStop(u8_t au8_channel)
{
	/*Switching over timer channels*/
	switch(au8_channel)
	{
		/*In case of timer0 channel*/
		case TIMER_CHANNEL_0:

			/*Starting timer channel 0*/
			mtimer_timerStop(TIMER_CHANNEL_0);

			/*Breaking from this case*/
			break;

		/*In case of timer1 channel*/
		case TIMER_CHANNEL_1:

			/*Breaking from this case*/
			break;

		/*In case of timer2 channel*/
		case TIMER_CHANNEL_2:

			/*Breaking from this case*/
			break;

		/*In case of default*/
		default:

			/*Breaking from default case*/
			break;
	}

	/*Return from this function*/
	return;
}

void mtimer_customFreqPWMRun(u8_t au8_customPWMChannel, u16_t au16_dutyCycle)
{
	/*Switching over custom PWM channels*/
	switch(au8_customPWMChannel)
	{
		/*In case of choosing channel A*/
		case TIMER_PWM_CHANNEL_A:

			/*Setting the duty cycle*/
			MTIMER_OCR1A = au16_dutyCycle;

			/*Break from this case*/
			break;

		/*In case of choosing channel B*/
		case TIMER_PWM_CHANNEL_B:

			/*Setting the duty cycle*/
			MTIMER_OCR1B = au16_dutyCycle;

			/*Break from this case*/
			break;

		/*In case of default*/
		default:

			/*Breaking from default case*/
			break;
	}

	/*Starting timer1*/
	mtimer_timerStart(TIMER_CHANNEL_1);

	/*Return from this function*/
	return;
}

void mtimer_pwmCatch(u32_t* pu32_dutyCycle, u32_t* pu32_frequency)
{
	/*Local variables used to get time laps for duty cycle and frequency*/
	u16_t au16_timeLap1 = 0;
	u16_t au16_timeLap2 = 0;
	u16_t au16_timeLap3 = 0;

	/*Starting timer channel 1*/
	mtimer_timerStart(TIMER_CHANNEL_1);

	/*Polling over ICU flag*/
	while(!GET_BIT(MTIMER_TIFR, 5));

	/*Clearing ICU flag*/
	SET_BIT(MTIMER_TIFR, 5);

	/*Get the first time lap value*/
	au16_timeLap1 = MTIMER_ICR1;

	/*Enable falling edge ICU detection*/
	CLEAR_BIT(MTIMER_TCCR1, 6);

	/*Polling over ICU flag*/
	while(!GET_BIT(MTIMER_TIFR, 5));

	/*Clearing ICU flag*/
	SET_BIT(MTIMER_TIFR, 5);

	/*Get the second time lap value*/
	au16_timeLap2 = MTIMER_ICR1;

	/*Enable rising edge ICU detection*/
	SET_BIT(MTIMER_TCCR1, 6);

	/*Polling over ICU flag*/
	while(!GET_BIT(MTIMER_TIFR, 5));

	/*Clearing ICU flag*/
	SET_BIT(MTIMER_TIFR, 5);

	/*Get the third time lap value*/
	au16_timeLap3 = MTIMER_ICR1;

	/*Stop timer1*/
	mtimer_timerStop(TIMER_CHANNEL_1);

	/*Get the duty cycle in (%)*/
	*pu32_dutyCycle = ((au16_timeLap2 - au16_timeLap1) * 100) / (au16_timeLap3 - au16_timeLap1);

	/*Get the frequency in (Hz)*/
	*pu32_frequency = 1000000 / (au16_timeLap3 - au16_timeLap1);

	/*Return from this function*/
	return;
}

/************************************************************************************************/
/*                                              Timer ISRs                                      */
/************************************************************************************************/

/*Timer0 compare match interrupt service routine (ISR)*/
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	/*Checking if the call back pointer has an address of function or not*/
	if(gpfunc_timer0_isr != NULL)
	{
		/*Checking if the delay period has passed or not*/
		if(gu32_timer0_delayPeriod)
		{
			/*Decrementing delay period*/
			gu32_timer0_delayPeriod--;
		}
		else
		{
			/*Executing the call back function*/
			gpfunc_timer0_isr();

			/*Disable the compare match interrupt*/
			CLEAR_BIT(MTIMER_TIMSK, 1);

			/*Stopping the timer*/
			mtimer_timerStop(TIMER_CHANNEL_0);
		}
	}
	else
	{
		/*Do nothing*/
	}
}
