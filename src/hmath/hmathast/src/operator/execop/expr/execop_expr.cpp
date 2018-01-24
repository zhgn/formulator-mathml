

#include "../execop_call.h"
#include "../../vmevallink.h"

///////////////////////////////////////////////////////////////////////////////

long __Call_Nop( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord * /*arg*/ )
{
	return 1 - addr.param3;
}

long __Call_TypeSpec( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord * /*arg*/ )
{
	// vasya : to do type spec
	return 1 - addr.param3;
}

///////////////////////////////////////////////////////////////////////////////

long __Call_UserCall( CDSR_VMEval& vm, MMD_Address& addr, UniWord * /*arg*/ )
{
#if _DEBUG
	if( addr.param2 < vm.getFunction_Begin() || 
		addr.param2 >= vm.getFunction_End() ||
		addr.param3 < 0 )
	{
		vm.getSmbTable().AddLine( _T("internal problem while running: variable address in polynomial call is out of range") );
		vm.setError();
		return 1 - addr.param3;
	}
#endif

	// push ret addr == address of CALL op + 1 -> (segment, IP)
	vm.m_stack[ vm.m_SP++ ] = _create_lparam( vm.m_context, vm.m_context_no, vm.m_IP + 1 );

	// push BP
	vm.m_stack[ vm.m_SP++ ] = _create_lparam( vm.m_BP );

	// push run stack pointer
	vm.m_stack[ vm.m_SP++ ] = _create_lparam( vm.m_run_stack_ptr  - addr.param3 );

	// push actual parameters
	vm.m_BP = vm.m_SP;
	for( long i = - addr.param3; i < 0; i++ )
		vm.m_stack[ vm.m_SP++ ] = vm.m_run_stack[ vm.m_run_stack_ptr + i ];
	// reserve stack space for function results
	vm.m_SP += addr.param4;

	// change context to the function being called
	vm.m_context = VMEval_CODE_SEGMENT_ID__FUNCTION;
	vm.m_context_no = addr.param2;
	vm.m_IP_base_ptr = &vm.m_fun_table[ addr.param2 ].body;
	vm.m_IP = 0;

	return /*1*/ - addr.param3;
}

///////////////////////////////////////////////////////////////////////////////

long __Call_UserCallPolynomial( CDSR_VMEval& vm, MMD_Address& addr, UniWord *arg )
{
#if _DEBUG
	if( addr.param2 < vm.getVariable_Begin() || 
		addr.param2 >= vm.getVariable_End() ||
		!vm.m_var_table[ addr.param2 ].getPolynomial() )
	{
		vm.getSmbTable().AddLine( _T("internal problem while running: variable address in polynomial call is out of range") );
		vm.setError();
		return 1 - addr.param3;
	}
#endif
	vm.m_var_table[ addr.param2 ].getPolynomial()->getValue( *(arg - 1), *(arg - 1) );
	return 1 - addr.param3;
}

///////////////////////////////////////////////////////////////////////////////

long __Call_UserCallRationalFun( CDSR_VMEval& vm, MMD_Address& addr, UniWord *arg )
{
#if _DEBUG
	if( addr.param2 < vm.getVariable_Begin() || 
		addr.param2 >= vm.getVariable_End() ||
		!vm.m_var_table[ addr.param2 ].getRationalFun() )
	{
		vm.getSmbTable().AddLine( _T("internal problem while running: variable address in rational function call is out of range") );
		vm.setError();
		return 1 - addr.param3;
	}
#endif
	vm.m_var_table[ addr.param2 ].getRationalFun()->getValue( *(arg - 1), *(arg - 1) );
	return 1 - addr.param3;
}

///////////////////////////////////////////////////////////////////////////////
