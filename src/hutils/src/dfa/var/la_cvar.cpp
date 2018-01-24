

#include "HUtils/iustring.h"
#include "la_cvar.h"

long LCVarLeapes[ LCVarStates * LCVarAlphabet ] =
{
//  l  d  
	2, 0, 
	2, 2 
};

long LCVarsEndStates[ LCVarStates ] =
{
	0, 1
};

long LCVar::What( const QChar S )
//          ~~~~
{
	for(;;)
	{
		if( S.isLetter() || ( S == _T('_') ) )
			return 1;
		if( S.isDigit() )
			return 2;
		return 0;
	}
}

void LCVar::Deeds( void )
//          ~~~~~
{
	switch( CurrentState )
	{
	case 1 :
		identifier = _T("");
		break;
	case 2 :
		identifier += character;
		break;
	}
}

LCVar::LCVar( void )
//    ~~~~
: LAuto( LCVarStates, LCVarAlphabet, LCVarLeapes, LCVarsEndStates )
{
	identifier = _T("");
}
