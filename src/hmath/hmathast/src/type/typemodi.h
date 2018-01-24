

#if !defined( __PARSEDSR_OPERATOR_TYPEMODI_H__ )
#define __PARSEDSR_OPERATOR_TYPEMODI_H__

#include "../hmathast_global.h"
#include "HUtils/ihkflag.h"

#define CDsrDataType_Modifier_LVALUE	0x00000001
#define CDsrDataType_Modifier_XVALUE	0x00000002
#define CDsrDataType_Modifier_LOCAL		0x00000004
#define CDsrDataType_Modifier_DYNAMIC	0x00000008
#define CDsrDataType_Modifier_RETURNS	0x00000010
#define CDsrDataType_Modifier_LINEAR_EQ	0x00000020
#define CDsrDataType_Modifier_USED		0x00000040

/////////////////////////////////////////
//	CDsrDataType_Modifier
/////////////////////////////////////////
struct __HMATHLNGDLL__ CDsrDataType_Modifier
{
protected:
	HKLongFlag modifier;
public:
	CDsrDataType_Modifier( long v = 0 )
	{
		modifier.setValue( v );
	}
	
	HKLongFlag& getModifier( void )
	{
		return modifier;
	}
	
	int isLValue( void )
	{
		return modifier.isSetFlag( CDsrDataType_Modifier_LVALUE );
	}
	
	void setLValue( void )
	{
		modifier.setFlag( CDsrDataType_Modifier_LVALUE );
	}
	
	void clearLValue( void )
	{
		modifier.clearFlag( CDsrDataType_Modifier_LVALUE );
	}
	
	int isLocal( void )
	{
		return modifier.isSetFlag( CDsrDataType_Modifier_LOCAL );
	}
	
	void setLocal( void )
	{
		modifier.setFlag( CDsrDataType_Modifier_LOCAL );
	}
	
	int isXValue( void )
	{
		return modifier.isSetFlag( CDsrDataType_Modifier_XVALUE );
	}
	
	void setXValue( void )
	{
		modifier.setFlag( CDsrDataType_Modifier_XVALUE );
	}
	
	int isDynamic( void )
	{
		return modifier.isSetFlag( CDsrDataType_Modifier_DYNAMIC );
	}
	
	void setDynamic( void )
	{
		modifier.setFlag( CDsrDataType_Modifier_DYNAMIC );
	}
	
	int isReturns( void )
	{
		return modifier.isSetFlag( CDsrDataType_Modifier_RETURNS );
	}
	
	void setReturns( void )
	{
		modifier.setFlag( CDsrDataType_Modifier_RETURNS );
	}
	
	int isLinearEQ( void )
	{
		return modifier.isSetFlag( CDsrDataType_Modifier_LINEAR_EQ );
	}
	
	void setLinearEQ( void )
	{
		modifier.setFlag( CDsrDataType_Modifier_LINEAR_EQ );
	}
	
	int isUsed( void )
	{
		return modifier.isSetFlag( CDsrDataType_Modifier_USED );
	}
	
	void setUsed( void )
	{
		modifier.setFlag( CDsrDataType_Modifier_USED );
	}
	
	void copyModifier( CDsrDataType_Modifier *modi )
	{
		if( modi ) modifier.setValue( modi->getValue() );
	}
	
	long getValue( void )
	{
		return modifier.getValue();
	}
	
	void resetModifier( void )
	{
		modifier.resetFlag();
	}

};

#endif
	
