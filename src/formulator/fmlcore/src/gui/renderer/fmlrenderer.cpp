

#include "fmlrenderer.h"

#if !defined( FML_NO_RENDERER )

#include "../widget/fmlwidget.h"
#include "../../button/toolbarset.h"
#include "../../settings/options.h"
#include "../../version/version.h"

/////////////////////////////////////////////////////////////////////////////

QFormulatorRenderer::QFormulatorRenderer(QObject *parent)
	: QObject(parent)
{
	init();
}

QFormulatorRenderer::QFormulatorRenderer(const QString& filename, QObject *parent)
	: QObject(parent)
{
	init();
	load(filename);
}

QFormulatorRenderer::QFormulatorRenderer(const QByteArray& contents, QObject *parent)
	: QObject(parent)
{
	init();
	load(contents);
}

QFormulatorRenderer::~QFormulatorRenderer()
{
	if( m_engine )
	{
		delete m_engine;
		m_engine = 0;
	}
}

void QFormulatorRenderer::init()
{
	FBtnToolbarSet *toolbarSet = ::getCurrentToolBarSet();
	if( toolbarSet == 0 || toolbarSet->getToolBarCount() == 0 )
	{
		::setCurrentFormulatorContentMathML_TranslateTimes( ::Formulib_GetTimes2Times() );
		::setCurrentFormulatorStyle_TranslatePref( ::Formulib_GetTranslator() );
		::setCurrentFormulatorOptionsValue( ::Formulib_GetOptionsValue() );
		QFormulatorWidget::initFormulatorCore();
	}

	m_engine = new QFormulatorWidget();
	m_engine->initialUpdate();
	setMargins(0, 0, 0, 0);
	m_isValid = false;
}

QString QFormulatorRenderer::text()
{
	return m_engine->text();
}

QSize QFormulatorRenderer::defaultSize() const
{
	return m_engine->size();
}

bool QFormulatorRenderer::isValid() const
{
	return m_isValid;
}

void QFormulatorRenderer::setScale( double value )
{
	m_engine->setScale( value );
}

double QFormulatorRenderer::scale()
{
	return m_engine->scale();
}

void QFormulatorRenderer::setBackColor( QColor color )
{
	m_engine->setBackColor( color );
}

QColor QFormulatorRenderer::backColor()
{
	return m_engine->backColor();
}

void QFormulatorRenderer::setLineSpacing( double value )
{
	m_engine->setLineSpacing( value );
}

double QFormulatorRenderer::lineSpacing()
{
	return m_engine->lineSpacing();
}

void QFormulatorRenderer::margins( double& l, double& t, double& r, double& b )
{
	m_engine->indents(l, t, r, b);
}

void QFormulatorRenderer::setMargins( double l, double t, double r, double b )
{
	m_engine->setIndents(l, t, r, b);
}

bool QFormulatorRenderer::load(const QString& filename)
{
	m_isValid = (m_engine->fileOpenSilent( filename ) == 1);
	if( m_isValid )
		emit repaintNeeded();
	return m_isValid;
}

bool QFormulatorRenderer::load(const QByteArray& contents)
{
	m_engine->clear();
	m_isValid = (m_engine->insertMathML( __FMLCORE_Product_Title, QString(contents), 0 ) == 1);
	if( m_isValid )
		emit repaintNeeded();
	return m_isValid;
}

bool QFormulatorRenderer::reload()
{
	m_isValid = (m_engine->refreshViaMathML() == 1);
	if( m_isValid )
		emit repaintNeeded();
	return m_isValid;
}

void QFormulatorRenderer::render(QPainter *painter)
{
	QRectF bounds(0, 0, m_engine->size().width(), m_engine->size().height());
	m_engine->render(painter, bounds);
}

void QFormulatorRenderer::render(QPainter *painter, const QRectF& bounds)
{
	m_engine->render(painter, bounds);
}

bool QFormulatorRenderer::exportImage(const QString& filename)
{
	return (m_engine->fileExportImage(filename) == 1) ? true : false;
}

/////////////////////////////////////////////////////////////////////////////

#endif
