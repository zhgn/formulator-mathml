

#ifndef __CINTLIB_UNDOREDO_H__
#define __CINTLIB_UNDOREDO_H__

///////////////////////////////////////////////////////////////////////////////

//#include <cstdlib>

#include <QTimerEvent>
#include <QDataStream>
#include <QByteArray>
#include <QList>

#include "../hutils_global.h"

///////////////////////////////////////////////////////////////////////////////

class HUTILS_EXPORT CHaveUndoRedo 
	: public QObject
{
public:
	virtual void StoreDocument( QDataStream& ar ) const = 0;
	virtual void LoadDocument( QDataStream& ar ) = 0;
};

///////////////////////////////////////////////////////////////////////////////

class HUTILS_EXPORT CUndoRedo 
	: public QObject
{
	Q_OBJECT

public:
	CUndoRedo( CHaveUndoRedo *document, long nUndoLevels = 1024 );
	~CUndoRedo();

	long GetUndoCount();
	long GetRedoCount();
	int CanUndo();			// Returns 1 if can Undo
	int CanRedo();			// Returns 1 if can Redo
	void Undo();			// Restore next Undo state
	void Redo();			// Restore next Redo state				

	void Clear();			// clear undo/redo manager
	int Init();				// init undo/redo manager
	int CheckPoint( int fForcedCheck = 0 );

	void EnableCheckPoint();
	void DisableCheckPoint();

	long GetUndoLevels();
	void SetUndoLevels( long nUndoLevels );

	virtual void timerEvent( QTimerEvent *event );

protected:
	void ClearUndoList();
	void ClearRedoList();
	void AddUndo( QByteArray *pData );
	void AddRedo( QByteArray *pData );
	void Load( QByteArray *pData );
	void Store( QByteArray *pData ) const;

	QByteArray* GetLastUndoFile();

	int UpdateTickCount( int fForcedCheck = 0 );

	void SetTimer();
	void KillTimer();

protected:
	CHaveUndoRedo		*m_document;
	QList<QByteArray*>	m_undoList;		// Stores undo states
	QList<QByteArray*>	m_redoList;		// Stores redo states
	long				m_nUndoLevels;	// Requested nUndoLevels 

	unsigned int		m_nTickCount;	// 
	unsigned int		m_nTimeStep;	//
	int					m_nTimerID;		//

signals:
	void undoAvailableSignal( bool enable );
	void redoAvailableSignal( bool enable );
};

/////////////////////////////////////////////////////////////////////////////

inline 
long CUndoRedo::GetUndoCount() 
	{ return (long) m_undoList.size(); }

inline 
long CUndoRedo::GetRedoCount() 
	{ return (long) m_redoList.size(); }

inline 
int CUndoRedo::CanUndo() 
	{ return GetUndoCount() > 1; }

inline 
int CUndoRedo::CanRedo() 
	{ return GetRedoCount() > 0; }

inline 
QByteArray* CUndoRedo::GetLastUndoFile()
	{ return m_undoList.isEmpty() ? NULL : (QByteArray*) m_undoList.first(); }

inline 
long CUndoRedo::GetUndoLevels()
	{ return m_nUndoLevels; };

inline 
void CUndoRedo::SetUndoLevels( long nUndoLevels )
	{ m_nUndoLevels = qMax( (long) 1, nUndoLevels ); };

///////////////////////////////////////////////////////////////////////////////

#endif
