

#include "message.h"

///////////////////////////////////////////////////////////////////////////////

QString DRMessage::Format()
{
	QString formatedText;
	if( c_arg1.length() )
	{
		formatedText = (n_arg1 != -1) ?
			QString("%1 %2: %3").arg(c_arg1).arg(n_arg1).arg(text) : 
			QString("%1: %3").arg(c_arg1).arg(text);
	}
	else
		formatedText = text;

	if( c_arg2.length() )
		return formatedText.arg(c_arg2);
	else if( n_arg2 != -1 )
		return formatedText.arg(n_arg2);
	return formatedText;
}

///////////////////////////////////////////////////////////////////////////////
