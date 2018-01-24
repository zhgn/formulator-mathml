

#include "object.h"

///////////////////////////////////////////////////////////////////////////////


MMD_Object::MMD_Object( CParseDsrSymbolTable& _smbtable, CDsrDataType_Node *_type ) :
	m_smbtable( &_smbtable )
{
	if( _type )
		m_type = getSmbTable().getTypeTable().cloneDataTypeNode( _type );
	else
		m_type = 0;
}


enum CDsrDataTypes MMD_Object::getType( void )
{
	return getDataType() && getDataType()->getNestedType() ?
			getDataType()->getNestedType()->getType() : DSRDATA_TYPE_NONE;
}


QString MMD_Object::getTypeName( void )
{
	return getDataType() ? getDataType()->getTypeName() : ::getTypeName( DSRDATA_TYPE_NONE );
}


MMD_Object::MMD_Object( CParseDsrSymbolTable& _smbtable, enum CDsrDataTypes _type ) :
	m_smbtable( &_smbtable )
{
	m_type = getSmbTable().getTypeTable().makeDataTypeNode( _type );
}


MMD_Object::MMD_Object( const MMD_Object& o ) :
	m_smbtable( &o.getSmbTable() )
{
	m_type = getSmbTable().getTypeTable().cloneDataTypeNode( o.getDataType() );
}


MMD_Object::~MMD_Object( void )
{
}


MMD_Object* MMD_Object::copy( const MMD_Object *o )
{
	m_smbtable = &o->getSmbTable();
	m_type = getSmbTable().getTypeTable().cloneDataTypeNode( o->getDataType() );
	return this;
}


MMD_Object MMD_Object::operator=( const MMD_Object& o )
{
	return *copy( &o );
}


CParseDsrSymbolTable& MMD_Object::getSmbTable( void ) const
{
	return *m_smbtable;
}


CDsrDataType_Node* MMD_Object::getDataType( void ) const
{
	return m_type;
}


void MMD_Object::setDataType( CDsrDataType_Node *tp )
{
	m_type = tp;
}


QString MMD_Object::getTextView( void )
{
	return _T("");
}


QString MMD_Object::getFormulatorView( void )
{
	return _T("");
}


QString MMD_Object::getMmlView( void )
{
	return _T("");
}

///////////////////////////////////////////////////////////////////////////////

MMD_ObjectHeap::~MMD_ObjectHeap( void )
{
	for( long i = 0; i < (long) ArrayDim(); i++ )
	{
		if( at( i ) )
			delete at( i );
	}
}

///////////////////////////////////////////////////////////////////////////////
