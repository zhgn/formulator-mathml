

#if !defined( __FORMULATOR_NODEINFO_H__ )
#define __FORMULATOR_NODEINFO_H__

#include "../../button/xmlbtn.h"
#include "nodeinfo_property.h"

/////////////////////////////////////////////////////////////////////

class __YUNEN_FORMULIB__ CNodeInfo_Alignment
{
protected:
	qint32 type, value;
public:
	CNodeInfo_Alignment( void )
		{ type = FBtnChildPos::Default; value = 0; }
	void setNodeInfo_Alignment( const CNodeInfo_Alignment& a )
		{ type = a.type; value = a.value; }
	void setSpecialVerticalCenter( long _type, long _value )
		{ type = _type; value = _value; }
	long getAlignmentType( void ) const
		{ return type; }
	long getAlignmentValue( void ) const
		{ return value; }

	friend QDataStream& operator << ( QDataStream& ar, const CNodeInfo_Alignment& lp );
	friend QDataStream& operator >> ( QDataStream& ar, CNodeInfo_Alignment& lp );
};

/////////////////////////////////////////////////////////////////////

inline
QDataStream& operator << ( QDataStream& ar, const CNodeInfo_Alignment& lp )
{
	return ar << lp.type << lp.value;
}

inline
QDataStream& operator >> ( QDataStream& ar, CNodeInfo_Alignment& lp )
{
	return ar >> lp.type >> lp.value;
}

/////////////////////////////////////////////////////////////////////

class __YUNEN_FORMULIB__ CNodeInfo_MathMLFormat
{
public:
	FBtnMMLData to_mathml_data;
public:
	void setMathMLFormat( const FBtnMMLData& _to_mathml_data )
		{ to_mathml_data = _to_mathml_data; }
	const FBtnMMLData& getMathMLFormat() const
		{ return to_mathml_data; }
	void setNodeInfo_MathMLFormat( const CNodeInfo_MathMLFormat& a )
		{ setMathMLFormat( a.getMathMLFormat() ); }
	void setNodeInfo_setMathMLNodeName( QString aname )
		{ to_mathml_data.name = aname; }
};

/////////////////////////////////////////////////////////////////////

inline
QDataStream& operator << ( QDataStream& ar, const CNodeInfo_MathMLFormat& lp )
{
	return ar << lp.to_mathml_data;
}

inline
QDataStream& operator >> ( QDataStream& ar, CNodeInfo_MathMLFormat& lp )
{
	return ar >> lp.to_mathml_data;
}

/////////////////////////////////////////////////////////////////////

class __YUNEN_FORMULIB__ CNodeInfo
	: public CNodeInfo_MathMLFormat
	, public CNodeInfo_Alignment
	, public CNodeInfo_Property
{
public:
	CNodeInfo( void ) {}
	CNodeInfo( CNodeInfo *pNodeInfo )
		{ setNodeInfo( *pNodeInfo ); }
	int isAble2Glue() const
		{ return CNodeInfo_Property::isAble2Glue(); }
	const CNodeInfo& operator = ( const CNodeInfo& a )
		{ setNodeInfo( a ); return *this; }
	virtual void setNodeInfo( const CNodeInfo& a )
	{ 
		setNodeInfo_MathMLFormat( a );
		setNodeInfo_Alignment( a );
		setNodeInfo_Property( a );
	}
};

/////////////////////////////////////////////////////////////////////

inline
QDataStream& operator << ( QDataStream& ar, const CNodeInfo& lp )
{
	return ar << (const CNodeInfo_MathMLFormat&) lp << (const CNodeInfo_Alignment&) lp << (const CNodeInfo_Property&) lp;
}

inline
QDataStream& operator >> ( QDataStream& ar, CNodeInfo& lp )
{
	return ar >> (CNodeInfo_MathMLFormat&) lp >> (CNodeInfo_Alignment&) lp >> (CNodeInfo_Property&) lp;
}

/////////////////////////////////////////////////////////////////////

#endif
