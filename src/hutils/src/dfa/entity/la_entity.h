

#if !defined( __MATHLANG_LIMAUTO_LA_ENTITY_H__ )
#define __MATHLANG_LIMAUTO_LA_ENTITY_H__

#include "../limauto.h"

#define LCEntityStates   9
#define LCEntityAlphabet 7

// class LCEntity
// ~~~~~ ~~~~~~~~
class HUTILS_EXPORT LCEntity : public LAuto
{
public :
	QString identifier;	// Идентификатор переменной
	unsigned short pre, value;
	short int is_big;

	enum LCEntityTypes
	{
		Identifier = 1,
		Number
	};

public :
	LCEntity( void );
	~LCEntity(){}

	QString& getID( void );
	unsigned short getVal( void );
	int isBig( void );

protected:
	virtual long What( const QChar S );
	virtual void Deeds( void );
};

inline
int LCEntity::isBig( void )
{
	return is_big;
}

inline
QString& LCEntity::getID( void )
{
	return identifier;
}

inline
unsigned short LCEntity::getVal( void )
{
	return value;
}

#endif
