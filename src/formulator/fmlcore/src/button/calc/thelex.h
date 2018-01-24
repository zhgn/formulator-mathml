

#ifndef __BULAN_THELEXER_H__
#define __BULAN_THELEXER_H__

#include "HUtils/ibaselexer.h"
#include "HUtils/iautoheap.h"

class BulanLex : public Lex
{
protected:
	HU_Heap2Free<QString> s_autoheap;
	HU_Heap2Free<double> d_autoheap;

public :
	BulanLex( Source& Src ) : Lex( Src ) {}
	int RemTermination( Lexem& ret );
	virtual Lexem NextLexem();
};

#endif
