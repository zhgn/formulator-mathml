

#include "HUtils/ihkstring.h"
#include "ni_brackets.h"
#include "ni_root.h"

/////////////////////////////////////////////////////////////////////////////

CLRBracketSelection::CLRBracketSelection( CRootNode& rootNode )
	: m_rootNode( rootNode )
	, m_sn()
	, m_isSNVectorLeft( -1 )
	, m_isSNLeft( -1 )
{
}

int CLRBracketSelection::isExistPosition( CNode *pNode )
{
	for( long i = 0; i < (long) m_snb.size(); i++ )
	{
		if( m_snb[ i ].GetNode() == pNode )
			return 1;
	}
	return 0;
}

void CLRBracketSelection::deletePosition( CNode *pNode )
{
	if( m_sn.GetNode() == pNode )
		ClearBrackets_SN();
	for( long i = 0; i < (long) m_snb.size(); )
	{
		if( m_snb[ i ].GetNode() == pNode )
		{
			notifyNodeOnRemoveBracket( m_snb[ i ] );
			m_snb[ i ].SetEmpty();
			m_snb.erase( m_snb.begin() + i );
		}
		else
			i++;
	}
	if( m_snb.size() == 0 )
		ClearBrackets_SNVector();
}

void CLRBracketSelection::notifyNodeOnRemoveBracket( const std::vector<SelectNode>& /*snb*/ )
{
	for( long i = 0; i < (long) m_snb.size(); i++ )
		notifyNodeOnRemoveBracket( m_snb[ i ] );
}

void CLRBracketSelection::notifyNodeOnRemoveBracket( const SelectNode& sn )
{
	if( sn.GetNode() != NULL && m_rootNode.haveChild( sn.GetNode() ) )
		sn.GetNode()->notifyNodeOnRemoveBracket( sn.GetPosition() );
}

void CLRBracketSelection::notifyNodeOnCreateBracket( const SelectNode& sn, int isLeft )
{
	if( sn.GetNode() != 0 )
		sn.GetNode()->notifyNodeOnCreateBracket( sn.GetPosition(), isLeft );
}

/////////////////////////////////////////////////////////////////////////////
