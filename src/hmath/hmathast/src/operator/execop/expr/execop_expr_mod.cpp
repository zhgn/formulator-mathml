

#include "../execop_call.h"
#include "../../vmevallink.h"

///////////////////////////////////////////////////////////////////////////////

#define __Call_Mod_subcalls_LENGTH 2
long __Call_Mod( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
#if _DEBUG
	if( addr.param2 < 0 || 
		addr.param2 >= __Call_Mod_subcalls_LENGTH )
		throw _T("__Call_Mod : internal error, out of range");
#endif
	if( addr.param2 == 0 )	// DSRDATA_TYPE_NATURAL
		_dsrop_Mod_natural( *(arg - 2), *(arg - 2), *(arg - 1) );
	else					// DSRDATA_TYPE_INTEGER
		_dsrop_Mod_integer( *(arg - 2), *(arg - 2), *(arg - 1) );
	return 1 - addr.param3;
}

///////////////////////////////////////////////////////////////////////////////
