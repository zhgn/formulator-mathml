

#include "../execop_call.h"
#include "../../vmevallink.h"

///////////////////////////////////////////////////////////////////////////////

long __Call_ConstructSet( CDSR_VMEval& vm, MMD_Address& addr, UniWord *arg )
{
	MMD_Set *res = vm.getSmbTable().makeUniWord( new MMD_Set( vm.getSmbTable() ) );
	for( long i = 0; i < addr.param3; i++ )
	{
		--arg;
		res->Add( *arg );
	}
	*arg = res;
	return 1 - addr.param3;
}

///////////////////////////////////////////////////////////////////////////////

#define __Call_SetAdd_subcalls_LENGTH 1
long __Call_SetAdd( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
#if _DEBUG
	if( addr.param2 < 0 || 
		addr.param2 >= __Call_SetAdd_subcalls_LENGTH )
		throw _T("__Call_SetAdd : internal error, out of range");
#endif
	*(arg - 2) = _dsrop_SetAdd( (arg - 2)->getSet(), (arg - 1)->getSet() );
	return 1 - addr.param3;
}

///////////////////////////////////////////////////////////////////////////////

#define __Call_SetMul_subcalls_LENGTH 1
long __Call_SetMul( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
#if _DEBUG
	if( addr.param2 < 0 || 
		addr.param2 >= __Call_SetMul_subcalls_LENGTH )
		throw _T("__Call_SetMul : internal error, out of range");
#endif
	*(arg - 2) = _dsrop_SetMul( (arg - 2)->getSet(), (arg - 1)->getSet() );
	return 1 - addr.param3;
}

///////////////////////////////////////////////////////////////////////////////
