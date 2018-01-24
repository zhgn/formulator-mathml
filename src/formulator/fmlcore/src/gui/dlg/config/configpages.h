

#ifndef __FMLCORE_DLG_CONFIGPAGES_H__
#define __FMLCORE_DLG_CONFIGPAGES_H__

/////////////////////////////////////////////////////////////////////////////

#include <QWidget>
#include <QCheckBox>
#include <QRadioButton>
#include <QSpinBox>

class CTypesettingPage : public QWidget
{
	Q_OBJECT

protected:
	QCheckBox *m_isContent, *m_isMoveOut, *m_isDxDt, *m_isOneCharID;

public:
    CTypesettingPage(QWidget *parent = 0);
	void load();
	void save();
	void loadPresetWord();
	void loadPresetPmml();
	void loadPresetCmml();
	void loadPresetCmmlPmml();
	void loadPresetCmmlAutograph();
public slots:
	void defaultSettings();
};

/////////////////////////////////////////////////////////////////////////////

class CTranslatePage : public QWidget
{
	Q_OBJECT

protected:
	QCheckBox *m_isSymbolUnicode, *m_isPureContent;
	QRadioButton *m_displayBlockBtn, *m_displayInlineBtn;
	QRadioButton *m_namespaceNoBtn, *m_namespaceMBtn, *m_namespaceXmlnsBtn;
	QRadioButton *m_timesTimesBtn, *m_timesSdotBtn, *m_timesInvisibleBtn;

public:
    CTranslatePage(QWidget *parent = 0);
	void load();
	void save();
	void loadPresetWord();
	void loadPresetPmml();
	void loadPresetCmml();
	void loadPresetCmmlPmml();
	void loadPresetCmmlAutograph();
public slots:
	void defaultSettings();
};

/////////////////////////////////////////////////////////////////////////////

class CRenderingPage : public QWidget
{
	Q_OBJECT

protected:
	QCheckBox *m_isMultipleItalic, *m_isForceMathML, *m_isShowHidden;
	QCheckBox *m_isDiff, *m_isArc, *m_isCalcTextByGlyph;
	QRadioButton *m_listComaBtn, *m_listLocaleBtn;

public:
    CRenderingPage(QWidget *parent = 0);
	void load();
	void save();
	void loadPresetWord();
	void loadPresetPmml();
	void loadPresetCmml();
	void loadPresetCmmlPmml();
	void loadPresetCmmlAutograph();
public slots:
	void defaultSettings();
};

/////////////////////////////////////////////////////////////////////////////

class CAppearancePage : public QWidget
{
	Q_OBJECT

protected:
	QSpinBox *leftEdit, *topEdit, *rightEdit, *bottomEdit, *linespacingEdit;

protected slots:
	void resetSettings();

public:
    CAppearancePage(QWidget *parent = 0);
	void load();
	void save();
	void loadPresetWord();
	void loadPresetPmml();
	void loadPresetCmml();
	void loadPresetCmmlPmml();
	void loadPresetCmmlAutograph();
public slots:
	void defaultSettings();
};

/////////////////////////////////////////////////////////////////////////////

class CWarningsPage : public QWidget
{
	Q_OBJECT

protected:
	QCheckBox *m_isShowNavigation,/* *m_isShowRefresh, */*m_isShowClipboard;

public:
    CWarningsPage(QWidget *parent = 0);
	void load();
	void save();
	void loadPresetWord();
	void loadPresetPmml();
	void loadPresetCmml();
	void loadPresetCmmlPmml();
	void loadPresetCmmlAutograph();
public slots:
	void defaultSettings();
};

/////////////////////////////////////////////////////////////////////////////

class CPerfomancePage : public QWidget
{
	Q_OBJECT

protected:
	QCheckBox *m_isCopyImage, *m_isUpdateMmlEditor, *m_isUpdate;

public:
    CPerfomancePage(QWidget *parent = 0);
	void load();
	void save();
	void loadPresetWord();
	void loadPresetPmml();
	void loadPresetCmml();
	void loadPresetCmmlPmml();
	void loadPresetCmmlAutograph();
public slots:
	void defaultSettings();
};

/////////////////////////////////////////////////////////////////////////////

#endif
