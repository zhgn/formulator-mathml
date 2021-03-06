

#if !defined( __FORMULATOR_DICTIONARY_ENTITY_MAP_H__ )
#define __FORMULATOR_DICTIONARY_ENTITY_MAP_H__

#include <vector>

#include "HUtils/ihkstring.h"
#include "HUtils/idfas.h"
#include "HUtils/ihkmap.h"

#include "../fmlcore_global.h"

///////////////////////////////////////////////////////////////////////////////

typedef HKKeywordMapString2Long			FMmlCharMap;
typedef QMap<quint16, QString>			FMmlEntityMap;
class __YUNEN_FORMULIB__ FMmlMap
{
protected:
	FMmlCharMap *m_char2no, *m_uchar2no;
	FMmlEntityMap *m_u2ent;

public:
	FMmlMap( void )
	{
		InitDFA();
		InitUDFA();
		InitValue2Name();
	}
	~FMmlMap( void )
	{
		if( m_char2no ) delete m_char2no;
		if( m_uchar2no ) delete m_uchar2no;
		if( m_u2ent ) delete m_u2ent;
	}
        QString unicode2name( const unsigned short val )
	{
		if( !m_u2ent ) return "";
		QMap<quint16, QString>::const_iterator i = m_u2ent->find( quint16(val) );
		return (i == m_u2ent->end()) ? "" : i.value();
	}
	FMmlCharMap* getKeywordMAPKeyword( void )
		{ return m_char2no; }
	FMmlCharMap* getKeywordUnicodeMAPKeyword( void )
		{ return m_uchar2no; }

	int ReadU2Ent( const QString& path );
	int WriteU2Ent( const QString& path );

	void InitDFA( void );
	void InitUDFA( void );
	void InitValue2Name( void );
};

///////////////////////////////////////////////////////////////////////////////

inline
int FMmlMap::ReadU2Ent( const QString& path )
{
	if( !m_u2ent ) return -1;
	QFile file( path );
	if( !file.open(QIODevice::ReadOnly) ) return -1;
	QDataStream ar( &file );
	ar >> *m_u2ent;
	file.close();
	return 0;
}

inline
int FMmlMap::WriteU2Ent( const QString& path )
{
	if( !m_u2ent ) return -1;
	QFile file( path );
	if( !file.open(QIODevice::WriteOnly) ) return -1;
	QDataStream ar( &file );
	ar << *m_u2ent;
	file.close();
	return 0;
}

///////////////////////////////////////////////////////////////////////////////

__YUNEN_FORMULIB__ unsigned short mapString2UnicodeValue( QString& str );
__YUNEN_FORMULIB__ void mapUnicodeValue2EntityName( QString& dest, QString& src );
__YUNEN_FORMULIB__ void getMathMLChar2Style( std::vector<QString>& dest_str, std::vector<long>& dest_style, QString& src_str, QString& tagname, long mode, unsigned short *unicode_ret_val = 0 );

///////////////////////////////////////////////////////////////////////////////

inline
int isXMLSymbol__BracketL( QString& src )
{
	return mapString2UnicodeValue( src ) == _T('(');
}

inline
int isXMLSymbol__BracketR( QString& src )
{
	return mapString2UnicodeValue( src ) == _T(')');
}

inline
int isXMLSymbol__BracketLB( QString& src )
{
	return mapString2UnicodeValue( src ) == _T('[');
}

inline
int isXMLSymbol__BracketRB( QString& src )
{
	return mapString2UnicodeValue( src ) == _T(']');
}

inline
int isXMLSymbol__BracketLF( QString& src )
{
	return mapString2UnicodeValue( src ) == _T('{');
}

inline
int isXMLSymbol__BracketRF( QString& src )
{
	return mapString2UnicodeValue( src ) == _T('}');
}

inline
int isXMLSymbol__BracketLA( QString& src )
{
	return mapString2UnicodeValue( src ) == 0x2329;
}

inline
int isXMLSymbol__BracketRA( QString& src )
{
	return mapString2UnicodeValue( src ) == 0x232A;
}

inline
int isXMLSymbol__BracketVerBar( QString& src )
{
	return mapString2UnicodeValue( src ) == _T('|');
}

inline
int isXMLSymbol__BracketDblVerBar( QString& src )
{
	return mapString2UnicodeValue( src ) == 0x2016;
}

inline
int isXMLSymbol__BracketLFloor( QString& src )
{
	return mapString2UnicodeValue( src ) == 0x230A;
}

inline
int isXMLSymbol__BracketRFloor( QString& src )
{
	return mapString2UnicodeValue( src ) == 0x230B;
}

inline
int isXMLSymbol__BracketLCeil( QString& src )
{
	return mapString2UnicodeValue( src ) == 0x2308;
}

inline
int isXMLSymbol__BracketRCeil( QString& src )
{
	return mapString2UnicodeValue( src ) == 0x2309;
}

///////////////////////////////////////////////////////////////////////////////

#endif
