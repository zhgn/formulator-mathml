

#if !defined( __PARSEDSR_VM_VM_EVAL_FUN_H__ )
#define __PARSEDSR_VM_VM_EVAL_FUN_H__

#include "vm_eval_cmd.h"

///////////////////////////////////////////////////////////////////////////////

class __HMATHLNGDLL__ CDSR_VMEval_Function
{
public:
	QString name;
	long id;
	long n_arg, n_res;
	UniWordVector args, res;
	CDsrDataType_Composition *m_arg_data;
	CDsrDataType_Node *m_res_data;
	CDSR_VMEval_Line body;

	CDSR_VMEval_Function( void )
	{
		name = _T("");
		n_arg = 0;
		n_res = 0;
		m_arg_data = 0;
		m_res_data = 0;
	}

        int operator == ( CDSR_VMEval_Function& /*a*/ ) const
	{
		return 0;
	}
};

class __HMATHLNGDLL__ CDSR_VMEval_FT : public MArray<CDSR_VMEval_Function>
{
public:
	CDSR_VMEval_FT( void ) :
		MArray<CDSR_VMEval_Function>( 64, 0, 64 )
	{}
};

///////////////////////////////////////////////////////////////////////////////

__HMATHLNGDLL__
QString getTextView( CParseDsrSymbolTable& smbtable, CDSR_VMEval_Function& c );
__HMATHLNGDLL__
QString getTextView( CParseDsrSymbolTable& smbtable, CDSR_VMEval_FT& c );

///////////////////////////////////////////////////////////////////////////////

#endif
