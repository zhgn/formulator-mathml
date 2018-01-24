

#if !defined( __FMLCORE_FMLEDITWIDGET_H__ )
#define __FMLCORE_FMLEDITWIDGET_H__

#include <QTimer>
#include "fmlwidget.h"
#include "../../fmlcore_global.h"

/////////////////////////////////////////////////////////////////////////////

class __YUNEN_FORMULIB__ QFormulatorEditWidget
	: public QFormulatorWidget
{
    Q_OBJECT

protected:
	QTimer	*m_cursorBlinkTimer;
	int		m_mouseMoveTimerId;

// init methods
///////////////
public:
	QFormulatorEditWidget( QWidget *parent = 0, QObject *uiUpdater = 0 );
	virtual ~QFormulatorEditWidget();

// events
///////////////
protected:
	virtual void paintEvent(QPaintEvent *e);
	virtual void focusInEvent( QFocusEvent *e );
	virtual void focusOutEvent( QFocusEvent *e );
	virtual void keyPressEvent( QKeyEvent *e );
	virtual void mousePressEvent( QMouseEvent *e );
	virtual void mouseReleaseEvent( QMouseEvent *e );
	virtual void mouseMoveEvent( QMouseEvent *e );
	virtual void mouseDoubleClickEvent( QMouseEvent *e );
	virtual void dragEnterEvent( QDragEnterEvent *e );
	virtual void dragLeaveEvent( QDragLeaveEvent *e );
	virtual void dragMoveEvent( QDragMoveEvent *e );
	virtual void dropEvent( QDropEvent *e );

// public wrappers for custom events
///////////////
public:
	void customEvent_MousePressOnParentWindow( QMouseEvent *e );
	void customEvent_MouseMoveOnParentWindow( QMouseEvent *e );

// caret methods
///////////////
protected:
	virtual void setBlinkingCursorEnabled( bool enable );
	virtual void repaintCursor( PointFde pt, SizeFde sz );
	virtual void repaintCursor();
private slots:
	void switchCursor();

// edit methods
///////////////
public:
	int editUndo();
	int editRedo();
	int editCut();
	int editCopy();
	int editPaste();
	int editDelete();
	int editSelectAll();

public:
	void Delete( void );
	void BackSpace( void );
	void Clear( void );

// edit/navigation methods
///////////////
protected:
	void MoveLR( int fLeft, int fSelect, int fWord );
	void MoveHE( int fHome, int fSelect, int fCtrl );
	void MoveUD( int fUp, int fSelect );
	void MovePG( int fUp, int fSelect );
public:
	void OnMoveBack();

	bool isRemovedSelection();
	void setRemovedSelection();
	void clearRemovedSelection();

// edit/navigation methods
///////////////
public:
	void OnMoveLeft();
	void OnMoveRight();
	void OnMoveHome();
	void OnMoveEnd();
	void OnMoveUp();
	void OnMoveDown();
	void OnMovePageUp();
	void OnMovePageDown();

	void OnMoveShiftLeft();
	void OnMoveShiftRight();
	void OnMoveShiftHome();
	void OnMoveShiftEnd();
	void OnMoveShiftUp();
	void OnMoveShiftDown();
	void OnMoveShiftPageUp();
	void OnMoveShiftPageDown();

	void OnMoveCtrlLeft();
	void OnMoveCtrlRight();
	void OnMoveCtrlHome();
	void OnMoveCtrlEnd();
	void OnMoveCtrlUp();
	void OnMoveCtrlDown();
	void OnMoveCtrlPageUp();
	void OnMoveCtrlPageDown();

	void OnMoveCtrlShiftLeft();
	void OnMoveCtrlShiftRight();
	void OnMoveCtrlShiftHome();
	void OnMoveCtrlShiftEnd();
	void OnMoveCtrlShiftUp();
	void OnMoveCtrlShiftDown();
	void OnMoveCtrlShiftPageUp();
	void OnMoveCtrlShiftPageDown();

signals:
	void editEvent( int );
};

/////////////////////////////////////////////////////////////////////////////

