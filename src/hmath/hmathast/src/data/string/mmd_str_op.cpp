

#include "mmd_str_op.h"

///////////////////////////////////////////////////////////////////////////////

UniWord _dsrop_Add_string( UniWord& ret, const UniWord& a, const UniWord& b )
{
	ret = *(a.getString()) + *(b.getString());
	return ret;
}

UniWord _dsrop_Equal_string( UniWord& ret, const UniWord& a, const UniWord& b )
{
	QString s1 = *(a.getString());
	QString s2 = *(b.getString());
	ret = CDSRInteger( s1 == s2 );
	return ret;
}

UniWord _dsrop_NotEqual_string( UniWord& ret, const UniWord& a, const UniWord& b )
{
	ret = CDSRInteger( *(a.getString()) != *(b.getString()) );
	return ret;
}

///////////////////////////////////////////////////////////////////////////////
