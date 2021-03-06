

#ifndef __FORMULATOR_NI_BRACKETS_H__
#define __FORMULATOR_NI_BRACKETS_H__

#include "node.h"

/////////////////////////////////////////////////////////////////////////////

typedef std::pair<CLineNode*, long> CBracketCoord;
class CRootNode;

class __YUNEN_FORMULIB__ CLRBracketSelection
{
public:
	CLRBracketSelection( CRootNode& rootNode );

	const SelectNode& GetLBMark() const;
	const SelectNode& GetRBMark() const;
	const SelectNode& GetSNMark( int isLeft ) const;
	int isSNLeft() const;

	void ClearBrackets_All();
	void ClearBrackets_SNVector();
	void ClearBrackets_SN();
	void DecBracketsStack();
	void ClearBrackets_OnePair();

	int OnCharBracket( unsigned int nChar,  const SelectNode& sn );

	std::vector<SelectNode>& getSNVectorRef( int& isLeft );
	const std::vector<SelectNode>& getSNVector( int& shouldDraw ) const;
	const SelectNode& getSN( int& shouldDraw ) const;

	void RefreshBracketsSN( int isSNVectorLeft, const std::vector<SelectNode>& toload );

	int  isExistPosition( CNode *pNode );
	void deletePosition( CNode *pNode );
	void notifyNodeOnRemoveBracket( const std::vector<SelectNode>& snb );
	void notifyNodeOnRemoveBracket( const SelectNode& sn );
	void notifyNodeOnCreateBracket( const SelectNode& sn, int isSNVectorLeft );

protected:
	CRootNode&			m_rootNode;
	SelectNode			m_sn;
	int					m_isSNVectorLeft, m_isSNLeft;
	std::vector<SelectNode>	m_snb;
};

/////////////////////////////////////////////////////////////////////////////

inline 
const SelectNode& CLRBracketSelection::GetSNMark( int isLeft ) const
{
	static SelectNode emptySn( NULL, 0 );
	if( m_isSNVectorLeft == isLeft && m_snb.size() >  0)
		return m_snb[ m_snb.size() - 1 ];
	else if( m_isSNLeft == isLeft )
		return m_sn;
	return emptySn;
}

inline 
const SelectNode& CLRBracketSelection::GetLBMark() const
{
	return GetSNMark( 1 );
}

inline 
const SelectNode& CLRBracketSelection::GetRBMark() const
{
	return GetSNMark( 0 );
}

inline
void CLRBracketSelection::ClearBrackets_All()
{
	ClearBrackets_SNVector();
	ClearBrackets_SN();
}

inline
int CLRBracketSelection::isSNLeft() const
{
	return m_isSNLeft == 1;
}

inline
void CLRBracketSelection::ClearBrackets_SNVector()
{
	m_isSNVectorLeft = -1;
	notifyNodeOnRemoveBracket( m_snb );
	m_snb.clear();
}

inline
void CLRBracketSelection::ClearBrackets_SN()
{
	m_isSNLeft = -1;
	m_sn.SetEmpty();
}

inline
void CLRBracketSelection::DecBracketsStack()
{
	if( m_snb.size() > 0 )
	{
		long pos = m_snb.size() - 1;
		notifyNodeOnRemoveBracket( m_snb[ pos ] );
		m_snb[ pos ].SetEmpty();
		m_snb.erase( m_snb.begin() + pos );
	}
	if( m_snb.size() == 0 )
		m_isSNVectorLeft = -1;
}

inline
void CLRBracketSelection::ClearBrackets_OnePair()
{
	ClearBrackets_SN();
	DecBracketsStack();
}

inline
const std::vector<SelectNode>& CLRBracketSelection::getSNVector( int& shouldDraw ) const
{
	shouldDraw = m_isSNVectorLeft;
	return m_snb;
}

inline
std::vector<SelectNode>& CLRBracketSelection::getSNVectorRef( int& isLeft )
{
	isLeft = m_isSNVectorLeft;
	return m_snb;
}

inline
const SelectNode& CLRBracketSelection::getSN( int& shouldDraw ) const
{
	shouldDraw = m_isSNLeft;
	return m_sn;
}

inline
void CLRBracketSelection::RefreshBracketsSN( int isSNVectorLeft, const std::vector<SelectNode>& toload )
{
	m_isSNVectorLeft = isSNVectorLeft;
	m_snb.resize( toload.size(), SelectNode( NULL, 0 ) );
	std::copy( toload.begin(), toload.end(), m_snb.begin() );
}

#endif
