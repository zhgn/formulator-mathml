

#if !defined( __FMLCORE_FMLRENDERER_H__ )
#define __FMLCORE_FMLRENDERER_H__

#if !defined( FML_NO_RENDERER )

#include <QObject>
#include <QSize>
#include <QColor>
#include <QByteArray>
#include <QXmlStreamReader>
#include <QPainter>

#include "../../fmlcore_global.h"

class QFormulatorWidget;

/////////////////////////////////////////////////////////////////////////////

class __YUNEN_FORMULIB__ QFormulatorRenderer
	: public QObject
{
	Q_OBJECT

protected:
	QFormulatorWidget		*m_engine;
	bool					m_isValid;

public:
	QFormulatorRenderer(QObject *parent = 0);
	QFormulatorRenderer(const QString& filename, QObject *parent = 0);
	QFormulatorRenderer(const QByteArray& contents, QObject *parent = 0);
	~QFormulatorRenderer();

	QString text();
	QSize defaultSize() const;
	bool isValid() const;

	void setScale(double value);
	double scale();

	void setBackColor(QColor color);
	QColor backColor();

	void setLineSpacing(double value);
	double lineSpacing();

	void margins( double& l, double& t, double& r, double& b );
	void setMargins( double l, double t, double r, double b );

public slots:
	bool load(const QString& filename);
	bool load(const QByteArray& contents);

	bool reload();

	void render(QPainter *painter);
	void render(QPainter *painter, const QRectF& bounds );

	bool exportImage(const QString& filename);

protected:
	void init();

signals:
	void repaintNeeded();
};

#endif	// FML_NO_RENDERER

/////////////////////////////////////////////////////////////////////////////

#endif
