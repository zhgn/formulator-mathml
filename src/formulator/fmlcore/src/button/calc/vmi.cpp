

#include "vmi.h"

///////////////////////////////////////////////////////////////////////////////

FBtnVM::FBtnVM( FBtnCalc& _commands, DRMessageManager& _dmm, long _dmm_page )
	: commands( _commands )
	, dmm( _dmm )
	, dmm_page( _dmm_page )
{
	clearError();

	field_name.push_back( QString(FBtnVM_Margin_Left) );
	field_name.push_back( QString(FBtnVM_Margin_Top) );
	field_name.push_back( QString(FBtnVM_Margin_Right) );
	field_name.push_back( QString(FBtnVM_Margin_Bottom) );

	field_name.push_back( QString(SVG_NodeTemplate_Parameter_Left_Name) );
	field_name.push_back( QString(SVG_NodeTemplate_Parameter_Top_Name) );
	field_name.push_back( QString(SVG_NodeTemplate_Parameter_Right_Name) );
	field_name.push_back( QString(SVG_NodeTemplate_Parameter_Bottom_Name) );

	AddLocal( QString(SVG_NodeTemplate_Parameter_Left_Name) );
	AddLocal( QString(SVG_NodeTemplate_Parameter_Top_Name) );
	AddLocal( QString(SVG_NodeTemplate_Parameter_Right_Name) );
	AddLocal( QString(SVG_NodeTemplate_Parameter_Bottom_Name) );

	AddLocal( QString(FBtnVM_Margin_Left) );
	AddLocal( QString(FBtnVM_Margin_Top) );
	AddLocal( QString(FBtnVM_Margin_Right) );
	AddLocal( QString(FBtnVM_Margin_Bottom) );

	AddLocal( QString(FBtnVM_EM_NAME) );
	AddLocal( QString(FBtnVM_ASCENT_NAME) );
	AddLocal( QString(FBtnVM_DESCENT_NAME) );
}

int FBtnVM::getAddress( QString obj, QString obj_field, long& obj_addr, long& field_addr, long ln )
{
	static QString err1 =	_T("unknown field name %1");
	static QString err2 =	_T("unknown parent name %1 is neither object nor primitive");
	static QString err3 =	_T("unknown local variable name %1");

	long i, j;
	int ret = 0;
	if( obj != _T("") )
	{
		if( (j = field_name.indexOf( obj_field )) == -1 )
		{
			dmm.AddLine( dmm_page, err1, ln, obj_field );
			ret = -1;
		}
		else if( (i = object_name.indexOf( obj )) != -1 )
		{
			obj_addr = (i + 1);
			field_addr = j - 4;
		}
		else if( (i = primitive_name.indexOf( obj )) != -1 )
		{
			obj_addr = - (i + 1);
			field_addr = j - 4;
		}
		else
		{
			dmm.AddLine( dmm_page, err2, ln, obj );
			ret = -1;
		}
	}
	else
	{
		obj_addr = 0;
		if( (j = locals_name.indexOf( obj_field )) == -1 )
		{
			dmm.AddLine( dmm_page, err3, ln, obj_field );
			ret = -1;
		}
		else
			field_addr = j;
	}
	return ret;
}

void FBtnVM::CheckAssignTable( QVector<QPair<long, long> >& err_pairs )
{
	err_pairs.clear();
	for( long i = 0; i < (long) primitive_assign_table.size(); i++ )
	{
		if( !(primitive_assign_table[ i ] & (1 << SVG_NodeTemplate_Parameter_Left)) )
			err_pairs.push_back( QPair<long, long>(i, long(SVG_NodeTemplate_Parameter_Left)) );
		if( !(primitive_assign_table[ i ] & (1 << SVG_NodeTemplate_Parameter_Top)) )
			err_pairs.push_back( QPair<long, long>(i, long(SVG_NodeTemplate_Parameter_Top)) );
		if( !(primitive_assign_table[ i ] & (1 << SVG_NodeTemplate_Parameter_Right)) )
			err_pairs.push_back( QPair<long, long>(i, long(SVG_NodeTemplate_Parameter_Right)) );
		if( !(primitive_assign_table[ i ] & (1 << SVG_NodeTemplate_Parameter_Bottom)) )
			err_pairs.push_back( QPair<long, long>(i, long(SVG_NodeTemplate_Parameter_Bottom)) );
	}
}

///////////////////////////////////////////////////////////////////////////////
