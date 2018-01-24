

#ifndef __COMMON_XML_THELEXER_H__
#define __COMMON_XML_THELEXER_H__

/////////////////////////////////////////////////////////////////////////////

#include "HUtils/ibaselexer.h"
#include "HUtils/iautoheap.h"

#define TXML_Lex_MODE_INTAG		0
#define TXML_Lex_MODE_OUTTAG	1

class TXML_Lex : public Lex
{
protected:
	long mode;
	Lexem prev_lexem;
	HU_Heap2Free<QString> s_autoheap;
	HU_Heap2Free<double> d_autoheap;
  
public :
	TXML_Lex( Source& Src )
		: Lex( Src )
	{
		mode = TXML_Lex_MODE_OUTTAG;
	}
	virtual Lexem NextLexem( void );
	int RemTermination( Lexem& ret );
	~TXML_Lex()
	{}
};

/////////////////////////////////////////////////////////////////////////////

#endif
