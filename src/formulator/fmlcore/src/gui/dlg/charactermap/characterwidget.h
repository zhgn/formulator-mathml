

#ifndef __FMLCORE_DLG_CHARACTERWIDGET_H__
#define __FMLCORE_DLG_CHARACTERWIDGET_H__

#include <QFont>
#include <QPoint>
#include <QSize>
#include <QString>
#include <QWidget>

QT_BEGIN_NAMESPACE
class QMouseEvent;
class QPaintEvent;
QT_END_NAMESPACE

#include "../../../fmlcore_global.h"

class __YUNEN_FORMULIB__ CInsertCharacterWidget : public QWidget
{
    Q_OBJECT

public:
    CInsertCharacterWidget(QWidget *parent = 0);
    QSize sizeHint() const;
	const QFont& currentFont() { return displayFont; }
	const QColor& currentColor() { return color; }

public slots:
    void updateFont(const QFont &font);
    void updateSize(const QString &fontSize);
    void updateStyle(const QString &fontStyle);
	void updateColor(const QColor &fontColor);
    void updateFontMerging(bool enable);

signals:
    void characterSelected(const QString &character);

protected:
    void mouseMoveEvent( QMouseEvent *event );
    void mousePressEvent( QMouseEvent *event );
    void paintEvent( QPaintEvent *event );

private:
    QFont displayFont;
	QColor color;
    int columns;
    int lastKey;
    int squareSize;
};

#endif
