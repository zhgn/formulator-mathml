

#include "HUtils/iustring.h"
#include "la_str.h"

long LStringLeapes[ LStringStates * LStringAlphabet ] = {
	//         "  \  D  A ...
	2, 0, 0, 0, 0,
	7, 3, 0, 0, 2,
	2, 2, 4, 0, 2,
	0, 0, 0, 2, 0,
	0, 0, 0, 6, 0,
	2, 0, 5, 0, 0,
	2, 0, 5, 0, 0
};

long LStringsEndStates[ LStringStates ] = {
	0, 0, 0, 0, 0, LString::String, LString::String
};

long LString::What( const QChar S )
//                ~~~~
{
	for(;;)
	{
		if( S == quat ) return 1;
		if( S == _T('\\') ) return 2;
		if( S == _T('\x0D') ) return 3;
		if( S == _T('\x0A') ) return 4;
		if( S.isPrint() ) return 5;
		return 0;
	}
}

void LString::Deeds( void )
//            ~~~~~
{
	switch( CurrentState )
	{
	case 1:
		read_string = _T("");
		break;
	case 2:
		if( PrevState == 2 ) read_string += character;
		else if( PrevState == 3 )
			switch( character.toLatin1() )
			{
			case _T('n'):
				read_string += _T("\n");
				break;
			case _T('r'):
				read_string += _T("\r");
				break;
			case _T('t'):
				read_string += _T("\t");
				break;
			case _T('v'):
				read_string += _T("\v");
				break;
			case _T('b'):
				read_string += _T("\b");
				break;
			case _T('a'):
				read_string += _T("\a");
				break;
			case _T('\\'):
				read_string += _T("\\");
				break;
			default:
				read_string += character;
			}
		break;
	case 3:
		break;
	}
}

LString::LString( QChar _quat )
//       ~~~~~~~
: LAuto( LStringStates, LStringAlphabet, LStringLeapes, LStringsEndStates )
{
	quat = _quat;
}
