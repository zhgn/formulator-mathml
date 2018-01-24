

#ifndef __FORMULATOR_NODES_DUMP_H__
#define __FORMULATOR_NODES_DUMP_H__

#ifdef _DEBUG 

class CNode;
CNode* root( CNode* pNode );
void info( CNode *pNode, int level = 0 );
void dump( CNode *pNode, int level = 0 );

#endif // _DEBUG

/////////////////////////////////////////////////////////////////////////////
#endif // __FORMULATOR_NODES_DUMP_H__