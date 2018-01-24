

#include "baseratio.h"
#include "../nodes/dump/dumptags.h"

/////////////////////////////////////////////////////////////////////////////
// constructor / destructor
/////////////////////////////////////////////////////////////////////////////

CGraphBSplineEx::CGraphBSplineEx() 
	: CGraphBSpline()
	, m_offset_direction_x( 0.0 )
	, m_offset_direction_y( 0.0 )
{
}

CGraphBSplineEx::CGraphBSplineEx( const CGraphBSplineEx& a ) 
	: CGraphBSpline( a )
	, m_offset_direction_x( a.m_offset_direction_x )
	, m_offset_direction_y( a.m_offset_direction_y )
{
}

CGraphBSplineEx::~CGraphBSplineEx()
{
}

int CGraphBSplineEx::Create( const CGraphPrimFormula& templatePrim  )
{
	if ( !CGraphBSpline::Create( templatePrim ) )
		return 0;

	m_offset_direction_x = templatePrim.m_offset_direction_x;
	m_offset_direction_y = templatePrim.m_offset_direction_y;

	return 1;
}

/////////////////////////////////////////////////////////////////////////////

int CGraphBSplineEx::GetPoints( const RectFde &rc, QVector<PointFde> &xy, QVector<qint8> &tp )
{
	CGraphBSpline::GetPoints( rc, xy, tp );

	// b-spline-ex part
	long i, count = xy.size();
	if( count )
	{
		PointFde cp;
		qint8 vl = spln_point_type_lineto;

		tp[ count - 1 ] &= ~spln_point_type_clsfig;
		for( i = count; i > 0; i-- )
		{
			cp = xy[ i - 1 ];
			cp.rx() += m_offset_direction_x;
			cp.ry() += m_offset_direction_y;
			xy.push_back( cp );
			tp.push_back( vl );
			vl = tp[ i - 1 ];
		}
		tp[ xy.size() - 1 ] |= spln_point_type_clsfig;
	}

	return 0;
}

QDataStream& operator << ( QDataStream& ar, const CGraphBSplineEx& lp )
{
	return ar << (const CGraphPrim&) lp << lp.m_offset_direction_x << lp.m_offset_direction_y;
}

QDataStream& operator >> ( QDataStream& ar, CGraphBSplineEx& lp )
{
	return ar >> (CGraphPrim&) lp >> lp.m_offset_direction_x >> lp.m_offset_direction_y;
}

//////////////////////////////////////////////////////////////////////
