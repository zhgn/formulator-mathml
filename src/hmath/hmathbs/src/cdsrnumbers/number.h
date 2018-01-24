

#if !defined( __COMMON_NUMBER_H__ )
#define __COMMON_NUMBER_H__

#include <complex>
#include <string>

#include "cdsrnatural.h"
#include "cdsrinteger.h"
#include "cdsrrational.h"
#include "cdsrreal.h"
#include "bignumber.h"
#include "rootinfo.h"

typedef double				CDSRIrrationalStorage;
typedef double				CDSRIrrational;
typedef std::complex<double>		CDSRComplexStorage;
typedef std::complex<double>		CDSRComplex;
typedef long				CDSRRangeStorage;
typedef long				CDSRRange;
typedef CBigNumber*			CDSRBitsStorage;
typedef CBigNumber			CDSRBits;

inline
BN_TYPE bit( CDSRBitsStorage bits, unsigned long i )
{
	return bits->testbit( i );
}

typedef CDSRReal			MReal;
typedef CDSRRealStorage		MRealStorage;
typedef CDSRNatural			MNatural;
typedef CDSRNaturalStorage	MNaturalStorage;
typedef CDSRInteger			MInteger;
typedef CDSRIntegerStorage	MIntegerStorage;
typedef CDSRRational		MRational;
typedef CDSRRationalStorage	MRationalStorage;
#define MFraction			MRational
#define MFractionStorage	MRationalStorage
#define MIrrationalStorage	MRealStorage
#define MIrrational			MReal
typedef CDSRComplex			MComplex;

struct MRadixStorage {
	MIntegerStorage z_val;
	int radix;
};

struct MComplexStorage {
  MReal re;
  MReal im;
  operator std::complex<double>( void )
  {
    return std::complex<double>( re, im );
  }
};

MComplexStorage ToMComplexStorage( std::complex<double> cv );
MComplexStorage ToMComplexStorage( double v );
MComplexStorage ToMComplexStorage( long v );
MComplexStorage ToMComplexStorage( int v );

inline
MComplexStorage ToMComplexStorage( std::complex<double> cv )
{
  MComplexStorage tmp;
  tmp.re = real(cv);
  tmp.im = imag(cv);
  return tmp;
}

inline
MComplexStorage ToMComplexStorage( double v )
{
  MComplexStorage tmp;
  tmp.re = v;
  return tmp;
}

inline
MComplexStorage ToMComplexStorage( long v )
{
  MComplexStorage tmp;
  tmp.re = v;
  return tmp;
}

inline
MComplexStorage ToMComplexStorage( int v )
{
  MComplexStorage tmp;
  tmp.re = v;
  return tmp;
}

typedef CDSRRangeStorage	MRangeStorage;
typedef CDSRRange		MRange;
#define MIndex			MRange
#define MIndexStorage		MRangeStorage
typedef CDSRBitsStorage		MBitsStorage;
typedef CDSRBits		MBits;
typedef long			MFunction;
typedef std::string*			MString;

//=== ! OPERATOR ===
inline
int operator!(MIntegerStorage a)
{
	return !a.value;
}
//=== END OF ! OPERATOR ===

//=== ADD OPERATOR ===
inline
MNaturalStorage operator+(MNaturalStorage a, MNaturalStorage b)
{
	return *(MNatural*)&a + *(MNatural*)&b;
}
inline
MNaturalStorage operator+(natural a, MNaturalStorage b)
{
	return MNatural(a) + *(MNatural*)&b;
}
inline
MNaturalStorage operator+(MNaturalStorage a, natural b)
{
	return *(MNatural*)&a + MNatural(b);
}

inline
MIntegerStorage operator+(MIntegerStorage a, MIntegerStorage b)
{
	return *(MInteger*)&a + *(MInteger*)&b;
}
inline
MIntegerStorage operator+(integer a, MIntegerStorage b)
{
	return MInteger(a) + *(MInteger*)&b;
}
inline
MIntegerStorage operator+(MIntegerStorage a, integer b)
{
	return *(MInteger*)&a + MInteger(b);
}

inline
MRationalStorage operator+(MRationalStorage a, MRationalStorage b)
{
	return *(MRational*)&a + *(MRational*)&b;
}
inline
MRationalStorage operator+(integer a, MRationalStorage b)
{
	return MRational(a) + *(MRational*)&b;
}
inline
MRationalStorage operator+(MRationalStorage a, integer b)
{
	return *(MRational*)&a + MRational(b);
}
/*
inline
MComplexStorage operator+(MComplexStorage a, MComplexStorage b)
{
	return a + b;
}*/
//=== END OF ADD OPERATOR ===

