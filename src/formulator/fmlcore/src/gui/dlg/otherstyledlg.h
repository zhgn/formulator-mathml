

#ifndef __FMLCORE_DLG_OTHERSTYLEDLG_H__
#define __FMLCORE_DLG_OTHERSTYLEDLG_H__

#include <QMainWindow>
#include <QString>
#include <QDialog>

QT_BEGIN_NAMESPACE
class QComboBox;
class QFontComboBox;
class QCheckBox;
class QColorDialog;
class QToolButton;
class QLabel;
QT_END_NAMESPACE

class FS_LogFont_Color;
#include "../../fmlcore_global.h"

class __YUNEN_FORMULIB__ COtherStyleDialog : public QDialog
{
    Q_OBJECT

protected:
	const FS_LogFont_Color& m_lfc;
	QString m_currentStyle;
	QColor m_backColor;
	QFont m_currentFont;
	QColor m_currentColor;

public:
    COtherStyleDialog( QColor backColor, QWidget *parent =  0 );
    ~COtherStyleDialog();

	const QString& currentStyle() { return m_currentStyle; }
	const QFont& currentFont() { return m_currentFont; }
	const QColor& currentColor() { return m_currentColor; }

protected slots:
    void apply();
    void findStyles(const QFont &font);
    void updateFont(const QFont &font);
    void updateStyle(const QString &fontStyle);
	void updateColor();
	void updateSampleText();

protected:
    QComboBox *styleCombo;
	QLabel *labelSampleText;
    QFontComboBox *fontCombo;
};

#endif
