

#if !defined( __FORMULATOR_FMLCORE_BTN_CHILDPOS_H__ )
#define __FORMULATOR_FMLCORE_BTN_CHILDPOS_H__

#include <QVector>
#include <QDataStream>

#include "../fmlcore_global.h"
#include "HUtils/idrawstruct.h"

/////////////////////////////////////////////////////////////////////

class __YUNEN_FORMULIB__ FBtnChildPos
{
public:
	enum AlignmentType
	{
		Default = 0,
		Child,
		Child_Average,
		Frame,
		Frame_Blank_Average,
		Half,
		MSPACE_Exact_HeightDepth,
		TableAxis,
		TableCenter2Baseline,
		TableTop2Baseline,
		TableBottom2Baseline
	};

public:
	RectFde pos;
	qint32 align;
	qint32 level;

public:
	FBtnChildPos();
	FBtnChildPos( RectFde apos, long aalign, long alevel );
};

/////////////////////////////////////////////////////////////////////

QDataStream& operator << ( QDataStream& ar, const FBtnChildPos& lp );
QDataStream& operator >> ( QDataStream& ar, FBtnChildPos& lp );

/////////////////////////////////////////////////////////////////////

#endif
