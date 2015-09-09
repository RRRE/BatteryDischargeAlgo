/*	Output.h
*
*	Declarations for classes that handle digital output.
*
*/

#ifndef _OUTPUT_H_
#define _OUTPUT_H_

#include <avr/io.h>

class OUT
{

	protected:
		bool m_valid;
		unsigned char m_bit;
		volatile uint8_t *m_preg;

	public:
	/* constructor for setting the register ('A', 'B', etc),
	   port (0-7), and initial state (low/high output) */
		OUT(char reg, char port, bool fStartHigh=false);
	
		void Set(bool);     // set high if true, low if false
		void SetHigh();			 // set output high
		void SetLow();			 // set output low
		void Toggle();			 // toggle output

		inline unsigned char GetBit() {return m_bit;};
		inline bool IsValid() {return m_valid;};

		~OUT(){}
};

#endif
