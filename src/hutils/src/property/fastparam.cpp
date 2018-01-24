

#include "fastparam.h"
//#include "HUtils/idfas.h"

void HKFastParameterList::setParameter( const QString& key, HKParameter& param )
{
	if( m_list_name.find( key ) == m_list_name.end() )
	{	// add a new parameter
		m_list_value.push_back( param );
		m_list_name[ key ] = (long) (m_list_value.size()) - 1;
	}
	else
		m_list_value[ m_list_name[ key ] ] = param; // assign a new parameter value
}

int HKFastParameterList::Read_XML( AST_TXML_Tag *root, DRMessageManager& dmm, long dmm_page )
{
	long ret = 0;
	AST_TXML_Tag* tag = root->getFirstTag( FBL_TAG_property_list );
	if( !tag )
		return 0;

	std::vector<AST_TXML_Tag*> arrtags;
	tag->getAllTags( FBL_TAG_property, arrtags, 1 );

	long i;
	for( i = 0; i < (long) arrtags.size(); i++ )
	{
		if( arrtags[ i ] )
		{
			HKParameter item;
			QString name;
			if( !item.Read_XML( arrtags[ i ], name, dmm, dmm_page ) && name != _T("") )
			{
				if( getParameter( name ) )
				{
					QString err3 = _T("property already exists");
					dmm.AddLine( dmm_page, err3, arrtags[ i ]->getLine() );
				}
				else
					setParameter( name, item );
			}
		}
	}
	return ret;
}

///////////////////////////////////////////////////////////////////////////
