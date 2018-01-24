

#ifndef __PARSEDSR_DATA_MMD_RATF_H__
#define __PARSEDSR_DATA_MMD_RATF_H__

#include "mmd_poly.h"

///////////////////////////////////////////////////////////////////////////////

class __HMATHLNGDLL__ MMD_RationalFun :  public MMD_Object
{
public :
	MMD_Polynomial *hi;
	MMD_Polynomial *lo;

	MMD_RationalFun( CParseDsrSymbolTable& _smbtable, enum CDsrDataTypes nested_type = DSRDATA_TYPE_REAL );
	MMD_RationalFun( CParseDsrSymbolTable& _smbtable, MMD_Polynomial *_hi, MMD_Polynomial *_lo );
	MMD_RationalFun( const MMD_RationalFun& ms );
	virtual MMD_Object* copy( const MMD_RationalFun *src );
	MMD_RationalFun* clone( void );
	virtual ~MMD_RationalFun( void );

	int isNormal( void );
	void Normalize( void );
	void getValue( UniWord& ret, const UniWord& x );
	virtual QString getTextView();
	virtual QString getFormulatorView();
	virtual QString getMmlView();
};

///////////////////////////////////////////////////////////////////////////////

inline
MMD_RationalFun::MMD_RationalFun( CParseDsrSymbolTable& _smbtable, MMD_Polynomial *_hi, MMD_Polynomial *_lo ) :
	MMD_Object( 
		_smbtable, 
		_smbtable.getTypeTable().makeDataTypeNode( 
			new CDsrDataType_RationalFun( 
				_smbtable.getTypeTable().makeDataTypeNode( _hi->getType() ) 
			) ) ),
	hi( _hi ), lo( _lo )
{
	if( _hi->getType() != _lo->getType() )
		throw _T("Internal error");
}

inline
MMD_RationalFun::MMD_RationalFun( const MMD_RationalFun& ms ) :
	MMD_Object( ms ), hi( ms.hi->clone() ), lo( ms.lo->clone() )
{
}

inline
MMD_Object* MMD_RationalFun::copy( const MMD_RationalFun *src )
{
	MMD_Object::copy( src );
	hi = src->hi->clone();
	lo = src->lo->clone();
	return this;
}

inline
MMD_RationalFun::~MMD_RationalFun( void )
{}

inline
MMD_RationalFun* MMD_RationalFun::clone( void )
{
	return getSmbTable().makeUniWord( new MMD_RationalFun( *this ) );
}

inline
int MMD_RationalFun::isNormal( void )
{
	if( hi->isNormal() && lo->isNormal() )
		return 1;
	return 0;
}

inline
void MMD_RationalFun::Normalize( void )
{
	if( !hi->isNormal() ) hi->Normalize();
	if( !lo->isNormal() ) lo->Normalize();
}

///////////////////////////////////////////////////////////////////////////////

typedef MMD_RationalFun* CDSRRFunStorage;

#endif
