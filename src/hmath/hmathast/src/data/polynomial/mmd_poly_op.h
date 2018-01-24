

#ifndef __PARSEDSR_DATA_MMD_POLY_OP_H__
#define __PARSEDSR_DATA_MMD_POLY_OP_H__

#include "../uniword/uniword_op.h"
#include "mmd_poly.h"
#include "mmd_ratf.h"

///////////////////////////////////////////////////////////////////////////////

__HMATHLNGDLL__
MMD_Polynomial* _dsrop_PolynomialAdd_integer( MMD_Polynomial *a, MMD_Polynomial *b );
__HMATHLNGDLL__
MMD_Polynomial* _dsrop_PolynomialAdd_real( MMD_Polynomial *a, MMD_Polynomial *b );
__HMATHLNGDLL__
MMD_Polynomial* _dsrop_PolynomialAdd_complex( MMD_Polynomial *a, MMD_Polynomial *b );
__HMATHLNGDLL__
MMD_Polynomial* _dsrop_PolynomialPlus_integer( MMD_Polynomial *a );
__HMATHLNGDLL__
MMD_Polynomial* _dsrop_PolynomialPlus_real( MMD_Polynomial *a );
__HMATHLNGDLL__
MMD_Polynomial* _dsrop_PolynomialPlus_complex( MMD_Polynomial *a );
__HMATHLNGDLL__
MMD_Polynomial* _dsrop_PolynomialSub_integer( MMD_Polynomial *a, MMD_Polynomial *b );
__HMATHLNGDLL__
MMD_Polynomial* _dsrop_PolynomialSub_real( MMD_Polynomial *a, MMD_Polynomial *b );
__HMATHLNGDLL__
MMD_Polynomial* _dsrop_PolynomialSub_complex( MMD_Polynomial *a, MMD_Polynomial *b );
__HMATHLNGDLL__
MMD_Polynomial* _dsrop_PolynomialMinus_integer( MMD_Polynomial *a );
__HMATHLNGDLL__
MMD_Polynomial* _dsrop_PolynomialMinus_real( MMD_Polynomial *a );
__HMATHLNGDLL__
MMD_Polynomial* _dsrop_PolynomialMinus_complex( MMD_Polynomial *a );
__HMATHLNGDLL__
MMD_Polynomial* _dsrop_PolynomialMul_integer( MMD_Polynomial *a, MMD_Polynomial *b );
__HMATHLNGDLL__
MMD_Polynomial* _dsrop_PolynomialMul_real( MMD_Polynomial *a, MMD_Polynomial *b );
__HMATHLNGDLL__
MMD_Polynomial* _dsrop_PolynomialMul_complex( MMD_Polynomial *a, MMD_Polynomial *b );
__HMATHLNGDLL__
MMD_RationalFun* _dsrop_PolynomialDiv_anytype( MMD_Polynomial *a, MMD_Polynomial *b );
__HMATHLNGDLL__
MMD_RationalFun* _dsrop_PolynomialDiv_integer( MMD_Polynomial *a, MMD_Polynomial *b );
__HMATHLNGDLL__
MMD_RationalFun* _dsrop_PolynomialDiv_real( MMD_Polynomial *a, MMD_Polynomial *b );
__HMATHLNGDLL__
MMD_RationalFun* _dsrop_PolynomialDiv_complex( MMD_Polynomial *a, MMD_Polynomial *b );
__HMATHLNGDLL__
MMD_Polynomial* _dsrop_PolynomialDiv_integer( MMD_Polynomial *a, UniWord& b );
__HMATHLNGDLL__
MMD_Polynomial* _dsrop_PolynomialDiv_real( MMD_Polynomial *a, UniWord& b );
__HMATHLNGDLL__
MMD_Polynomial* _dsrop_PolynomialDiv_complex( MMD_Polynomial *a, UniWord& b );
__HMATHLNGDLL__
MMD_Polynomial* _dsrop_PolynomialPow_anytype( MMD_Polynomial *a, UniWord& b );
__HMATHLNGDLL__
MMD_Polynomial* _dsrop_PolynomialPow_integer( MMD_Polynomial *a, UniWord& b );
__HMATHLNGDLL__
MMD_Polynomial* _dsrop_PolynomialPow_real( MMD_Polynomial *a, UniWord& b );
__HMATHLNGDLL__
MMD_Polynomial* _dsrop_PolynomialPow_complex( MMD_Polynomial *a, UniWord& b );
__HMATHLNGDLL__
UniWord _dsrop_PolynomialEqual_anytype( MMD_Polynomial *a, MMD_Polynomial *b );
__HMATHLNGDLL__
UniWord _dsrop_PolynomialEqual_integer( MMD_Polynomial *a, MMD_Polynomial *b );
__HMATHLNGDLL__
UniWord _dsrop_PolynomialEqual_real( MMD_Polynomial *a, MMD_Polynomial *b );
__HMATHLNGDLL__
UniWord _dsrop_PolynomialEqual_complex( MMD_Polynomial *a, MMD_Polynomial *b );
__HMATHLNGDLL__
UniWord _dsrop_PolynomialNotEqual_integer( MMD_Polynomial *a, MMD_Polynomial *b );
__HMATHLNGDLL__
UniWord _dsrop_PolynomialNotEqual_real( MMD_Polynomial *a, MMD_Polynomial *b );
__HMATHLNGDLL__
UniWord _dsrop_PolynomialNotEqual_complex( MMD_Polynomial *a, MMD_Polynomial *b );
__HMATHLNGDLL__
MMD_Polynomial* _dsrop_PolynomialAssign_anytype( MMD_Polynomial *a, MMD_Polynomial *b );
__HMATHLNGDLL__
MMD_Polynomial* _dsrop_PolynomialAssign_integer( MMD_Polynomial *a, MMD_Polynomial *b );
__HMATHLNGDLL__
MMD_Polynomial* _dsrop_PolynomialAssign_real( MMD_Polynomial *a, MMD_Polynomial *b );
__HMATHLNGDLL__
MMD_Polynomial* _dsrop_PolynomialAssign_complex( MMD_Polynomial *a, MMD_Polynomial *b );
__HMATHLNGDLL__
MMD_Polynomial* _dsrop_Convert_natural2Polynomial_integer( UniWord& a, CParseDsrSymbolTable& _smbtable );
__HMATHLNGDLL__
MMD_Polynomial* _dsrop_Convert_natural2Polynomial_real( UniWord& a, CParseDsrSymbolTable& _smbtable );
__HMATHLNGDLL__
MMD_Polynomial* _dsrop_Convert_natural2Polynomial_complex( UniWord& a, CParseDsrSymbolTable& _smbtable );
__HMATHLNGDLL__
MMD_Polynomial* _dsrop_Convert_integer2Polynomial_integer( UniWord& a, CParseDsrSymbolTable& _smbtable );
__HMATHLNGDLL__
MMD_Polynomial* _dsrop_Convert_integer2Polynomial_real( UniWord& a, CParseDsrSymbolTable& _smbtable );
__HMATHLNGDLL__
MMD_Polynomial* _dsrop_Convert_integer2Polynomial_complex( UniWord& a, CParseDsrSymbolTable& _smbtable );
__HMATHLNGDLL__
MMD_Polynomial* _dsrop_Convert_rational2Polynomial_real( UniWord& a, CParseDsrSymbolTable& _smbtable );
__HMATHLNGDLL__
MMD_Polynomial* _dsrop_Convert_rational2Polynomial_complex( UniWord& a, CParseDsrSymbolTable& _smbtable );
__HMATHLNGDLL__
MMD_Polynomial* _dsrop_Convert_real2Polynomial_real( UniWord& a, CParseDsrSymbolTable& _smbtable );
__HMATHLNGDLL__
MMD_Polynomial* _dsrop_Convert_real2Polynomial_complex( UniWord& a, CParseDsrSymbolTable& _smbtable );
__HMATHLNGDLL__
MMD_Polynomial* _dsrop_Convert_complex2Polynomial_complex( UniWord& a, CParseDsrSymbolTable& _smbtable );
__HMATHLNGDLL__
MMD_Polynomial* _dsrop_Convert_Polynomial_integer2Polynomial_real( MMD_Polynomial* a );
__HMATHLNGDLL__
MMD_Polynomial* _dsrop_Convert_Polynomial_integer2Polynomial_complex( MMD_Polynomial* a );
__HMATHLNGDLL__
MMD_Polynomial* _dsrop_Convert_Polynomial_real2Polynomial_complex( MMD_Polynomial* a );
__HMATHLNGDLL__
MMD_RationalFun* _dsrop_Convert_Polynomial_integer2RationalFun_integer( MMD_Polynomial* a );
__HMATHLNGDLL__
MMD_RationalFun* _dsrop_Convert_Polynomial_integer2RationalFun_real( MMD_Polynomial* a );
__HMATHLNGDLL__
MMD_RationalFun* _dsrop_Convert_Polynomial_integer2RationalFun_complex( MMD_Polynomial* a );
__HMATHLNGDLL__
MMD_RationalFun* _dsrop_Convert_Polynomial_real2RationalFun_real( MMD_Polynomial* a );
__HMATHLNGDLL__
MMD_RationalFun* _dsrop_Convert_Polynomial_real2RationalFun_complex( MMD_Polynomial* a );
__HMATHLNGDLL__
MMD_RationalFun* _dsrop_Convert_Polynomial_complex2RationalFun_complex( MMD_Polynomial* a );

///////////////////////////////////////////////////////////////////////////////

#endif
