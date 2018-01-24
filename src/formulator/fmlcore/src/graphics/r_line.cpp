

#include "baseratio.h"
#include "../style/style.h"
#include "../settings/options.h"
#include "../nodes/dump/dumptags.h"

//////////////////////////////////////////////////////////////////////

CGraphLine::CGraphLine()
	: CGraphPrim() 
{
}

CGraphLine::CGraphLine( const CGraphLine& a ) 
	: CGraphPrim( a ) 
{
}

CGraphLine::~CGraphLine()
{
}

/////////////////////////////////////////////////////////////////////

int CGraphLine::Draw( CFmlDrawEngine& fde, const PointFde& tl, CNode* )
{
	if( GetWidth() == 0 ) return 0;
	RectFde objPosition = GetPositionRect();
	objPosition.translate( tl.x(), tl.y() );

	QColor color = (GetColor() == DEFAULT_GRAPH_COLOR ? ::getCurrentFormulatorStyle().getLogPen().m_color : GetColor());
	fde.DrawLine( objPosition.left(), objPosition.top(), objPosition.right(), objPosition.bottom(), 
		FS_LogPen( color, (Qt::PenStyle) GetStyle(), GetWidth() ) );

	return 1;
}

/////////////////////////////////////////////////////////////////////

QDataStream& operator << ( QDataStream& ar, const CGraphLine& lp )
{
	return ar << (const CGraphPrim&) lp;
}

QDataStream& operator >> ( QDataStream& ar, CGraphLine& lp )
{
	return ar >> (CGraphPrim&) lp;
}

//////////////////////////////////////////////////////////////////////
