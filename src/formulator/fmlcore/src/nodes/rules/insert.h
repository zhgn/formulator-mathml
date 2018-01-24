

#ifndef __FORMULATOR_NODES_RULES_INSERT_H__
#define __FORMULATOR_NODES_RULES_INSERT_H__

#include "../node.h"
#include "../extcontent/ext_node.h"

CPlaneText* InsertAlnumPlaneText( SelectNode &sn, QChar ch, RealFde kegl );
CPlaneText* InsertPlaneText( SelectNode &sn, QChar ch, long style, RealFde kegl, CNodeInfo& ni, CNodeExInfo& ex_ni );
CPlaneText* InsertPlaneText( SelectNode &sn, QString &strText, long style, RealFde kegl, CNodeInfo& ni, CNodeExInfo& ex_ni );

void SetReadOnlyAttribute4AllNonEmptyNodes( CParentNode *pParentNode );

int InsertFromText( CPlaneText *pPlaneText, SelectNode &sn, int fUpCalc = -1 );
int InsertFromLine( CLineNode *pLineNode, SelectNode &sn, int fUpCalc = -1, SelectInfo *psi = NULL );
int InsertFromFrame( CFrameNode *pFrameNode, SelectNode &sn, int fUpCalc = -1, SelectInfo *psi = NULL );
int InsertFromFormula( CFormulaNode *pFormulaNode, SelectNode &sn, int fUpCalc = -1 );

CPlaneText* InsertPlaneText( SelectNode &sn, CExtNode *pNode );

/////////////////////////////////////////////////////////////////////////////
#endif//__FORMULATOR_NODES_RULES_INSERT_H__
