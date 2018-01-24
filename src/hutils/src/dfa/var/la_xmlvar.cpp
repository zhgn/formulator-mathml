

#include "HUtils/iustring.h"
#include "la_xmlvar.h"

const static QString kw_xml				= _T("xml");
const static QString kw_doctype			= _T("doctype");

long LXMLVarLeapes[ LXMLVarStates * LXMLVarAlphabet ] =
{
//  l_  d -. :
	2, 0, 0,
	2, 2, 3,
	4, 0, 0,
	4, 4, 0
};

long LXMLVarsEndStates[ LXMLVarStates ] =
{
	0, 1, 1, 1
};

long LXMLVar::What( const QChar S )
//            ~~~~
{
	for(;;)
	{
		if( S.isLetter() || (S == _T('_')) )
			return 1;
		if( S.isDigit() || ( S == _T('-') ) || ( S == _T('.') ) )
			return 2;
		if( S == _T(':') )
			return 3;
		return 0;
	}
}

void LXMLVar::Deeds( void )
//            ~~~~~
{
	switch( CurrentState )
	{
	case 1 :
		m_identifier = _T("");
		m_namespace = _T("");
		break;
	case 2 :
		m_identifier += character;
		break;
	case 3 :
		m_namespace = m_identifier;
		m_identifier = _T("");
		break;
	case 4 :
		m_identifier += character;
		break;
	}
}

LXMLVar::LXMLVar( void )
//    ~~~~
: LAuto( LXMLVarStates, LXMLVarAlphabet, LXMLVarLeapes, LXMLVarsEndStates )
{
	m_identifier = _T("");
	m_namespace = _T("");
}

int LXMLVar::Analisys( const QStringRef& aText )
//            ~~~~~~~~
{
	int ret = LAuto::Analisys( aText );
	if( ret )
	{
		if( m_identifier.length() == 0 )
		{
			m_identifier = m_namespace;
			m_namespace = _T("");
		}
		if( !m_identifier.compare( kw_xml, Qt::CaseInsensitive ) )
			return XML;
		else if( !m_identifier.compare( kw_doctype, Qt::CaseInsensitive ) )
			return DOCTYPE;
	}
	return ret;
}
