

#if !defined( __MATHLANG_LIMAUTO_LA_XMLATTR_SDIGIT_H__ )
#define __MATHLANG_LIMAUTO_LA_XMLATTR_SDIGIT_H__

#include "../limauto.h"

#define LXMLSizeSDigitStates   5
#define LXMLSizeSDigitAlphabet 5

// class LXMLSizeSDigit
// ~~~~~ ~~~~~~
class HUTILS_EXPORT LXMLSizeSDigit : public LAuto
{

public :

	enum LXMLSizeSDigitTypes
	{
		Integer   = 1,
		Float     = 2
	};

	LXMLSizeSDigit( void );
	int	isBig( void );

	double			mnt_float;	// �������� ��� ���. ���������
	unsigned long	pre_int;	// ��������� ������ ����
	unsigned long	mnt_int;	// ��������� ������ ����
	short int		power;		// �������
	short int		asign;		// ����
	short int		is_big;		// 
	short int		decimal;	// decimal

protected:

	virtual void Deeds( void );
	virtual long What( const QChar S );
};

inline
int LXMLSizeSDigit::isBig( void )
{
	return is_big;
}

#endif
