

#ifndef __COMMON_CTRL_TEMPLATE_H__
#define __COMMON_CTRL_TEMPLATE_H__

#include "../basexxx.h"
#include "param.h"
#include "internal_property.h"

class HUTILS_EXPORT GUICtrlTemplate : public HKParameterList
{
protected:
	long m_id;
	long m_type;

	void InitProperty_STATIC_TEXT( void );
	void InitProperty_EDIT_BOX( void );
	void InitProperty_DROPDOWN_COMBO_BOX( void );
	void InitProperty_OPEN_FILE_EDIT_BOX( void );
	void InitProperty_FORMULATOR_EDIT_BOX( void );
	void InitProperty_COLOR_COMBO_BOX( void );

	void InitAdditionalProperty_STATIC_TEXT( AST_TXML_Compound *comp );
	void InitAdditionalProperty_EDIT_BOX( AST_TXML_Compound *comp );
	void InitAdditionalProperty_DROPDOWN_COMBO_BOX( AST_TXML_Compound *comp );
	void InitAdditionalProperty_OPEN_FILE_EDIT_BOX( AST_TXML_Compound *comp );
	void InitAdditionalProperty_FORMULATOR_EDIT_BOX( AST_TXML_Compound *comp );
	void InitAdditionalProperty_COLOR_COMBO_BOX( AST_TXML_Compound *comp );

public:
	GUICtrlTemplate( long id = GUI_CTRL_TEMPLATE_NONE, long type = HKParameterType_String );
	GUICtrlTemplate( const GUICtrlTemplate& gc );

	GUICtrlTemplate& operator = ( const GUICtrlTemplate& gc );

	long getID( void );
	long getType( void );
	void setType( long tp );
	void InitProperty( void );
	void InitAdditionalProperty( AST_TXML_Compound *comp );
	int AddComboItem( QString& _title, HKParameter& _value );

	//virtual void store( CArchive& ar );
	//virtual void load( CArchive& ar );

	//friend CArchive& operator << ( CArchive& ar, GUICtrlTemplate& param );
	//friend CArchive& operator >> ( CArchive& ar, GUICtrlTemplate& param );
};

inline
GUICtrlTemplate::GUICtrlTemplate( long id, long type ) :
	HKParameterList(), m_id( id ), m_type( type )
{
	InitProperty();
}

inline
GUICtrlTemplate::GUICtrlTemplate( const GUICtrlTemplate& gc ) : 
	HKParameterList( gc ), m_id( gc.m_id ), m_type( gc.m_type )
{
}

inline
GUICtrlTemplate& GUICtrlTemplate::operator = ( const GUICtrlTemplate& gc )
{
	m_id = gc.m_id;
	m_type = gc.m_type;
	const HKParameterList& pl = gc;
	HKParameterList::operator = ( pl );
	return *this;
}

inline
long GUICtrlTemplate::getID( void )
{
	return m_id;
}

inline
long GUICtrlTemplate::getType( void )
{
	return m_type;
}

inline
void GUICtrlTemplate::setType( long tp )
{
	m_type = tp;
}

/*
inline
void GUICtrlTemplate::store( CArchive& ar )
{
	ar << m_id;
	ar << m_type;
	HKParameterList::store( ar );
}

inline
void GUICtrlTemplate::load( CArchive& ar )
{
	ar >> m_id;
	ar >> m_type;
	HKParameterList::load( ar );
}

inline
CArchive& operator << ( CArchive& ar, GUICtrlTemplate& param )
{
	param.store( ar );
	return ar;
}

inline
CArchive& operator >> ( CArchive& ar, GUICtrlTemplate& param )
{
	param.load( ar );
	return ar;
}
*/

#endif // __COMMON_CTRL_TEMPLATE_H__
