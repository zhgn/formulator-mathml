

#ifndef __FORMULATOR_NODES_RULES_APPSTYLE_H__
#define __FORMULATOR_NODES_RULES_APPSTYLE_H__

#include "../node.h"

int wouldChangeStyleOnMathStyleAutodetect( CPlaneText *pPlaneText );

int ApplyUserOtherStyle( long style, SelectNode &sn, SelectInfo &si );
int ApplyUserOtherKegl( RealFde kegl, SelectNode &sn, SelectInfo &si );
int ApplyUserOtherKegl_IncDec( RealFde kegl, SelectNode &sn, SelectInfo &si );
RealFde GetCurrentKegl( SelectNode &sn );

/////////////////////////////////////////////////////////////////////////////
#endif//__FORMULATOR_NODES_RULES_APPSTYLE_H__
