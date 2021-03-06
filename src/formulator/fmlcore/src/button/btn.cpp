

#include "../settings/options.h"
#include "btn.h"
#include "calc/vmi.h"

/////////////////////////////////////////////////////////////////////

FBtn::FBtn( void )
	: HKToolBarButton()
{
	node_type = NODE_FORMULA;
	text_style = getCurrentFormulatorStyle_OnChar();
	rows = 1;
	columns = 1;
	vertical_center_type = FBtnChildPos::Default;
	vertical_center_value = 0;
	text_color = getCurrentFormulatorStyle().getFontStyle( text_style ).m_color;
}

const FBtn& FBtn::operator = ( const FBtn& a )
{
	HKToolBarButton::operator = ( a );
	node_type = a.node_type;
	formula_type_name = a.formula_type_name;
	mathml_name = a.mathml_name;
	vertical_center_type = a.vertical_center_type;
	vertical_center_value = a.vertical_center_value;
	to_mathml = a.to_mathml;
	ar_child = a.ar_child;
	ar_graphics = a.ar_graphics;
	coord_calculation = a.coord_calculation;
	node_mathml_string = a.node_mathml_string;
	proplist = a.proplist;
	input_properties = a.input_properties;
	text_value = a.text_value;
	m_cannot_draw_width = a.m_cannot_draw_width;
	m_cannot_draw_height = a.m_cannot_draw_height;
	text_color = a.text_color;
	rows = a.rows;
	columns = a.columns;
	text_style = a.text_style;
	return *this;
}

/////////////////////////////////////////////////////////////////////

QDataStream& operator << ( QDataStream& ar, const FBtn& lp )
{
	ar << (const HKToolBarButton&) lp;
	return ar << lp.to_mathml << lp.formula_type_name << lp.mathml_name << lp.node_mathml_string << 
					lp.text_value << lp.m_cannot_draw_width << lp.m_cannot_draw_height << lp.node_type << 
					lp.vertical_center_type << lp.vertical_center_value << lp.rows << lp.columns << 
					lp.text_style << lp.text_color << lp.proplist << 
					lp.ar_child << lp.ar_graphics << lp.input_properties << lp.coord_calculation;
}

QDataStream& operator >> ( QDataStream& ar, FBtn& lp )
{
	ar >> (HKToolBarButton&) lp;
	return ar >> lp.to_mathml >> lp.formula_type_name >> lp.mathml_name >> lp.node_mathml_string >> 
					lp.text_value >> lp.m_cannot_draw_width >> lp.m_cannot_draw_height >> lp.node_type >> 
					lp.vertical_center_type >> lp.vertical_center_value >> lp.rows >> lp.columns >> 
					lp.text_style >> lp.text_color >> lp.proplist >> 
					lp.ar_child >> lp.ar_graphics >> lp.input_properties >> lp.coord_calculation;
}

/////////////////////////////////////////////////////////////////////
