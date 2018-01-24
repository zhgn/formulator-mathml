

#include "../execop_call.h"
#include "../../vmevallink.h"

///////////////////////////////////////////////////////////////////////////////

__HMATHLNGDLL__
void _call_dsrop_Mul_natural( UniWord *arg )
{
	_dsrop_Mul_natural( *(arg - 2), *(arg - 2), *(arg - 1) );
}
__HMATHLNGDLL__
void _call_dsrop_Mul_integer( UniWord *arg )
{
	_dsrop_Mul_integer( *(arg - 2), *(arg - 2), *(arg - 1) );
}
__HMATHLNGDLL__
void _call_dsrop_Mul_rational( UniWord *arg )
{
	_dsrop_Mul_rational( *(arg - 2), *(arg - 2), *(arg - 1) );
}
__HMATHLNGDLL__
void _call_dsrop_Mul_real( UniWord *arg )
{
	_dsrop_Mul_real( *(arg - 2), *(arg - 2), *(arg - 1) );
}
__HMATHLNGDLL__
void _call_dsrop_Mul_complex( UniWord *arg )
{
	_dsrop_Mul_complex( *(arg - 2), *(arg - 2), *(arg - 1) );
}

__HMATHLNGDLL__
void _call_dsrop_PolynomialMul_integer( UniWord *arg )
{
	*(arg - 2) = _dsrop_PolynomialMul_integer( (arg - 2)->getPolynomial(), (arg - 1)->getPolynomial() );
}
__HMATHLNGDLL__
void _call_dsrop_PolynomialMul_real( UniWord *arg )
{
	*(arg - 2) = _dsrop_PolynomialMul_real( (arg - 2)->getPolynomial(), (arg - 1)->getPolynomial() );
}
__HMATHLNGDLL__
void _call_dsrop_PolynomialMul_complex( UniWord *arg )
{
	*(arg - 2) = _dsrop_PolynomialMul_complex( (arg - 2)->getPolynomial(), (arg - 1)->getPolynomial() );
}

__HMATHLNGDLL__
void _call_dsrop_RationalFunMul_integer( UniWord *arg )
{
	*(arg - 2) = _dsrop_RationalFunMul_integer( (arg - 2)->getRationalFun(), (arg - 1)->getRationalFun() );
}
__HMATHLNGDLL__
void _call_dsrop_RationalFunMul_real( UniWord *arg )
{
	*(arg - 2) = _dsrop_RationalFunMul_real( (arg - 2)->getRationalFun(), (arg - 1)->getRationalFun() );
}
__HMATHLNGDLL__
void _call_dsrop_RationalFunMul_complex( UniWord *arg )
{
	*(arg - 2) = _dsrop_RationalFunMul_complex( (arg - 2)->getRationalFun(), (arg - 1)->getRationalFun() );
}

__HMATHLNGDLL__
void _call_dsrop_VectorMul_natural( UniWord *arg )
{
	*(arg - 2) = _dsrop_VectorMul_natural( (arg - 2)->getVector(), (arg - 1)->getVector() );
}
__HMATHLNGDLL__
void _call_dsrop_VectorMul_integer( UniWord *arg )
{
	*(arg - 2) = _dsrop_VectorMul_integer( (arg - 2)->getVector(), (arg - 1)->getVector() );
}
__HMATHLNGDLL__
void _call_dsrop_VectorMul_rational( UniWord *arg )
{
	*(arg - 2) = _dsrop_VectorMul_rational( (arg - 2)->getVector(), (arg - 1)->getVector() );
}
__HMATHLNGDLL__
void _call_dsrop_VectorMul_real( UniWord *arg )
{
	*(arg - 2) = _dsrop_VectorMul_real( (arg - 2)->getVector(), (arg - 1)->getVector() );
}
__HMATHLNGDLL__
void _call_dsrop_VectorMul_complex( UniWord *arg )
{
	*(arg - 2) = _dsrop_VectorMul_complex( (arg - 2)->getVector(), (arg - 1)->getVector() );
}

__HMATHLNGDLL__
void _call_dsrop_Mul_group_string( UniWord * /*arg*/ )
{
	// vasya : group QString mul
}

__HMATHLNGDLL__
void _call_dsrop_VectorScalarMul_natural( UniWord *arg )
{
	*(arg - 2) = _dsrop_VectorScalarMul_natural( (arg - 2)->getVector(), (arg - 1)->getVector() );
}
__HMATHLNGDLL__
void _call_dsrop_VectorScalarMul_integer( UniWord *arg )
{
	*(arg - 2) = _dsrop_VectorScalarMul_integer( (arg - 2)->getVector(), (arg - 1)->getVector() );
}
__HMATHLNGDLL__
void _call_dsrop_VectorScalarMul_rational( UniWord *arg )
{
	*(arg - 2) = _dsrop_VectorScalarMul_rational( (arg - 2)->getVector(), (arg - 1)->getVector() );
}
__HMATHLNGDLL__
void _call_dsrop_VectorScalarMul_real( UniWord *arg )
{
	*(arg - 2) = _dsrop_VectorScalarMul_real( (arg - 2)->getVector(), (arg - 1)->getVector() );
}
__HMATHLNGDLL__
void _call_dsrop_VectorScalarMul_complex( UniWord *arg )
{
	*(arg - 2) = _dsrop_VectorScalarMul_complex( (arg - 2)->getVector(), (arg - 1)->getVector() );
}

