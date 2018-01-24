

#ifndef __PARSEDSR_DATA_MMD_STR_OP_H__
#define __PARSEDSR_DATA_MMD_STR_OP_H__

#include "../uniword/uniword_op.h"
#include "mmd_str.h"

///////////////////////////////////////////////////////////////////////////////

__HMATHLNGDLL__
UniWord _dsrop_Add_string( UniWord& ret, const UniWord& a, const UniWord& b );
__HMATHLNGDLL__
UniWord _dsrop_Equal_string( UniWord& ret, const UniWord& a, const UniWord& b );
__HMATHLNGDLL__
UniWord _dsrop_NotEqual_string( UniWord& ret, const UniWord& a, const UniWord& b );

///////////////////////////////////////////////////////////////////////////////

#endif
