

#if !defined( __FORMULATOR_FMLCORE_BTN_TOOLBARSET_H__ )
#define __FORMULATOR_FMLCORE_BTN_TOOLBARSET_H__

#include <QMultiMap>
#include <vector>
#include "toolbar.h"

///////////////////////////////////////////////////////////////////////////////

class __YUNEN_FORMULIB__ FBtnToolbarSet : public QVector<FBtnToolbar>, public HKToolBarSet
{
protected:
	QMultiMap< QString, QPair<qint32, qint32> > m_id2tb;
	QMultiMap< QString, QPair<qint32, qint32> > m_mmlname2tb;
	QMultiMap< QString, QPair<qint32, qint32> > m_mmlvalue2tb;

public:
	FBtnToolbarSet()
		{}
	virtual ~FBtnToolbarSet()
		{}
	const FBtn& getFBtn(long t, long b) const
		{ return at(t).at(b); }
	virtual long getToolBarCount() const
		{ return QVector<FBtnToolbar>::size(); }
	virtual const HKToolBar* getToolBar( long i ) const
		{ return &at(i); }
	QString getToolbarDescr( void ) const
	{
		QString ret;
		for( long i = 0; i < getToolBarCount(); i++ )
			ret.append( at(i).getToolbarDescr() );
		return ret;
	}
	FXmlBtn* getButtonCalc( long t, long b )
		{ return (t >= 0 && t < size() && b >= 0 && b < at(t).size() ) ? &((*this)[t][b]) : NULL; }
	FXmlBtn* getButtonCalc( const QString& id )
	{
		long t = -1, b = -1;
		return (id.length() && getButtonCoordByID(id, t, b) != -1) ? getButtonCalc(t, b) : NULL;
	}

	int Read_XML( std::vector<AST_TXML_Tag*>& root_tags, DRMessageManager& dmm, long dmm_page = 0 );
	int AddToolBar( AST_TXML_Node *root, DRMessageManager& dmm, long dmm_page = 0 );
	int AddToolBar( const QString& path, DRMessageManager& dmm, long dmm_page = 0 );

	void FillMultiMap4Search( void );
	int getButtonCoordByID( const QString& id, long& _toolbar_no, long& _button_no, long *argc = 0 );
	int getButtonCoordByMathMLTag( const QString& tagname, long& _toolbar_no, long& _button_no );
	int getButtonCoordByMathMLValue( const QString& tagname, long& _toolbar_no, long& _button_no );
	int getButtonCoordByMathMLNameType( const QString& tagname, QString& tagtype, long& _toolbar_no, long& _button_no );
	int getTextButtonCoordByID( const QString& v, long& _toolbar_no, long& _button_no );
	int text2DsrButton( const QString& body, FXmlBtn*& pFXmlBtn, FBtnAttr& ni );

	friend QDataStream& operator << ( QDataStream& ar, const FBtnToolbarSet& lp );
	friend QDataStream& operator >> ( QDataStream& ar, FBtnToolbarSet& lp );
};

/////////////////////////////////////////////////////////////////////

inline
QDataStream& operator << ( QDataStream& ar, const FBtnToolbarSet& lp )
{
	return ar << (const QVector<FBtnToolbar>&) lp << (const HKToolBarSet&) lp << lp.m_id2tb << lp.m_mmlname2tb << lp.m_mmlvalue2tb;
}

inline
QDataStream& operator >> ( QDataStream& ar, FBtnToolbarSet& lp )
{
	return ar >> (QVector<FBtnToolbar>&) lp >> (HKToolBarSet&) lp >> lp.m_id2tb >> lp.m_mmlname2tb >> lp.m_mmlvalue2tb;
}

/////////////////////////////////////////////////////////////////////

#endif
