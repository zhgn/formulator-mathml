

#ifndef __FMLCORE_DLG_MATHMLTEXTEDITWIDGET_H__
#define __FMLCORE_DLG_MATHMLTEXTEDITWIDGET_H__

#include <QDockWidget>

QT_BEGIN_NAMESPACE
class QAction;
class QToolButton;
class QPushButton;
class QHBoxLayout;
class QSettings;
class QTextEdit;
class QMathMLHighlighter;
QT_END_NAMESPACE

class QMathMLTextEdit
	: public QDockWidget
{
    Q_OBJECT

protected:
    QTextEdit			*m_editor;
    QMathMLHighlighter	*m_highlighter;
	bool				m_isReadOnly;
	bool				m_wrapMode;
	bool				m_isDelayedUpdate;

    //QAction *undoAct, *redoAct, *cutAct, *copyAct, *pasteAct, *uploadAct;
	QToolButton *btnUndo, *btnRedo, *btnCut, *btnCopy, *btnPaste, *btnUpload, *btnLoad, *btnColorMode;
	//QPushButton 
	QToolButton *btnWrapMode, *btnUpdateMode;

public:
    QMathMLTextEdit( bool isReadOnly = false, const QString &text = QString(), QWidget *parent = 0 );

	QString text();
	bool isWrapMode();

	bool delayedUpdate();
	void setDelayedUpdate( bool enable );

	void readSettings( QSettings& settings );
	void writeSettings( QSettings& settings );

public slots:
    void setText( const QString &text = QString() );

protected:
	//virtual void contextMenuEvent( QContextMenuEvent *e );
	virtual void focusInEvent( QFocusEvent * event );

    void setupEditor( bool isReadOnly );
	//void setupActions();
	QHBoxLayout* setupToolLayout();
	void setupCentralWidget();
	void setupConnection();

protected slots:
    void clipboardDataChanged();
	void upload();
	void load();
	void setWrapMode( bool enabled );
	void setHighlightMode( bool enabled );
	void setUpdateMode( bool enabled );

signals:
	void uploadRequested();
	void loadRequested();
};

#endif
