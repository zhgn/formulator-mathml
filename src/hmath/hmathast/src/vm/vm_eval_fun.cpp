

#include "vmeval.h"

CDSR_VMEval_Line* CDSR_VMEval::getFunction_CmdLine( long fun_no )
{
	if( fun_no > 0 && fun_no < (long) m_fun_table.ArrayDim() )
		return &(m_fun_table[ fun_no ].body);
	return 0;
}

QString CDSR_VMEval::getFunction_getName( long fun_no )
{
	if( fun_no > 0 && fun_no < (long) m_fun_table.ArrayDim() )
		return m_fun_table[ fun_no ].name;
	return _T("");
}

long CDSR_VMEval::getFunction_getNoByName( QString name )
{
	long *pid = getSmbTable().is_find( name );
	if( !pid ) return -1;
	CParseDsrSymbol *smb = getSmbTable().getSymbol( *pid );
	if( !smb || smb->smb_record_type != SMBTABLE_TYPE_FUNCTION ||
		!smb->getDataType() || smb->param2 <= 0 || smb->param2 >= (long) m_fun_table.ArrayDim() )
		return -1;
	return smb->param2;
}

long CDSR_VMEval::getFunction_getArgNumber( long fun_no )
{
	if( fun_no > 0 && fun_no < (long) m_fun_table.ArrayDim() )
		return m_fun_table[ fun_no ].n_arg;
	return -1;
}

long CDSR_VMEval::getFunction_getResNumber( long fun_no )
{
	if( fun_no > 0 && fun_no < (long) m_fun_table.ArrayDim() )
		return m_fun_table[ fun_no ].n_res;
	return -1;
}

CDsrDataType_Node* CDSR_VMEval::getFunction_getArgType( long fun_no )
{
	if( fun_no > 0 && fun_no < (long) m_fun_table.ArrayDim() )
		return m_fun_table[ fun_no ].m_arg_data;
	return 0;
}

CDsrDataType_Node* CDSR_VMEval::getFunction_getArgType( long fun_no, long arg_no )
{
	if( fun_no > 0 && fun_no < (long) m_fun_table.ArrayDim() )
	{
		if( arg_no > 0 && arg_no < m_fun_table[ fun_no ].m_arg_data->getChildNumber() )
			return m_fun_table[ fun_no ].m_arg_data->at( arg_no );
	}
	return 0;
}

CDsrDataType_Node* CDSR_VMEval::getFunction_getResType( long fun_no )
{
	if( fun_no > 0 && fun_no < (long) m_fun_table.ArrayDim() )
		return m_fun_table[ fun_no ].m_res_data;
	return 0;
}

int CDSR_VMEval::getFunction_setArg( long fun_no, long arg_no, UniWord& value )
{
	if( fun_no > 0 && fun_no < (long) m_fun_table.ArrayDim() )
	{
		if( arg_no > 0 && arg_no < (long) m_fun_table[ fun_no ].args.ArrayDim() )
		{
			m_fun_table[ fun_no ].args[ arg_no ] = value;
			return 0;
		}
	}
	return -1;
}

int CDSR_VMEval::getFunction_getRes( long fun_no, UniWord& res_value, long res_no )
{
	if( fun_no > 0 && fun_no < (long) m_fun_table.ArrayDim() )
	{
		if( res_no > 0 && res_no < (long) m_fun_table[ fun_no ].args.ArrayDim() )
		{
			res_value = m_fun_table[ fun_no ].res[ res_no ];
			return 0;
		}
	}
	return -1;
}
