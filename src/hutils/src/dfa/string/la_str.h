

#if !defined( __COMMON_LA_STR_H__ )
#define __COMMON_LA_STR_H__

#include "../limauto.h"

#define LStringStates   7
#define LStringAlphabet 5

// class LString
// ~~~~~ ~~~~~~~
class HUTILS_EXPORT LString : public LAuto
{
public:
	enum LStringTypes
	{
		String = 1
	};

	QString read_string;	// принятая строка
	QChar quat;

	LString( QChar _quat = _T('\"') );
	const QChar* data();

protected:
	virtual long What( const QChar S );
	virtual void Deeds( void );
};


inline
const QChar* LString::data()
{
	return read_string.data();
}

#endif
