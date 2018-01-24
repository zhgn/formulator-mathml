

#if !defined( __FORMULATOR_EXTCONTENT_EXTC_TEST_H__ )
#define __FORMULATOR_EXTCONTENT_EXTC_TEST_H__

#include "../../fmlcore_global.h"
#include "ext_node.h"

/////////////////////////////////////////////////////////////////////////////

#define EXTNODECONTENT_ID_TEST	0

/////////////////////////////////////////////////////////////////////////////

class __YUNEN_FORMULIB__ CExtNodeContent_Test : public CExtNodeContent_Base
{
public:
	CExtNodeContent_Test( void );
	CExtNodeContent_Test( const CExtNodeContent_Test& _content );

public:
	virtual void Init( void *pData );
	virtual CExtNodeContent_Base* Clone( void );

	virtual void Store( QDataStream& ar ) const;
	virtual void Load( QDataStream& ar );

	void Draw( CFmlDrawEngine& fde, const PointFde& tl, const RectFde& rc );
};

/////////////////////////////////////////////////////////////////////////////

#endif//__FORMULATOR_EXTCONTENT_EXTC_TEST_H__
