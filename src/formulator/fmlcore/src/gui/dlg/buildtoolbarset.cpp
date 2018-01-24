

#include <QtGlobal>
#include <QFileDialog>
#include <vector>

#include "buildtoolbarset.h"

#include "HUtils/iversion.h"
#include "HUtils/imessage.h"
#include "HMathML/isettings.h"
#include "HMathML/itoolbarset.h"
#include "HMathML/idictionary.h"

CBuildToolbarsetDlg::CBuildToolbarsetDlg()
{
	m_ui.setupUi(this);
	setWindowIcon(QIcon(":/images/fmlideico.ico"));

	QDir destDir( FmlCoreSettings::getDataDir() );
	QString destDirPath = destDir.absolutePath();
	if( !destDir.exists( destDirPath ) )
		destDir.mkpath( destDirPath );
	m_ui.m_path->insert( destDirPath );

	destDir.setPath(FmlCoreSettings::getXmlBtnDir());
	destDirPath = destDir.absolutePath();
	if( !destDir.exists( destDirPath ) )
		destDir.mkpath( destDirPath );
#ifdef Q_WS_MAC
        QSettings settings(QSettings::IniFormat, QSettings::UserScope, __COMPANY_DOMAIN_, QCoreApplication::applicationName() );
#else
        QSettings settings(QSettings::IniFormat, QSettings::UserScope, __COMPANY_NAME__, QCoreApplication::applicationName() );
#endif
    QStringList files = settings.value("XmlBtn/recentFileList").toStringList();
	m_ui.m_src->addItems( files );

	if( m_ui.m_src->count() == 0 )
	{
		m_ui.btnDelete->setEnabled(false);
		m_ui.btnClear->setEnabled(false);
		m_ui.btnBuild->setEnabled(false);
	}
	m_ui.m_msg->setReadOnly(true);

    connect(m_ui.btnBrowse, SIGNAL(clicked()), this, SLOT(slotBrowse()));
    connect(m_ui.btnAdd, SIGNAL(clicked()), this, SLOT(slotAdd()));
    connect(m_ui.btnDelete, SIGNAL(clicked()), this, SLOT(slotDelete()));
    connect(m_ui.btnClear, SIGNAL(clicked()), this, SLOT(slotClear()));
    connect(m_ui.btnBuild, SIGNAL(clicked()), this, SLOT(slotBuild()));
}

CBuildToolbarsetDlg::~CBuildToolbarsetDlg()
{
	QStringList files;
	for( long i = 0; i < m_ui.m_src->count(); i++ )
		files.push_back( m_ui.m_src->item(i)->text() );
#ifdef Q_WS_MAC
        QSettings settings(QSettings::IniFormat, QSettings::UserScope, __COMPANY_DOMAIN_, QCoreApplication::applicationName() );
#else
        QSettings settings(QSettings::IniFormat, QSettings::UserScope, __COMPANY_NAME__, QCoreApplication::applicationName() );
#endif
	settings.setValue("XmlBtn/recentFileList", files);
}

void CBuildToolbarsetDlg::slotAdd()
{
	QStringList files = QFileDialog::getOpenFileNames( this, "Select one or more files to open",
							FmlCoreSettings::getXmlBtnDir(), "Formulator Button Description Files (*.xml);;All Files (*.*)");
	if( files.count() > 0 )
	{
		m_ui.m_src->addItems( files );
		m_ui.btnDelete->setEnabled(true);
		m_ui.btnClear->setEnabled(true);
		m_ui.btnBuild->setEnabled(true);
	}
}

void CBuildToolbarsetDlg::slotDelete()
{
	QListWidgetItem *w;
	QList<QListWidgetItem*> selectedItems = m_ui.m_src->selectedItems();
	for(int i = 0; i < selectedItems.size(); i++)
	{
		w = m_ui.m_src->takeItem( m_ui.m_src->row( selectedItems.at(i) ) );
		if( w ) delete w;
	}
	if( m_ui.m_src->count() == 0 )
	{
		m_ui.btnDelete->setEnabled(false);
		m_ui.btnClear->setEnabled(false);
		m_ui.btnBuild->setEnabled(false);
	}
}

void CBuildToolbarsetDlg::slotClear()
{
	m_ui.m_src->clear();
	m_ui.btnDelete->setEnabled(false);
	m_ui.btnClear->setEnabled(false);
	m_ui.btnBuild->setEnabled(false);
}

void CBuildToolbarsetDlg::slotBrowse()
{
	QString dir = QFileDialog::getExistingDirectory(this, "Open Destination Directory", m_ui.m_path->text(),
					QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	if( !dir.isNull() )
	{
		m_ui.m_path->clear();
		m_ui.m_path->insert( dir );
	}
}

void CBuildToolbarsetDlg::slotBuild()
{
	QApplication::setOverrideCursor( Qt::WaitCursor );

	m_ui.m_msg->setText("Start building...");
	m_ui.m_msg->moveCursor(QTextCursor::End);
	m_ui.m_msg->ensureCursorVisible();
	QCoreApplication::processEvents();

	QStringList files;
	long i, page;
	for(i = 0; i < m_ui.m_src->count(); i++)
		files.append( m_ui.m_src->item(i)->text() );

	DRMessageManager dmm;
	::getCurrentToolBarSet()->clear();
	for(i = 0; i < files.size(); i++)
	{
		m_ui.m_msg->append(files.at(i));
		m_ui.m_msg->moveCursor(QTextCursor::End);
		m_ui.m_msg->ensureCursorVisible();
		QCoreApplication::processEvents();
		if ( ::getCurrentToolBarSet()->AddToolBar( files.at(i), dmm ) )
		{
			for( i = 0; i < (long) dmm.size(); i++ )
				m_ui.m_msg->append(dmm.getFormatedText(i, page) + QString("\n"));
			m_ui.m_msg->append("Failed to create binary button file\n");
			break;
		}
	}
	dmm.clear();

	if( i == files.size() )
	{
		::getCurrentToolBarSet()->FillMultiMap4Search();
		::FORMULATOR_saveToolBarSet( FmlCoreSettings::getXmlBtnFile() );
		{
			m_ui.m_msg->append(QString("Math toolbars are created successfully: %1").arg(FmlCoreSettings::getXmlBtnFile()));
			m_ui.m_msg->moveCursor(QTextCursor::End);
			m_ui.m_msg->ensureCursorVisible();
			QCoreApplication::processEvents();
			std::vector<QString> vec1V;
			std::vector<long> vec2V;
			QString sV;
			::getMathMLChar2Style( vec1V, vec2V, sV, sV, __GLOBAL_INIT_MODE );
		}
	}
	QApplication::restoreOverrideCursor();
}
