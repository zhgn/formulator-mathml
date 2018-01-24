

#include <QPrinter>

#include "../../mathml/mml_format.h"
#include "extc_img.h"

/////////////////////////////////////////////////////////////////////////////

void CExtNodeContent_Image_Data::setPath( const QString& path )
{
	CFmlDrawEngineQt::DelImageEx( m_path );
	m_path = path;
	CFmlDrawEngineQt::AddImageEx( m_path );
}

void CExtNodeContent_Image_Data::Store( QDataStream& ar ) const
{
	ar << m_flag;
	ar << m_path;
}

void CExtNodeContent_Image_Data::Load( QDataStream& ar )
{
	QString path;

	ar >> m_flag;
	ar >> path;
	if( m_flag.isSetFlag( EXTNODECONTENT_ID_IMG__FLAG_ATTACHED | EXTNODECONTENT_ID_IMG__FLAG_EMBEDDED ) )
		setPath( path );
	else
		m_path = path;	// sekito : хотя логика мне не понятна
}

/////////////////////////////////////////////////////////////////////////////

CExtNodeContent_Image::CExtNodeContent_Image( void )
	: CExtNodeContent_Base( EXTNODECONTENT_ID_IMG )
	, CExtNodeContent_Image_Data()
{
}

CExtNodeContent_Image::CExtNodeContent_Image( const CExtNodeContent_Image& _content )
	: CExtNodeContent_Base( _content )
	, CExtNodeContent_Image_Data( _content )
{
}

/////////////////////////////////////////////////////////////////////

void CExtNodeContent_Image::InitSize( void )
{
	SizeFde sz( 0.0, 0.0 );
	sz = CFmlDrawEngineQt::MeasureImageEx( getPath() );
	setWidth( sz.width() > 0.0 ? sz.width() : CExtNodeContent_Image_DEFAULT_EMPTY_BOX_CX );
	setHeight( sz.height() > 0.0 ? sz.height() : CExtNodeContent_Image_DEFAULT_EMPTY_BOX_CY );
}

/////////////////////////////////////////////////////////////////////

QString CExtNodeContent_Image::to_mathml( long nLevel, long& nodesCount )
{
	nodesCount = 1;
	return ::mml_tag_self_nl( QString( FBL_TAG_mspace ), 
		MAKE_MATHML_ATTR( FBL_ATTR_image_path, getPath() ), nLevel );
}

/////////////////////////////////////////////////////////////////////

void CExtNodeContent_Image::Init( void *pData )
{
	if( pData != NULL )
	{
		CExtNodeContent_Image_Data *pImagedata = (CExtNodeContent_Image_Data*) pData;
		set( *pImagedata );
		delete pImagedata;
		pImagedata = NULL;
	}

	InitSize();
}

void CExtNodeContent_Image::Store( QDataStream& ar ) const
{
	CExtNodeContent_Base::Store( ar );
	CExtNodeContent_Image_Data::Store( ar );
}

void CExtNodeContent_Image::Load( QDataStream& ar )
{
	CExtNodeContent_Base::Load( ar );
	CExtNodeContent_Image_Data::Load( ar );

	InitSize();
}

/////////////////////////////////////////////////////////////////////

void CExtNodeContent_Image::Draw( CFmlDrawEngine& fde, const PointFde& tl, const RectFde& rc )
{
	if( m_flag.isSetFlag( EXTNODECONTENT_ID_IMG__FLAG_ATTACHED | EXTNODECONTENT_ID_IMG__FLAG_EMBEDDED ) )
	{
		if( tl.x() + getWidth() < rc.left() || tl.y() + getHeight() < rc.top() || tl.x() > rc.right() || tl.y() > rc.bottom() )
			return;
	    
		if( fde.DrawImage( tl.x(), tl.y(), getWidth(), getHeight(), getPath() ) )
			return;
	}

	RectFde rcf = getDrawSize();
	rcf.translate( tl.x(), tl.y() );

	FS_LogPen lp( QColor( 255, 0, 0 ) );
	fde.DrawRectangle( rcf.left(), rcf.top(), rcf.width(), rcf.height(), lp );
	fde.DrawLine( rcf.left(), rcf.top(), rcf.right(), rcf.bottom(), lp );
	fde.DrawLine( rcf.left(), rcf.bottom(), rcf.right(), rcf.top(), lp );
}

/////////////////////////////////////////////////////////////////////////////
