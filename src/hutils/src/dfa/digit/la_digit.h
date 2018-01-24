

#if !defined( __MATHLANG_LIMAUTO_LA_DIGIT_H__ )
#define __MATHLANG_LIMAUTO_LA_DIGIT_H__

#include "../limauto.h"

#define LDigitStates   8
#define LDigitAlphabet 6

// class LDigit
// ~~~~~ ~~~~~~
class HUTILS_EXPORT LDigit : public LAuto
{

public :

	enum LDigitTypes
	{
		Integer   = 1,
		Float     = 2,
		FloatIEEE = 3
	};

	LDigit( void );
	int	isBig( void );

	double			mnt_float;	// мантисса для вещ. константы
	unsigned long	pre_int;	// константа целого типа
	unsigned long	mnt_int;	// константа целого типа
	short int		power;		// степень
	short int		powerE;		// степень для E
	short int		sign;		// знак степени
	short int		is_big;		// 
	short int		decimal;	// decimal

protected:

	virtual void Deeds( void );
	virtual long What( const QChar S );

};

inline
int LDigit::isBig( void )
{
	return is_big;
}

#endif
