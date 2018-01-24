

#if !defined( __FORMULATOR_EXTCONTENT_EXTC_IMG_H__ )
#define __FORMULATOR_EXTCONTENT_EXTC_IMG_H__

#include "../../settings/options.h"
#include "../../fmlcore_global.h"
#include "ext_node.h"

/////////////////////////////////////////////////////////////////////////////

#define EXTNODECONTENT_ID_IMG	1

/////////////////////////////////////////////////////////////////////////////

#define EXTNODECONTENT_ID_IMG__FLAG_ATTACHED	0x00000001
#define EXTNODECONTENT_ID_IMG__FLAG_EMBEDDED	0x00000002

class __YUNEN_FORMULIB__ CExtNodeContent_Image_Data
{
protected:
	QString	m_path;
	HKLongFlag	m_flag;

public:
	CExtNodeContent_Image_Data( long flag = 0, QString path = _T("") )
	{
		m_flag = flag;
		m_path = "";
		setPath( path );
	}
	CExtNodeContent_Image_Data( const CExtNodeContent_Image_Data& data )
	{
		m_flag = 0;
		m_path = "";
		set( data );
	}
	virtual ~CExtNodeContent_Image_Data( void )
		{ setPath( _T("") ); }

	void set( const CExtNodeContent_Image_Data& data )
		{ m_flag = data.m_flag; setPath( data.m_path ); }

	QString getPath( void ) { return m_path; }
	void setPath( const QString& path );

	long getFlag( void ) { return m_flag.getValue(); }
	void setFlag( long flag ) { m_flag.setValue( flag ); }

	virtual void Store( QDataStream& ar ) const;
	virtual void Load( QDataStream& ar );
};


/////////////////////////////////////////////////////////////////////////////

#define CExtNodeContent_Image_DEFAULT_EMPTY_BOX_CX	50.0
#define CExtNodeContent_Image_DEFAULT_EMPTY_BOX_CY	50.0

/////////////////////////////////////////////////////////////////////////////

class __YUNEN_FORMULIB__ CExtNodeContent_Image : 
	public CExtNodeContent_Base, public CExtNodeContent_Image_Data
{
public:
	CExtNodeContent_Image( void );
	CExtNodeContent_Image( const CExtNodeContent_Image& _content );

protected:
	virtual void InitSize( void );

public:
	virtual QString to_mathml( long nLevel, long& nodesCount ); 

	virtual void Init( void *pData );

	virtual void Store( QDataStream& ar ) const;
	virtual void Load( QDataStream& ar );

	virtual void Draw( CFmlDrawEngine& fde, const PointFde& tl, const RectFde& rc );
};

/////////////////////////////////////////////////////////////////////////////

#endif//__FORMULATOR_EXTCONTENT_EXTC_TEST_H__
