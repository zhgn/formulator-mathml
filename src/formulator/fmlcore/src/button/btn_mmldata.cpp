

#include "btn_mmldata.h"

/////////////////////////////////////////////////////////////////////

FBtnMMLData::FBtnMMLData()
{
	precedence = assoc = is_content = 0;
}

void FBtnMMLData::reset()
{
	value = name = left = right = type = frame = mathml_template_string = reserved = "";
	precedence = 0;
	assoc = 0;
	is_content = 0;
}

const FBtnMMLData& FBtnMMLData::operator = ( const FBtnMMLData& a )
{
	value = a.value;
	name = a.name;
	left = a.left;
	right = a.right;
	type = a.type;
	frame = a.frame;
	mathml_template_string = a.mathml_template_string;
	reserved = a.reserved;
	precedence = a.precedence;
	assoc = a.assoc;
	is_content = a.is_content;
	return *this;
}

/////////////////////////////////////////////////////////////////////

QDataStream& operator << ( QDataStream& ar, const FBtnMMLData& lp )
{
	return ar << lp.value << lp.name << lp.left << lp.right << lp.type << lp.frame << lp.mathml_template_string << lp.reserved << lp.precedence << lp.assoc << lp.is_content;
}

QDataStream& operator >> ( QDataStream& ar, FBtnMMLData& lp )
{
	return ar >> lp.value >> lp.name >> lp.left >> lp.right >> lp.type >> lp.frame >> lp.mathml_template_string >> lp.reserved >> lp.precedence >> lp.assoc >> lp.is_content;
}

/////////////////////////////////////////////////////////////////////
