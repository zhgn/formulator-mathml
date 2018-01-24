

#if !defined( __FORMULATOR_NODEINFO_PROPERTY_H__ )
#define __FORMULATOR_NODEINFO_PROPERTY_H__

#include "selectnode.h"
#include "../../button/btn_attr.h"

class __YUNEN_FORMULIB__ CNodeInfo_Property : public FBtnAttr
{
protected:
	CNode *m_markup_addon;

public:
	CNodeInfo_Property();
	virtual ~CNodeInfo_Property();
	const CNodeInfo_Property& operator = ( const CNodeInfo_Property& v );
	void setNodeInfo_Property( const CNodeInfo_Property& v );
	void setNodeInfo_Property( const FBtnAttr& v );

	CNode* getAddonNode( void ) const;
	void setAddonNode( CNode* node );
	virtual int isAble2Glue() const;

	friend QDataStream& operator << ( QDataStream& ar, const CNodeInfo_Property& lp );
	friend QDataStream& operator >> ( QDataStream& ar, CNodeInfo_Property& lp );
};

/////////////////////////////////////////////////////////////////////

inline
CNode* CNodeInfo_Property::getAddonNode( void ) const
{
	return m_markup_addon;
}

inline
void CNodeInfo_Property::setAddonNode( CNode* node )
{
	m_markup_addon = node;
}

inline
int CNodeInfo_Property::isAble2Glue() const
{
	if( FBtnAttr::isAble2Glue() == 0 ) return 0;
	return m_markup_addon ? 0 : 1;
}

inline
void CNodeInfo_Property::setNodeInfo_Property( const CNodeInfo_Property& v )
{
	operator =( v );
}

inline
void CNodeInfo_Property::setNodeInfo_Property( const FBtnAttr& v )
{
	(FBtnAttr&) (*this) = (const FBtnAttr&) v;
}

/////////////////////////////////////////////////////////////////////

#endif
