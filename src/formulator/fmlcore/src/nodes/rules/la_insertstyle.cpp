

#include "la_insertstyle.h"

long LFInsertStyleLeapes[ LFInsertStyleStates * LFInsertStyleAlphabet ] = {
	//     l  d  .
	2, 3, 4,
	2, 0, 0,
	0, 3, 0,
	0, 0, 4
};

long LFInsertStylesEndStates[ LFInsertStyleStates ] = {
	0, 'a', '1', '.'
};

long LFInsertStyle::What( const QChar S )
//                ~~~~
{
	for(;;)
	{
		if( S.isLetter() || (S == QChar('_')) )
			return 1;
		if( S.isDigit() )
			return 2;
		if( S == _T('\0') )
			return 0;
		return 3;
	}
}

void LFInsertStyle::Deeds( void )
//            ~~~~~
{
	switch( CurrentState )
	{
	case 1 :
		text = _T("");
		break;
	case 2 :
		text += character;
		break;
	case 3 :
		text += character;
		break;
	case 4 :
		text += character;
		break;
	}
}

LFInsertStyle::LFInsertStyle( void )
//       ~~~~~~~
: LAuto( LFInsertStyleStates, LFInsertStyleAlphabet, LFInsertStyleLeapes, LFInsertStylesEndStates )
{
	text = _T("");
}


QString& LFInsertStyle::getText( void )
{
	return text;
}
