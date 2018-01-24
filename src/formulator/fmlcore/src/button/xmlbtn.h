

#if !defined( __FORMULATOR_FMLCORE_BTN_FROMXML_H__ )
#define __FORMULATOR_FMLCORE_BTN_FROMXML_H__

#include "HUtils/ixml.h"
#include "HUtils/imessage.h"

#include "btn.h"

///////////////////////////////////////////////////////////////////////////////

class FBtnVM;

class __YUNEN_FORMULIB__ FXmlBtn : public FBtn
{
public:
	FXmlBtn() : FBtn() {}
	const FXmlBtn& operator = ( const FXmlBtn& a ) { (FBtn&) (*this) = (const FBtn&)a; return *this; }
	int Read_XML( AST_TXML_Tag *root, DRMessageManager& dmm, long dmm_page = 0 );

protected:
	void validateVerticalCenter( FBtnVM& vm );
	void AddButtonData( AST_TXML_Tag *root, FBtnVM& vm );
	void AddAccels( AST_TXML_Tag *root, FBtnVM& vm );
	int AddChildData( AST_TXML_Tag *root, FBtnVM& vm );
	int AddChildData_read_align( AST_TXML_Tag *node, FBtnChildPos& child, FBtnVM& vm );
	int AddGraphicsData( AST_TXML_Tag *root, FBtnVM& vm );
	int AddGraphicsData_read_width( AST_TXML_Tag *node, FBtnGraphics& child, FBtnVM& vm );
	int AddGraphicsData_spline( AST_TXML_Tag *tag, FBtnGraphics &child, FBtnVM& vm );
	int AddNodeType_NODE_MATHML(AST_TXML_Tag *root, FBtnVM& vm);
	int CompileCalculationScheme( AST_TXML_Tag *root, FBtnVM& vm );
	void SetFormulaName( AST_TXML_Tag *root );
	void SetToMathML( AST_TXML_Tag *root, FBtnVM& vm );
};

/////////////////////////////////////////////////////////////////////

inline
QDataStream& operator << ( QDataStream& ar, const FXmlBtn& lp )
{
	return ar << (const FBtn&) lp;
}

inline
QDataStream& operator >> ( QDataStream& ar, FXmlBtn& lp )
{
	return ar >> (FBtn&) lp;
}

/////////////////////////////////////////////////////////////////////

int bb_read_attr_linethickness( AST_TXML_Tag *node, const QString& attr_name, RealFde& child_width );
int bb_read_attr_align_vertical( AST_TXML_Tag *node, const QString& attr_name, long& child_align );
int bb_read_attr_align_vertical( AST_TXML_Tag *node, const QString& attr_name, std::vector<long>& child_align, long defaultAlign );
int bb_read_attr_align_horizontal( AST_TXML_Tag *node, const QString& attr_name, long& child_align );
int bb_read_attr_align_horizontal( AST_TXML_Tag *node, const QString& attr_name, std::vector<long>& child_align, long defaultAlign );
int bb_read_attr_table_lines( AST_TXML_Tag *node, const QString& attr_name, std::vector<long>& penStyle );

/////////////////////////////////////////////////////////////////////

#endif
