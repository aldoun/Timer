/*
 * Name: MWDT.h
 * Author: Ahmed Ashraf
 * Description: This file contains interfacing information of WDT module
 * Version: v1.0
 * */

/*Header file guard*/
#ifndef MWDT_H_
#define MWDT_H_

/************************************************************************************************/
/*                                           WDT Register                                       */
/************************************************************************************************/

#define MWDT_WDTCR      	 (*(volatile u8_t*)(0x41))

/************************************************************************************************/
/*                                        WDT Register bits                                     */
/************************************************************************************************/

#define WDTCR_WDTOE          (4)
#define WDTCR_WDE            (3)

/************************************************************************************************/
/*                                          WDT Timing                                          */
/************************************************************************************************/

#define WDT_TIMING_16_3_MS   (0)
#define WDT_TIMING_32_5_MS   (1)
#define WDT_TIMING_65_MS     (2)
#define WDT_TIMING_0_13_S    (3)
#define WDT_TIMING_0_26_S    (4)
#define WDT_TIMING_0_52_S    (5)
#define WDT_TIMING_1_S       (6)
#define WDT_TIMING_2_1_S     (7)

/************************************************************************************************/
/*                                         WDT Operations                                       */
/************************************************************************************************/

/*This function is used to start WDT operation*/
#define WDT_START(TIMING)    MWDT_WDTCR = (1 << WDTCR_WDE) | TIMING

/*This function is used to stop the WDT operation*/
#define WDT_STOP()      	 do  \
							 {   \
							 	 MWDT_WDTCR |= (1 << WDTCR_WDTOE) | (1 << WDTCR_WDE);  \
							 	 MWDT_WDTCR = 0; \
							 	 asm("wdr"); \
							 }while(0)

/*This function is used to refresh the WDT operation*/
#define WDT_REFRESH()        asm("wdr")

#endif /* MWDT_H_ */
