

#include "HUtils/iustring.h"
#include "la_sdigit.h"

long LSDigitLeapes[ LSDigitStates * LSDigitAlphabet ] = {
//  d  e  .  +  -  _
	3, 0, 4, 2, 2, 0,
	3, 0, 4, 0, 0, 0,
	3, 6, 5, 0, 0, 3,
	5, 0, 0, 0, 0, 0,
	5, 6, 0, 0, 0, 5,
	9, 0, 0, 7, 8, 0,
	9, 0, 0, 0, 0, 0,
	9, 0, 0, 0, 0, 0,
	9, 0, 0, 0, 0, 9
};

long LSDigitsEndStates[ LSDigitStates ] =
{
	0, 0, LSDigit::Integer, 0, LSDigit::Float,
	0, 0, 0, LSDigit::FloatIEEE
};

long LSDigit::What( const QChar S )
//            ~~~~
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

void LSDigit::Deeds( void )
//            ~~~~~
{
	switch( CurrentState )
	{
	case 1 :
		asign = 1;
		pre_int = mnt_int = 0;
		is_big = 0;
		break;
	case 2 :
		if( character == _T('-') )
			asign = -1;
		break;
	case 3 :
		if( character != _T('_') )
		{
			mnt_int = 10 * mnt_int + character.digitValue();
			if(mnt_int < pre_int)
				is_big = 1;
			else
				pre_int = mnt_int;
		}
		break;
	case 4 :
		mnt_float = mnt_int;
		power = 0;
		break;
	case 5 :
		if( GetPreviousState() == 3 )
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
	case 6 :
		if( GetPreviousState() == 3 )
		{
			mnt_float = mnt_int;
			power = 0;
		}
		powerE = 0;
		sign = 1;
		break;
		//  case 7 :
		//    break;
	case 8 :
		sign = -1;
		break;
	case 9 :
		if( character != _T('_') )
			powerE = 10 * powerE + character.digitValue();
		break;
	}
}

LSDigit::LSDigit( void )
//      ~~~~~~
: LAuto( LSDigitStates, LSDigitAlphabet, LSDigitLeapes, LSDigitsEndStates )
{
	sign = asign = 1;
	is_big = 0;
	decimal = 0;
}
