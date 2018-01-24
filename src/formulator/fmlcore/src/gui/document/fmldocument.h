

#if !defined( __FMLCORE_FMLDOCUMENT_H__ )
#define __FMLCORE_FMLDOCUMENT_H__

#include "HUtils/idrawing.h"
#include "HUtils/iundoredo.h"
#include "../../fmlcore_global.h"

/////////////////////////////////////////////////////////////////////////////

class QMimeData;

class CRootNode;
class QFormulatorBaseWidget;

/////////////////////////////////////////////////////////////////////////////

#define FORMULATOR_MIME_FORMAT "application/formulator-internal"

class __YUNEN_FORMULIB__ CFormulatorDoc 
	: public CHaveUndoRedo
{
protected:
	QFormulatorBaseWidget *m_owner;
	CRootNode*		m_pRootNode;		// to store
	QString			m_mmlCache;
	QString			m_cmmlCache;
	CUndoRedo*		m_pUndoRedo;		// undo - redo 
	QColor			m_clrBkgrnd;		// background color
	bool			m_isModified;		//
	bool			m_isMmlChanged;		//
	QString			m_path;

public: 
	CFormulatorDoc( QFormulatorBaseWidget *owner );
	virtual ~CFormulatorDoc();
	QString getPath() { return m_path; }
	void setPath(const QString& path) { m_path = path; }
	void setModified( bool isModified );
	bool isModified();
	void setMmlChanged( bool isMmlChanged );
	bool isMmlChanged();
	CRootNode* rootNode();
	CUndoRedo* undoRedo();

public:
	virtual void StoreDocument( QDataStream& ar ) const;
	virtual void LoadDocument( QDataStream& ar );

public:
	void afterNew();
	void afterOpen( const QString &filePath );
	void afterSave( const QString &filePath );

public:
	QString exportMathML();
	QString exportPureContentMathML( bool ignoreCache = false );
	static QString exportMathML( CRootNode *pRootNode );

public:
	static QMimeData* copyToMimeData( CRootNode *pRootNode, QImage *pImage = 0 );
	static int copy( CRootNode *pRootNode, QImage *pImage = 0 );
	int copy( QImage *pImage = 0, bool isCut = false, bool needSelection = true );
	int copyAll( QImage *pImage = 0 );
	int paste();
	int paste( const QMimeData *mimeData, bool deleteOldSelection );
	static int isAcceptedMimeFormat( const QMimeData *mimeData );

	bool isEnabledUndo();
	bool isEnabledRedo();
	bool isEnabledCopy();
	bool isEnabledPaste();
	bool isEnabledDelete();
	bool isEnabledSelectAll();
};

/////////////////////////////////////////////////////////////////////////////

inline
CRootNode* CFormulatorDoc::rootNode() 
	{ return m_pRootNode; }

inline
CUndoRedo* CFormulatorDoc::undoRedo()
	{ return m_pUndoRedo; }

inline
void CFormulatorDoc::setModified( bool isModified )
{
	m_isModified = isModified;
}

inline
bool CFormulatorDoc::isModified()
{
	return m_isModified;
}

inline
bool CFormulatorDoc::isMmlChanged()
{
	return m_isMmlChanged;
}

inline
void CFormulatorDoc::setMmlChanged( bool isMmlChanged )
{
	m_isMmlChanged = isMmlChanged;
}

/////////////////////////////////////////////////////////////////////////////

#endif
