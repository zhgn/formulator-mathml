

#ifndef __FMLCORE_DLG_NODEINPUTDLG_H__
#define __FMLCORE_DLG_NODEINPUTDLG_H__

#include <QString>
#include <QDialog>
#include <QComboBox>
#include <QSpinBox>
#include <QCheckBox>

#include "HUtils/idrawstruct.h"
#include "../../fmlcore_global.h"

/////////////////////////////////////////////////////////////////////////////

class __YUNEN_FORMULIB__ CMmlDeclareDlg : public QDialog
{
protected:
	QComboBox *m_type, *m_occurance;
	QCheckBox *m_isSecondSlot;
	QSpinBox *m_arg;

public:
	CMmlDeclareDlg( QWidget *parent = 0 );

	QString type()
		{ return m_type->currentText(); }
	QString occurance()
		{ return m_occurance->currentText(); }
	bool isSecondSlot()
		{ return m_isSecondSlot->checkState() == Qt::Checked; }
	int argc()
		{ return m_arg->value(); }
};

/////////////////////////////////////////////////////////////////////////////

class __YUNEN_FORMULIB__ CMmlCiDlg : public QDialog
{
protected:
	QComboBox *m_type;

public:
	CMmlCiDlg( QWidget *parent = 0 );

	QString type()
		{ return m_type->currentText(); }
};

/////////////////////////////////////////////////////////////////////////////

class __YUNEN_FORMULIB__ CMmlCnDlg : public QDialog
{
protected:
	QComboBox *m_type;
	QSpinBox *m_base;

public:
	CMmlCnDlg( QWidget *parent = 0 );

	QString type()
		{ return m_type->currentText(); }
	int base()
		{ return m_base->value(); }
};

/////////////////////////////////////////////////////////////////////////////

class __YUNEN_FORMULIB__ CMmlQualifierDlg : public QDialog
{
protected:
	QComboBox *m_op;
	QSpinBox *m_bvar;

public:
	CMmlQualifierDlg( QString title, bool argsOn, QWidget *parent = 0 );

	QString op()
		{ return m_op->currentText(); }
	int bvar()
		{ return m_bvar->value(); }
};

/////////////////////////////////////////////////////////////////////////////

class __YUNEN_FORMULIB__ CMmlTableDlg : public QDialog
{
protected:
	QSpinBox *m_rows, *m_columns;

public:
	CMmlTableDlg( bool isRows, int rowNumber, bool isColumns, int colNumber, QWidget *parent = 0 );

	int rows()
		{ return m_rows->value(); }
	int columns()
		{ return m_columns->value(); }
};

/////////////////////////////////////////////////////////////////////////////

class __YUNEN_FORMULIB__ QMmlSelectorDlg : public QDialog
{
protected:
	QSpinBox *m_argc;

public:
	QMmlSelectorDlg( QString title, int minArgs, QWidget *parent = 0 );

	int argc()
		{ return m_argc->value(); }
};

/////////////////////////////////////////////////////////////////////////////

#endif