//=== SUB OPERATOR ===
inline
MNaturalStorage operator-(MNaturalStorage a, MNaturalStorage b)
{
	return *(MNatural*)&a - *(MNatural*)&b;
}
inline
MNaturalStorage operator-(natural a, MNaturalStorage b)
{
	return MNatural(a) - *(MNatural*)&b;
}
inline
MNaturalStorage operator-(MNaturalStorage a, natural b)
{
	return *(MNatural*)&a - MNatural(b);
}

inline
MIntegerStorage operator-(MIntegerStorage a, MIntegerStorage b)
{
	return *(MInteger*)&a - *(MInteger*)&b;
}
inline
MIntegerStorage operator-(integer a, MIntegerStorage b)
{
	return MInteger(a) - *(MInteger*)&b;
}
inline
MIntegerStorage operator-(MIntegerStorage a, integer b)
{
	return *(MInteger*)&a - MInteger(b);
}

inline
MRationalStorage operator-(MRationalStorage a, MRationalStorage b)
{
	return *(MRational*)&a - *(MRational*)&b;
}
inline
MRationalStorage operator-(integer a, MRationalStorage b)
{
	return MRational(a) - *(MRational*)&b;
}
inline
MRationalStorage operator-(MRationalStorage a, integer b)
{
	return *(MRational*)&a - MRational(b);
}
/*
inline
MComplexStorage operator-(MComplexStorage a, MComplexStorage b)
{
	return a - b;
}*/
//=== END OF SUB OPERATOR ===

//=== MUL OPERATOR ===
inline
MNaturalStorage operator*(MNaturalStorage a, MNaturalStorage b)
{
	return *(MNatural*)&a * *(MNatural*)&b;
}
inline
MNaturalStorage operator*(natural a, MNaturalStorage b)
{
	return MNatural(a) * *(MNatural*)&b;
}
inline
MNaturalStorage operator*(MNaturalStorage a, natural b)
{
	return *(MNatural*)&a * MNatural(b);
}

inline
MIntegerStorage operator*(MIntegerStorage a, MIntegerStorage b)
{
	return *(MInteger*)&a * *(MInteger*)&b;
}
inline
MIntegerStorage operator*(integer a, MIntegerStorage b)
{
	return MInteger(a) * *(MInteger*)&b;
}
inline
MIntegerStorage operator*(MIntegerStorage a, integer b)
{
	return *(MInteger*)&a * MInteger(b);
}

inline
MRationalStorage operator*(MRationalStorage a, MRationalStorage b)
{
	return *(MRational*)&a * *(MRational*)&b;
}
inline
MRationalStorage operator*(integer a, MRationalStorage b)
{
	return MRational(a) * *(MRational*)&b;
}
inline
MRationalStorage operator*(MRationalStorage a, integer b)
{
	return *(MRational*)&a * MRational(b);
}
/*
inline
MComplexStorage operator*(MComplexStorage a, MComplexStorage b)
{
	return a * b;
}*/
//=== END OF MUL OPERATOR ===

//=== DIV OPERATOR ===
inline
MRealStorage operator/(MNaturalStorage a, MNaturalStorage b)
{
	return ((MNatural*)&a)->get() / ((MNatural*)&b)->get();
}
inline
MRealStorage operator/(integer a, MNaturalStorage b)
{
	return MNatural(a).get() / ((MNatural*)&b)->get();
}
inline
MRealStorage operator/(MNaturalStorage a, integer b)
{
	return ((MNatural*)&a)->get() / MNatural(b).get();
}

inline
MRealStorage operator/(MIntegerStorage a, MIntegerStorage b)
{
	return ((MInteger*)&a)->get() / ((MInteger*)&b)->get();
}
inline
MRealStorage operator/(integer a, MIntegerStorage b)
{
	return MInteger(a).get() / ((MInteger*)&b)->get();
}
inline
MRealStorage operator/(MIntegerStorage a, integer b)
{
	return ((MInteger*)&a)->get() / MInteger(b).get();
}

inline
MRationalStorage operator/(MRationalStorage a, MRationalStorage b)
{
	return *(MRational*)&a / *(MRational*)&b;
}
/*
inline
MComplexStorage operator/(MComplexStorage a, MComplexStorage b)
{
	return a / b;
}*/
//=== END OF DIV OPERATOR ===

//=== MOD OPERATOR ===
inline
MNaturalStorage operator%(MNaturalStorage a, MNaturalStorage b)
{
	return MNatural( a.value % b.value );
}
inline
MNaturalStorage operator%(natural a, MNaturalStorage b)
{
	return MNatural( a % b.value );
}
inline
MNaturalStorage operator%(MNaturalStorage a, natural b)
{
	return MNatural( a.value % b );
}

