

#ifndef __FORMULATOR_NODES_RULES_EDIT_H__
#define __FORMULATOR_NODES_RULES_EDIT_H__

#include "../node.h"

class CUndoRedo;
class HAutodetectMulticharOp;

void BreakPlaneText( SelectNode &sn, int fUpCalc = 1, SelectNode *psb = NULL, SelectNode *pse = NULL );
void BreakLine( SelectNode &sn, int fUpCalc = 1, SelectNode *psb = NULL, SelectNode *pse = NULL );

int GlueText( SelectNode &sn, CNode *pPrev, int fUpCalc = 1, SelectNode *psb = NULL, SelectNode *pse = NULL );
int GlueLine( SelectNode &sn, CNode *pPrev, int fUpCalc = 1, SelectNode *psb = NULL, SelectNode *pse = NULL );
int GlueTextInLine( CLineNode *pLineNode, SelectInfo *psi = NULL );

int MoveDelBs_RemoveOperatorFromApply( CPlaneText *pOperatorNode, CLineNode *pParentLine, SelectNode &sn, HAutodetectMulticharOp *autoMulticharOp );
int MoveDelBs_RemoveBrackets( CFormulaNode* bracketsNode, SelectNode &sn, int isSNBeforeOpNode, int isSNBeforeBracket );

int MoveDel( SelectNode &sn, SelectInfo &si, HAutodetectMulticharOp *autoMulticharOp, CUndoRedo *pUndoRedo );
int MoveBs( SelectNode &sn, SelectInfo &si, HAutodetectMulticharOp *autoMulticharOp, CUndoRedo *pUndoRedo );

int OnChar( QChar ch, SelectNode &sn, SelectInfo &si );

class HAutodetectMulticharOp;
int OnOperator( QChar ch, SelectNode &sn, SelectInfo &si, QString& btnID, QString& btnIDParam, HAutodetectMulticharOp* autoMulticharOp, int isOnCharState, const SelectNode &snlb, CUndoRedo *pUndoRedo );

int IsMoveDelCheck( SelectNode &sn, SelectInfo &si );
int IsMoveBsCheck( SelectNode &sn, SelectInfo &si );

/////////////////////////////////////////////////////////////////////////////

int CutLeftRight( SelectNode &sn, SelectInfo &si, 
	CFrameNode **ppFrameNodeL, CFrameNode **ppFrameNodeR );

/////////////////////////////////////////////////////////////////////////////

int PasteLeftRight( SelectNode &sn, SelectInfo &si, 
	CFrameNode *pFrameNodeL, CFrameNode *pFrameNodeR, CFormulaNode *pFormulaNode );

/////////////////////////////////////////////////////////////////////////////

#endif
