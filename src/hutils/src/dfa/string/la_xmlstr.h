

#if !defined( __COMMON_LA_XMLSTR_H__ )
#define __COMMON_LA_XMLSTR_H__

#include "../limauto.h"

#define LXMLStringStates   22
#define LXMLStringAlphabet 18

// class LXMLString
// ~~~~~ ~~~~~~~
class HUTILS_EXPORT LXMLString : public LAuto
{

public :

	enum LXMLStringTypes
	{
		String = 1
	};

	QString read_string;	// принятая строка
	QString read_buff;	// принятая строка
	unsigned long	pre_int;	// константа целого типа
	unsigned long	mnt_int;	// константа целого типа
	short int		is_big;		// 
	short int		is_numentity_notchar;		// 
	QChar quat;

	LXMLString( QChar _quat );
	void Reset( QChar _quat ) { LAuto::Reset(); setQuat( _quat ); }
	void setQuat( QChar _quat ) { quat = _quat; }
	const QChar* data();

protected:

	virtual long What( const QChar S );
	virtual void Deeds( void );
};


inline
const QChar* LXMLString::data()
//       ~~~~~~~~~~~~~~~~~~~~
{
	return read_string.data();
}

#endif
