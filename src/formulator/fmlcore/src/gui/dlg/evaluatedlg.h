

#ifndef __FMLCORE_DLG_EVALUATEDLG_H__
#define __FMLCORE_DLG_EVALUATEDLG_H__

#include <QMainWindow>
#include <QString>
#include <QDialog>

QT_BEGIN_NAMESPACE
class QSpinBox;
class QToolButton;
class QLabel;
QT_END_NAMESPACE

#include <QByteArray>
#include "HMathAST/icmml.h"

#include "HUtils/idrawstruct.h"
#include "../../fmlcore_global.h"

class __YUNEN_FORMULIB__ CEvaluateDialog : public QDialog
{
    Q_OBJECT

protected:
	QLabel *m_resultLabel;

public:
	CEvaluateDialog( QWidget *parent );
    ~CEvaluateDialog();

public slots:
	virtual void accept();

protected:
	QString m_taskName;
	QString m_path;
	QByteArray m_readBytes;
	TXML_Storage* m_xmlTree;

	DRMessageManager m_dmm;
	long m_dmmPage;

	CMMLCalc	*m_cmmlCalc;

	// reports
	QString m_vmcode, m_astTreeDump, m_vmVariables;

public:
	void init();
	void dispose();

	int prepareInputData( int argc, char* argv[] );
	int compileMathML();
	int convertMathML2AST();
	int createVM();

	void reportVMTextCode();
	void reportVMTree();
	void reportVMVariables();

	int main();
};

#endif
