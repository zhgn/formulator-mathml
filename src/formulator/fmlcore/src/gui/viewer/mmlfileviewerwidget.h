

#ifndef __FMLCORE_DLG_MATHMLFILEVIEWER_H__
#define __FMLCORE_DLG_MATHMLFILEVIEWER_H__

#include <QDockWidget>
#include <QDirModel>
#include <QTreeView>
#include <QDir>

QT_BEGIN_NAMESPACE
class QToolButton;
class QPushButton;
class QComboBox;
class QLabel;
class QSettings;
class QTableWidget;
class QHBoxLayout;
class QProgressDialog;
class QTableWidgetItem;
QT_END_NAMESPACE

class QMathMLFileViewer
	: public QDockWidget
{
    Q_OBJECT

protected:
	QDirModel			m_dirModel;
    QTreeView			*m_dirTree;
    QDir				m_currentDir;

	QToolButton *btnRecursive;
    QComboBox *fileComboBox, *directoryComboBox;
    QTableWidget *filesTable;
	QLabel *foundMessage;

	QSize	m_iconSize;
	bool	m_isRecursiveSearch;

public:
    QMathMLFileViewer( QWidget *parent = 0 );

	bool isRecursive()
		{ return m_isRecursiveSearch; }

	void readSettings( QSettings& settings );
	void writeSettings( QSettings& settings );

protected slots:
	void setRecursive( bool enable );
	void fileBack();
	void fileForward();
	void fileFind();
	void fileFind( QStringList& files, const QDir& rootDir, const QStringList& mask, QProgressDialog *progressDlg );
	void fileRefresh();
	void fileLoad();
	void fileOpen();
	void activated(const QModelIndex& index);
	void pressed(const QModelIndex& index);
	void loadFileOfItem(const QModelIndex& index);
    void openFileOfItem(const QModelIndex& index);
    void loadFileOfItem(int row, int /*column*/);
    void openFileOfItem(int row, int /*column*/);
	void loadFileOfItem(QTableWidgetItem *current, QTableWidgetItem *previous);
	void changeDir( QString directory );
    void browse();
    void browseUp();

protected:
    QComboBox *createComboBox(const QString &text = QString());
	void createFilesTree();
    void createFilesTable();
	QHBoxLayout* setupToolLayout();

	int isValidSelection(QString filePath, int noParanoiaCheck);
	int isValidSelection(int noParanoiaCheck);
	QString getSelected();
	QWidget* getFocusItem();
	int emitLoad( QString fileName, int noParanoiaCheck );
	int emitOpen( QString fileName, int noParanoiaCheck );

    void showFiles(const QStringList &files);

signals:
	void loadFile( QString path, QWidget* self );
	void openFile( QString path, QWidget* self );
	void hasFound( bool enable );
	void hasSelectedItem( bool enable );
};

#endif
