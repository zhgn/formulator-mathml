

#if !defined( __FMLCORE_FMLBASEWIDGET_H__ )
#define __FMLCORE_FMLBASEWIDGET_H__

#include <QVariant>
#include <QDialog>

#include "../../fmlcore_global.h"

/////////////////////////////////////////////////////////////////////////////

class __YUNEN_FORMULIB__ QFormulatorBaseWidget
{
protected:
	bool					m_isVerbose;
	QMap<QString, QVariant>	m_properties;

public:
	QFormulatorBaseWidget() {}
	virtual ~QFormulatorBaseWidget() {}

	bool isVerbose();
	void setVerbose( bool status );

	virtual int callDialog( QDialog * /*dlg*/ )								{ return QDialog::Rejected; }
};

/////////////////////////////////////////////////////////////////////////////

inline
bool QFormulatorBaseWidget::isVerbose()
{
	return m_isVerbose;
}

inline
void QFormulatorBaseWidget::setVerbose( bool status )
{
	m_isVerbose = status;
}

/////////////////////////////////////////////////////////////////////////////

#endif
