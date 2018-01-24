

#include "HUtils/iustring.h"
#include "la_entity.h"

long LCEntityLeapes[ LCEntityStates * LCEntityAlphabet ] = 
{
//  &  l  ;  #  x hex d
	2, 0, 0, 0, 0, 0, 0,
	0, 3, 0, 5, 3, 3, 0,
	0, 3, 4, 0, 3, 3, 3,
	0, 0, 0, 0, 0, 0, 0, // *
	0, 0, 0, 0, 7, 0, 6,
	0, 0, 9, 0, 0, 0, 6,
	0, 0, 0, 0, 0, 8, 8,
	0, 0, 9, 0, 0, 8, 8,
	0, 0, 0, 0, 0, 0, 0, // *
};

long LCEntitysEndStates[ LCEntityStates ] =
{
	0, 0, 0, LCEntity::Identifier, 0, 0, 0, 0, LCEntity::Number
};

long LCEntity::What( const QChar S )
//             ~~~~
{
	//     &  l  ;  #  x hex d
	//     1  2  3  4  5  6  7
	for(;;)
	{ // order of if's is principle
		if( S == _T('&') ) return 1;
		if( S == _T(';') ) return 3;
		if( S == _T('#') ) return 4;
		if( S == _T('x') || S == _T('X') ) return 5;
		if( S.isDigit() ) return 7;
		if( _isxdigit( S.toLatin1() ) ) return 6;
		if( S.isLetter() ) return 2;
		return 0;
	}
}

void LCEntity::Deeds( void )
//             ~~~~~
{
	switch( CurrentState )
	{
	case 1 :
		identifier = _T("");
		break;
	case 2 :
		identifier += character;
		break;
	case 3 :
		identifier += character;
		break;
	case 4 :
		identifier += character;
		break;
	case 5 :
		identifier += character;
		value = 0;
		pre = 0;
		is_big = 0;
		break;
	case 6 :
		identifier += character;
		value = 10 * value + character.digitValue();
		if(value < pre) is_big = 1;
		else pre = value;
		break;
	case 7 :
		identifier += character;
		break;
	case 8 :
		identifier += character;
		value = 16 * value + hex2dec( character.toLatin1() );
		if(value < pre) is_big = 1;
		else pre = value;
		break;
	case 9 :
		identifier += character;
		break;
	}
}

LCEntity::LCEntity( void )
//    ~~~~
: LAuto( LCEntityStates, LCEntityAlphabet, LCEntityLeapes, LCEntitysEndStates )
{
	identifier = _T("");
	value = 0;
	pre = 0;
	is_big = 0;
}