inline
MIntegerStorage operator%(MIntegerStorage a, MIntegerStorage b)
{
	return MInteger( a.value % b.value );
}
inline
MIntegerStorage operator%(integer a, MIntegerStorage b)
{
	return MInteger( a % b.value );
}
inline
MIntegerStorage operator%(MIntegerStorage a, integer b)
{
	return MInteger( a.value % b );
}
//=== END OF MOD OPERATOR ===

//=== && OPERATOR ===
inline
int operator&&(MNaturalStorage a, MNaturalStorage b)
{
	return a.value && b.value;
}
inline
int operator&&(natural a, MNaturalStorage b)
{
	return a && b.value;
}
inline
int operator&&(MNaturalStorage a, natural b)
{
	return a.value && b;
}

inline
int operator&&(MIntegerStorage a, MIntegerStorage b)
{
	return a.value && b.value;
}
inline
int operator&&(integer a, MIntegerStorage b)
{
	return a && b.value;
}
inline
int operator&&(MIntegerStorage a, integer b)
{
	return a.value && b;
}
//=== END OF && OPERATOR ===

//=== || OPERATOR ===
inline
int operator||(MNaturalStorage a, MNaturalStorage b)
{
	return a.value || b.value;
}
inline
int operator||(natural a, MNaturalStorage b)
{
	return a || b.value;
}
inline
int operator||(MNaturalStorage a, natural b)
{
	return a.value || b;
}

inline
int operator||(MIntegerStorage a, MIntegerStorage b)
{
	return a.value || b.value;
}
inline
int operator||(integer a, MIntegerStorage b)
{
	return a || b.value;
}
inline
int operator||(MIntegerStorage a, integer b)
{
	return a.value || b;
}
//=== END OF || OPERATOR ===

//=== == OPERATOR ===
inline
int operator==(MNaturalStorage a, MNaturalStorage b)
{
	return *(MNatural*)&a == *(MNatural*)&b;
}
inline
int operator==(natural a, MNaturalStorage b)
{
	return MNatural(a) == *(MNatural*)&b;
}
inline
int operator==(MNaturalStorage a, natural b)
{
	return *(MNatural*)&a == MNatural(b);
}

inline
int operator==(MIntegerStorage a, MIntegerStorage b)
{
	return *(MInteger*)&a == *(MInteger*)&b;
}
inline
int operator==(integer a, MIntegerStorage b)
{
	return MInteger(a) == *(MInteger*)&b;
}
inline
int operator==(MIntegerStorage a, integer b)
{
	return *(MInteger*)&a == MInteger(b);
}

inline
int operator==(MRationalStorage a, MRationalStorage b)
{
	return *(MRational*)&a == *(MRational*)&b;
}
inline
int operator==(integer a, MRationalStorage b)
{
	return MRational(a) == *(MRational*)&b;
}
inline
int operator==(MRationalStorage a, integer b)
{
	return *(MRational*)&a == MRational(b);
}
//=== END OF == OPERATOR ===

//!== != OPERATOR !==
inline
int operator!=(MNaturalStorage a, MNaturalStorage b)
{
	return a.value != b.value;
}
inline
int operator!=(natural a, MNaturalStorage b)
{
	return a != b.value;
}
inline
int operator!=(MNaturalStorage a, natural b)
{
	return a.value != b;
}

inline
int operator!=(MIntegerStorage a, MIntegerStorage b)
{
	return a.value != b.value;
}
inline
int operator!=(integer a, MIntegerStorage b)
{
	return a != b.value;
}
inline
int operator!=(MIntegerStorage a, integer b)
{
	return a.value != b;
}

inline
int operator!=(MRationalStorage a, MRationalStorage b)
{
	return !(a == b);
}
inline
int operator!=(integer a, MRationalStorage b)
{
	return !(a == b);
}
inline
int operator!=(MRationalStorage a, integer b)
{
	return !(a == b);
}
//!== END OF != OPERATOR !==

//=== > OPERATOR ===
inline
int operator>(MNaturalStorage a, MNaturalStorage b)
{
	return *(MNatural*)&a > *(MNatural*)&b;
}
inline
int operator>(natural a, MNaturalStorage b)
{
	return MNatural(a) > *(MNatural*)&b;
}
inline
int operator>(MNaturalStorage a, natural b)
{
	return *(MNatural*)&a > MNatural(b);
}

