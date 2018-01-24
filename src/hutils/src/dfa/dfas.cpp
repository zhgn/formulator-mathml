

#include <math.h>
#include "dfas.h"

int _hatol( const QStringRef& str, long& value )
{
	int err_level = ELH_NO_ERROR;

	LSDigit ldigit;
	int ret = ldigit.Analisys( str );
	switch( ret )
	{
	case LSDigit::Integer:
		value = ldigit.asign * ldigit.mnt_int;
		break;
	case LSDigit::Float:
		ldigit.mnt_float *= pow( 10.0f, (int)(ldigit.power) );
		value = long(ldigit.asign * ldigit.mnt_float);
		err_level = ELH_SOFT_ERROR;
		break;
	case LSDigit::FloatIEEE:
		ldigit.mnt_float *= pow( 10.0f, (int)(ldigit.power + ldigit.sign * ldigit.powerE) );
		value = long(ldigit.asign * ldigit.mnt_float);
		err_level = ELH_SOFT_ERROR;
		break;
	default:
		err_level = ELH_CRITICAL_ERROR;
	}
	return err_level;
}

int _hatof( const QStringRef& str, double& value )
{
	int err_level = ELH_NO_ERROR;

	LSDigit ldigit;
	int ret = ldigit.Analisys( str );
	switch( ret )
	{
	case LSDigit::Integer:
		value = ldigit.asign * double( ldigit.mnt_int );
		break;
	case LSDigit::Float:
		ldigit.mnt_float *= pow( 10.0f, (int)( ldigit.power ) );
		value = ldigit.asign * ldigit.mnt_float;
		break;
	case LSDigit::FloatIEEE:
		ldigit.mnt_float *= pow( 10.0f, (int)( ldigit.power + ldigit.sign * ldigit.powerE ) );
		value = ldigit.asign * ldigit.mnt_float;
		break;
	default:
		err_level = ELH_CRITICAL_ERROR;
	}
	return err_level;
}

int _hatol_base( const QStringRef& str, const QString& base, long& value )
{
	short int iBase = base.toInt();
	if( iBase < 2 || iBase > 36 || iBase == 10 )
		return ::_hatol( str, value );

	int err_level = ELH_NO_ERROR;

	LSDigitBase ldigit( iBase );
	int ret = ldigit.Analisys( str );
	switch( ret )
	{
	case LSDigitBase::Integer:
		value = ldigit.asign * ldigit.mnt_int;
		break;
	case LSDigitBase::Float:
		ldigit.mnt_float *= pow( (double) iBase, (int)(ldigit.power) );
		value = long(ldigit.asign * ldigit.mnt_float);
		err_level = ELH_SOFT_ERROR;
		break;
	case LSDigitBase::FloatIEEE:
		ldigit.mnt_float *= pow( (double) iBase, (int)(ldigit.power + ldigit.sign * ldigit.powerE) );
		value = long(ldigit.asign * ldigit.mnt_float);
		err_level = ELH_SOFT_ERROR;
		break;
	default:
		err_level = ELH_CRITICAL_ERROR;
	}
	return err_level;
}

int _hatof_base( const QStringRef& str, const QString& base, double& value )
{
	short int iBase = base.toInt();
	if( iBase < 2 || iBase > 36 || iBase == 10 )
		return ::_hatof( str, value );

	int err_level = ELH_NO_ERROR;

	LSDigitBase ldigit( iBase );
	int ret = ldigit.Analisys( str );
	switch( ret )
	{
	case LSDigitBase::Integer:
		value = ldigit.asign * double( ldigit.mnt_int );
		break;
	case LSDigitBase::Float:
		ldigit.mnt_float *= pow( (double) iBase, (int)( ldigit.power ) );
		value = ldigit.asign * ldigit.mnt_float;
		break;
	case LSDigitBase::FloatIEEE:
		ldigit.mnt_float *= pow( (double) iBase, (int)( ldigit.power + ldigit.sign * ldigit.powerE ) );
		value = ldigit.asign * ldigit.mnt_float;
		break;
	default:
		err_level = ELH_CRITICAL_ERROR;
	}
	return err_level;
}
