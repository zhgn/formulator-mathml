

#if !defined( __MATHLANG_LIMAUTO_LA_SDIGIT_H__ )
#define __MATHLANG_LIMAUTO_LA_SDIGIT_H__

#include "../limauto.h"

#define LSDigitStates   9
#define LSDigitAlphabet 6

// class LSDigit
// ~~~~~ ~~~~~~
class HUTILS_EXPORT LSDigit : public LAuto
{

public :

	enum LSDigitTypes
	{
		Integer   = 1,
		Float     = 2,
		FloatIEEE = 3
	};

	LSDigit( void );
	int	isBig( void );

	double			mnt_float;	// мантисса для вещ. константы
	unsigned long	pre_int;	// константа целого типа
	unsigned long	mnt_int;	// константа целого типа
	short int		power;		// степень
	short int		powerE;		// степень для E
	short int		asign;		// знак
	short int		sign;		// знак степени
	short int		is_big;		// 
	short int		decimal;	// decimal

protected:

	virtual void Deeds( void );
	virtual long What( const QChar S );
};

inline
int LSDigit::isBig( void )
{
	return is_big;
}

#endif
