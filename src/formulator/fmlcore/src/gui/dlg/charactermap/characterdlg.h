

#ifndef __FMLCORE_DLG_CHARACTERDLG_H__
#define __FMLCORE_DLG_CHARACTERDLG_H__

#include <QMainWindow>
#include <QString>
#include <QDialog>

QT_BEGIN_NAMESPACE
class QClipboard;
class QComboBox;
class QFontComboBox;
class QLineEdit;
class QScrollArea;
class QCheckBox;
class QColorDialog;
class QToolButton;
class QLabel;
QT_END_NAMESPACE

class CInsertCharacterWidget;

#include "../../../fmlcore_global.h"

class __YUNEN_FORMULIB__ CInsertCharacterDialog : public QDialog
{
    Q_OBJECT

protected:
	QString m_text;
	bool m_hasStyledText;
	int m_initFontSize;
	QColor m_backColor;
	QString m_initFontStyle;

public:
    CInsertCharacterDialog( QColor backColor, QWidget *parent =  0 );
    ~CInsertCharacterDialog();

	bool hasStyledText() { return m_hasStyledText; }
	QString text() { return m_text; }
	const QFont& currentFont();
	const QColor& currentColor();

protected:
	void updateDocument( bool styledText );

public slots:
    void findStyles(const QFont &font);
    void findSizes(const QFont &font);
    void insertCharacter(const QString &character);
    void updateFont(const QFont &font);
    void updateSize(const QString &fontSize);
    void updateStyle(const QString &fontStyle);
	void updateColor();
	void updateSampleText();
    void updateClipboard();
	void styledInsert() { updateDocument( true ); }
	void plainInsert() { updateDocument( false ); }

private:
	CInsertCharacterWidget *characterWidget;
    QClipboard *clipboard;
    QComboBox *styleCombo;
    QComboBox *sizeCombo;
	QLabel *labelSampleText;
    QFontComboBox *fontCombo;
    QLineEdit *lineEdit;
    QScrollArea *scrollArea;
    QCheckBox *fontMerging;

//signals:
//    void characterSelected(const QString &character);
};

#endif
