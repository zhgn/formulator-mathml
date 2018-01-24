

#if !defined( __COMMON_LA_DSR2VAR_H__ )
#define __COMMON_LA_DSR2VAR_H__

#include "HUtils/ihkarray.h"
#include "../limauto.h"

#define LDsr2VarStates   4
#define LDsr2VarAlphabet 3

// class LDsr2Var
// ~~~~~ ~~~~~
class HUTILS_EXPORT LDsr2Var : public LAuto
{
protected:
	MArray<QString> keywords;

public :
	QString identifier;	// Идентификатор переменной
	QString modifier;		// Модификатор переменной ('g' = greek, etc.)

public :

	enum LDsr2VarTypes
	{
		Identifier = 1,
		KW_begin,
		KW_end,
		KW_if,
		KW_then,		
		KW_else,
		KW_function,		
		KW_group,		
		KW_polynomial,		
		KW_rational_function		
	};

	LDsr2Var( void );
	~LDsr2Var(){}
	QChar getModifierChar( void );
	QString& getID( void );
	QString& getModifier( void );
	int	Analisys( const QStringRef& aText );

	long getKeywordNumber( void )
		{ return (long) keywords.ArrayDim(); }
	long getKeywordStartIdx( void )
		{ return LDsr2Var::KW_begin; }
	const QString& getKeyword( long i )
		{ return keywords[ i ]; }

protected:
	virtual long What( const QChar S );
	virtual void Deeds( void );
};

inline
QString& LDsr2Var::getID( void )
{
	return identifier;
}

inline
QString& LDsr2Var::getModifier( void )
{
	return modifier;
}

inline
QChar LDsr2Var::getModifierChar( void )
{
	return _T('$');
}

#endif
