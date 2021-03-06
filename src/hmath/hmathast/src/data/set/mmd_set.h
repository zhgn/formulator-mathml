

#ifndef __PARSEDSR_DATA_MMD_SET_H__
#define __PARSEDSR_DATA_MMD_SET_H__

#include "../object/obj_vec.h"

///////////////////////////////////////////////////////////////////////////////

class __HMATHLNGDLL__ MMD_Set : public MMD_ObjectVec
{
protected :
	long			next_to_take;
	long			m_to_combine;
	MArray<long>	combo_storage;
	MArray<long>	combo_no_storage;

public :
	MMD_Set( CParseDsrSymbolTable& _smbtable );
	MMD_Set( const MMD_Set& ms );
	MMD_Set* clone( void );
	virtual MMD_Object* copy( const MMD_Set *src );
	virtual ~MMD_Set( void );
	long Add( UniWord& uw );

	// is empty set
	int isEmpty( void ) const;
	// returns subset of this
	MMD_Set* GetSubSet( CDSRBitsStorage& det );
	// returns C(n, m) of this
	MMD_Set* GetComboC_First( unsigned m );
	MMD_Set* GetComboC_Next( void );
	// returns A(n, m) of this
	MMD_Set* GetComboA_First( unsigned m );
	MMD_Set* GetComboA_Next( void );
	// returns P(n) of this
	MMD_Set* GetComboP_First( void );
	MMD_Set* GetComboP_Next( void );
	// returns A_with_ret(n, m) of this
	MMD_Set* GetComboARet_First( unsigned m );
	MMD_Set* GetComboARet_Next( void );
	// returns C_with_ret(n, m) of this
	MMD_Set* GetComboCRet_First( unsigned m );
	MMD_Set* GetComboCRet_Next( void );
	//
	double GetCountOf_SubSet( unsigned m );
	double GetCountOf_ComboC_First( unsigned m );
	double GetCountOf_ComboA_First( unsigned m );
	double GetCountOf_ComboP_First( void );
	double GetCountOf_ComboARet_First( unsigned m );
	double GetCountOf_ComboCRet_First( unsigned m );
	//
	virtual QString getTextView( void );
	virtual QString getFormulatorView( void );
	virtual QString getMmlView( void );
};

///////////////////////////////////////////////////////////////////////////////

inline
MMD_Set* MMD_Set::clone( void )
{
	return getSmbTable().makeUniWord( new MMD_Set( *this ) );
}

inline
MMD_Set::~MMD_Set( void )
{}

inline
long MMD_Set::Add( UniWord& uw )
{
/*	
	long i = -1;
	if( (i = Find( uw )) == INT_MAX )
		return MMD_ObjectVec::Add( uw );
	return i;
*/
	return MMD_ObjectVec::Add( uw );
}

inline
int MMD_Set::isEmpty( void ) const
{
	return getCount() == 0;
}

///////////////////////////////////////////////////////////////////////////////

typedef MMD_Set* CDSRSetStorage;

#endif
