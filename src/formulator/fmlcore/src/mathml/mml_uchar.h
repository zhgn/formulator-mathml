

#if !defined( __COMMON_LANGUAGE_MATHML_FORMAT_MML_UCHAR_H__ )
#define __COMMON_LANGUAGE_MATHML_FORMAT_MML_UCHAR_H__

#include "../fmlcore_global.h"
#include "HUtils/ihkstring.h"

#define MML_UNICODE_CHAR		1943

__YUNEN_FORMULIB__ extern const QString __mml_unicode_char__name[ MML_UNICODE_CHAR ];
__YUNEN_FORMULIB__ extern const unsigned short __mml_unicode_char__value[ MML_UNICODE_CHAR ];

inline
QString __mml_unicode_char2string( unsigned short v )
{
	return QString("&#%1;").arg(v);
}

#endif
