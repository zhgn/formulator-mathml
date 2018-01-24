

#include "baseratio.h"
#include "../button/btn_tags.h"
#include "../settings/options.h"
#include "../style/style.h"
#include "../nodes/dump/dumptags.h"

//////////////////////////////////////////////////////////////////////

CGraphQuaterArc::CGraphQuaterArc()
	: CGraphPrim()
{
}

CGraphQuaterArc::CGraphQuaterArc( const CGraphQuaterArc& a ) 
	: CGraphPrim( a )
	, orientation( a.orientation )
{
}

CGraphQuaterArc::~CGraphQuaterArc()
{
}

/////////////////////////////////////////////////////////////////////

int CGraphQuaterArc::Create( const CGraphPrimFormula& templatePrim )
{
	if( !CGraphPrim::Create( templatePrim ) )
		return 0;
	orientation = templatePrim.GetString();
	return 1;
}

/////////////////////////////////////////////////////////////////////

int CGraphQuaterArc::Draw( CFmlDrawEngine& fde, const PointFde& tl, CNode* )
{
	RectFde objPosition = GetPositionRect();
	objPosition.translate( tl.x(), tl.y() );

	RealFde start, sweep;
	GetObjPosition( objPosition, start, sweep );

	QColor color = (GetColor() == DEFAULT_GRAPH_COLOR ? ::getCurrentFormulatorStyle().getLogPen().m_color : GetColor());

	fde.DrawArc( 
		objPosition.left(), objPosition.top(), 
		objPosition.width(), objPosition.height(), 
		start, sweep, FS_LogPen( color, (Qt::PenStyle) GetStyle(), GetWidth() ) );

	return 1;
}

/////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////

void CGraphQuaterArc::GetObjPosition( RectFde& objPosition, RealFde& start, RealFde& sweep )
{
	if( orientation == FBL_VAL_NW )
	{
		start = 180.0;
		sweep = 90.0;
		objPosition.setRight( objPosition.left() + (objPosition.right() - objPosition.left()) * 2.0);
		objPosition.setBottom( objPosition.top() + (objPosition.bottom() - objPosition.top()) * 2.0);
	}
	else if( orientation == FBL_VAL_SW )
	{
		start = 90.0;
		sweep = 90.0;
		objPosition.setRight( objPosition.left() + (objPosition.right() - objPosition.left()) * 2.0);
		objPosition.setTop( objPosition.bottom() - (objPosition.bottom() - objPosition.top()) * 2.0);
	}
	else if( orientation == FBL_VAL_NE )
	{
		start = 270.0;
		sweep = 90.0;
		objPosition.setLeft( objPosition.right() - (objPosition.right() - objPosition.left()) * 2.0);
		objPosition.setBottom( objPosition.top() + (objPosition.bottom() - objPosition.top()) * 2.0);
	}
	else if( orientation == FBL_VAL_SE )
	{
		start = 0.0;
		sweep = 90.0;
		objPosition.setLeft( objPosition.right() - (objPosition.right() - objPosition.left()) * 2.0);
		objPosition.setTop( objPosition.bottom() - (objPosition.bottom() - objPosition.top()) * 2.0);
	}
	else
	{
		start = 0.0;
		sweep = 0.0;
	}
}

//////////////////////////////////////////////////////////////////////

QDataStream& operator << ( QDataStream& ar, const CGraphQuaterArc& lp )
{
	return ar << (const CGraphPrim&) lp << lp.orientation;
}

QDataStream& operator >> ( QDataStream& ar, CGraphQuaterArc& lp )
{
	return ar >> (CGraphPrim&) lp >> lp.orientation;
}

//////////////////////////////////////////////////////////////////////
