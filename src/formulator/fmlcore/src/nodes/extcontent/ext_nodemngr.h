

#if !defined( __FORMULATOR_EXTNODEMNGR_H__ )
#define __FORMULATOR_EXTNODEMNGR_H__

#include "../../fmlcore_global.h"

/////////////////////////////////////////////////////////////////////////////

class CExtNodeContent_Base;
class CExtNode;

__YUNEN_FORMULIB__ CExtNode* CreateExtNode( long externalNodeClassID, void *pData );
__YUNEN_FORMULIB__ void* PrepareExtNodeData( long extNodeClasssID, const QString& strImgPath, const QString& strDocPath );

/////////////////////////////////////////////////////////////////////////////

#endif

