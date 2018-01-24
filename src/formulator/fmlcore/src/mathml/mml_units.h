

#if !defined( __COMMON_LANGUAGE_MATHML_FORMAT_MML_UNITS_H__ )
#define __COMMON_LANGUAGE_MATHML_FORMAT_MML_UNITS_H__

#include "../fmlcore_global.h"
#include "HUtils/ihkstring.h"
#include "HUtils/idrawstruct.h"

#define MML_UNIT_NAME__EM		_T("em")
#define MML_UNIT_NAME__EX		_T("ex")
#define MML_UNIT_NAME__PX		_T("px")
#define MML_UNIT_NAME__IN		_T("in")
#define MML_UNIT_NAME__CM		_T("cm")
#define MML_UNIT_NAME__MM		_T("mm")
#define MML_UNIT_NAME__PT		_T("pt")
#define MML_UNIT_NAME__PC		_T("pc")
#define MML_UNIT_NAME__PERCENT	_T("%")

__YUNEN_FORMULIB__ int mml_attr_unit_2_value( int is_y, RealFde& old_value, const QString& body, const SYSINFO_Unit2PX& unit2px );
__YUNEN_FORMULIB__ int mml_convertSpaceName2FloatValue( int is_y, const QString& spacename, RealFde& value, const SYSINFO_Unit2PX& unit2px );
__YUNEN_FORMULIB__ int mml_convertFloatValue2SpaceName( QString& destname, RealFde value, const SYSINFO_Unit2PX& unit2px );
__YUNEN_FORMULIB__ int mml_attr_paddedunit_2_value( long selfIdx, const QString& body, RealFde* newValues, RealFde* oldValues, const SYSINFO_Unit2PX& unit2px );
__YUNEN_FORMULIB__ int mml_findUnit( QString& destUnitName, double& destVal, int& isNeedRound, const QString& body, int is_y, const SYSINFO_Unit2PX& unit2px );

#endif
