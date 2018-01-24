

#if !defined( __FORMULATOR_DICTIONARY_OP_MAP_H__ )
#define __FORMULATOR_DICTIONARY_OP_MAP_H__

#include "HUtils/ihkstring.h"
#include "HUtils/idfas.h"

#include "../fmlcore_global.h"
#include "op_iddefs.h"

class HMathOpAttr;

///////////////////////////////////////////////////////////////////////////////

class __YUNEN_FORMULIB__ HMathOpAttrDFA
{
protected:
	LKeyword *ptr_la_keyword_bydsr;
	LKeyword *ptr_la_keyword_bymml;
public:
	HMathOpAttrDFA( void );
	~HMathOpAttrDFA( void );

	LKeyword* getByDSR( void );
	LKeyword* getByMML( void );

	void InitByDSR( void );
	void InitByMML( void );
};

///////////////////////////////////////////////////////////////////////////////

inline
HMathOpAttrDFA::HMathOpAttrDFA( void )
{
	InitByDSR();
	InitByMML();
}

inline
HMathOpAttrDFA::~HMathOpAttrDFA( void )
{
	if( ptr_la_keyword_bydsr ) delete ptr_la_keyword_bydsr;
	if( ptr_la_keyword_bymml ) delete ptr_la_keyword_bymml;
}

inline
LKeyword* HMathOpAttrDFA::getByDSR( void )
{
	return ptr_la_keyword_bydsr;
}

inline
LKeyword* HMathOpAttrDFA::getByMML( void )
{
	return ptr_la_keyword_bymml;
}

///////////////////////////////////////////////////////////////////////////////

__YUNEN_FORMULIB__ HMathOpAttr* getOperatorEntryByName( const QString& name, int mode );
__YUNEN_FORMULIB__ HMathOpAttr* getOperatorEntryByMML( const QString& name );
__YUNEN_FORMULIB__ HMathOpAttr* getOperatorEntryByDSR( const QString& name );

///////////////////////////////////////////////////////////////////////////////

#endif
