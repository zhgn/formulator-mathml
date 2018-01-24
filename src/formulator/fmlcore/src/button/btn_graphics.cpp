

#include "btn_graphics.h"
#include "../style/style.h"

/////////////////////////////////////////////////////////////////////

FBtnGraphics::FBtnGraphics( void ) 
	: pos( 0.0, 0.0, 100.0, 100.0 )
{
	line = -1;
	grType = FBtnGraphics::GRAPH_PRIM_NONE;
	color = QColor(0, 0, 0);
	style = Qt::SolidLine;
	height = FTEXT_HEIGHT_FRAME;
	width = LINETHICKNESS_DEFAULT;
	sizeType = VARIABLE_SIZE;
	coord_type = COORD_TYPE_RATIO;
	stretchy = 0;
	altGroup = DEFAULT_ALT_GR_PRIMITIVE_GROUP;
	align = HORISONTAL_CENTER | VERTICAL_CENTER;
	expr_enable = 0;
	bind_to = -1;
	offset_direction_x = 0.0;
	offset_direction_y = 0.0;
}

void FBtnGraphics::createLine( int grTp, int penStyle, RectFde& rc )
{
	line = -1;
	name = text_reserve = "";
	coord_type = COORD_TYPE_RATIO;
	pos = RectFde( PointFde(0.0, 0.0), PointFde(HF_BINBUTTON_HORIZONTAL_SCALE, HF_BINBUTTON_VERTICAL_SCALE) );
	color = QColor( 0, 0, 0 );
	height = FTEXT_HEIGHT_FRAME;
	width = LINETHICKNESS_DEFAULT;
	sizeType = VARIABLE_SIZE;
	altGroup = DEFAULT_ALT_GR_PRIMITIVE_GROUP;
	stretchy = 0;
	align = HORISONTAL_CENTER | VERTICAL_CENTER;
	expr_enable = 0;
	bind_to = -1;
	grType = grTp;
	style = penStyle;
	pos = rc;
}

/////////////////////////////////////////////////////////////////////

QDataStream& operator << ( QDataStream& ar, const FBtnGraphics& lp )
{
	return	ar << lp.name << lp.text_reserve << lp.line << lp.grType << lp.style << lp.sizeType << 
			lp.stretchy << lp.altGroup << lp.align << lp.expr_enable << lp.bind_to << lp.coord_type << 
			lp.color << lp.pos << lp.height << lp.width << lp.point_type << lp.point_x << lp.point_y << 
			lp.offset_direction_x << lp.offset_direction_y;
}

QDataStream& operator >> ( QDataStream& ar, FBtnGraphics& lp )
{
	return	ar >> lp.name >> lp.text_reserve >> lp.line >> lp.grType >> lp.style >> lp.sizeType >> 
			lp.stretchy >> lp.altGroup >> lp.align >> lp.expr_enable >> lp.bind_to >> lp.coord_type >> 
			lp.color >> lp.pos >> lp.height >> lp.width >> lp.point_type >> lp.point_x >> lp.point_y >> 
			lp.offset_direction_x >> lp.offset_direction_y;
}

/////////////////////////////////////////////////////////////////////

