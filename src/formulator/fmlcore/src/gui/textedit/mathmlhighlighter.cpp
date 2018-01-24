

#if QT_VERSION > QT_VERSION_CHECK(5, 0, 0)
#include <QtWidgets>
#else
#include <QtGui>
#endif
#include "mathmlhighlighter.h"

#include "../../nodes/info/n_proplist.h"

/////////////////////////////////////////////////////////////////////////////

QMathMLHighlighter::QMathMLHighlighter( QTextDocument *parent )
    : QSyntaxHighlighter( parent )
{
	m_enableMode = true;
    HighlightingRule rule;
#if 0
	CMMLNodeAttrList& mmlDb = ::getFullMathMLAttrList();
	const std::multimap<QString, long>& tag2attr = mmlDb.getTag2AttrMap();
	std::multimap<QString, long>::const_iterator tagIter = tag2attr.begin();
	QString tagName, attrName;
	if( tagIter != tag2attr.end() )
	{
		tagName = tagIter->first;
		if( !m_tagMap.contains( tagName ) )
			m_tagMap.insert( tagName, true );

		CNode_TextPropertyData *attrData = mmlDb.getParameter( tagIter->second );
		if( attrData )
		{
			attrName = attrData->m_name;
			if( !m_attrMap.contains( attrName ) )
				m_attrMap.insert( attrName, tagName );
		}
	}

	if( !m_tagMap.empty() )
	{
    	knownTagFormat.setForeground( Qt::darkRed );
    	knownTagFormat.setFontWeight( QFont::Bold );
		QMap<QString, bool>::const_iterator i = m_tagMap.constBegin();
		while( i != m_tagMap.constEnd() )
		{
			rule.pattern = QRegExp( QString("\\b%1\\b").arg(i.key()) );
			rule.format = knownTagFormat;
			highlightingRules.append(rule);
			++i;
		}
	}

	if( !m_attrMap.empty() )
	{
    	knownAttrFormat.setForeground( Qt::red );
    	//knownAttrFormat.setFontWeight( QFont::Bold );
		QMap<QString, QString>::const_iterator i = m_attrMap.constBegin();
		while( i != m_attrMap.constEnd() )
		{
			rule.pattern = QRegExp( QString("\\b%1\\b").arg(i.key()) );
			rule.format = knownAttrFormat;
			highlightingRules.append(rule);
			++i;
		}
	}
	//int CMMLNodeAttrList::isSupportedTag2Attr( QString tagName, QString attrName )
    //tagFormat.setFontWeight(QFont::Bold);
    //tagFormat.setForeground(Qt::darkMagenta);
    //rule.pattern = QRegExp("\\Q[A-Za-z]+\\b");
    //rule.format = classFormat;
    //highlightingRules.append(rule);
#endif
	tagNameFormat.setForeground(Qt::darkRed/*Qt::darkMagenta*/);
	rule.pattern = QRegExp("</?\\s*[A-Za-z:_][A-Za-z\\d:_.-]*\\b");
	rule.format = tagNameFormat;
	highlightingRules.append(rule);

	attrNameFormat.setForeground(Qt::red/*Qt::darkRed*/);
	rule.pattern = QRegExp("\\b[A-Za-z:_][A-Za-z\\d:_.-]*(?=\\s*\\=\\s*[\'\"])\\b");
	rule.format = attrNameFormat;
	highlightingRules.append(rule);

	commentFormat.setForeground(Qt::darkGreen/*Qt::darkGray*/);
    commentStartExpression = QRegExp("<!--");
    commentEndExpression = QRegExp("-->");

	quotationFormat.setForeground(Qt::blue/*Qt::darkGreen*/);
    rule.format = quotationFormat;
    rule.pattern = QRegExp("\".*\"");
	rule.pattern.setMinimal( true );
    highlightingRules.append(rule);
    rule.pattern = QRegExp("\'.*\'");
	rule.pattern.setMinimal( true );
    highlightingRules.append(rule);

	opFormat.setForeground(Qt::darkBlue);
	rule.pattern = QRegExp("[<>=/\\\\]+");
	rule.format = opFormat;
	highlightingRules.append(rule);
}

void QMathMLHighlighter::highlightBlock(const QString &text)
{
	if( !m_enableMode ) return;

    foreach (const HighlightingRule &rule, highlightingRules)
	{                   
        QRegExp expression( rule.pattern );
        int index = expression.indexIn( text );
        while( index >= 0 )
		{
            int length = expression.matchedLength();
            setFormat( index, length, rule.format );
            index = expression.indexIn( text, index + length );
        }
    }

    setCurrentBlockState( 0 );

    int startIndex = 0;
    if( previousBlockState() != 1 )
        startIndex = commentStartExpression.indexIn( text );

    while( startIndex >= 0 )
	{
        int endIndex = commentEndExpression.indexIn( text, startIndex );
        int commentLength;
        if( endIndex == -1 )
		{
            setCurrentBlockState( 1 );
            commentLength = text.length() - startIndex;
        }
		else
		{
            commentLength = endIndex - startIndex + commentEndExpression.matchedLength();
        }
        setFormat( startIndex, commentLength, commentFormat );
        startIndex = commentStartExpression.indexIn( text, startIndex + commentLength );
    }
}

void QMathMLHighlighter::setHighlightMode( bool enabled )
{
	m_enableMode = enabled;
	rehighlight();
}

bool QMathMLHighlighter::isHighlightMode()
{
	return m_enableMode;
}


/////////////////////////////////////////////////////////////////////////////
