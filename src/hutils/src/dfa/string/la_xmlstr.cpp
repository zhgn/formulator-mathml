

#include <limits.h>

#include "HUtils/iustring.h"
#include "la_xmlstr.h"

long LXML_ASCII_2_Alphabet[ 256 ] = 
{
	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,
	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,
	6,	6,	1,	3,	6,	6,	2,	1,	6,	6,	6,	6,	6,	6,	6,	6,
	18,	18,	18,	18,	18,	18,	18,	18,	18,	18,	6,	5,	6,	6,	6,	6,
	6,	17,	17,	17,	17,	17,	17,	6,	6,	6,	6,	6,	6,	6,	6,	6,
	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,
	6,	7,	17,	17,	17,	17,	17,	16,	6,	6,	6,	6,	15,	8,	6,	12,
	9,	10,	6,	14,	13,	11,	6,	6,	4,	6,	6,	6,	6,	6,	6,	6,
	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,
	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,
	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,
	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,
	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,
	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,
	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,
	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6
};

long LXMLStringLeapes[ LXMLStringStates * LXMLStringAlphabet ] =
{
	//"	&	#	x	;	...	a	m	p	q	u	o	t	s	l	g	A	0
	2,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,
	3,	4,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,
	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,
	3,	4,	14,	2,	2,	2,	8,	2,	2,	7,	2,	2,	2,	2,	5,	6,	2,	2,
	3,	4,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	11,	2,	2,	2,	2,	2,
	3,	4,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	12,	2,	2,	2,	2,	2,
	3,	4,	2,	2,	2,	2,	2,	2,	2,	2,	13,	2,	2,	2,	2,	2,	2,	2,
	3,	4,	2,	2,	2,	2,	2,	9,	10,	2,	2,	2,	2,	2,	2,	2,	2,	2,
	3,	4,	2,	2,	2,	2,	2,	2,	15,	2,	2,	2,	2,	2,	2,	2,	2,	2,
	3,	4,	2,	2,	2,	2,	2,	2,	2,	2,	2,	16,	2,	2,	2,	2,	2,	2,
	3,	4,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,
	3,	4,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,
	3,	4,	2,	2,	2,	2,	2,	2,	2,	2,	2,	18,	2,	2,	2,	2,	2,	2,
	3,	4,	2,	21,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	20,
	3,	4,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,
	3,	4,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	17,	2,	2,	2,	2,
	3,	4,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,
	3,	4,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	19,	2,	2,	2,	2,	2,
	3,	4,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,
	3,	4,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	20,
	3,	4,	2,	2,	2,	2,	22,	2,	2,	2,	2,	2,	2,	2,	2,	2,	22,	22,
	3,	4,	2,	2,	2,	2,	22,	2,	2,	2,	2,	2,	2,	2,	2,	2,	22,	22
};

long LXMLStringsEndStates[ LXMLStringStates ] =
{
	0, 0, LXMLString::String, 0, 0,
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	0, 0
};

long LXMLString::What( const QChar S )
//               ~~~~
{
	if( (S == _T('\"') || S == _T('\'')) && S != quat )
		return 6;
	return (S.unicode() < 256) ? LXML_ASCII_2_Alphabet[ S.unicode() ] : 6;
}

void LXMLString::Deeds( void )
//                    ~~~~~
{
	switch( CurrentState )
	{
	case 1:
		read_string = _T("");
		read_buff = _T("");
		is_big = 0;
		is_numentity_notchar = 0;
		break;
	case 3:
		if( PrevState != 1 && PrevState != 2 )
			read_string += read_buff;
		break;
	case 2:
		if( PrevState == 2 ) read_string += character;
		else if( PrevState != 1 )
		{
			switch( PrevState )
			{
			case 11:
				if( character == _T(';') )
					read_buff = _T('<');
				else
					read_buff += character;
				break;
			case 12:
				if( character == _T(';') )
					read_buff = _T('>');
				else
					read_buff += character;
				break;
			case 15:
				if( character == _T(';') )
					read_buff = _T('&');
				else
					read_buff += character;
				break;
			case 17:
				if( character == _T(';') )
					read_buff = _T('\'');
				else
					read_buff += character;
				break;
			case 19:
				if( character == _T(';') )
					read_buff = _T('\"');
				else
					read_buff += character;
				break;
			case 20:
			case 22:
				if( character == _T(';') )
				{
					if( mnt_int > UCHAR_MAX || is_big ) 
						is_numentity_notchar = 1;
					read_buff = QChar( (unsigned short)mnt_int );
				}
				else
					read_buff += character;
				break;
			default:
				read_buff += character;
			}
			read_string += read_buff;
		}
		break;

	case 20:
		read_buff += character;
		if( PrevState == 14 )
		{
			mnt_int = 0;
			pre_int = 0;
		}
		mnt_int = 10 * mnt_int + character.digitValue();
		if( mnt_int < pre_int )
			is_big = 1;
		else
			pre_int = mnt_int;
		break;
	case 22:
		read_buff += character;
		if( PrevState == 21 )
		{
			mnt_int = 0;
			pre_int = 0;
		}
		mnt_int = 16 * mnt_int + hex2dec( character.toLatin1() );
		if( mnt_int < pre_int )
			is_big = 1;
		else
			pre_int = mnt_int;
		break;

	case 4:
		if( PrevState != 2 )
			read_string += read_buff;
		read_buff = character;
		break;
	default:
		read_buff += character;
	}
}

LXMLString::LXMLString( QChar _quat )
//          ~~~~~~~
: LAuto( LXMLStringStates, LXMLStringAlphabet, LXMLStringLeapes, LXMLStringsEndStates )
{
	quat = _quat;
	pre_int = mnt_int = 0;
	is_big = 0;
	is_numentity_notchar = 0;
}