inline void QFormulatorEditWidget::OnMoveLeft()					{ MoveLR( 1, 0, 0 ); }
inline void QFormulatorEditWidget::OnMoveRight()				{ MoveLR( 0, 0, 0 ); }
inline void QFormulatorEditWidget::OnMoveHome()					{ MoveHE( 1, 0, 0 ); }
inline void QFormulatorEditWidget::OnMoveEnd()					{ MoveHE( 0, 0, 0 ); }
inline void QFormulatorEditWidget::OnMoveUp()					{ MoveUD( 1, 0 ); }
inline void QFormulatorEditWidget::OnMoveDown()					{ MoveUD( 0, 0 ); }
inline void QFormulatorEditWidget::OnMovePageUp()				{ MovePG( 1, 0 ); }
inline void QFormulatorEditWidget::OnMovePageDown()				{ MovePG( 0, 0 ); }

inline void QFormulatorEditWidget::OnMoveShiftLeft()			{ MoveLR( 1, 1, 0 ); }
inline void QFormulatorEditWidget::OnMoveShiftRight()			{ MoveLR( 0, 1, 0 ); }
inline void QFormulatorEditWidget::OnMoveShiftHome()			{ MoveHE( 1, 1, 0 ); }
inline void QFormulatorEditWidget::OnMoveShiftEnd()				{ MoveHE( 0, 1, 0 ); }
inline void QFormulatorEditWidget::OnMoveShiftUp()				{ MoveUD( 1, 1 ); }
inline void QFormulatorEditWidget::OnMoveShiftDown()			{ MoveUD( 0, 1 ); }
inline void QFormulatorEditWidget::OnMoveShiftPageUp()			{ MovePG( 1, 1 ); }
inline void QFormulatorEditWidget::OnMoveShiftPageDown()		{ MovePG( 0, 1 ); }

inline void QFormulatorEditWidget::OnMoveCtrlLeft()				{ MoveLR( 1, 0, 1 ); }
inline void QFormulatorEditWidget::OnMoveCtrlRight()			{ MoveLR( 0, 0, 1 ); }
inline void QFormulatorEditWidget::OnMoveCtrlHome()				{ MoveHE( 1, 0, 1 ); }
inline void QFormulatorEditWidget::OnMoveCtrlEnd()				{ MoveHE( 0, 0, 1 ); }
inline void QFormulatorEditWidget::OnMoveCtrlUp()				{}
inline void QFormulatorEditWidget::OnMoveCtrlDown()				{}
inline void QFormulatorEditWidget::OnMoveCtrlPageUp()			{}
inline void QFormulatorEditWidget::OnMoveCtrlPageDown()			{}

inline void QFormulatorEditWidget::OnMoveCtrlShiftLeft()		{ MoveLR( 1, 1, 1 ); }
inline void QFormulatorEditWidget::OnMoveCtrlShiftRight()		{ MoveLR( 0, 1, 1 ); }
inline void QFormulatorEditWidget::OnMoveCtrlShiftHome()		{ MoveHE( 1, 1, 1 ); }
inline void QFormulatorEditWidget::OnMoveCtrlShiftEnd()			{ MoveHE( 0, 1, 1 ); }
inline void QFormulatorEditWidget::OnMoveCtrlShiftUp()			{}
inline void QFormulatorEditWidget::OnMoveCtrlShiftDown()		{}
inline void QFormulatorEditWidget::OnMoveCtrlShiftPageUp()		{}
inline void QFormulatorEditWidget::OnMoveCtrlShiftPageDown()	{}

inline void QFormulatorEditWidget::OnMoveBack()					{ BackSpace(); }

/////////////////////////////////////////////////////////////////////////////

inline
bool QFormulatorEditWidget::isRemovedSelection()
	{ return m_removedSelection; }
inline
void QFormulatorEditWidget::setRemovedSelection()
	{ m_removedSelection = true; }
inline
void QFormulatorEditWidget::clearRemovedSelection()
	{ m_removedSelection = false; }

/////////////////////////////////////////////////////////////////////////////

#endif
