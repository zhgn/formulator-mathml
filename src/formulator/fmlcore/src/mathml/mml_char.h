

#if !defined( __COMMON_LANGUAGE_MATHML_FORMAT_MML_CHAR_H__ )
#define __COMMON_LANGUAGE_MATHML_FORMAT_MML_CHAR_H__

#include "../fmlcore_global.h"
#include "HUtils/ihkstring.h"

#define MML_CHAR__ASCII_NUMBER		17
#define MML_CHAR__GREEK_NUMBER		26
#define MML_CHAR__GREEK_OP_NUMBER	18
#define MML_CHAR__NUMBER			(2 * MML_CHAR__GREEK_NUMBER + MML_CHAR__ASCII_NUMBER + MML_CHAR__GREEK_OP_NUMBER)

#define MML_CHAR_AMP				_T('&')

#define MML_STYLE_GREEK				0
#define MML_STYLE_OP				1
#define MML_STYLE_TEXT				2

__YUNEN_FORMULIB__ extern const QString __mml_char__name[ MML_CHAR__NUMBER ];
__YUNEN_FORMULIB__ extern const QString __mml_char__value[ MML_CHAR__NUMBER ];
__YUNEN_FORMULIB__ extern const long __mml_char__font[ MML_CHAR__NUMBER ];
__YUNEN_FORMULIB__ QString mml_getGreek( QChar a );

#endif
