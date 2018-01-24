

#include <QString>
#include "../cdsrarrays/cdsrarray.h"
#include "../cdsrarrays/cdsrmatrix.h"
#include "internalfunc.h"

void GetHurwitzMatrix(CDSRArray<CDSRReal>& polynom, long order, CDSRMatrix<CDSRReal>& HurwitzMatrix)
{
	long i, j;
	HurwitzMatrix.resize_matrix(order, order);
	for( i = 0; i < order; i++ )
		for( j = 0; j < order; j++ )
			HurwitzMatrix(j, i) = ( 2 * i + 1 - j < (long) polynom.size() ) && ( 2 * i + 1 - j >= 0 ) ? polynom[ 2 * i + 1 - j ] : 0.0;
}

//////////////////////////////////////////////////////////////////////

void ComplexNumberNthRoot(CDSRComplex x, long power, CDSRArray<CDSRComplex>& roots)
{
	double r, _arg;
	r = pow(abs(x), (double) 1 / power);
	_arg = arg(x);
	roots.resize(power);
	for( long i = 0; i < power; i++ )
		roots[ i ] = CDSRComplex( r * cos( ( _arg + i * MATH_2_PI ) / power), r * sin(( _arg + i * MATH_2_PI ) / power) );
}

//////////////////////////////////////////////////////////////////////

double fact( long ii )
{
	if( !ii ) return 1.0;
	double p = (double)ii;
	for( --ii; ii > 0; ii-- )
		p *= ii;
	return p;
}

//////////////////////////////////////////////////////////////////////

double C_nj( long n, long j)
{
	return fact(n) / ( fact(j) * fact(n - j));
}

void complexBinomNewton(CDSRArray<CDSRComplex>& nBinomial, long lPower, CDSRArray<CDSRComplex>& nResult)
{
	nResult.resize(lPower + 1);
	for( long i = 0; i < lPower + 1; i++ )
		nResult[ i ] = C_nj(lPower, i)*pow(nBinomial[ 0 ], lPower - i)*pow(nBinomial[ 1 ], i);
}

/////////////////////////////////////////////////////////////////////////////////////
// convertions for Watch

/////////////////////////////////////////////////////////////////////////////////////
// 
QString CreateComplexNumberString(CDSRComplex number)
{
	QString result;

	if( number.real() != 0.0 )
	{
		result = QString("%1").arg( number.real() );
		if( number.imag() != 0.0 )
			result += (number.imag() > 0.0) ? QString("+%1").arg( number.imag() ) : QString("%1").arg( number.imag() );
	}
	else
		if( number.imag() == 0.0 )
			result = "0.0";
		else
			result = QString("%1i").arg( number.imag() );
	return result;
}

/////////////////////////////////////////////////////////////////////////////////////

QString CreatePolynomAnyPowerString(CDSRArray<CDSRComplex>& polynom)
{
	QString result, str, _str;

	unsigned long i;
	for( i = 0; i < polynom.size(); i++ )
	{
		if( i != 0 )
                {
			if( polynom[ i ].real() != 0.0 && polynom[ i ].imag() != 0.0 )
				result += "+(";
			else
                        {
				if( polynom[ i ].real() > 0.0 || polynom[ i ].imag() > 0.0 )
					result += "+";
                        }
                }
		switch( polynom.size() - i )
		{
		case 1 :
			str = CreateComplexNumberString(polynom[ i ]);
			str += ( polynom[ i ].real() != 0.0 && polynom[ i ].imag() != 0.0 ) ? ")" : "";
			break;

		case 2 :
			if( polynom[ i ].imag() == 0.0 )
				str = polynom[ i ].real() > 0.0 ? "x" : "-x";
			else
				str = CreateComplexNumberString(polynom[ i ]) + ( ( polynom[ i ].real() != 0.0 && polynom[ i ].imag() != 0.0 ) ? ")" : "" ) + "*x";
			break;

		default:
			if( fabs( polynom[ i ].real() ) == 1.0 && polynom[ i ].imag() == 0.0 )
			{
				str = QString("x^%1").arg( polynom.size() - 1 - i );
				str = ( polynom[ i ].real() > 0.0 ? "" : "-" ) + str;
			}
			else
			{
				str = QString("%1").arg( polynom.size() - 1 - i );
				if( polynom[ i ].real() != 0.0 && polynom[ i ].imag() != 0.0 )
					str = CreateComplexNumberString(polynom[ i ]) + ")*x^" + _str;
				else
					str = CreateComplexNumberString(polynom[ i ]) + "*x^" + _str;
			}
			break;
		}
		if( !( polynom[ i ].real() == 0.0 && polynom[ i ].imag() == 0.0 ) )
			result += str;
	}
	return result;
}
