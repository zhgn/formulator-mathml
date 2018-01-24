

/////////////////////////////////////////////////////////////////////////////

#ifndef __COMMON_XML_PARSER_H__
#define __COMMON_XML_PARSER_H__

#include "HUtils/ibaseparser.h"
#include "../xml_tree.h"

class TXML_Parser : public BaseParser {
protected :

	MIArray<AST_TXML_Node> astn;
	long astn_index;

	void GenCode( unsigned int RuleNumber );
	void NewLex( Source& aSource );
	void BeforeMake( void );
	void AfterMake ( void );
  
public :
	TXML_Storage** the_storage;

	TXML_Parser( Source& src, ActionT *actions, TXML_Storage **st );
	virtual void SetSemanticError( void );
	virtual ~TXML_Parser( void )
	{
		astn_index = 0;
	}
};

inline
TXML_Parser::TXML_Parser( Source& src, ActionT *actions, TXML_Storage** st )
	: BaseParser( src, actions )
	, astn( MIArray<AST_TXML_Node>::LeaveItems, 8, 0, 8 )
{
	the_storage = st;
	astn_index = 0;
	NewLex( src );
}

/////////////////////////////////////////////////////////////////////////////

#endif
