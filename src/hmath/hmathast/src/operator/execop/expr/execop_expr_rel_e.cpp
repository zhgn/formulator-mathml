

#include "../execop_call.h"
#include "../../vmevallink.h"

///////////////////////////////////////////////////////////////////////////////

__HMATHLNGDLL__
void _call_dsrop_Equal_natural( UniWord *arg )
{
	_dsrop_Equal_natural( *(arg - 2), *(arg - 2), *(arg - 1) );
}
__HMATHLNGDLL__
void _call_dsrop_Equal_integer( UniWord *arg )
{
	_dsrop_Equal_integer( *(arg - 2), *(arg - 2), *(arg - 1) );
}
__HMATHLNGDLL__
void _call_dsrop_Equal_rational( UniWord *arg )
{
	_dsrop_Equal_rational( *(arg - 2), *(arg - 2), *(arg - 1) );
}
__HMATHLNGDLL__
void _call_dsrop_Equal_real( UniWord *arg )
{
	_dsrop_Equal_real( *(arg - 2), *(arg - 2), *(arg - 1) );
}
__HMATHLNGDLL__
void _call_dsrop_Equal_complex( UniWord *arg )
{
	_dsrop_Equal_complex( *(arg - 2), *(arg - 2), *(arg - 1) );
}
__HMATHLNGDLL__
void _call_dsrop_Equal_bool( UniWord *arg )
{
	_dsrop_Equal_bool( *(arg - 2), *(arg - 2), *(arg - 1) );
}
__HMATHLNGDLL__
void _call_dsrop_Equal_string( UniWord *arg )
{
	_dsrop_Equal_string( *(arg - 2), *(arg - 2), *(arg - 1) );
}

__HMATHLNGDLL__
void _call_dsrop_PolynomialEqual_integer( UniWord *arg )
{
	*(arg - 2) = _dsrop_PolynomialEqual_integer( (arg - 2)->getPolynomial(), (arg - 1)->getPolynomial() );
}
__HMATHLNGDLL__
void _call_dsrop_PolynomialEqual_real( UniWord *arg )
{
	*(arg - 2) = _dsrop_PolynomialEqual_real( (arg - 2)->getPolynomial(), (arg - 1)->getPolynomial() );
}
__HMATHLNGDLL__
void _call_dsrop_PolynomialEqual_complex( UniWord *arg )
{
	*(arg - 2) = _dsrop_PolynomialEqual_complex( (arg - 2)->getPolynomial(), (arg - 1)->getPolynomial() );
}

__HMATHLNGDLL__
void _call_dsrop_RationalFunEqual_integer( UniWord *arg )
{
	*(arg - 2) = _dsrop_RationalFunEqual_integer( (arg - 2)->getRationalFun(), (arg - 1)->getRationalFun() );
}
__HMATHLNGDLL__
void _call_dsrop_RationalFunEqual_real( UniWord *arg )
{
	*(arg - 2) = _dsrop_RationalFunEqual_real( (arg - 2)->getRationalFun(), (arg - 1)->getRationalFun() );
}
__HMATHLNGDLL__
void _call_dsrop_RationalFunEqual_complex( UniWord *arg )
{
	*(arg - 2) = _dsrop_RationalFunEqual_complex( (arg - 2)->getRationalFun(), (arg - 1)->getRationalFun() );
}

__HMATHLNGDLL__
void _call_dsrop_VectorEqual_natural( UniWord *arg )
{
	*(arg - 2) = _dsrop_VectorEqual_natural( (arg - 2)->getVector(), (arg - 1)->getVector() );
}
__HMATHLNGDLL__
void _call_dsrop_VectorEqual_integer( UniWord *arg )
{
	*(arg - 2) = _dsrop_VectorEqual_integer( (arg - 2)->getVector(), (arg - 1)->getVector() );
}
__HMATHLNGDLL__
void _call_dsrop_VectorEqual_rational( UniWord *arg )
{
	*(arg - 2) = _dsrop_VectorEqual_rational( (arg - 2)->getVector(), (arg - 1)->getVector() );
}
__HMATHLNGDLL__
void _call_dsrop_VectorEqual_real( UniWord *arg )
{
	*(arg - 2) = _dsrop_VectorEqual_real( (arg - 2)->getVector(), (arg - 1)->getVector() );
}
__HMATHLNGDLL__
void _call_dsrop_VectorEqual_complex( UniWord *arg )
{
	*(arg - 2) = _dsrop_VectorEqual_complex( (arg - 2)->getVector(), (arg - 1)->getVector() );
}
__HMATHLNGDLL__
void _call_dsrop_SetEqual( UniWord *arg )
{
	*(arg - 2) = _dsrop_SetEqual_anytype( (arg - 2)->getSet(), (arg - 1)->getSet() );
}

///////////////////////////////////////////////////////////////////////////////

typedef void (*SUBCALL_EQUAL)( UniWord *arg );
#define __Call_Equal_subcalls_LENGTH	19
static SUBCALL_EQUAL __Call_Equal_subcalls[ __Call_Equal_subcalls_LENGTH ] = 
{
	_call_dsrop_Equal_natural,
	_call_dsrop_Equal_integer,
	_call_dsrop_Equal_rational,
	_call_dsrop_Equal_real,
	_call_dsrop_Equal_complex,
	_call_dsrop_Equal_bool,
	_call_dsrop_Equal_string,
	_call_dsrop_PolynomialEqual_integer,
	_call_dsrop_PolynomialEqual_real,
	_call_dsrop_PolynomialEqual_complex,
	_call_dsrop_RationalFunEqual_integer,
	_call_dsrop_RationalFunEqual_real,
	_call_dsrop_RationalFunEqual_complex,
	_call_dsrop_VectorEqual_natural,
	_call_dsrop_VectorEqual_integer,
	_call_dsrop_VectorEqual_rational,
	_call_dsrop_VectorEqual_real,
	_call_dsrop_VectorEqual_complex,
	_call_dsrop_SetEqual
};
long __Call_Equal( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
#if _DEBUG
	if( addr.param2 < 0 || 
		addr.param2 >= __Call_Equal_subcalls_LENGTH )
		throw _T("__Call_Equal : internal error, out of range");
#endif
	__Call_Equal_subcalls[ addr.param2 ]( arg );
	return 1 - addr.param3;
}

///////////////////////////////////////////////////////////////////////////////
