

#include "execop_call.h"
#include "../vmevallink.h"

///////////////////////////////////////////////////////////////////////////////

long __Call_Convert_natural2integer( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
	_dsrop_Convert_natural2integer( *(arg - 1), *(arg - 1) );
	return 1 - addr.param3;
}

long __Call_Convert_natural2bits( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
	_dsrop_Convert_natural2bits( *(arg - 1), *(arg - 1) );
	return 1 - addr.param3;
}

long __Call_Convert_natural2rational( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
	_dsrop_Convert_natural2rational( *(arg - 1), *(arg - 1) );
	return 1 - addr.param3;
}

long __Call_Convert_natural2real( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
	_dsrop_Convert_natural2real( *(arg - 1), *(arg - 1) );
	return 1 - addr.param3;
}

long __Call_Convert_natural2complex( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
	_dsrop_Convert_natural2complex( *(arg - 1), *(arg - 1) );
	return 1 - addr.param3;
}

long __Call_Convert_integer2bits( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
	_dsrop_Convert_integer2bits( *(arg - 1), *(arg - 1) );
	return 1 - addr.param3;
}

long __Call_Convert_integer2rational( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
	_dsrop_Convert_integer2rational( *(arg - 1), *(arg - 1) );
	return 1 - addr.param3;
}

long __Call_Convert_integer2real( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
	_dsrop_Convert_integer2real( *(arg - 1), *(arg - 1) );
	return 1 - addr.param3;
}

long __Call_Convert_integer2complex( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
	_dsrop_Convert_integer2complex( *(arg - 1), *(arg - 1) );
	return 1 - addr.param3;
}

long __Call_Convert_rational2real( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
	_dsrop_Convert_rational2real( *(arg - 1), *(arg - 1) );
	return 1 - addr.param3;
}

long __Call_Convert_rational2complex( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
	_dsrop_Convert_rational2complex( *(arg - 1), *(arg - 1) );
	return 1 - addr.param3;
}

long __Call_Convert_real2complex( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
	_dsrop_Convert_real2complex( *(arg - 1), *(arg - 1) );
	return 1 - addr.param3;
}

long __Call_Convert_natural2Polynomial_integer( CDSR_VMEval& vm, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_Convert_natural2Polynomial_integer( *(arg - 1), vm.getSmbTable() );
	return 1 - addr.param3;
}

long __Call_Convert_natural2Polynomial_real( CDSR_VMEval& vm, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_Convert_natural2Polynomial_real( *(arg - 1), vm.getSmbTable() );
	return 1 - addr.param3;
}

long __Call_Convert_natural2Polynomial_complex( CDSR_VMEval& vm, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_Convert_natural2Polynomial_complex( *(arg - 1), vm.getSmbTable() );
	return 1 - addr.param3;
}

long __Call_Convert_natural2RationalFun_integer( CDSR_VMEval& vm, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_Convert_natural2RationalFun_integer( *(arg - 1), vm.getSmbTable() );
	return 1 - addr.param3;
}

long __Call_Convert_natural2RationalFun_real( CDSR_VMEval& vm, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_Convert_natural2RationalFun_real( *(arg - 1), vm.getSmbTable() );
	return 1 - addr.param3;
}

long __Call_Convert_natural2RationalFun_complex( CDSR_VMEval& vm, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_Convert_natural2RationalFun_complex( *(arg - 1), vm.getSmbTable() );
	return 1 - addr.param3;
}

long __Call_Convert_integer2Polynomial_integer( CDSR_VMEval& vm, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_Convert_integer2Polynomial_integer( *(arg - 1), vm.getSmbTable() );
	return 1 - addr.param3;
}

long __Call_Convert_integer2Polynomial_real( CDSR_VMEval& vm, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_Convert_integer2Polynomial_real( *(arg - 1), vm.getSmbTable() );
	return 1 - addr.param3;
}

long __Call_Convert_integer2Polynomial_complex( CDSR_VMEval& vm, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_Convert_integer2Polynomial_complex( *(arg - 1), vm.getSmbTable() );
	return 1 - addr.param3;
}

long __Call_Convert_integer2RationalFun_integer( CDSR_VMEval& vm, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_Convert_integer2RationalFun_integer( *(arg - 1), vm.getSmbTable() );
	return 1 - addr.param3;
}

long __Call_Convert_integer2RationalFun_real( CDSR_VMEval& vm, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_Convert_integer2RationalFun_real( *(arg - 1), vm.getSmbTable() );
	return 1 - addr.param3;
}

long __Call_Convert_integer2RationalFun_complex( CDSR_VMEval& vm, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_Convert_integer2RationalFun_complex( *(arg - 1), vm.getSmbTable() );
	return 1 - addr.param3;
}

long __Call_Convert_rational2Polynomial_real( CDSR_VMEval& vm, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_Convert_rational2Polynomial_real( *(arg - 1), vm.getSmbTable() );
	return 1 - addr.param3;
}

long __Call_Convert_rational2Polynomial_complex( CDSR_VMEval& vm, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_Convert_rational2Polynomial_complex( *(arg - 1), vm.getSmbTable() );
	return 1 - addr.param3;
}

long __Call_Convert_rational2RationalFun_real( CDSR_VMEval& vm, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_Convert_rational2RationalFun_real( *(arg - 1), vm.getSmbTable() );
	return 1 - addr.param3;
}

long __Call_Convert_rational2RationalFun_complex( CDSR_VMEval& vm, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_Convert_rational2RationalFun_complex( *(arg - 1), vm.getSmbTable() );
	return 1 - addr.param3;
}

