

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

	double			mnt_float;	// �������� ��� ���. ���������
	unsigned long	pre_int;	// ��������� ������ ����
	unsigned long	mnt_int;	// ��������� ������ ����
	short int		power;		// �������
	short int		powerE;		// ������� ��� E
	short int		sign;		// ���� �������
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
