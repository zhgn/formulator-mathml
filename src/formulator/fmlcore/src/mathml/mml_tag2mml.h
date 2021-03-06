

#if !defined( __COMMON_LANGUAGE_MATHML_MML_TAG2MML_H__ )
#define __COMMON_LANGUAGE_MATHML_MML_TAG2MML_H__

#include "../fmlcore_global.h"
#include "HUtils/ihkstring.h"
#include "HUtils/iustring.h"
#include "HUtils/ixml.h"
#include "mml_operator.h"
#include "mml_defs.h"

///////////////////////////////////////////////////////////////////////////////

__YUNEN_FORMULIB__ void mml_get_cn_attr( AST_TXML_Tag *node, QString& base, long& typeidx );
__YUNEN_FORMULIB__ int mml_get_CM2PM_simple( enum TAG2MML tag_id, AST_TXML_Tag *xml_node, QString& newtag, QString& newtext, std::vector<QString>& attr );

///////////////////////////////////////////////////////////////////////////////

__YUNEN_FORMULIB__ extern QString szCMTag2PMTag_standalone[ TAG2MML_LAST ];
__YUNEN_FORMULIB__ extern QString szCMTag2PMText_standalone[ TAG2MML_LAST ];
__YUNEN_FORMULIB__ QString mml_getCM2PMTag_standalone( enum TAG2MML tag_id, AST_TXML_Tag *xml_node );
__YUNEN_FORMULIB__ QString mml_getCM2PMText_standalone( enum TAG2MML tag_id, AST_TXML_Tag *xml_node );

__YUNEN_FORMULIB__ long mml_getCM2Argc( enum TAG2MML tag_id );
__YUNEN_FORMULIB__ int mml_getCM2isOp( enum TAG2MML tag_id );

__YUNEN_FORMULIB__ long mml_getPrecedence( enum TAG2MML tag_id, long argc = -1, QString opBody = QString() );
__YUNEN_FORMULIB__ short mml_getAssoc( enum TAG2MML tag_id, long argc = -1, QString opBody = QString() );
__YUNEN_FORMULIB__ bool mml_shouldWrapByPrecAssoc( long parent_precedence, long self_precedence, short parent_assoc, short self_assoc, short position );

#define __APPLY_RENDER_FORM_FENCED_FUN		0
#define __APPLY_RENDER_FORM_NONFENCED_FUN	1
#define __APPLY_RENDER_FORM_OP				2
#define __APPLY_RENDER_SPECIAL				3

__YUNEN_FORMULIB__ long mml_getApplyForm( enum TAG2MML tag_id );

inline
int mml_isNAryOperator( long op_id )
{
	switch( op_id )
	{
	case TAG2MML_plus:
	case TAG2MML_times:
	case TAG2MML_max:
	case TAG2MML_min:
	case TAG2MML_gcd:
	case TAG2MML_lcm:
	case TAG2MML_mean:
	case TAG2MML_sdev:
	case TAG2MML_variance:
	case TAG2MML_median:
	case TAG2MML_mode:
	case TAG2MML_and:
	case TAG2MML_or:
	case TAG2MML_xor:
	case TAG2MML_union:
	case TAG2MML_intersect:
	case TAG2MML_cartesianproduct:
	case TAG2MML_compose:
	case TAG2MML_eq:
	case TAG2MML_leq:
	case TAG2MML_lt:
	case TAG2MML_geq:
	case TAG2MML_gt:
	case TAG2MML_subset:
	case TAG2MML_prsubset:
	case TAG2MML_nop:
		return 1;
	default:
		break;
	}
	return 0;
}

///////////////////////////////////////////////////////////////////////////////

__YUNEN_FORMULIB__ int mml_isContentTag( QString name );
__YUNEN_FORMULIB__ int mml_isContentTag( enum TAG2MML id );

///////////////////////////////////////////////////////////////////////////////

#define TRANSLATE_CONTENT_MATHML2_TIMES				0
#define TRANSLATE_CONTENT_MATHML2_SDOT				1
#define TRANSLATE_CONTENT_MATHML2_INVISIBLETIMES	2

__YUNEN_FORMULIB__
void mml_UsePreference_ContentTimes( long contentTimes );

__YUNEN_FORMULIB__
int mml_GetPreference_ContentTimes();

///////////////////////////////////////////////////////////////////////////////

inline
int mml_isContentTag( enum TAG2MML id )
{
	return (id >= TAG2MML_cn && id < TAG2MML_LAST) ? 1 : 0;
}

inline
int mml_isContentTag( QString name )
{
	return ::mml_isContentTag( ::mml_getTag2MML( name ) );
}

///////////////////////////////////////////////////////////////////////////////

#endif
