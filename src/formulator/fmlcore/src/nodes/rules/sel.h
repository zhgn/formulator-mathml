

#ifndef __FORMULATOR_NODES_RULES_SEL_H__
#define __FORMULATOR_NODES_RULES_SEL_H__

#include <vector>
#include "../info/nodeinfo.h"

__YUNEN_FORMULIB__ int DrawSelection( const RectFde &rc, SelectInfo &si, std::vector<RectFde>& sel );
__YUNEN_FORMULIB__ int TestSelection( const RectFde &rc, SelectInfo &si, const PointFde &pt );

__YUNEN_FORMULIB__ int DragInSelection( SelectNode &sn, SelectInfo &si );

/////////////////////////////////////////////////////////////////////////////
#endif//__FORMULATOR_NODES_RULES_SEL_H__
