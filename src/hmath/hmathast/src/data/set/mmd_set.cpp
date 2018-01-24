

#include "HMathML/immldefs.h"
#include "../uniword/uniword_op.h"
#include "mmd_set.h"

MMD_Set::MMD_Set( CParseDsrSymbolTable& _smbtable ) :
	MMD_ObjectVec( _smbtable, DSRDATA_TYPE_ABS_SET ),
	next_to_take( 0 ), combo_storage( 8, 0, 8 ), combo_no_storage( 8, 0, 8 )
{
	m_to_combine = 0;
}

MMD_Set::MMD_Set( const MMD_Set& ms ) :
	MMD_ObjectVec( ms ),
	next_to_take( 0 ), combo_storage( 8, 0, 8 ), combo_no_storage( 8, 0, 8 )
{
	//copy( &ms );
}

MMD_Object* MMD_Set::copy( const MMD_Set *src )
{
	MMD_ObjectVec::copy( src );
	return this;
}

QString MMD_Set::getTextView( void )
{
	QString result = _T("");
	if( getCount() == 0 )
		return _T("{}");
	else
	{
		result = QString( _T("{") ) + at( 0 ).getTextView( getSmbTable() );
		for( long i = 1; i < (long) getCount(); i++ )
			result += QString( _T(", ") ) + at( i ).getTextView( getSmbTable() );
		result += QString( _T("}") );
	}
	return result;
}

QString MMD_Set::getFormulatorView( void )
{
	QString result = _T("");
	if( getCount() == 0 )
		return _T("{}");
	else
	{
		result = QString( _T("{") ) + at( 0 ).getFormulatorView( getSmbTable() );
		for( long i = 1; i < (long) getCount(); i++ )
			result += QString( _T(", ") ) + at( i ).getFormulatorView( getSmbTable() );
		result += QString( _T("}") );
	}
	return result;
}

QString MMD_Set::getMmlView( void )
{
	QString result = _T("");
	if( getCount() == 0 )
		return QString("<%1></%2>").arg(FBL_TAG_set).arg(FBL_TAG_set);
	else
	{
		result = QString("<%1>\n").arg(FBL_TAG_set) + at( 0 ).getMmlView( getSmbTable() );
		for( long i = 1; i < (long) getCount(); i++ )
			result += (at( i ).getMmlView( getSmbTable() ) + "\n");
		result += QString("</%1>\n").arg(FBL_TAG_set);
	}
	return result;
}

///////////////////////////////////////////////////////////////////////////////
