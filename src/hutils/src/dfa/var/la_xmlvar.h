

#if !defined( __COMMON_COMPILER_DFA_VAR_XMLVAR_H__ )
#define __COMMON_COMPILER_DFA_VAR_XMLVAR_H__

#include "../limauto.h"

#define LXMLVarStates   4
#define LXMLVarAlphabet 3

// class LXMLVar
// ~~~~~ ~~~~~
class HUTILS_EXPORT LXMLVar : public LAuto
{
public :
	enum LXMLVarTypes
	{
		Id      = 1,
		XML     = 2,
		DOCTYPE = 3
	};

	QString m_namespace;	// Идентификатор namespace
	QString m_identifier;	// Идентификатор переменной

public :
	LXMLVar( void );
	QString& getID( void );
	QString& getNS( void );
	int Analisys( const QStringRef& aText );
	~LXMLVar(){}

protected:
	virtual long What( const QChar S );
	virtual void Deeds( void );
};

inline
QString& LXMLVar::getID( void )
{
	return m_identifier;
}

inline
QString& LXMLVar::getNS( void )
{
	return m_namespace;
}

#endif
