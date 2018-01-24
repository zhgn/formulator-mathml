

#ifndef __FMLCORE_DLG_DEFINESTYLEDLG_H__
#define __FMLCORE_DLG_DEFINESTYLEDLG_H__

#include <QMainWindow>
#include <QString>
#include <QDialog>
#include <QVector>

QT_BEGIN_NAMESPACE
class QComboBox;
class QFontComboBox;
class QCheckBox;
class QColorDialog;
class QPushButton;
class QLabel;
QT_END_NAMESPACE

#include "../../fmlcore_global.h"

/////////////////////////////////////////////////////////////////////////////

class __YUNEN_FORMULIB__ CDefineStyleDialog : public QDialog
{
    Q_OBJECT

protected:
	int						m_styleNumber;
	const QString*			m_styleTitle;
	const int*				m_styleID;

	QColor					m_backColor;
	QVector<QFont>			m_currentFont;
	QVector<QString>		m_currentStyle;
	QVector<QColor>			m_currentColor;

	QVector<QLabel*>		m_label;
	QVector<QFontComboBox*>	m_font;
	QVector<QComboBox*>		m_style;
	QVector<QPushButton*>	m_btn;
	QVector<QLabel*>		m_sample;

public:
    CDefineStyleDialog( QColor backColor, int styleNumber, const QString* styleTitle, const int* styleID, QWidget *parent =  0 );
    ~CDefineStyleDialog();

public slots:
	void factorySettings();
	virtual void accept();

protected slots:
	void updateFont( const QFont &font );
	void updateStyle( const QString &fontStyle );
	void updateColor();
	void findStyles( const QFont &font );

protected slots:
	void findStyles( const QFont &font, int i );
	void updateStyle( const QString &fontStyle, int i );
	void updateSampleText( int i );
	void alignSampleText();
};

/////////////////////////////////////////////////////////////////////////////

#endif
