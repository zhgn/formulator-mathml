

#include "../execop_call.h"
#include "../../vmevallink.h"

///////////////////////////////////////////////////////////////////////////////

#define __Call_BoolAnd_subcalls_LENGTH 1
long __Call_BoolAnd( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
#if _DEBUG
	if( addr.param2 < 0 || 
		addr.param2 >= __Call_BoolAnd_subcalls_LENGTH )
		throw _T("__Call_BoolAnd : internal error, out of range");
#endif
	_dsrop_BoolAnd_bool( *(arg - 2), *(arg - 2), *(arg - 1) );
	return 1 - addr.param3;
}

///////////////////////////////////////////////////////////////////////////////

#define __Call_BoolOr_subcalls_LENGTH 1
long __Call_BoolOr( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
#if _DEBUG
	if( addr.param2 < 0 || 
		addr.param2 >= __Call_BoolOr_subcalls_LENGTH )
		throw _T("__Call_BoolOr : internal error, out of range");
#endif
	_dsrop_BoolOr_bool( *(arg - 2), *(arg - 2), *(arg - 1) );
	return 1 - addr.param3;
}

///////////////////////////////////////////////////////////////////////////////

#define __Call_BoolNot_subcalls_LENGTH 1
long __Call_BoolNot( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
#if _DEBUG
	if( addr.param2 < 0 || 
		addr.param2 >= __Call_BoolNot_subcalls_LENGTH )
		throw _T("__Call_BoolNot : internal error, out of range");
#endif
	_dsrop_BoolNot_bool( *(arg - 1), *(arg - 1) );
	return 1 - addr.param3;
}

///////////////////////////////////////////////////////////////////////////////
