

#ifndef __BULAN_PARSER_H__
#define __BULAN_PARSER_H__

#include "HUtils/ihkarray.h"
#include "HUtils/ibaseparser.h"

#include "thelex.h"
#include "ast.h"

class __YUNEN_FORMULIB__ BulanParser : public BaseParser
{
protected :
	MIArray<FBAST_Node> astn;
	long astn_index;

	virtual void GenCode( unsigned int RuleNumber );
	virtual void NewLex( Source& aSource );
	virtual void BeforeMake();
	virtual void AfterMake ();
	virtual void SetSemanticError();
  
public :
	const QString& GetLexError();
	PiCodeASTStorage** the_storage;
	BulanParser( Source& src, ActionT *aActionTable, PiCodeASTStorage** st );
};

inline
BulanParser::BulanParser( Source& src, ActionT *aActionTable, PiCodeASTStorage** st ) :
  	BaseParser( src, aActionTable ),
	astn( MIArray<FBAST_Node>::LeaveItems, 8, 0, 8 )
{
	the_storage = st;
	astn_index = 0;
	SemanticErrorHappened = false;
	NewLex( src );
}

#endif
