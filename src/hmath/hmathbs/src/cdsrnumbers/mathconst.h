

#if !defined(__MATHEMATICAL_CONST_H__)
#define __MATHEMATICAL_CONST_H__

#include <float.h>

//////////////////////////////////////////////////////////////////////
#define MATH_2_PI			6.283185307179586476925286766559
#define MATH_3_PI_2			4.7123889803846898576939650749193
#define MATH_PI				3.1415926535897932384626433832795
#define MATH_PI_2			1.5707963267948966192313216916398
#define MATH_PI_3			1.0471975511965977461542144610932
#define MATH_PI_4			0.78539816339744830961566084581988
#define MATH_PI_6			0.52359877559829887307710723054658

//////////////////////////////////////////////////////////////////////

#define MATH_REAL_EPSILON	(1e3 * DBL_EPSILON)

//////////////////////////////////////////////////////////////////////
#define POLYNOM_MAXITERS				1024
#define POLYNOM_PRECISION				1e-6

#define ALMASLAE_SITER_PREC				1e-4
#define ALMASLAE_MAX_ITER_COUNT			1024

#define ALMAFUNC_ITERATIONCOUNT			1024
#define ALMAFUNC_PRECISION				1e-3
#define ALMAFUNC_FIRST_APPR				1e-1

#define ALMA_ODE_PREC					1e-3
#define ALMA_ODE_PREC_MUL				1e-2

#define EIGENVALUES_PRECISION			1e-3

//////////////////////////////////////////////////////////////////////

#endif // __MATHEMATICAL_CONST_H__
