

#include "../vmevallink.h"
#include "../astdsr.h"

/////////////////////////////////////////
//	TypeSpec	:	Op, PrimaryID, Separator, ArgList, Separator;
/////////////////////////////////////////
void CDsrAST_TypeSpec::getInstruction( CDSR_VMEval& /*vm*/, CDSR_VMEval_Line& /*dest*/ )
{
}

/////////////////////////////////////////
//	ObjDef_Assign	:	ObjHead, Op, Expr, Separator;
/////////////////////////////////////////
void CDsrAST_ObjDef_Assign::getInstruction( CDSR_VMEval& vm, CDSR_VMEval_Line& dest )
{
	switch( head->keyword->getKeywordType() )
	{
	case DSRDATA_TYPE_RATIONAL_FUN:
	case DSRDATA_TYPE_POLYNOM:
		{
			if( head ) head->getInstruction( vm, dest );
			if( expr ) expr->getInstruction( vm, dest );
			UniWord uniop;
			uniop.v_addr.param1 = fun_id;
			uniop.v_addr.param2 = fun_id_param;
			uniop.v_addr.param3 = (head ? 1 : 0) + (expr ? 1 : 0);
			CDSR_VMEval_Cmd item( VMC_DSR_OP, uniop, getLine() );
			dest.Add( item );
		}
		break;
	case DSRDATA_TYPE_FUNCTION:
		{
			CParseDsrSymbol *head_op = head->getSymbol( vm.getSmbTable() );
			if( head_op )
			{
				CDSR_VMEval_Line* fun_line = vm.getFunction_CmdLine( head_op->param2 );
				if( head_op )
				{
					if( fun_line )
					{
						expr->getInstruction( vm, *fun_line );
						UniWord uw1( _create_lparam( 0, /* current function result number is always 0 for the in-line functions */
											0, head_op->getArgNumber(), head_op->getResNumber() ) );
						CDSR_VMEval_Cmd item1( VMC_DSR_ASSIGN_FUN_RES, 
							uw1,
							getLine() );
						fun_line->Add( item1 );
						UniWord uw2( _create_lparam( 0, /* current function result number is always 0 for the in-line functions */
											0, head_op->getArgNumber(), head_op->getResNumber() ) );
						CDSR_VMEval_Cmd item2(
							VMC_DSR_RETURN, 
							uw2,
							getLine() );
						fun_line->Add( item2 );
					}
				}
			}
		}
		break;
	case DSRDATA_TYPE_ABS_GROUP:
		break;
	default:
		break;
	}
}

/////////////////////////////////////////
//	ObjDef_Compound	:	ObjHead, Compound;
/////////////////////////////////////////
void CDsrAST_ObjDef_Compound::getInstruction( CDSR_VMEval& vm, CDSR_VMEval_Line& /*dest*/ )
{
	switch( head->keyword->getKeywordType() )
	{
	case DSRDATA_TYPE_FUNCTION:
		{
			CParseDsrSymbol *head_op = head->getSymbol( vm.getSmbTable() );
			if( head_op )
			{
				CDSR_VMEval_Line* fun_line = vm.getFunction_CmdLine( head_op->param2 );
				if( fun_line )
				{
					compound->getInstruction( vm, *fun_line );
					UniWord uw(_create_lparam( 0, /* for the compound functions this RETURN code is never called */
										0, head_op->getArgNumber(), head_op->getResNumber() ));
					CDSR_VMEval_Cmd item(
						VMC_DSR_RETURN, 
						uw, /*, head_op->param2*/
						getLine() );
					fun_line->Add( item );
				}
			}
		}
		break;
	default:
		break;
	}
}

/////////////////////////////////////////
//	ObjHead			:	Keyword, PrimaryID, ObjArg;
/////////////////////////////////////////
void CDsrAST_ObjHead::getInstruction( CDSR_VMEval& vm, CDSR_VMEval_Line& dest )
{
	name->getInstruction( vm, dest );
}

/////////////////////////////////////////
//	ObjArg			:	Separator, ArgList, Separator, TypeSpec;
/////////////////////////////////////////
void CDsrAST_ObjArg::getInstruction( CDSR_VMEval& /*vm*/, CDSR_VMEval_Line& /*dest*/ )
{
}

///////////////////////////////////////////////////////////////////////////////
