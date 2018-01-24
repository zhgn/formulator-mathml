

#ifndef __PARSEDSR_DATA_MMD_OBJ_VEC_H__
#define __PARSEDSR_DATA_MMD_OBJ_VEC_H__

#include "../uniword/uniword.h"

///////////////////////////////////////////////////////////////////////////////

class __HMATHLNGDLL__ MMD_ObjectVec : public MArray<UniWord>,
											  public MMD_Object
{
public :
	MMD_ObjectVec( CParseDsrSymbolTable& _smbtable, CDsrDataType_Node *_type = 0, long count = 0 );
	MMD_ObjectVec( CParseDsrSymbolTable& _smbtable, enum CDsrDataTypes _type, long count = 0 );
	MMD_ObjectVec( const MMD_ObjectVec& ms );
	virtual MMD_Object* copy( const MMD_ObjectVec *src );
	virtual ~MMD_ObjectVec( void );
	unsigned long getCount( void ) const;
};

///////////////////////////////////////////////////////////////////////////////

inline
MMD_ObjectVec::MMD_ObjectVec( CParseDsrSymbolTable& _smbtable, CDsrDataType_Node *_type, long count )
	: MArray<UniWord>( 32, 0, 32 )
	, MMD_Object( _smbtable, _type )
	
{
	if( count ) resize( count );
}

inline
MMD_ObjectVec::MMD_ObjectVec( CParseDsrSymbolTable& _smbtable, enum CDsrDataTypes _type, long count )
	: MArray<UniWord>( 32, 0, 32 )
	, MMD_Object( _smbtable, _type )
	
{
	if( count ) resize( count );
}

inline
MMD_ObjectVec::MMD_ObjectVec( const MMD_ObjectVec& ms )
	: MArray<UniWord>( 32, 0, 32 )
	, MMD_Object( ms )
	
{
	MMD_Object::copy( &ms );
	MArray<UniWord>::Copy( ms );
}

inline
MMD_Object* MMD_ObjectVec::copy( const MMD_ObjectVec *src )
{
	MMD_Object::copy( src );
	MArray<UniWord>::Copy( *src );
	return this;
}

inline
unsigned long MMD_ObjectVec::getCount( void ) const
{
	return (unsigned long) ArrayDim();
}

inline
MMD_ObjectVec::~MMD_ObjectVec( void )
{
}

///////////////////////////////////////////////////////////////////////////////

#endif
