

#include "execop_call.h"
#include "../vmevallink.h"

///////////////////////////////////////////////////////////////////////////////

long __Call_ConstructSetEmpty( CDSR_VMEval& vm, MMD_Address& addr, UniWord * /*arg*/ )
{
	vm.m_run_stack[ vm.m_run_stack_ptr ] = vm.getSmbTable().makeUniWord( new MMD_Set( vm.getSmbTable() ) );
	return 1 - addr.param3;
}

///////////////////////////////////////////////////////////////////////////////

typedef MMD_Vector* (*SUBCALL_CONSTRUCT_VECTOR)( CParseDsrSymbolTable& smbtable, UniWord *first_arg );
/*
#define __Call_ConstructVector_subcalls_LENGTH	5
static SUBCALL_CONSTRUCT_VECTOR __Call_ConstructVector_subcalls[ __Call_ConstructVector_subcalls_LENGTH ] = 
{
	_dsrop_ConstructVector_natural,
	_dsrop_ConstructVector_integer,
	_dsrop_ConstructVector_rational,
	_dsrop_ConstructVector_real,
	_dsrop_ConstructVector_complex
};
*/
long __Call_ConstructVector( CDSR_VMEval& vm, MMD_Address& addr, UniWord *arg )
{
/*
#if _DEBUG
	if( addr.param2 < 0 || 
		addr.param2 >= __Call_ConstructVector_subcalls_LENGTH )
		throw _T("__Call_ConstructVector : internal error, out of range");
#endif
	// *(arg - addr.param3) = __Call_ConstructVector_subcalls[ addr.param2 ]( vm.getSmbTable(), arg - addr.param3 );
*/
	*(arg - addr.param3) = _dsrop_ConstructVector_anytype( vm.getSmbTable(), arg - addr.param3, (enum CDsrDataTypes)(addr.param2) );
	return 1 - addr.param3;
}

///////////////////////////////////////////////////////////////////////////////

typedef MMD_Vector* (*SUBCALL_TRANSPOSE)( MMD_Vector *a );
#define __Call_VectorTranspose_subcalls_LENGTH	5
static SUBCALL_TRANSPOSE __Call_VectorTranspose_subcalls[ __Call_VectorTranspose_subcalls_LENGTH ] = 
{
	_dsrop_VectorTranspose_natural,
	_dsrop_VectorTranspose_integer,
	_dsrop_VectorTranspose_rational,
	_dsrop_VectorTranspose_real,
	_dsrop_VectorTranspose_complex
};
long __Call_VectorTranspose( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
#if _DEBUG
	if( addr.param2 < 0 || 
		addr.param2 >= __Call_VectorTranspose_subcalls_LENGTH )
		throw _T("__Call_VectorTranspose : internal error, out of range");
#endif
	*(arg - 1) = __Call_VectorTranspose_subcalls[ addr.param2 ]( (arg - 1)->getVector() );
	return 1 - addr.param3;
}

///////////////////////////////////////////////////////////////////////////////
