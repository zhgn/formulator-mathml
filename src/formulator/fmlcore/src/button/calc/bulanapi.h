

#if !defined( __BULAN_BULANAPI_H__ )
#define __BULAN_BULANAPI_H__

#include "HUtils/imessage.h"
#include "ast.h"

///////////////////////////////////////////////////////////////////////////////

int LS_CompileBulanExpr( const QString& _txt, PiCodeASTStorage*& bms, DRMessageManager& dmm, long message_page = 0 );

///////////////////////////////////////////////////////////////////////////////

#endif
