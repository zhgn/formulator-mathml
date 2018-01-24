

#if !defined( __COMMON_LANGUAGE_MATHNML_DFA_LA_MMLCHAR_H__ )
#define __COMMON_LANGUAGE_MATHNML_DFA_LA_MMLCHAR_H__

///////////////////////////////////////////////////////////////////////////////

#include "../fmlcore_global.h"
#include "HUtils/ilimauto.h"

#define LMMLCharStates   37
#define LMMLCharAlphabet 36

// class LMMLChar
// ~~~~~ ~~~~~~~~
class __YUNEN_FORMULIB__ LMMLChar : public LAuto
{
public :
	QString text;

public :
	LMMLChar( int _is_style_greek = 0, int _is_style_number = 0, int _is_style_variable = 0, int _is_style_text = 0 );
	QString& getText( void );
	QString getTag( void );
	QString getAttr( void );
	void reset( void );
	~LMMLChar(){}

  protected:
	int is_style_greek, is_style_text;

	virtual long What( const QChar S );
	virtual void Deeds( void );
};


inline
void LMMLChar::reset( void )
{
	text = _T("");
	LAuto::Reset();
}

///////////////////////////////////////////////////////////////////////////////

#endif
