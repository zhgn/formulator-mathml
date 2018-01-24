

#include "../execop_call.h"
#include "../../vmevallink.h"

///////////////////////////////////////////////////////////////////////////////

__HMATHLNGDLL__
void _call_dsrop_Assign_natural( UniWord& dest, UniWord *arg )
{
	dest = (arg - 1)->v_natural;
}
__HMATHLNGDLL__
void _call_dsrop_Assign_integer( UniWord& dest, UniWord *arg )
{
	dest = (arg - 1)->v_integer;
}
__HMATHLNGDLL__
void _call_dsrop_Assign_rational( UniWord& dest, UniWord *arg )
{
	dest = (arg - 1)->getRational();
}
__HMATHLNGDLL__
void _call_dsrop_Assign_real( UniWord& dest, UniWord *arg )
{
	dest = (arg - 1)->getReal();
}
__HMATHLNGDLL__
void _call_dsrop_Assign_complex( UniWord& dest, UniWord *arg )
{
	dest = (arg - 1)->getComplex();
}

__HMATHLNGDLL__
void _call_dsrop_Assign_bool( UniWord& dest, UniWord *arg )
{
	dest = (arg - 1)->getInteger();
}

__HMATHLNGDLL__
void _call_dsrop_Assign_string( UniWord& dest, UniWord *arg )
{
	dest = (arg - 1)->getString()->clone();
}

__HMATHLNGDLL__
void _call_dsrop_PolynomialAssign( UniWord& dest, UniWord *arg )
{
	dest = (arg - 1)->getPolynomial()->clone();
}

__HMATHLNGDLL__
void _call_dsrop_RationalFunAssign( UniWord& dest, UniWord *arg )
{
	dest = (arg - 1)->getRationalFun()->clone();
}

__HMATHLNGDLL__
void _call_dsrop_VectorAssign( UniWord& dest, UniWord *arg )
{
	dest = (arg - 1)->getVector()->clone();
}

__HMATHLNGDLL__
void _call_dsrop_SetAssign( UniWord& dest, UniWord *arg )
{
	dest = (arg - 1)->getSet()->clone();
}

__HMATHLNGDLL__
void _call_dsrop_Assign_group_string( UniWord& /*dest*/, UniWord * /*arg*/ )
{
	// vasya : to do group QString
}
__HMATHLNGDLL__
void _call_dsrop_GroupAssign( UniWord& /*dest*/, UniWord * /*arg*/ )
{
	// vasya : to do group
}

///////////////////////////////////////////////////////////////////////////////

typedef void (*SUBCALL_ASSIGN)( UniWord& dest, UniWord *arg );
#define __Call_Assign_subcalls_LENGTH	21
static SUBCALL_ASSIGN __Call_Assign_subcalls[ __Call_Assign_subcalls_LENGTH ] = 
{
	_call_dsrop_Assign_natural,
	_call_dsrop_Assign_integer,
	_call_dsrop_Assign_rational,
	_call_dsrop_Assign_real,
	_call_dsrop_Assign_complex,
	_call_dsrop_Assign_bool,
	_call_dsrop_Assign_string,
	_call_dsrop_PolynomialAssign,
	_call_dsrop_PolynomialAssign,
	_call_dsrop_PolynomialAssign,
	_call_dsrop_RationalFunAssign,
	_call_dsrop_RationalFunAssign,
	_call_dsrop_RationalFunAssign,
	_call_dsrop_VectorAssign,
	_call_dsrop_VectorAssign,
	_call_dsrop_VectorAssign,
	_call_dsrop_VectorAssign,
	_call_dsrop_VectorAssign,
	_call_dsrop_Assign_group_string,
	_call_dsrop_GroupAssign,
	_call_dsrop_SetAssign
};
long __Call_Assign( CDSR_VMEval& vm, MMD_Address& addr, UniWord *arg )
{
#if _DEBUG
	if( addr.param2 < 0 || 
		addr.param2 >= __Call_Assign_subcalls_LENGTH )
		throw _T("__Call_Assign : internal error, out of range");
#endif

	MMD_Address var_addr = (arg - 2)->getAddress();

	switch( var_addr.param1 )
	{
	case VARIABLE_USER:
#if _DEBUG
		if( var_addr.param2 < vm.getVariable_Begin() || 
			var_addr.param2 >= vm.getVariable_End() )
			throw _T("__Call_Assign : internal error, variable number is out of range in assignment");
#endif
		__Call_Assign_subcalls[ addr.param2 ]( vm.m_var_table[ var_addr.param2 ], arg );
		break;

	case LOCAL_VARIABLE_USER:
#if _DEBUG
		if( var_addr.param2 < 1 || 
			vm.m_BP + var_addr.param2 - 1 >= vm.m_SP )
			throw _T("__Call_Assign : internal error, local variable number is out of range in assignment");
#endif
		__Call_Assign_subcalls[ addr.param2 ]( vm.m_stack[ vm.m_BP + var_addr.param2 - 1 ], arg );
		break;

	case VARIABLE_USER_INDIRECT:
		{
#if _DEBUG
		if( var_addr.param2 < vm.getVariable_Begin() || 
			var_addr.param2 >= vm.getVariable_End() )
			throw _T("__Call_Assign : internal error, variable number is out of range in assignment");
#endif
		UniWord& vect = vm.m_var_table[ var_addr.param2 ];
#if _DEBUG
		if( !vect.getVector() ||
			var_addr.param3 < 1 || 
			var_addr.param3 > (long) vect.getVector()->getCount() )
			throw _T("__Call_Assign : internal error, global vector variable index is invalid");
#endif
		__Call_Assign_subcalls[ addr.param2 ]( vect.getVector()->at( var_addr.param3 - 1 ), arg );
		}
		break;

	case LOCAL_VARIABLE_USER_INDIRECT:
		{
#if _DEBUG
		if( var_addr.param2 < 1 || 
			vm.m_BP + var_addr.param2 - 1 >= vm.m_SP )
			throw _T("__Call_Assign : internal error, local variable number is out of range in assignment");
#endif
		UniWord& vect = vm.m_stack[ vm.m_BP + var_addr.param2 - 1 ];
#if _DEBUG
		if( !vect.getVector() ||
			var_addr.param3 < 1 || 
			var_addr.param3 > (long) vect.getVector()->getCount() )
			throw _T("__Call_Assign : internal error, local vector variable index is invalid");
#endif
		__Call_Assign_subcalls[ addr.param2 ]( vect.getVector()->at( var_addr.param3 - 1 ), arg );
		}
		break;

#if _DEBUG
	default:
		throw _T("__Call_Assign : internal error, unknown addressing scheme");
#endif
	}
	*(arg - 2) = *(arg - 1);
	return 1 - addr.param3;
}

///////////////////////////////////////////////////////////////////////////////
