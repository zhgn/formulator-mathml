

#if !defined( __FORMULATOR_N_RMML_CM_H__ )
#define __FORMULATOR_N_RMML_CM_H__

#include "n_cm_treetemplate.h"
#include "n_rmml_cm.h"
#include "../node.h"

///////////////////////////////////////////////////////////////////////////////

enum enApplyRenderSepList
{
	__APPLY_RENDER_HEAD_IDX = 0,
	__APPLY_RENDER_L_IDX,
	__APPLY_RENDER_R_IDX,
	__APPLY_RENDER_SEP_IDX,

	__APPLY_RENDER_RESERVED,

	__APPLY_RENDER_LAST
};

inline
int _CM_isBVarChild( AST_TXML_Compound *_tags, long idx )
{
	AST_TXML_Tag *_n = (AST_TXML_Tag*)(_tags->getChild( idx ));
	return !xml_strcmp( _n->getTagName(), FBL_TAG_bvar );
}

inline
int _CM_isDeclareChild( AST_TXML_Compound *_tags, long idx )
{
	AST_TXML_Tag *_n = (AST_TXML_Tag*)(_tags->getChild( idx ));
	return !xml_strcmp( _n->getTagName(), FBL_TAG_declare );
}

inline
int _CM_isUniversalQualifierChild( AST_TXML_Compound *_tags, long idx )
{
	AST_TXML_Tag *_n = (AST_TXML_Tag*)(_tags->getChild( idx ));
	return  _n->getTagName() == FBL_TAG_lowlimit || 
			_n->getTagName() == FBL_TAG_uplimit || 
			_n->getTagName() == FBL_TAG_interval || 
			_n->getTagName() == FBL_TAG_condition || 
			_n->getTagName() == FBL_TAG_domainofapplication;
}

class CLineNode;
struct __YUNEN_FORMULIB__ CCM_apply_args
{
	std::vector<CLineNode*> l2do;
	long arity;
	long nPrecedence;
	short nAssoc;
	long nSize;
	enum TAG2MML op_id;
	QString op_body;
	QString _h_str, _l_str, _r_str, _c_str;
	AST_TXML_Tag *_h_node, *_l_node, *_r_node, *_c_node;
	long form;
	AST_TXML_Compound *xml_tags;
	AST_TXML_Tag *xml_n;

	CCM_apply_args( void );
	~CCM_apply_args( void );
	int set( enum TAG2MML tag_id, AST_TXML_Tag*& xml_node );
};

///////////////////////////////////////////////////////////////////////////////

#endif
