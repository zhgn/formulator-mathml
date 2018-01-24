

#include "../mathml/mml_defs.h"
#include "op_iddefs.h"

///////////////////////////////////////////////////////////////////////////////

int shouldBracket4Apply( QString calculationCenterID, long childPos )
{
	if( calculationCenterID == HF_BTNID_DEFAULT_DIVISION_SP || calculationCenterID == HF_BTNID_SQRT ||
		calculationCenterID == HF_BTNID_DEFAULT_BRACKET_FLOOR || calculationCenterID == HF_BTNID_DEFAULT_BRACKET_CEIL ||
		calculationCenterID == HF_BTNID_DEFAULT_BRACKET_ABS || calculationCenterID == HF_BTNID_DEFAULT_BRACKET_NORM ||
		calculationCenterID == HF_BTNID_DEFAULT_BRACKET_LRA )
		return 0;

	if( (calculationCenterID == HF_BTNID_SUP || calculationCenterID == HF_BTNID_SUB) && (childPos < 0 || childPos == 1) )
		return 0;

	return 1;
}

int getSupContentByOperatorTagID( enum TAG2MML tag_id, QString& szBody, QString& szBase )
{
	int iRet = 0;
	switch( tag_id )
	{
	case TAG2MML_laplacian:
		szBody = _T("&nabla;");
		szBase = _T("2");
		break;
	case TAG2MML_variance:
		szBody = _T("&sigma;");
		szBase = _T("2");
		break;
	case TAG2MML_arcsin:
		szBody = _T("sin");
		szBase = _T("&minus;1");
		break;
	case TAG2MML_arccos:
		szBody = _T("cos");
		szBase = _T("&minus;1");
		break;
	case TAG2MML_arctan:
		szBody = _T("tan");
		szBase = _T("&minus;1");
		break;
	case TAG2MML_arccot:
		szBody = _T("cot");
		szBase = _T("&minus;1");
		break;
	case TAG2MML_arcsinh:
		szBody = _T("sinh");
		szBase = _T("&minus;1");
		break;
	case TAG2MML_arccosh:
		szBody = _T("cosh");
		szBase = _T("&minus;1");
		break;
	case TAG2MML_arctanh:
		szBody = _T("tanh");
		szBase = _T("&minus;1");
		break;
	case TAG2MML_arccoth:
		szBody = _T("coth");
		szBase = _T("&minus;1");
		break;
	case TAG2MML_arcsec:
		szBody = _T("sec");
		szBase = _T("&minus;1");
		break;
	case TAG2MML_arccsc:
		szBody = _T("csc");
		szBase = _T("&minus;1");
		break;
	case TAG2MML_arcsech:
		szBody = _T("sech");
		szBase = _T("&minus;1");
		break;
	case TAG2MML_arccsch:
		szBody = _T("csch");
		szBase = _T("&minus;1");
		break;
	default:
		iRet = -1;
	}
	return iRet;
}

///////////////////////////////////////////////////////////////////////////////
