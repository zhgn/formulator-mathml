

#include <QtGui/QApplication>
#include <QSplashScreen>
#include <QThread>
#include "HMathML/idocview.h"

int main( int argc, char *argv[] )
{
    //Q_INIT_RESOURCE(fmlide);
    QApplication a(argc, argv);

    QFormulatorMainWindow w( true );
    w.show();

    return a.exec();
}
