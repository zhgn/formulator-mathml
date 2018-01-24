

#ifndef __PARSEDSR_THELEXER_H__
#define __PARSEDSR_THELEXER_H__

#include "HUtils/ihkstring.h"
#include "HUtils/ibaselexer.h"
#include "HUtils/iautoheap.h"
#include "../hmathast_global.h"
#include "../operator/operator.h"
#include "../symbol/symbol_table_dsr.h"

//=============================================================================

class __HMATHLNGDLL__ ParseDsrLex : public Lex {
protected:
	HU_Heap2Free<QString> s_autoheap;
	HU_Heap2Free<double> d_autoheap;
	bool remark_mode;
	CParseDsrSymbolTable *ptr_symbol_table;

public :
	ParseDsrLex( Source& Src, Common* aInfo, CParseDsrSymbolTable *_ptr_symbol_table = 0 )
		: Lex( Src, aInfo )
	{
		remark_mode = false;
		ptr_symbol_table = _ptr_symbol_table;
	}

	CParseDsrSymbolTable* getSymbolTablePtr( void )
		{ return ptr_symbol_table; }
	void setRemarkMode( bool value = true )
		{ remark_mode = value; }
	bool isRemarkMode( void )
		{ return remark_mode; }

	const QString& getLexemText( Lexem& r )
	{
		static QString str = _T("");
		if( r.length )
			str.assign( Source::getText( r.shift ), r.length );
		else
			str = _T("");
		return str;
	}

	virtual Lexem NextLexem( void );
};

#endif
