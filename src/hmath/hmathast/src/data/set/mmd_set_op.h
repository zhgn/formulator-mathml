

#ifndef __PARSEDSR_DATA_MMD_SET_OP_H__
#define __PARSEDSR_DATA_MMD_SET_OP_H__

#include "../uniword/uniword_op.h"
#include "mmd_set.h"

///////////////////////////////////////////////////////////////////////////////

__HMATHLNGDLL__
MMD_Set* _dsrop_SetAdd( MMD_Set *a, MMD_Set *b );
__HMATHLNGDLL__
MMD_Set* _dsrop_SetMul( MMD_Set *vset1, MMD_Set *vset2 );
__HMATHLNGDLL__
MMD_Set* _dsrop_SetSub( MMD_Set *vset1, MMD_Set *vset2 );
__HMATHLNGDLL__
MMD_Set* _dsrop_SetDecartMul( MMD_Set *vset1, MMD_Set *vset2 );
__HMATHLNGDLL__
UniWord _dsrop_SetRelIn( UniWord& ret, MMD_Set *vset, UniWord& word );
__HMATHLNGDLL__
UniWord _dsrop_SetRelNotIn( UniWord& ret, MMD_Set *vset, UniWord& word );
__HMATHLNGDLL__
UniWord _dsrop_SetRelSetIn( UniWord& ret, MMD_Set *vset1, MMD_Set *vset2 );
__HMATHLNGDLL__
UniWord _dsrop_SetRelSetNotIn( UniWord& ret, MMD_Set *vset1, MMD_Set *vset2 );
__HMATHLNGDLL__
UniWord _dsrop_SetRelSetInInv( UniWord& ret, MMD_Set *vset1, MMD_Set *vset2 );
__HMATHLNGDLL__
UniWord _dsrop_SetRelSetInEq( UniWord& ret, MMD_Set *vset1, MMD_Set *vset2 );
__HMATHLNGDLL__
UniWord _dsrop_SetRelSetInEqInv( UniWord& ret, MMD_Set *vset1, MMD_Set *vset2 );
__HMATHLNGDLL__
UniWord _dsrop_SetEqual_anytype( MMD_Set *a, MMD_Set *b );
__HMATHLNGDLL__
UniWord _dsrop_SetNotEqual_anytype( MMD_Set *a, MMD_Set *b );

///////////////////////////////////////////////////////////////////////////////

#endif
