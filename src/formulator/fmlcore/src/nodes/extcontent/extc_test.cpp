

#include "extc_test.h"

/////////////////////////////////////////////////////////////////////////////

CExtNodeContent_Test::CExtNodeContent_Test( void ) :
	CExtNodeContent_Base( EXTNODECONTENT_ID_TEST )
{
	setWidth( 50.0 );
	setHeight( 50.0 );
}

CExtNodeContent_Test::CExtNodeContent_Test( const CExtNodeContent_Test& _content ) :
	CExtNodeContent_Base( _content )
{
}

CExtNodeContent_Base* CExtNodeContent_Test::Clone( void )
{
	return new CExtNodeContent_Test( *this );
}

void CExtNodeContent_Test::Init( void * /*pData*/ )
{
}

void CExtNodeContent_Test::Store( QDataStream& ar ) const
{
	CExtNodeContent_Base::Store( ar );
}

void CExtNodeContent_Test::Load( QDataStream& ar )
{
	CExtNodeContent_Base::Load( ar );
}

void CExtNodeContent_Test::Draw( CFmlDrawEngine& fde, const PointFde& tl, const RectFde& /*rc*/ )
{
	RectFde rcf = getDrawSize();
	rcf.translate( tl.x(), tl.y() );

	FS_LogPen lp( QColor( 0, 0, 127 ) );
	fde.DrawRectangle( rcf.left(), rcf.top(), rcf.width(), rcf.height(), lp );
	fde.DrawLine( rcf.left(), rcf.top(), rcf.right(), rcf.bottom(), lp );
	fde.DrawLine( rcf.left(), rcf.bottom(), rcf.right(), rcf.top(), lp );
}

/////////////////////////////////////////////////////////////////////////////
