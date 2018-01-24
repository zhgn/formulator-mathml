

#if !defined( __MATHLANG_LIMAUTO_LA_VAR_H__ )
#define __MATHLANG_LIMAUTO_LA_VAR_H__

#include "../limauto.h"

#define LCVarStates   2
#define LCVarAlphabet 2

// class LCVar
// ~~~~~ ~~~~~
class HUTILS_EXPORT LCVar : public LAuto
{
public :
	QString identifier;	// Идентификатор переменной

public :
	LCVar( void );
	~LCVar(){}
	QString& getID( void );

protected:
	virtual long What( const QChar S );
	virtual void Deeds( void );
};

inline
QString& LCVar::getID( void )
{
	return identifier;
}

#endif
