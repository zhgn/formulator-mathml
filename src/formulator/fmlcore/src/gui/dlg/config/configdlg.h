

#ifndef __FMLCORE_DLG_CONFIGDLG_H__
#define __FMLCORE_DLG_CONFIGDLG_H__

#include <QDialog>

QT_BEGIN_NAMESPACE
class QListWidget;
class QListWidgetItem;
class QStackedWidget;
class QAction;
QT_END_NAMESPACE

class CTypesettingPage;
class CTranslatePage;
class CRenderingPage;
class CAppearancePage;
class CWarningsPage;
class CPerfomancePage;

/////////////////////////////////////////////////////////////////////////////

class CFormulatorConfigDlg : public QDialog
{
    Q_OBJECT

protected:
	CTypesettingPage	*m_option1;
	CTranslatePage		*m_option2;
	CRenderingPage		*m_option3;
	CAppearancePage		*m_option4;
	CWarningsPage		*m_option5;
	CPerfomancePage		*m_option6;

	QAction				*presetWordAct;
	QAction				*presetPmmlAct;
	QAction				*presetCmmlAct;
	QAction				*presetCmmlPmmlAct;
	QAction				*presetCmmlAutographAct;
	int					m_applyPreset;
	int					m_activePage;

	enum
	{ MinPage = 0, MaxPage = 5 };

public:
    CFormulatorConfigDlg( int page, QWidget *parent );

	int getPreset() { return m_applyPreset; }

	void setActivePage( int page );
	int activePage() { return m_activePage; }

public slots:
	virtual void accept();
    void changePage(QListWidgetItem *current, QListWidgetItem *previous);

	void factorySettings();
	void presetWord();
	void presetPmml();
	void presetCmml();
	void presetCmmlPmml();
	void presetCmmlA();

private:
    void createIcons();

    QListWidget *contentsWidget;
    QStackedWidget *pagesWidget;
};

/////////////////////////////////////////////////////////////////////////////

#endif
