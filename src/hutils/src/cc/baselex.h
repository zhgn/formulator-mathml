

#ifndef __HUTILS_BASELEX_H__
#define __HUTILS_BASELEX_H__

#include "source.h"

//////////////////////////////////////////////////////////////////////

class HUTILS_EXPORT Lex : public Source
{
public :
	enum LexErrors
	{
		UnknownError,
		UnknownSymbol,
		UnterminatedComment,
		BadNumericFormat,
		UnknownWord
	};

protected :  
	Lex::LexErrors lex_err;
	virtual int IsSpaceNextChar( void );

public :
	Lex( Source& Src );
	Lex::LexErrors GetError();
	virtual void Reset( void );
	virtual Lexem NextLexem();
	virtual int RemTermination( Lexem& ret );
	virtual ~Lex();
};

//////////////////////////////////////////////////////////////////////

inline
Lex::Lex( Source& Src )
	: Source( Src )
{
	lex_err = UnknownError;
}

inline
Lex::LexErrors Lex::GetError()
{
	return lex_err;
}

inline
void Lex::Reset( void )
{
	Source::Reset();
}

//////////////////////////////////////////////////////////////////////

#endif