__HMATHLNGDLL__
void _call_dsrop_VectorMulConst_natural( UniWord *arg )
{
	*(arg - 2) = _dsrop_VectorMul_natural( (arg - 2)->getVector(), *(arg - 1) );
}
__HMATHLNGDLL__
void _call_dsrop_VectorMulConst_integer( UniWord *arg )
{
	*(arg - 2) = _dsrop_VectorMul_integer( (arg - 2)->getVector(), *(arg - 1) );
}
__HMATHLNGDLL__
void _call_dsrop_VectorMulConst_rational( UniWord *arg )
{
	*(arg - 2) = _dsrop_VectorMul_rational( (arg - 2)->getVector(), *(arg - 1) );
}
__HMATHLNGDLL__
void _call_dsrop_VectorMulConst_real( UniWord *arg )
{
	*(arg - 2) = _dsrop_VectorMul_real( (arg - 2)->getVector(), *(arg - 1) );
}
__HMATHLNGDLL__
void _call_dsrop_VectorMulConst_complex( UniWord *arg )
{
	*(arg - 2) = _dsrop_VectorMul_complex( (arg - 2)->getVector(), *(arg - 1) );
}

__HMATHLNGDLL__
void _call_dsrop_natural_VectorMulConst( UniWord *arg )
{
	*(arg - 2) = _dsrop_VectorMul_natural( (arg - 1)->getVector(), *(arg - 2) );
}
__HMATHLNGDLL__
void _call_dsrop_integer_VectorMulConst( UniWord *arg )
{
	*(arg - 2) = _dsrop_VectorMul_integer( (arg - 1)->getVector(), *(arg - 2) );
}
__HMATHLNGDLL__
void _call_dsrop_rational_VectorMulConst( UniWord *arg )
{
	*(arg - 2) = _dsrop_VectorMul_rational( (arg - 1)->getVector(), *(arg - 2) );
}
__HMATHLNGDLL__
void _call_dsrop_real_VectorMulConst( UniWord *arg )
{
	*(arg - 2) = _dsrop_VectorMul_real( (arg - 1)->getVector(), *(arg - 2) );
}
__HMATHLNGDLL__
void _call_dsrop_complex_VectorMulConst( UniWord *arg )
{
	*(arg - 2) = _dsrop_VectorMul_complex( (arg - 1)->getVector(), *(arg - 2) );
}

__HMATHLNGDLL__
void _call_dsrop_SetDecartMul( UniWord *arg )
{
	*(arg - 2) = _dsrop_SetDecartMul( (arg - 2)->getSet(), (arg - 1)->getSet() );
}

///////////////////////////////////////////////////////////////////////////////

typedef void (*SUBCALL_MUL)( UniWord *arg );
#define __Call_Mul_subcalls_LENGTH	33
static SUBCALL_MUL __Call_Mul_subcalls[ __Call_Mul_subcalls_LENGTH ] = 
{
	_call_dsrop_Mul_natural,
	_call_dsrop_Mul_integer,
	_call_dsrop_Mul_rational,
	_call_dsrop_Mul_real,
	_call_dsrop_Mul_complex,
	_call_dsrop_PolynomialMul_integer,
	_call_dsrop_PolynomialMul_real,
	_call_dsrop_PolynomialMul_complex,
	_call_dsrop_RationalFunMul_integer,
	_call_dsrop_RationalFunMul_real,
	_call_dsrop_RationalFunMul_complex,
	_call_dsrop_VectorMul_natural,
	_call_dsrop_VectorMul_integer,
	_call_dsrop_VectorMul_rational,
	_call_dsrop_VectorMul_real,
	_call_dsrop_VectorMul_complex,
	_call_dsrop_Mul_group_string,
	_call_dsrop_VectorScalarMul_natural,
	_call_dsrop_VectorScalarMul_integer,
	_call_dsrop_VectorScalarMul_rational,
	_call_dsrop_VectorScalarMul_real,
	_call_dsrop_VectorScalarMul_complex,
	_call_dsrop_VectorMulConst_natural,
	_call_dsrop_VectorMulConst_integer,
	_call_dsrop_VectorMulConst_rational,
	_call_dsrop_VectorMulConst_real,
	_call_dsrop_VectorMulConst_complex,
	_call_dsrop_natural_VectorMulConst,
	_call_dsrop_integer_VectorMulConst,
	_call_dsrop_rational_VectorMulConst,
	_call_dsrop_real_VectorMulConst,
	_call_dsrop_complex_VectorMulConst,
	_call_dsrop_SetDecartMul
};
long __Call_Mul( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
#if _DEBUG
	if( addr.param2 < 0 || 
		addr.param2 >= __Call_Mul_subcalls_LENGTH )
		throw _T("__Call_Mul : internal error, out of range");
#endif
	__Call_Mul_subcalls[ addr.param2 ]( arg );
	return 1 - addr.param3;
}

///////////////////////////////////////////////////////////////////////////////
