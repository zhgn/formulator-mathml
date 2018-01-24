

#if !defined( __HMATH_CMMCALC_CMMCALCTEST__ )
#define __HMATH_CMMCALC_CMMCALCTEST__

///////////////////////////////////////////////////////////////////////////////

#include <QByteArray>
#include "HMathAST/icmml.h"

///////////////////////////////////////////////////////////////////////////////

class CMMLCalcTest
{
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
	CMMLCalcTest();
	~CMMLCalcTest();

	int prepareInputData( int argc, char* argv[] );
	int compileMathML();
	int convertMathML2AST();
	int createVM();

	void reportVMTextCode();
	void reportVMTree();
	void reportVMVariables();
};

///////////////////////////////////////////////////////////////////////////////


#endif
