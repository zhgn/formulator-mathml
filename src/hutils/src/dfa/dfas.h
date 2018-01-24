

#if !defined( __MATHLANG_LIMAUTO_DFAS_H__ )
#define __MATHLANG_LIMAUTO_DFAS_H__

#include "digit/la_digit.h"
#include "digit/la_sdigit.h"
#include "digit/la_sdigit_base.h"
#include "digit/la_xmlattr_sdigit.h"
#include "dsr2_var/la_dsr2var.h"
#include "entity/la_entity.h"
#include "keyword/la_keyword.h"
#include "string/la_str.h"
#include "string/la_xmlstr.h"
#include "var/la_cvar.h"
#include "var/la_xmlvar.h"

#define ELH_NO_ERROR		0
#define ELH_SOFT_ERROR		-2
#define ELH_CRITICAL_ERROR	-1

HUTILS_EXPORT int _hatol( const QStringRef& str, long& value );
HUTILS_EXPORT int _hatof( const QStringRef& str, double& value );
HUTILS_EXPORT int _hatol_base( const QStringRef& str, const QString& base, long& value );
HUTILS_EXPORT int _hatof_base( const QStringRef& str, const QString& base, double& value );

#endif
