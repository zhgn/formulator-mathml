

#ifndef __FMLCORE_DLG_DEFINESIZEDLG_H__
#define __FMLCORE_DLG_DEFINESIZEDLG_H__

#include <QMainWindow>
#include <QString>
#include <QDialog>

QT_BEGIN_NAMESPACE
class QSpinBox;
class QToolButton;
class QLabel;
QT_END_NAMESPACE

#include "../../fmlcore_global.h"

class __YUNEN_FORMULIB__ CDefineSizeDialog : public QDialog
{
    Q_OBJECT

protected:
	QSpinBox *largeEdit, *regularEdit, *subEdit, *subsubEdit;

public:
    CDefineSizeDialog( QWidget *parent =  0 );
    ~CDefineSizeDialog();

public slots:
	void factorySettings();
	virtual void accept();
};

#endif
