

#if !defined( __FORMULATOR_FMLCORE_BTN_TOOLBAR_H__ )
#define __FORMULATOR_FMLCORE_BTN_TOOLBAR_H__

#include "xmlbtn.h"

///////////////////////////////////////////////////////////////////////////////

class __YUNEN_FORMULIB__ FBtnToolbar : public QVector<FXmlBtn>, public HKToolBar
{
public:
	FBtnToolbar() {}
	virtual long getButtonCount() const
		{ return QVector<FXmlBtn>::size(); }
	virtual const HKToolBarButton* getButton( long i ) const
		{ return &at(i); }
	QString getToolbarDescr( void ) const
		{
			QString ret = getName() + _T("\r\n");
			for( long i = 0; i < size(); i++ )
				ret.append( QString("%1\t%2\r\n").arg( getButton(i)->getID() ).arg( getButton(i)->getToolTip() ) );
			return ret;
		}

	int Read_XML( AST_TXML_Tag *root, DRMessageManager& dmm, long dmm_page = 0 );

protected:
	int AddToolBarData( AST_TXML_Tag *root, DRMessageManager& dmm, long dmm_page );
};

/////////////////////////////////////////////////////////////////////

inline
QDataStream& operator << ( QDataStream& ar, const FBtnToolbar& lp )
{
	return ar << (const QVector<FXmlBtn>&) lp << (const HKToolBar&) lp;
}

inline
QDataStream& operator >> ( QDataStream& ar, FBtnToolbar& lp )
{
	return ar >> (QVector<FXmlBtn>&) lp >> (HKToolBar&) lp;
}

/////////////////////////////////////////////////////////////////////

#endif
