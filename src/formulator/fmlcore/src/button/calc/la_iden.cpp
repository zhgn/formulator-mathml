

#include "la_iden.h"

const static QString kw_abs		= _T("abs");
const static QString kw_av		= _T("average");
const static QString kw_min		= _T("min");
const static QString kw_max		= _T("max");

long LIdenLeapes[ LIdenStates * LIdenAlphabet ] = {
	//	l  d
	//  ~~~~
	2, 0,
	2, 2
};

long LIdensEndStates[ LIdenStates ] = {
	0, LIden::Identifier
};

long LIden::What( const QChar S )
//              ~~~~
{
	for(;;)
	{
		if( S.isLetter() || (S == QChar('_')) )	return 1;
		if( S.isDigit() )						return 2;
		return 0;
	}
}

void LIden::Deeds()
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
	default:
		break;
	}
}

int LIden::Analisys( const QStringRef& aText )
//         ~~~~~~~~
{
	int ret = LAuto::Analisys( aText );
	if( ret )
	{
		if( identifier == kw_abs )
			return LIden::KW_Abs;
		else if( identifier == kw_av )
			return LIden::KW_Av;
		else if( identifier == kw_min )
			return LIden::KW_Min;
		else if( identifier == kw_max )
			return LIden::KW_Max;
	}
	return ret;
}
