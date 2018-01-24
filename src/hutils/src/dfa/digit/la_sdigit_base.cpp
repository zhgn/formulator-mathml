

#include "HUtils/iustring.h"
#include "la_sdigit_base.h"

long LSDigitBaseLeapes[ LSDigitBaseStates * LSDigitBaseAlphabet ] = {
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

long LSDigitBasesEndStates[ LSDigitBaseStates ] =
{
	0, 0, LSDigitBase::Integer, 0, LSDigitBase::Float,
	0, 0, 0, LSDigitBase::FloatIEEE
};

long LSDigitBase::What( const QChar S )
//            ~~~~
{
	for(;;)
	{
		if( _isalnum( S.toLatin1() ) )
		{
			long val = hex2dec( S );
			return (val < 0 || val >= base) ? 0 : 1;
		}
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

void LSDigitBase::Deeds( void )
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
			mnt_int = base * mnt_int + hex2dec( character );
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
				mnt_float = base * mnt_float + hex2dec( character );
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
			powerE = base * powerE + hex2dec( character );
		break;
	}
}

LSDigitBase::LSDigitBase( short int _base )
//      ~~~~~~
: LAuto( LSDigitBaseStates, LSDigitBaseAlphabet, LSDigitBaseLeapes, LSDigitBasesEndStates )
{
	sign = asign = 1;
	is_big = 0;
	decimal = 0;
	base = (_base >= 2 && _base <= 36) ? _base : 10;
}
