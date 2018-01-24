

#if !defined( __FORMULATOR_DICTIONARY_OP_AUTOKEYWORD_H__ )
#define __FORMULATOR_DICTIONARY_OP_AUTOKEYWORD_H__

#include <QMap>

#include "HUtils/ihkstring.h"

#include "../mathml/mml_tag2mml.h"
#include "../fmlcore_global.h"

///////////////////////////////////////////////////////////////////////////////

__YUNEN_FORMULIB__ const HKMap<QString, QString>& getText2ButtonIDMap();

__YUNEN_FORMULIB__ int detectContentTag( QString& name, QString& body, QString& sattr, QString& parsedBody, long parsedStyle );
__YUNEN_FORMULIB__ long getCMKeyword2ButtonID( QString keyword, QString& btnID );
__YUNEN_FORMULIB__ enum TAG2MML getCMKeyword2TagID( QString keyword, QString& opBody );
__YUNEN_FORMULIB__ int isCMKeywordPrefix( QString keyword );
__YUNEN_FORMULIB__ int shouldBracket4Apply( QString calculationCenterID, long childPos );
__YUNEN_FORMULIB__ int getSupContentByOperatorTagID( enum TAG2MML tag_id, QString& szBody, QString& szBase );

///////////////////////////////////////////////////////////////////////////////

#endif
