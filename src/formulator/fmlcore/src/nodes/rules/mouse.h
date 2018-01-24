

#ifndef __FORMULATOR_NODES_RULES_MOUSE_H__
#define __FORMULATOR_NODES_RULES_MOUSE_H__

#include "../node.h"

/////////////////////////////////////////////////////////////////////////////

int MoveCaret( CNode *pNode, int isRight, SelectNode &sn );

int MoveCaret( 
	const PointFde &pt, const RectFde &rc, 
	SelectNode &sn, CFrameNode *pFrameNode );

	int MoveCaret( int fSel, 
	const PointFde &pt, const RectFde &rc, 
	SelectNode &sn, SelectInfo &si, CFrameNode *pFrameNode );

int DblClk( 
	const PointFde &pt, const RectFde &rc, 
	SelectNode &sn, SelectInfo &si, CFrameNode *pFrameNode );

/////////////////////////////////////////////////////////////////////////////
#endif//__FORMULATOR_NODES_RULES_MOUSE_H__
