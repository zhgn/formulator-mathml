

#if !defined( __FMLCORE_TEST_DIR2HTML_H__ )
#define __FMLCORE_TEST_DIR2HTML_H__

#include <QObject>
#include <QDir>

#include "../fmlcore_global.h"

class QFormulatorRenderer;

/////////////////////////////////////////////////////////////////////////////

class __YUNEN_FORMULIB__ QFmlTestDir2Html
{
protected:
	QFormulatorRenderer		*m_engine;
	QDir					m_destDir;
	QString					m_rootDir, m_destPath;
	QString					m_mmlExt, m_pictExt;
	QString					m_text;

public:
	QFmlTestDir2Html(QString rootDir, QString destPath, QString mmlExt, QString pictExt, QObject *parent = 0);
	~QFmlTestDir2Html();
	QFormulatorRenderer* renderer();
	void run();

protected:
	void renderDir(const QDir& rootDir);
};

/////////////////////////////////////////////////////////////////////////////

#endif