long __Call_Convert_real2Polynomial_real( CDSR_VMEval& vm, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_Convert_real2Polynomial_real( *(arg - 1), vm.getSmbTable() );
	return 1 - addr.param3;
}

long __Call_Convert_real2Polynomial_complex( CDSR_VMEval& vm, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_Convert_real2Polynomial_complex( *(arg - 1), vm.getSmbTable() );
	return 1 - addr.param3;
}

long __Call_Convert_real2RationalFun_real( CDSR_VMEval& vm, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_Convert_real2RationalFun_real( *(arg - 1), vm.getSmbTable() );
	return 1 - addr.param3;
}

long __Call_Convert_real2RationalFun_complex( CDSR_VMEval& vm, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_Convert_real2RationalFun_complex( *(arg - 1), vm.getSmbTable() );
	return 1 - addr.param3;
}

long __Call_Convert_complex2Polynomial_complex( CDSR_VMEval& vm, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_Convert_complex2Polynomial_complex( *(arg - 1), vm.getSmbTable() );
	return 1 - addr.param3;
}

long __Call_Convert_complex2RationalFun_complex( CDSR_VMEval& vm, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_Convert_complex2RationalFun_complex( *(arg - 1), vm.getSmbTable() );
	return 1 - addr.param3;
}

long __Call_Convert_Polynomial_integer2Polynomial_real( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_Convert_Polynomial_integer2Polynomial_real( (arg - 1)->getPolynomial() );
	return 1 - addr.param3;
}

long __Call_Convert_Polynomial_integer2Polynomial_complex( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_Convert_Polynomial_integer2Polynomial_complex( (arg - 1)->getPolynomial() );
	return 1 - addr.param3;
}

long __Call_Convert_Polynomial_real2Polynomial_complex( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_Convert_Polynomial_real2Polynomial_complex( (arg - 1)->getPolynomial() );
	return 1 - addr.param3;
}

long __Call_Convert_Polynomial_integer2RationalFun_integer( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_Convert_Polynomial_integer2RationalFun_integer( (arg - 1)->getPolynomial() );
	return 1 - addr.param3;
}

long __Call_Convert_Polynomial_integer2RationalFun_real( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_Convert_Polynomial_integer2RationalFun_real( (arg - 1)->getPolynomial() );
	return 1 - addr.param3;
}

long __Call_Convert_Polynomial_integer2RationalFun_complex( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_Convert_Polynomial_integer2RationalFun_complex( (arg - 1)->getPolynomial() );
	return 1 - addr.param3;
}

long __Call_Convert_Polynomial_real2RationalFun_real( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_Convert_Polynomial_real2RationalFun_real( (arg - 1)->getPolynomial() );
	return 1 - addr.param3;
}

long __Call_Convert_Polynomial_real2RationalFun_complex( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_Convert_Polynomial_real2RationalFun_complex( (arg - 1)->getPolynomial() );
	return 1 - addr.param3;
}

long __Call_Convert_Polynomial_complex2RationalFun_complex( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_Convert_Polynomial_complex2RationalFun_complex( (arg - 1)->getPolynomial() );
	return 1 - addr.param3;
}

long __Call_Convert_RationalFun_integer2RationalFun_real( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_Convert_RationalFun_integer2RationalFun_real( (arg - 1)->getRationalFun() );
	return 1 - addr.param3;
}

long __Call_Convert_RationalFun_integer2RationalFun_complex( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_Convert_RationalFun_integer2RationalFun_complex( (arg - 1)->getRationalFun() );
	return 1 - addr.param3;
}

long __Call_Convert_RationalFun_real2RationalFun_complex( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_Convert_RationalFun_real2RationalFun_complex( (arg - 1)->getRationalFun() );
	return 1 - addr.param3;
}

long __Call_VectorConvert_natural2integer( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_VectorConvert_natural2integer( (arg - 1)->getVector() );
	return 1 - addr.param3;
}

long __Call_VectorConvert_natural2rational( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_VectorConvert_natural2rational( (arg - 1)->getVector() );
	return 1 - addr.param3;
}

long __Call_VectorConvert_natural2real( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_VectorConvert_natural2real( (arg - 1)->getVector() );
	return 1 - addr.param3;
}

long __Call_VectorConvert_natural2complex( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_VectorConvert_natural2complex( (arg - 1)->getVector() );
	return 1 - addr.param3;
}

long __Call_VectorConvert_integer2rational( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_VectorConvert_integer2rational( (arg - 1)->getVector() );
	return 1 - addr.param3;
}

long __Call_VectorConvert_integer2real( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_VectorConvert_integer2real( (arg - 1)->getVector() );
	return 1 - addr.param3;
}

long __Call_VectorConvert_integer2complex( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_VectorConvert_integer2complex( (arg - 1)->getVector() );
	return 1 - addr.param3;
}

long __Call_VectorConvert_rational2real( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_VectorConvert_rational2real( (arg - 1)->getVector() );
	return 1 - addr.param3;
}

long __Call_VectorConvert_rational2complex( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_VectorConvert_rational2complex( (arg - 1)->getVector() );
	return 1 - addr.param3;
}

long __Call_VectorConvert_real2complex( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
	*(arg - 1) = _dsrop_VectorConvert_real2complex( (arg - 1)->getVector() );
	return 1 - addr.param3;
}

///////////////////////////////////////////////////////////////////////////////