inline
int operator>(MIntegerStorage a, MIntegerStorage b)
{
	return *(MInteger*)&a > *(MInteger*)&b;
}
inline
int operator>(integer a, MIntegerStorage b)
{
	return MInteger(a) > *(MInteger*)&b;
}
inline
int operator>(MIntegerStorage a, integer b)
{
	return *(MInteger*)&a > MInteger(b);
}

inline
int operator>(MRationalStorage a, MRationalStorage b)
{
	return *(MRational*)&a > *(MRational*)&b;
}
inline
int operator>(integer a, MRationalStorage b)
{
	return MRational(a) > *(MRational*)&b;
}
inline
int operator>(MRationalStorage a, integer b)
{
	return *(MRational*)&a > MRational(b);
}
//=== END OF > OPERATOR ===

//=== < OPERATOR ===
inline
int operator<(MNaturalStorage a, MNaturalStorage b)
{
	return *(MNatural*)&a < *(MNatural*)&b;
}
inline
int operator<(natural a, MNaturalStorage b)
{
	return MNatural(a) < *(MNatural*)&b;
}
inline
int operator<(MNaturalStorage a, natural b)
{
	return *(MNatural*)&a < MNatural(b);
}

inline
int operator<(MIntegerStorage a, MIntegerStorage b)
{
	return *(MInteger*)&a < *(MInteger*)&b;
}
inline
int operator<(integer a, MIntegerStorage b)
{
	return MInteger(a) < *(MInteger*)&b;
}
inline
int operator<(MIntegerStorage a, integer b)
{
	return *(MInteger*)&a < MInteger(b);
}

inline
int operator<(MRationalStorage a, MRationalStorage b)
{
	return *(MRational*)&a < *(MRational*)&b;
}
inline
int operator<(integer a, MRationalStorage b)
{
	return MRational(a) < *(MRational*)&b;
}
inline
int operator<(MRationalStorage a, integer b)
{
	return *(MRational*)&a < MRational(b);
}
//=== END OF < OPERATOR ===

//=== <= OPERATOR ===
inline
int operator<=(MNaturalStorage a, MNaturalStorage b)
{
	return *(MNatural*)&a <= *(MNatural*)&b;
}
inline
int operator<=(natural a, MNaturalStorage b)
{
	return MNatural(a) <= *(MNatural*)&b;
}
inline
int operator<=(MNaturalStorage a, natural b)
{
	return *(MNatural*)&a <= MNatural(b);
}

inline
int operator<=(MIntegerStorage a, MIntegerStorage b)
{
	return *(MInteger*)&a <= *(MInteger*)&b;
}
inline
int operator<=(integer a, MIntegerStorage b)
{
	return MInteger(a) <= *(MInteger*)&b;
}
inline
int operator<=(MIntegerStorage a, integer b)
{
	return *(MInteger*)&a <= MInteger(b);
}

inline
int operator<=(MRationalStorage a, MRationalStorage b)
{
	return *(MRational*)&a <= *(MRational*)&b;
}
inline
int operator<=(integer a, MRationalStorage b)
{
	return MRational(a) <= *(MRational*)&b;
}
inline
int operator<=(MRationalStorage a, integer b)
{
	return *(MRational*)&a <= MRational(b);
}
//=== END OF <= OPERATOR ===

//=== >= OPERATOR ===
inline
int operator>=(MNaturalStorage a, MNaturalStorage b)
{
	return *(MNatural*)&a >= *(MNatural*)&b;
}
inline
int operator>=(natural a, MNaturalStorage b)
{
	return MNatural(a) >= *(MNatural*)&b;
}
inline
int operator>=(MNaturalStorage a, natural b)
{
	return *(MNatural*)&a >= MNatural(b);
}

inline
int operator>=(MIntegerStorage a, MIntegerStorage b)
{
	return *(MInteger*)&a >= *(MInteger*)&b;
}
inline
int operator>=(integer a, MIntegerStorage b)
{
	return MInteger(a) >= *(MInteger*)&b;
}
inline
int operator>=(MIntegerStorage a, integer b)
{
	return *(MInteger*)&a >= MInteger(b);
}

inline
int operator>=(MRationalStorage a, MRationalStorage b)
{
	return *(MRational*)&a >= *(MRational*)&b;
}
inline
int operator>=(integer a, MRationalStorage b)
{
	return MRational(a) >= *(MRational*)&b;
}
inline
int operator>=(MRationalStorage a, integer b)
{
	return *(MRational*)&a >= MRational(b);
}
//=== END OF >= OPERATOR ===

//=== "=" OPERATOR ===
//=== END OF "=" OPERATOR ===

#endif
