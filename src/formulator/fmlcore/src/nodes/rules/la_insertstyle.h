

#if !defined( __FORMULATOR_DFA_LA_INSERTSTYLE_H__ )
#define __FORMULATOR_DFA_LA_INSERTSTYLE_H__

#include "HUtils/ilimauto.h"

#define LFInsertStyleStates   4
#define LFInsertStyleAlphabet 3

// class LFInsertStyle
// ~~~~~ ~~~~~
class LFInsertStyle : public LAuto
{
public :
	QString text;

public :
	LFInsertStyle( void );
	QString& getText( void );
	void reset( void );
	~LFInsertStyle(){}

protected:
	virtual long What( const QChar S );
	virtual void Deeds( void );
};


inline
void LFInsertStyle::reset( void )
{
	text = _T("");
	LAuto::Reset();
}

#endif
