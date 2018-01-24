

#include "HUtils/iustring.h"
#include "la_digit.h"

long LDigitLeapes[ LDigitStates * LDigitAlphabet ] =
{
//  d  e  .  +  -  _
	2, 0, 3, 0, 0, 0,
	2, 5, 4, 0, 0, 2,
	4, 0, 0, 0, 0, 0,
	4, 5, 0, 0, 0, 4,
	8, 0, 0, 6, 7, 0,
	8, 0, 0, 0, 0, 0,
	8, 0, 0, 0, 0, 0,
	8, 0, 0, 0, 0, 8
};

long LDigitsEndStates[ LDigitStates ] =
{
	0, LDigit::Integer, 0, LDigit::Float,
	0, 0, 0, LDigit::FloatIEEE
};

long LDigit::What( const QChar S )
//           ~~~~
{
	for(;;)
	{
		if( S.isDigit() )
			return 1;
		if( ( S == _T('E') ) || ( S == _T('e') ) )
			return 2;
		if( S == _T('.') )
			return 3;
		if( S == _T('+') )
			return 4;
		if( S == _T('-') )
			return 5;
		if( S == _T('_') )
			return 6;
		return 0;
	}
}

void LDigit::Deeds( void )
//           ~~~~~
{
	switch( CurrentState )
	{
	case 1:
		pre_int = mnt_int = 0;
		is_big = 0;
		break;
	case 2:
		if( character != _T('_') )
		{
			mnt_int = 10 * mnt_int + character.digitValue();
			if(mnt_int < pre_int)
				is_big = 1;
			else
				pre_int = mnt_int;
		}
		break;
	case 3 :
		mnt_float = mnt_int;
		power = 0;
		break;
	case 4 :
		if( GetPreviousState() == 2 )
		{
			mnt_float = mnt_int;
			power = 0;
		}
		else
		{
			if( character != _T('_') )
			{
				decimal++;
				mnt_float = 10 * mnt_float + character.digitValue();
				power--;
			}
		}
		break;
	case 5 :
		if( GetPreviousState() == 2 )
		{
			mnt_float = mnt_int;
			power = 0;
		}
		powerE = 0;
		sign = 1;
		break;
		//  case 6 :
		//    break;
	case 7 :
		sign = -1;
		break;
	case 8 :
		if( character != _T('_') )
			powerE = 10 * powerE + character.digitValue();
		break;
	}
}

LDigit::LDigit( void )
//      ~~~~~~
: LAuto( LDigitStates, LDigitAlphabet, LDigitLeapes, LDigitsEndStates )
{
	is_big = 0;
	decimal = 0;
}
