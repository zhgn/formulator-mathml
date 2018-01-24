

#include "btn_childpos.h"
#include "btn_graphics.h"
#include "../style/style.h"

/////////////////////////////////////////////////////////////////////

FBtnChildPos::FBtnChildPos()
	: pos( RectFde( PointFde(0.0, 0.0), PointFde(HF_BINBUTTON_HORIZONTAL_SCALE, HF_BINBUTTON_VERTICAL_SCALE) ) )
	, align( HORISONTAL_CENTER | VERTICAL_CENTER )
	, level( 0 )
{
}

FBtnChildPos::FBtnChildPos( RectFde apos, long aalign, long alevel )
	: pos( apos )
	, align( aalign )
	, level( alevel )
{
}

/////////////////////////////////////////////////////////////////////

QDataStream& operator << ( QDataStream& ar, const FBtnChildPos& lp )
{
	return	ar << lp.pos << lp.align << lp.level;
}

QDataStream& operator >> ( QDataStream& ar, FBtnChildPos& lp )
{
	return	ar >> lp.pos >> lp.align >> lp.level;
}

/////////////////////////////////////////////////////////////////////
