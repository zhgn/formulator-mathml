

/////////////////////////////////////////////////////////////////////////////

#include <math.h>
#include "HUtils/iustring.h"
#include "HUtils/idfas.h"
#include "thelexxml.h"
#include "grammar.h"

//*****************************************************************************
// TXML_Lex::NextLexem (m) - returns next extracted lexem.
// Your should define the function yourself.
//*****************************************************************************
Lexem TXML_Lex::NextLexem( void )
{
	Lexem ret;
	double *p_d;
	QString *p_s;
	ret.LexType = LEX_NONE;

	do
	{
                while( IsSpaceNextChar() ) ;
		//*** Remarks' termination ***
		if( RemTermination( ret ) == -1 )
		{
			if( ret.LexType == __LEX_eof )
			{
				ret.LexType = LEX_eof;
				PutBack();
			}
			continue;
		}

		ret.line = GetLine();
		ret.col = GetCol();
		ret.shift = GetShift();
		if( ( SoleChar().isDigit() || SoleChar() == _T('.')  || SoleChar() == _T('+') || SoleChar() == _T('-') )
			&& mode == TXML_Lex_MODE_INTAG )
		{
			static LSDigit ldigit;
			ldigit.Reset();
			ret.LexType = ldigit.Analisys( getCurrentText() );
			switch( ret.LexType )
			{
			case LSDigit::Integer:
				ret.Index = ldigit.asign * ldigit.mnt_int;
				ret.LexType = LEX_const_int;
				break;
			case LSDigit::Float:
				ret.LexType = LEX_const_real;
				ldigit.mnt_float *= pow( 10.0, (int)ldigit.power );
				ret.Smth = d_autoheap.Add2List( p_d = new double( ldigit.asign * ldigit.mnt_float ) );
				break;
			case LSDigit::FloatIEEE:
				ret.LexType = LEX_const_real;
				ldigit.mnt_float *= pow( 10.0, (int)(ldigit.power + ldigit.sign * ldigit.powerE) );
				ret.Smth = d_autoheap.Add2List( p_d = new double( ldigit.asign * ldigit.mnt_float ) );
				break;
			default:
				lex_err = Lex::BadNumericFormat;
				ret.LexType = LEX_NONE;
				ret.Smth = 0;
			}
			Inc( ldigit.GetRead() );
			continue;
		}

		if( (SoleChar() == _T('\"') || SoleChar() == _T('\'')) && mode == TXML_Lex_MODE_INTAG )
		{
			static LXMLString lstring( SoleChar() );
			lstring.Reset( SoleChar() );
			if( ( ret.LexType = lstring.Analisys( getCurrentText() ) ) != LEX_NONE )
			{
				ret.LexType = LEX_const_string;
				ret.Smth    = s_autoheap.Add2List( p_s = new QString( lstring.read_string ) );
			}
			Inc( lstring.GetRead() );
			continue;
		}

		if( (SoleChar().isLetter() || (SoleChar() == _T('_'))) && mode == TXML_Lex_MODE_INTAG )
		{
			static LXMLVar lvar;
			lvar.Reset();
			int r = lvar.Analisys( getCurrentText() );
			if( r )
			{
				if( r == LXMLVar::XML )
					ret.LexType = LEX_kw_xml;
				else if( r == LXMLVar::DOCTYPE )
					ret.LexType = LEX_kw_doctype;
				else
					ret.LexType = LEX_id;
				ret.Smth    = s_autoheap.Add2List( p_s = new QString( (lvar.getNS().length() == 0) ? 
																			lvar.getID() : 
																			(lvar.getNS() + _T(":") + lvar.getID()) ) );
				Inc( lvar.GetRead() );
			}
			else
				ret.LexType = LEX_NONE;
			continue;
		}

		if( mode == TXML_Lex_MODE_INTAG )
		{
			QChar tch = NextChar();
			switch( tch.unicode() )
			{
			case _T('<'):
				if( SoleChar() == _T('?') )
				{
					ret.LexType = LEX_begintag_q;
					NextChar();
				}
				else if( SoleChar() == _T('!') )
				{
					ret.LexType = LEX_begintag_e;
					NextChar();
				}
				else if( SoleChar() == _T('/') )
				{
					ret.LexType = LEX_begintag_s;
					NextChar();
				}
				else
					ret.LexType = LEX_begintag;
				mode = TXML_Lex_MODE_INTAG;
				break;

			case _T('>'):
				ret.LexType = LEX_endtag;
				mode = TXML_Lex_MODE_OUTTAG;
				break;

			case _T('='):
				ret.LexType = LEX_equal;
				break;

			case _T('['):
				ret.LexType = LEX_lab;
				break;

			case _T(']'):
				ret.LexType = LEX_rab;
				break;

			case EOF_ASCII_1A :
			case EOF_ASCII_NULL :
				ret.LexType = LEX_eof;
				PutBack();
				break;

			case _T('/'):
			case _T('?'):
				if( SoleChar() == _T('>') )
				{
					ret.LexType = tch == _T('/') ? LEX_endtag_s : LEX_endtag_q;
					mode = TXML_Lex_MODE_OUTTAG;
					NextChar();
				}
				else
					ret.LexType = LEX_NONE;
				break;
			}
		}
		else
		{
			switch( NextChar().unicode() )
			{
			case _T('<'):
				if( SoleChar() == _T('?') )
				{
					ret.LexType = LEX_begintag_q;
					NextChar();
				}
				else if( SoleChar() == _T('!') )
				{
					ret.LexType = LEX_begintag_e;
					NextChar();
				}
				else if( SoleChar() == _T('/') )
				{
					ret.LexType = LEX_begintag_s;
					NextChar();
				}
				else
					ret.LexType = LEX_begintag;
				mode = TXML_Lex_MODE_INTAG;
				break;
			case EOF_ASCII_1A :				// !!! eof !!!
			case EOF_ASCII_NULL :				// !!! eof !!!
				ret.LexType = LEX_eof;
				PutBack();
				break;
			default :
				{
					QChar pch;
					PutBack( 2 );
					while( SoleChar().isSpace() && !isBOF() ) PutBack();
					NextChar();
					ret.Smth    = s_autoheap.Add2List( p_s = new QString( _T("") ) );
					ret.LexType = LEX_text;
					for( pch = NextChar(); pch != QChar('<') && pch != QChar(EOF_ASCII_1A) && pch != QChar(EOF_ASCII_NULL); pch = NextChar() )
					{
						*(QString*)ret.Smth += pch;
					}
					PutBack();
				}
			}
		}
	}
	while( 0 );

	prev_lexem.LexType = ret.LexType;
	return ret;
}

//*****************************************************************************
// Lex::RemTermination - Terminates remarks.
// Returns : -1 if <NextLexem> must returns something, 0 otherwise.
//*****************************************************************************
int TXML_Lex::RemTermination( Lexem& /*ret*/ )
//       ~~~~~~~~~~~~~~
{
	static QString startRem = _T("<!--");
	static QString endRem   = _T("-->");
	while( isLA( startRem ) )
	{
		Inc( startRem.length() );
		while( !::_iseof( SoleChar() ) && !isLA( endRem ) )
			NextChar();
		if( ::_iseof( SoleChar() ) )
		{
			lex_err = Lex::UnterminatedComment;
			return -1;
		}
		else
			Inc( endRem.length() );
                while( IsSpaceNextChar() ) ;
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////////////
