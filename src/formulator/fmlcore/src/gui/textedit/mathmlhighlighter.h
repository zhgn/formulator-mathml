

#ifndef __FMLCORE_DLG_MATHMLHIGHLIGHTER_H__
#define __FMLCORE_DLG_MATHMLHIGHLIGHTER_H__

#include <QSyntaxHighlighter>
#include <QHash>
#include <QMap>
#include <QTextCharFormat>

QT_BEGIN_NAMESPACE
class QTextDocument;
QT_END_NAMESPACE

class QMathMLHighlighter
	: public QSyntaxHighlighter
{
   Q_OBJECT

protected:
	bool					m_enableMode;
	QMap<QString, bool>		m_tagMap;
	QMap<QString, QString>	m_attrMap;

public:
    QMathMLHighlighter( QTextDocument *parent = 0 );

	bool isHighlightMode();

public slots:
	void setHighlightMode( bool enabled );

protected:
    void highlightBlock( const QString &text );

protected:
    struct HighlightingRule
    {
        QRegExp pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> highlightingRules;

    QRegExp commentStartExpression;
    QRegExp commentEndExpression;

    QTextCharFormat knownTagFormat, knownAttrFormat;
    QTextCharFormat tagNameFormat, attrNameFormat, commentFormat, opFormat, quotationFormat;

signals:
	void dummySignal();
};

#endif
