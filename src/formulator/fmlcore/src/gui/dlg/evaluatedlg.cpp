

#include <QtGui>
#include <QFile>

#include "evaluatedlg.h"
#include "HMathML/isettings.h"

/////////////////////////////////////////////////////////////////////////////

CEvaluateDialog::CEvaluateDialog( QWidget *parent )
	: QDialog( parent )
{
	init();

	int iRes = main();
	QString strRes;
	if( iRes == 0 )
	{
		for( unsigned long i = 0; i < m_dmm.size(); i++ )
			strRes = m_dmm.getFormatedText(i, m_dmmPage).toAscii().data();
	}

    m_resultLabel = new QLabel(strRes);
	QVBoxLayout *mainLayout = new QVBoxLayout();
	mainLayout->addWidget( m_resultLabel );
	setLayout(mainLayout);
	setWindowTitle(tr("Content MathML Evaluation"));
}

CEvaluateDialog::~CEvaluateDialog()
{
	dispose();
}

void CEvaluateDialog::accept()
{
	QDialog::accept();
}

///////////////////////////////////////////////////////////////////////////////

void CEvaluateDialog::init()
{
	m_dmm.clear();
	m_dmmPage = 0;
	m_cmmlCalc = NULL;
	m_xmlTree = NULL;
	m_vmcode = _T("");
	m_astTreeDump = _T("");
	m_vmVariables = _T("");
}

void CEvaluateDialog::dispose()
{
	if( m_xmlTree )
	{
		delete m_xmlTree;
		m_xmlTree = NULL;
	}
	if( m_cmmlCalc )
	{
		delete m_cmmlCalc;
		m_cmmlCalc = NULL;
	}
	for( unsigned long i = 0; i < m_dmm.size(); i++ )
		printf( "%s\n", m_dmm.getFormatedText(i, m_dmmPage).toAscii().data() );
}

int CEvaluateDialog::prepareInputData( int argc, char* argv[] )
{
	m_taskName = argv[ 0 ];
	if( argc > 1 )
		m_path = argv[ 1 ];
	if( m_path == NULL )
	{
		m_dmm.AddLine( m_dmmPage, _T("Usage: cmmCalcConsole <Content MathML Input File>\n"));
		return -1;
	}

	QFile file( m_path );
	if( !file.open( QIODevice::ReadOnly ) )
	{
		m_dmm.AddLine( m_dmmPage, _T("File is not found\n"), QString(m_path));
		return -1;
	}
	m_readBytes = file.readAll();
	file.close();
	if( m_readBytes.size() == 0 )
	{
		m_dmm.AddLine( m_dmmPage, _T("File is empty or cannot be read\n"), QString(m_path));
		m_readBytes = 0;
		return -1;
	}
	return 0;
}
 
int CEvaluateDialog::compileMathML() 
{
	if( m_readBytes.size() == 0 ) return -1;

	if( ::LS_CompileXML( m_path, QString( m_readBytes ), m_xmlTree, m_dmm, m_dmmPage ) == 0 && m_xmlTree != NULL )
		return 0;
	m_dmm.AddLine( m_dmmPage, _T("File cannot be compiled (error of Content MathML parsing)\n"), QString(m_path));
	return -1;
}

int CEvaluateDialog::convertMathML2AST()
{
	if( !m_xmlTree ) return -1;

	AST_TXML_Tag* mathTag = m_xmlTree->getFirstTag( FBL_TAG_math );
	if( !mathTag )
	{
		m_dmm.AddLine( m_dmmPage, _T("Tag <math> is missed\n"), QString(m_path));
		return -1;
	}

	m_cmmlCalc = new CMMLCalc( m_dmm, m_dmmPage, m_path );
	if( m_cmmlCalc->CreateAST( mathTag ) == CMMLError_NONE )
		return 0;
	m_dmm.AddLine( m_dmmPage, _T("File cannot be compiled (error of Content MathML parsing)\n"), QString(m_path));
	return -1;
}

int CEvaluateDialog::createVM()
{
	if( !m_cmmlCalc ) return -1;
	return m_cmmlCalc->CreateVM( DSRMM_FUNCTION, INT_MM_ID_FUNCTION_REAL_E );
}

///////////////////////////////////////////////////////////////////////////////

void CEvaluateDialog::reportVMTextCode()
{
	if( !m_cmmlCalc || !m_cmmlCalc->getVM() ) return;

	m_vmcode = ::getTextView( m_cmmlCalc->getVM()->getSmbTable(), *(m_cmmlCalc->getVM()) );
	m_dmm.AddLine( m_dmmPage, m_vmcode);
}

void CEvaluateDialog::reportVMTree()
{
	if( !m_cmmlCalc ) return;

	m_astTreeDump = _T("");
	m_cmmlCalc->debugPrint( m_astTreeDump );
	m_dmm.AddLine( m_dmmPage, m_astTreeDump );
}

void CEvaluateDialog::reportVMVariables()
{
	if( !m_cmmlCalc || !m_cmmlCalc->getVM() ) return;

	// exec main body
	m_cmmlCalc->execMain();
	// report values of variables
	m_cmmlCalc->getVM()->printVariableValue2Text( m_vmVariables, -1, 1 );
	m_dmm.AddLine( m_dmmPage, m_vmVariables );
}

///////////////////////////////////////////////////////////////////////////////

int CEvaluateDialog::main()
{
/*
	const int argc = 2;
	char *argv[ argc ] = {"", "D:\\mmlsoft\\test\\hmath\\ContentMathML\\_cmml-01.txt"};

	if( prepareInputData( argc, argv ) == -1 )
		return -1;
	if( compileMathML() == -1 )
		return -1;
	if( convertMathML2AST() == -1 )
		return -1;
	if( createVM() == -1 )
		return -1;

	reportVMTextCode();
	reportVMTree();
	reportVMVariables();
*/
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
