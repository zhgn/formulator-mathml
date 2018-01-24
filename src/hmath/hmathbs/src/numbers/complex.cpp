

#include <math.h>
#include "../cdsrnumbers/cdsrcomplex.h"
#include "complex.h"

#if !defined(M_PI)
#define M_PI        3.14159265358979323846
#endif
#if !defined(M_PI_2)
#define M_PI_2      1.57079632679489661923
#endif
//#define M_PI_4      0.785398163397448309616

/////////////////////////////////////////////////////////////////////////////////////////////
//	Internal Functions

/////////////////////////////////////////////////////////////////////////////////////////////
//
double GetComplexMagnitude(CDSRComplex& c)
{
	return (sqrt(c.real()*c.real() + c.imag()*c.imag()));
}

/////////////////////////////////////////////////////////////////////////////////////////////
//
double GetComplexPhaseAngle(CDSRComplex& c)
{
	double r, im;

	r = c.real(); im = c.imag();
	if(r == 0)
	{
		if(im >= 0)
			return (M_PI_2); // r == 0 && im > 0
		else
			return (-M_PI_2); // r == 0 && im < 0
	}
	else
	{
		if(r < 0)
		{
			if(im >= 0)
				return (atan(im / r) + M_PI); // r < 0 && im >=0
			else
				return (atan(im / r) - M_PI); // r < 0 && im < 0
		}
		else
			return atan(im / r);  // r > 0;
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////

MATHBASE_API void ConvertComplexNumberForm(CDSRComplex& src, CDSRComplex& dest, COMPLEX_NUMBER_FORM destForm, COMPLEX_NUMBER_FORM srcForm)
{
	if(srcForm == destForm)
	{
		dest = src;
		return;
	}//end if

	switch(srcForm)
	{
	case CNF_ALGERAIC:

		switch(destForm)
		{
		case CNF_EXPONENTIAL:
		case CNF_TRIGONOMETRIC:
			{
				dest = CDSRComplex(GetComplexMagnitude(src), GetComplexPhaseAngle(src));
				break;
			}//ens case CNF_EXPONENTIAL
		default:
			dest = src;
		}//end switch(destForm)

		break;

	case CNF_EXPONENTIAL:
	case CNF_TRIGONOMETRIC:

		switch(destForm)
		{
		case CNF_ALGERAIC:
			{
				dest = CDSRComplex(std::polar(src.real(), src.imag()));
				break;
			}//ens case CNF_ALGERAIC
		default:
			dest = src;
		}//end switch(destForm)

		break;
	}//end switch(srcForm)
}

