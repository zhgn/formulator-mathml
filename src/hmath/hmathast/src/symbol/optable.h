

#if !defined( __PARSEDSR_SYMBOL_OPTABLE_H__ )
#define __PARSEDSR_SYMBOL_OPTABLE_H__

#include "../hmathast_global.h"

///////////////////////////////////////////////////////////////////////////////

#define CDsrOptionTable__DblPrecision 3
struct __HMATHLNGDLL__ CDsrOptionTable
{
	long print__double_prec;	// print option: digits after floating point

	CDsrOptionTable( void )
	{
		print__double_prec = CDsrOptionTable__DblPrecision;
	}
	void setPrint_DoublePrec( long v = CDsrOptionTable__DblPrecision )
	{ print__double_prec = v; }
	long getPrint_DoublePrec( void )
	{ return print__double_prec; }
};

///////////////////////////////////////////////////////////////////////////////

#endif
