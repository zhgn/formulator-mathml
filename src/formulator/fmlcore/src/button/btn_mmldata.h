

#if !defined( __FORMULATOR_FMLCORE_BTN_MMLDATA_H__ )
#define __FORMULATOR_FMLCORE_BTN_MMLDATA_H__

#include <QVector>
#include <QDataStream>

#include "../fmlcore_global.h"
#include "HUtils/ihkstring.h"

/////////////////////////////////////////////////////////////////////

class __YUNEN_FORMULIB__ FBtnMMLData
{
public:
	QString value, name, left, right, type, frame, mathml_template_string, reserved;
	qint8 precedence, assoc, is_content;

	FBtnMMLData( void );
	const FBtnMMLData& operator = ( const FBtnMMLData& a );
	void reset();
};

/////////////////////////////////////////////////////////////////////

QDataStream& operator << ( QDataStream& ar, const FBtnMMLData& lp );
QDataStream& operator >> ( QDataStream& ar, FBtnMMLData& lp );

/////////////////////////////////////////////////////////////////////

#endif
