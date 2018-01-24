

///////////////////////////////////////////////////////////////////////////////

#include <QtCore/QCoreApplication>
#include "src/cmmlCalcTest.h"

int main(int argc, char *argv[])
{
	//QCoreApplication a(argc, argv);
	CMMLCalcTest testCalc;
	if( testCalc.prepareInputData( argc, argv ) == -1 )
		return -1;
	if( testCalc.compileMathML() == -1 )
		return -1;
	if( testCalc.convertMathML2AST() == -1 )
		return -1;
	if( testCalc.createVM() == -1 )
		return -1;

	testCalc.reportVMTextCode();
	testCalc.reportVMTree();
	testCalc.reportVMVariables();

	return 0;
}
