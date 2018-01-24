

#include "baseratio.h"
#include "../style/style.h"
#include "../settings/options.h"
#include "../nodes/dump/dumptags.h"

//////////////////////////////////////////////////////////////////////

CGraphRect::CGraphRect()
	: CGraphPrim()
{
}

CGraphRect::CGraphRect( const CGraphRect& a ) 
	: CGraphPrim( a )
{
}

CGraphRect::~CGraphRect()
{
}

/////////////////////////////////////////////////////////////////////

int CGraphRect::Draw( CFmlDrawEngine& fde, const PointFde& tl, CNode* )
{
	if( GetWidth() == 0 ) return 0;
	RectFde objPosition = GetPositionRect();
	objPosition.translate( tl.x(), tl.y() );

	QColor color = (GetColor() == DEFAULT_GRAPH_COLOR ? ::getCurrentFormulatorStyle().getLogPen().m_color : GetColor());

	if( GetAlign() & ELLIPSE_MASK_ALIGN )	// circle
	{
		fde.DrawEllipse( 
			objPosition.left(),  objPosition.top(), 
			objPosition.width(), objPosition.height(), 
			FS_LogPen( color, (Qt::PenStyle) GetStyle(), GetWidth() ) );
	}
	else
	{
		fde.DrawRectangle( 
			objPosition.left(),  objPosition.top(), 
			objPosition.width(), objPosition.height(), 
			FS_LogPen( color, (Qt::PenStyle) GetStyle(), GetWidth() ) );
	}

	return 1;
}

/////////////////////////////////////////////////////////////////////

QDataStream& operator << ( QDataStream& ar, const CGraphRect& lp )
{
	return ar << (const CGraphPrim&) lp;
}

QDataStream& operator >> ( QDataStream& ar, CGraphRect& lp )
{
	return ar >> (CGraphPrim&) lp;
}

//////////////////////////////////////////////////////////////////////
