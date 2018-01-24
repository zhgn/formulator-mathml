

#if !defined( __FORMULATOR_NODE_MATHML_NODE2PROPLIST_H__ )
#define __FORMULATOR_NODE_MATHML_NODE2PROPLIST_H__

#include "info/n_proplist.h"

///////////////////////////////////////////////////////////////////////////

class CNode;
__YUNEN_FORMULIB__ void parseNodeAttr2PropList( CNode_TextPropertyList& props, std::vector<char>& supports, CNode *frmNode );
__YUNEN_FORMULIB__ void parseNodeAttr2PropList( CNode_TextPropertyList& props, std::vector<char>& supports, QString mathmlRes );

///////////////////////////////////////////////////////////////////////////

#endif
