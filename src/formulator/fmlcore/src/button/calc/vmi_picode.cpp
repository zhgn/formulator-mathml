

#include "vmi_picode.h"

///////////////////////////////////////////////////////////////////////////////
// Button Language VM defines

QString FBtnPiCode_Command_Str[ LPC_LAST ] =
{
	_T("LPC_NONE"),
	_T("LPC_ASIGN"),
	_T("LPC_POP"),
	_T("LPC_PUSH"),
	_T("LPC_PUSHVAL"),
	_T("LPC_MINUS"),
	_T("LPC_ADD"),
	_T("LPC_SUB"),
	_T("LPC_MUL"),
	_T("LPC_DIV"),
	_T("LPC_ABS"),
	_T("LPC_AVERAGE"),
	_T("LPC_MIN"),
	_T("LPC_MAX")
};

void FBtnPiCode::operator=( const FBtnPiCode& ls )
{
	line = ls.line;
	val = ls.val;
	frame_var = ls.frame_var;
	command = ls.command;
}

///////////////////////////////////////////////////////////////////////////////
