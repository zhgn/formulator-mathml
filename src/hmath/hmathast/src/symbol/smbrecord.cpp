

#include "symbol_table_dsr.h"
#include "smbrecord.h"

///////////////////////////////////////////////////////////////////////////////

void CParseDsrSymbol::debugPrint( QString& dest, CParseDsrSymbolTable * /*smbtable*/ )
{
	dest += QString("(%1/%2)").arg( param1 ).arg( param2 );
	if( data_type )
	{
		dest += QString( _T(", data_type = ") ) + data_type->getTypeName();
		if( data_type->isLValue() )
			dest += QString( _T(", l-value") );
		if( data_type->isXValue() )
			dest += QString( _T(", x-value") );
		if( data_type->isLocal() )
			dest += QString( _T(", local-value") );
		if( data_type->isReturns() )
			dest += QString( _T(", returns") );
		if( data_type->isDynamic() )
			dest += QString( _T(", dynamic") );
	}
}

long CParseDsrSymbol::getArgNumber( long no )
{
	if( !getDataType() ) return 0;
	CDsrDataType_Node *n_arg = 0;
	CDsrDataType_Composition *c;
	switch( getDataType()->getType() )
	{
	case DSRDATA_TYPE_FUNCTION:
		n_arg = ((CDsrDataType_Function*)data_type)->n_arg;
		break;
	case DSRDATA_TYPE_COMPOSITION:
		c = (CDsrDataType_Composition*)data_type;
		if( no >= 0 && no < (long) c->n_arg.ArrayDim() && c->n_arg[ no ]->getType() == DSRDATA_TYPE_FUNCTION )
			n_arg = ((CDsrDataType_Function*)(c->n_arg[ no ]))->n_arg;
		break;
	default:
		break;
	}
	if( !n_arg ) return 0;
	return n_arg->getType() == DSRDATA_TYPE_COMPOSITION ? ((CDsrDataType_Composition*)n_arg)->getChildNumber() : 1;
}

long CParseDsrSymbol::getResNumber( long no )
{
	if( !getDataType() ) return 0;
	CDsrDataType_Node *n_res = 0;
	CDsrDataType_Composition *c;
	switch( getDataType()->getType() )
	{
	case DSRDATA_TYPE_FUNCTION:
		n_res = ((CDsrDataType_Function*)data_type)->n_res;
		break;
	case DSRDATA_TYPE_COMPOSITION:
		c = (CDsrDataType_Composition*)data_type;
		if( no >= 0 && no < (long) c->n_arg.ArrayDim() && c->n_arg[ no ]->getType() == DSRDATA_TYPE_FUNCTION )
			n_res = ((CDsrDataType_Function*)(c->n_arg[ no ]))->n_res;
		break;
	default:
		break;
	}
	if( !n_res ) return 0;
	return n_res->getType() == DSRDATA_TYPE_COMPOSITION ? ((CDsrDataType_Composition*)n_res)->getChildNumber() : 1;
}

///////////////////////////////////////////////////////////////////////////////
