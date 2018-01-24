

#include "baseratio.h"
#include "../style/style.h"
#include "../settings/options.h"
#include "../nodes/dump/dumptags.h"

/////////////////////////////////////////////////////////////////////////////

CGraphBSpline::CGraphBSpline() 
	: CGraphPrim()
	, m_point_type()
	, m_point_xy()
{
}

CGraphBSpline::CGraphBSpline( const CGraphBSpline& a ) 
	: CGraphPrim( a )
	, m_point_type( a.m_point_type )
	, m_point_xy( a.m_point_xy )
{
}

CGraphBSpline::~CGraphBSpline()
{
}

/////////////////////////////////////////////////////////////////////////////

int CGraphBSpline::Create( const CGraphPrimFormula& pf  )
{
	if( !CGraphPrim::Create( pf ) )
		return 0;

	m_point_type = pf.m_point_type;
	m_point_xy = pf.m_point_xy;

	return 1;
}

/////////////////////////////////////////////////////////////////////////////

int CGraphBSpline::Draw( CFmlDrawEngine& fde, const PointFde& tl, CNode* )
{
	RectFde rc = GetPositionRect();
	rc.translate( tl.x(), tl.y() );

	QVector<qint8> tp;
	QVector<PointFde> xy;
	GetPoints( rc, xy, tp );

	QColor color = (GetColor() == DEFAULT_GRAPH_COLOR ? ::getCurrentFormulatorStyle().getLogPen().m_color : GetColor());

	fde.DrawFillPath( xy, tp, FS_LogPen( color, (Qt::PenStyle) GetStyle(), GetWidth() ), FS_LogBrush(GetColor(), Qt::SolidPattern) );

	return 1;
}

/////////////////////////////////////////////////////////////////////////////

int CGraphBSpline::GetPoints( const RectFde &rc, QVector<PointFde>& xy, QVector<qint8>& tp )
{
	// scale factor
	RealFde w = rc.width();
	RealFde h = rc.height();

	PointFde point;
	long i, count = m_point_xy.size();
	for( i = 0; i < count; i++ )
	{
		point.rx() = rc.left() + m_point_xy[ i ].x() * w / DRAWENGINE_BSPLINE_SCALE_X;
		point.ry() = rc.top()  + m_point_xy[ i ].y() * h / DRAWENGINE_BSPLINE_SCALE_Y;
		xy.push_back( point );
	}

	tp = m_point_type;
	return 0;
}

//////////////////////////////////////////////////////////////////////

QDataStream& operator << ( QDataStream& ar, const CGraphBSpline& lp )
{
	return ar << (const CGraphPrim&) lp << lp.m_point_type << lp.m_point_xy;
}

QDataStream& operator >> ( QDataStream& ar, CGraphBSpline& lp )
{
	return ar >> (CGraphPrim&) lp >> lp.m_point_type >> lp.m_point_xy;
}

//////////////////////////////////////////////////////////////////////
