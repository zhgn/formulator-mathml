

#if !defined( __PARSEDSR_OPERATOR_MM_INFO_H__ )
#define __PARSEDSR_OPERATOR_MM_INFO_H__

#include "../hmathast_global.h"
#include "../type/typedsr.h"
#include "mm_domain.h"

///////////////////////////////////////////////////////////////////////////////

__HMATHLNGDLL__ extern enum CDsrDataTypes CDsrMMDefaultTypeTable[ DSRMM_LAST ];
__HMATHLNGDLL__ enum CDsrDataTypes getCDsrMMDefaultType( enum CDsrMathModel mm_id, long mm_sub_task = -1 );
__HMATHLNGDLL__ extern int CDsrMMPropertyTable[ DSRMM_LAST ][ DSR_HAVE_LAST ];
__HMATHLNGDLL__ long getCDsrMMProperty( enum CDsrMathModel mm_id, enum CDsrMMProperty mmprop_id );
__HMATHLNGDLL__ int isCDsrAGWCongruence( int agw );

///////////////////////////////////////////////////////////////////////////////

#endif
