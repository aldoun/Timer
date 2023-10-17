#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"
#include "MDIO_interface.h"
#include "MTIMER_interface.h"

#define F_CPU 8000000UL
#include "util/delay.h"


int main(void)
{
	mdio_setPinStatus(PORTD, PIN5, OUTPUT);

	mtimer_customFreqPWMInit(20000);

    while(1)
    {
    	mtimer_customFreqPWMRun(TIMER_PWM_CHANNEL_A, 500);
    	_delay_ms(1000);
    	mtimer_customFreqPWMRun(TIMER_PWM_CHANNEL_A, 750);
		_delay_ms(1000);
		mtimer_customFreqPWMRun(TIMER_PWM_CHANNEL_A, 1000);
		_delay_ms(1000);
    }

	return 0;
}

