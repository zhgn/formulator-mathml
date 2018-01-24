

#ifndef __FORMULATOR_NODES_RULES_COPY_H__
#define __FORMULATOR_NODES_RULES_COPY_H__

#include "../node.h"

/////////////////////////////////////////////////////////////////////////////

int RemoveToFrame( CFrameNode *pFrameNode, SelectNode &sn, 
	SelectInfo &si, int fUpCalc = -1, SelectNode *psn = NULL );

int CopyToFrame( CFrameNode *pFrameNode, SelectNode &sn, 
	SelectInfo &si, int fUpCalc = -1 );

/////////////////////////////////////////////////////////////////////////////

#endif
