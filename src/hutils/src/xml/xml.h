

#if !defined( __XMPARSER_XMLPARSER_H__ )
#define __XMPARSER_XMLPARSER_H__

#include "HUtils/imessage.h"

class AST_TXML_Compound;
HUTILS_EXPORT int LS_CompileXML( const QString& _taskname, const QString& _txt, AST_TXML_Compound*& bms, DRMessageManager& dmm, long message_page = 0 );

#endif
