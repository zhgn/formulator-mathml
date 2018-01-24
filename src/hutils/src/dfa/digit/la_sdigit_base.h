

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

	double			mnt_float;	// �������� ��� ���. ���������
	unsigned long	pre_int;	// ��������� ������ ����
	unsigned long	mnt_int;	// ��������� ������ ����
	short int		power;		// �������
	short int		powerE;		// ������� ��� E
	short int		asign;		// ����
	short int		sign;		// ���� �������
	short int		is_big;		// 
	short int		decimal;	// decimal
	short int		base;		// ��������� (2-36)

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
