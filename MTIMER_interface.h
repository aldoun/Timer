/*
 * Name: MTIMER_interface.h
 * Author: Ahmed Ashraf
 * Description: This file contains interfacing information of TIMER module
 * Version: v1.0
 * */

/*Header file guard*/
#ifndef MTIMER_INTERFACE_H_
#define MTIMER_INTERFACE_H_

/************************************************************************************************/
/*                                        Interfacing macros                                    */
/************************************************************************************************/

/*Timer channels*/
#define TIMER_CHANNEL_0      (0)
#define TIMER_CHANNEL_1      (1)
#define TIMER_CHANNEL_2      (2)

/*Stop timer*/
#define TIMER_PRE_STOP       (0xF8)

/*Timer pre-scalers*/
#define TIMER_PRESCALER_1    (1)
#define TIMER_PRESCALER_8    (2)
#define TIMER_PRESCALER_64   (3)
#define TIMER_PRESCALER_256  (4)
#define TIMER_PRESCALER_1024 (5)

/*Fast PWM frequencies*/
#define TIMER_FREQ_31_25KHZ  (TIMER_PRESCALER_1)
#define TIMER_FREQ_3_9KHZ    (TIMER_PRESCALER_8)
#define TIMER_FREQ_500HZ     (TIMER_PRESCALER_64)
#define TIMER_FREQ_122HZ     (TIMER_PRESCALER_256)
#define TIMER_FREQ_30HZ      (TIMER_PRESCALER_1024)

/*Phase correct frequencies*/
#define PHASE_CORRECT_OFFSET (10)
#define TIMER_FREQ_15_6KHZ   (TIMER_PRESCALER_1 + PHASE_CORRECT_OFFSET)
#define TIMER_FREQ_2KHZ      (TIMER_PRESCALER_8 + PHASE_CORRECT_OFFSET)
#define TIMER_FREQ_250HZ     (TIMER_PRESCALER_64 + PHASE_CORRECT_OFFSET)
#define TIMER_FREQ_61HZ      (TIMER_PRESCALER_256 + PHASE_CORRECT_OFFSET)
#define TIMER_FREQ_15HZ      (TIMER_PRESCALER_1024 + PHASE_CORRECT_OFFSET)

/*Custom PWM channels*/
#define TIMER_PWM_CHANNEL_A  (0)
#define TIMER_PWM_CHANNEL_B  (1)

/************************************************************************************************/
/*                                        Functions' prototypes                                 */
/************************************************************************************************/

/*This function is used to initialize a specific timer channel in delay mode*/
void mtimer_delayInit(u8_t au8_channel);

/*This function is used to initialize a specific PWM signal with specific frequency*/
void mtimer_pwmInit(u8_t au8_channel, u8_t au8_frequency);

/*This function is used to generate custom frequency PWM signal*/
void mtimer_customFreqPWMInit(u16_t au16_periodicTime_us);

/*This function is used to initialize input capture unit (ICU)*/
void mtimer_pwmCaptureInit(void);

/*This function is used to generate delay period in milliseconds (Synchronous mode)*/
void mtimer_delayMs_sync(u8_t au8_channel, u32_t au32_delayPeriodMs);

/*This function is used to generate delay period in milliseconds (Asynchronous mode)*/
void mtimer_delayMs_async(u8_t au8_channel, u32_t au32_delayPeriodMs, void(*pfunc)(void));

/*This function is used to run a specific PWM signal with chosen duty cycle over a specific channel*/
void mtimer_pwmRun(u8_t au8_channel, u8_t au8_dutyCycle);

/*This function is used to run custom frequency PWM signal with 16-bits duty cycle at specific channel [A or B]*/
void mtimer_customFreqPWMRun(u8_t au8_customPWMChannel, u16_t au16_dutyCycle);

/*This function is used to stop the PWM signal generation*/
void mtimer_pwmStop(u8_t au8_channel);

/*This function is used to calculate the duty cycle and frequency of a PWM signal*/
void mtimer_pwmCatch(u32_t* pu32_dutyCycle, u32_t* pu32_frequency);

#endif /* MTIMER_INTERFACE_H_ */
