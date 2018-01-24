

#include <QtGui/QApplication>
#include <QTextStream>
#include <QThread>
#include "HUtils/idrawing.h"
#include "HMathML/itest.h"

int main( int argc, char *argv[] )
{
	QApplication a(argc, argv, true);
	QStringList argList = QCoreApplication::arguments();
	QTextStream out(stdout);

	if( argList.size() < 2 )
	{
		out << "Usage: fmltest <options-list>" << endl;
		return 0;
	}

	if( argList.size() > 3 && argList.at(1).compare("-dir2html") == 0 )
	{
		out << "Searching for MathML files...\n" << endl;
		::StartUpFDE( FmlDrawEngine_Qt );
		QFmlTestDir2Html testRunner(argList.at(2), argList.at(3), "*.mml", "png" );
		testRunner.run();
		out << "Searching done\n" << endl;
	}

	return 1;//a.exec();
}
