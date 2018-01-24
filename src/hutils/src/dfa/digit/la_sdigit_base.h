

#if !defined( __MATHLANG_LIMAUTO_LA_SDIGIT_BASE_H__ )
#define __MATHLANG_LIMAUTO_LA_SDIGIT_BASE_H__

#include "../limauto.h"

#define LSDigitBaseStates   9
#define LSDigitBaseAlphabet 6

// class LSDigitBase
// ~~~~~ ~~~~~~
class HUTILS_EXPORT LSDigitBase : public LAuto
{

public :

	enum LSDigitBaseTypes
	{
		Integer   = 1,
		Float     = 2,
		FloatIEEE = 3
	};

	LSDigitBase( short int _base );
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
	short int		base;		// основание (2-36)

protected:

	virtual void Deeds( void );
	virtual long What( const QChar S );
};

inline
int LSDigitBase::isBig( void )
{
	return is_big;
}

#endif
