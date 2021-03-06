

#include "../execop_call.h"
#include "../../vmevallink.h"

///////////////////////////////////////////////////////////////////////////////

#define __Call_SetRelIn_subcalls_LENGTH	22
long __Call_SetRelIn( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
#if _DEBUG
	if( addr.param2 < 0 || 
		addr.param2 >= __Call_SetRelIn_subcalls_LENGTH )
		throw _T("__Call_SetRelIn : internal error, out of range");
#endif
	_dsrop_SetRelIn( *(arg - 2), (arg - 1)->getSet(), *(arg - 2) );
	return 1 - addr.param3;
}

///////////////////////////////////////////////////////////////////////////////

#define __Call_SetRelNotIn_subcalls_LENGTH	22
long __Call_SetRelNotIn( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
#if _DEBUG
	if( addr.param2 < 0 || 
		addr.param2 >= __Call_SetRelNotIn_subcalls_LENGTH )
		throw _T("__Call_SetRelNotIn : internal error, out of range");
#endif
	_dsrop_SetRelNotIn( *(arg - 2), (arg - 1)->getSet(), *(arg - 2) );
	return 1 - addr.param3;
}

///////////////////////////////////////////////////////////////////////////////

#define __Call_SetRelSetIn_subcalls_LENGTH	1
long __Call_SetRelSetIn( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
#if _DEBUG
	if( addr.param2 < 0 || 
		addr.param2 >= __Call_SetRelSetIn_subcalls_LENGTH )
		throw _T("__Call_SetRelSetIn : internal error, out of range");
#endif
	_dsrop_SetRelSetIn( *(arg - 2), (arg - 2)->getSet(), (arg - 1)->getSet() );
	return 1 - addr.param3;
}

///////////////////////////////////////////////////////////////////////////////

#define __Call_SetRelSetNotIn_subcalls_LENGTH	1
long __Call_SetRelSetNotIn( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
#if _DEBUG
	if( addr.param2 < 0 || 
		addr.param2 >= __Call_SetRelSetNotIn_subcalls_LENGTH )
		throw _T("__Call_SetRelSetNotIn : internal error, out of range");
#endif
	_dsrop_SetRelSetNotIn( *(arg - 2), (arg - 2)->getSet(), (arg - 1)->getSet() );
	return 1 - addr.param3;
}

///////////////////////////////////////////////////////////////////////////////

#define __Call_SetRelSetInInv_subcalls_LENGTH	1
long __Call_SetRelSetInInv( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
#if _DEBUG
	if( addr.param2 < 0 || 
		addr.param2 >= __Call_SetRelSetInInv_subcalls_LENGTH )
		throw _T("__Call_SetRelSetInInv : internal error, out of range");
#endif
	_dsrop_SetRelSetInInv( *(arg - 2), (arg - 2)->getSet(), (arg - 1)->getSet() );
	return 1 - addr.param3;
}

///////////////////////////////////////////////////////////////////////////////

#define __Call_SetRelSetInEq_subcalls_LENGTH	1
long __Call_SetRelSetInEq( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
#if _DEBUG
	if( addr.param2 < 0 || 
		addr.param2 >= __Call_SetRelSetInEq_subcalls_LENGTH )
		throw _T("__Call_SetRelSetInEq : internal error, out of range");
#endif
	_dsrop_SetRelSetInEq( *(arg - 2), (arg - 2)->getSet(), (arg - 1)->getSet() );
	return 1 - addr.param3;
}

///////////////////////////////////////////////////////////////////////////////

#define __Call_SetRelSetInEqInv_subcalls_LENGTH	1
long __Call_SetRelSetInEqInv( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
#if _DEBUG
	if( addr.param2 < 0 || 
		addr.param2 >= __Call_SetRelSetInEqInv_subcalls_LENGTH )
		throw _T("__Call_SetRelSetInEqInv : internal error, out of range");
#endif
	_dsrop_SetRelSetInEqInv( *(arg - 2), (arg - 2)->getSet(), (arg - 1)->getSet() );
	return 1 - addr.param3;
}

///////////////////////////////////////////////////////////////////////////////
