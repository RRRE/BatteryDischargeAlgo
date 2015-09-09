
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>                           /* for ADC sleep mode */
#include <math.h>
//#include "adc.h"
//#include "Output.h"


/* Define CPU frequency in Mhz here if not defined in Makefile */
#ifndef F_CPU
	#define F_CPU 8000000UL
#endif
