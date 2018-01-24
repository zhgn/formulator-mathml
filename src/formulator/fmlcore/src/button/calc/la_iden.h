

#if !defined( __LA_IDEN_H__ )
#define __LA_IDEN_H__

#include "HUtils/ilimauto.h"
#include "grammar.h"

#define LIdenStates   2
#define LIdenAlphabet 2

extern long LIdenLeapes[ LIdenStates * LIdenAlphabet ];
extern long LIdensEndStates[ LIdenStates ];

// class LIden
// ~~~~~ ~~~~~
class LIden : public LAuto
{

public:

	QString identifier;

public :

	enum LIdenTypes
	{
		Identifier = 1,
		KW_Abs,
		KW_Av,
		KW_Max,
		KW_Min		
	};

	LIden();
	int	Analisys( const QStringRef& aText );


protected:

	virtual long	What( const QChar S );
	virtual void	Deeds();
};


inline
LIden::LIden()
//     ~~~~~
: LAuto( LIdenStates, LIdenAlphabet, LIdenLeapes, LIdensEndStates )
{}

#endif
