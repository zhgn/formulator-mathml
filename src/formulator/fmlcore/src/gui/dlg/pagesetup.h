

#ifndef __FMLCORE_DLG_PAGESETUPDLG_H__
#define __FMLCORE_DLG_PAGESETUPDLG_H__

#if QT_VERSION > QT_VERSION_CHECK(5, 0, 0)
#include <QtPrintSupport>
#include <QtWidgets>
#else
#include <QtGui>
#endif

QT_BEGIN_NAMESPACE
class QSpinBox;
class QToolButton;
class QLabel;
QT_END_NAMESPACE

#include "HUtils/idrawstruct.h"
#include "../../fmlcore_global.h"

class __YUNEN_FORMULIB__ CPageSetupDialog : public QDialog
{
    Q_OBJECT

protected:
    QSpinBox *leftEdit, *topEdit, *rightEdit, *bottomEdit, *linespacingEdit;

public:
    CPageSetupDialog( RectFde rcIndents, RealFde linespacing, QWidget *parent );
    ~CPageSetupDialog();

    RectFde indents();
    RealFde lineSpacing();

public slots:
    void pageSetup();
    virtual void accept();
};

#endif
