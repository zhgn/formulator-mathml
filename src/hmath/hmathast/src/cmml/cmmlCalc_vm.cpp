

#include "cmmlCalc.h"
#include "../ast/astdsr.h"
#include "../vm/vmeval.h"
#include "../symbol/symbol_table_dsr.h"

///////////////////////////////////////////////////////////////////////////////

//int CMMLCalc::CreateVM( enum CDsrMathModel taskID, long subtaskID )
//{
//	int iRes = CMMLError_NONE;
//	if( !m_dsrSymbolTable || !m_ast )
//		iRes = CMMLError_NoAST;
//	else
//	{
//		// Create Virtual PC
//		m_dsrSymbolTable->setMessanger( &m_dmm, m_dmmPage, QString( m_taskName ) );
//		m_dsrSymbolTable->setTaskID( taskID, subtaskID );
//		m_dsrSymbolTable->allocateVariables();
//		m_vm = new CDSR_VMEval( m_dsrSymbolTable );
//	    
//		// Calculate types
//		m_ast->setObjectContextThroughTree();
//		m_ast->placeDataType( *m_dsrSymbolTable );
//	    
//		if( !(m_ast->getDataType() && m_ast->getDataType()->getType() != DSRDATA_TYPE_ERROR) )
//			iRes = CMMLError_Semantic;
//
//		m_ast->setLevelThroughTree();
//		m_vm->getInstruction( m_ast );
//		if( iRes != CMMLError_Semantic && m_vm->isError() )
//			iRes = CMMLError_Semantic;
//	}
//
//	m_dmm.AddLine( m_dmmPage, getErrorMsg(iRes), QString(m_taskName) );
//	return iRes;
//}

int CMMLCalc::CreateVM( enum CDsrMathModel taskID, long subtaskID )
{
	int iRes = CMMLError_NONE;
	if( !m_dsrSymbolTable || !m_ast )
		iRes = CMMLError_NoAST;
	else
	{
		// Create Virtual PC
		m_dsrSymbolTable->setMessanger( &m_dmm, m_dmmPage, QString( m_taskName ) );
		m_dsrSymbolTable->setTaskID( taskID, subtaskID );
		m_dsrSymbolTable->allocateVariables();
		m_vm = new CDSR_VMEval( m_dsrSymbolTable );
	    
		// Calculate types
		m_ast->setObjectContextThroughTree();
		m_ast->placeDataType( *m_dsrSymbolTable, true );
	    
		if( m_ast->getDataType() && m_ast->getDataType()->getType() != DSRDATA_TYPE_ERROR )
		{
			m_ast->setLevelThroughTree();
			m_vm->getInstruction( m_ast );
			if( m_vm->isError() )
				iRes = CMMLError_Semantic;
		}
		else
			iRes = CMMLError_Semantic;
	}

	m_dmm.AddLine( m_dmmPage, getErrorMsg(iRes), QString(m_taskName) );
	return iRes;
}

int CMMLCalc::execMain()
{
	if( !m_vm )
	{
		m_dmm.AddLine( m_dmmPage, getErrorMsg(CMMLError_NoVM), QString(m_taskName) );
		return CMMLError_NoVM;
	}

	return m_vm->execCommand();
}

///////////////////////////////////////////////////////////////////////////////
