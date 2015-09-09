
/********** OutPut.Cpp ***********/

#include "Output.h"


OUT::OUT(char reg, char port, bool fStartHigh)
{
	m_bit = (1<<port);
	m_valid = true;
	
	switch (reg)
	{
	case 'b':
	case 'B':	DDRB |= m_bit; m_preg = &PORTB;	break;
	case 'c':
	case 'C':	DDRC |= m_bit; m_preg = &PORTC;	break;
	case 'd':
	case 'D':	DDRD |= m_bit; m_preg = &PORTD;	break;
	default: m_valid=false;
	}
	
	/* set initial state */
	Set(fStartHigh);
}

/* set output high */
void OUT::SetHigh()
{
	Set(true);
}

/* set output low */
void OUT::SetLow()
{
	Set(false);
}

/* toggle output */
void OUT::Toggle()
{
	if(m_valid)
	{
		*m_preg ^= m_bit;
	}
}

void OUT::Set(bool high)
{
	if(m_valid)
	{
		if (high)
			*m_preg |= m_bit;
		else
			*m_preg &= ~m_bit;
	}
}


