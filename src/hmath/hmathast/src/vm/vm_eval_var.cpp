

#include "vmeval.h"

///////////////////////////////////////////////////////////////////////////////

long CDSR_VMEval::getVariable_getNoByID( long id )
{
	CParseDsrSymbol *smb = getSmbTable().getSymbol( id );
	if( !smb || smb->smb_record_type != SMBTABLE_TYPE_VARIABLE ||
		!smb->getDataType() || smb->param2 <= 0 || smb->param2 >= (long) m_var_table.ArrayDim() )
		return -1;
	return smb->param2;
}

long CDSR_VMEval::getVariable_getNoByName( QString name )
{
	long *pid = getSmbTable().is_find( name );
	if( !pid ) return -1;
	return getVariable_getNoByID( *pid );
}

int CDSR_VMEval::getVariable_getType( long no, enum CDsrDataTypes& type )
{
	long pid = getVariable_getSmbID( no );
	if( pid == -1 ) return -1;
	CParseDsrSymbol *smb = getSmbTable().getSymbol( pid );
	if( smb )
	{
		type = smb->getDataType()->getType();
		return 0;
	}
	return -1;
}

int CDSR_VMEval::getVariable_getValue( long var_no, UniWord& value )
{
	if( var_no > 0 && var_no < (long) m_var_table.ArrayDim() )
	{
		value = m_var_table[ var_no ];
		return 0;
	}
	return -1;
}

int CDSR_VMEval::getVariable_setValue( long var_no, UniWord& value )
{
	if( var_no > 0 && var_no < (long) m_var_table.ArrayDim() )
	{
		m_var_table[ var_no ] = value;
		return 0;
	}
	return -1;
}

int CDSR_VMEval::getVariable_getVectorValue( long var_no, long var_idx, UniWord& value )
{
	UniWord vv;
	enum CDsrDataTypes tp;
	//=== check internal problems
	if( getVariable_getValue( var_no, vv ) == -1 ||
		getVariable_getType( var_no, tp )  == -1 )
		return -1;
	if( tp != DSRDATA_TYPE_VECTOR || 
		vv.getType() != DSRDATA_TYPE_VECTOR )
		return -1;
	//=== check index validity
	if( !vv.getVector()->isValidIdx( var_idx ) )
		return -1;
	value = vv.getVector()->get( var_idx );
	return 0;
}

int CDSR_VMEval::getVariable_setVectorValue( long var_no, long var_idx, UniWord& value )
{
	UniWord vv;
	enum CDsrDataTypes tp;
	//=== check internal problems
	if( getVariable_getValue( var_no, vv ) == -1 ||
		getVariable_getType( var_no, tp )  == -1 )
		return -1;
	if( tp != DSRDATA_TYPE_VECTOR || 
		vv.getType() != DSRDATA_TYPE_VECTOR )
		return -1;
	//=== check index validity
	if( !vv.getVector()->isValidIdx( var_idx ) )
		return -1;
	//=== caution!!! type of value must be the same as:
	//=== + cell type if the variable is vector
	//=== + vector type if the variable is matrix
	// otherwise internal error will be thrown
	if( vv.getVector()->getRows() != 1 && 
		vv.getVector()->getColumns() != 1 )
	{
		if( value.getType() != DSRDATA_TYPE_VECTOR )
			return -1;
	}
	vv.getVector()->set( var_idx, value );
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
