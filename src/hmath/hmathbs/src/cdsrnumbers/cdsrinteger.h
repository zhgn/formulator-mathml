

#ifndef _CDSRINTEGER_H_
#define _CDSRINTEGER_H_

typedef long integer;

struct CDSRIntegerStorage
{
	integer value;
	integer& operator= ( double v ) { return value = (integer) v; }
};

class CDSRInteger : public CDSRIntegerStorage
{
public:
	CDSRInteger( integer val = 0 ){ value = val; };

	integer get(){ return value; };

	const CDSRInteger& operator = ( const CDSRInteger& i )
	{
		value = i.value;
		return *this;
	};
	const CDSRInteger& operator = ( const integer& val )
	{
		value = val;
		return *this;
	};

	friend inline CDSRInteger operator + ( CDSRInteger& i1, CDSRInteger& i2 )
	{
		integer result;
		result = i1.value + i2.value;

		//__asm jno mmm;
		//throw "Result of the operation is out of range";
		//__asm mmm: nop;

		return CDSRInteger( result );
	};
	friend inline CDSRInteger operator + ( CDSRInteger& i1, integer i2 )
	{
		integer result;
		result = i1.value + i2;

		//__asm jno mmm;
		//throw "Result of the operation is out of range";
		//__asm mmm: nop;

		return CDSRInteger( result );
	};
	friend inline CDSRInteger operator + ( integer i1, CDSRInteger& i2 )
	{
		integer result;
		result = i1 + i2.value;

		//__asm jno mmm;
		//throw "Result of the operation is out of range";
		//__asm mmm: nop;

		return CDSRInteger( result );
	};

	friend inline CDSRInteger operator - ( CDSRInteger& i1, CDSRInteger& i2 )
	{
		integer result;
		result = i1.value - i2.value;

		//__asm jno mmm;
		//throw "Result of the operation is out of range";
		//__asm mmm: nop;

		return CDSRInteger( result );
	};
	friend inline CDSRInteger operator - ( CDSRInteger& i1, integer i2 )
	{
		integer result;
		result = i1.value - i2;

		//__asm jno mmm;
		//throw "Result of the operation is out of range";
		//__asm mmm: nop;

		return CDSRInteger( result );
	};
	friend inline CDSRInteger operator - ( integer i1, CDSRInteger& i2 )
	{
		integer result;
		result = i1 - i2.value;

		//__asm jno mmm;
		//throw "Result of the operation is out of range";
		//__asm mmm: nop;

		return CDSRInteger( result );
	};
	friend CDSRInteger operator * ( CDSRInteger& i1, CDSRInteger& i2 )
	{
		integer result;
		result = i1.value * i2.value;

		//__asm jno mmm;
		//throw "Result of the operation is out of range";
		//__asm mmm: nop;

		return CDSRInteger( result );
	};

	friend CDSRInteger operator * ( CDSRInteger& i1, integer i2 )
	{
		integer result;
		result = i1.value * i2;

		//__asm jno mmm;
		//throw "Result of the operation is out of range";
		//__asm mmm: nop;

		return CDSRInteger( result );
	};

	friend CDSRInteger operator * ( integer i1, CDSRInteger& i2 )
	{
		integer result;
		result = i1 * i2.value;

		//__asm jno mmm;
		//throw "Result of the operation is out of range";
		//__asm mmm: nop;

		return CDSRInteger( result );
	};

	friend CDSRInteger operator / ( CDSRInteger& i1, CDSRInteger& i2 )
	{
		integer result;
		if( i2.get() == 0 )
			throw "Result of the operation is out of range";
		result = i1.get() / i2.get();
		return CDSRInteger( result );
	};
	friend CDSRInteger operator / ( CDSRInteger& i1, integer i2 )
	{
		integer result;
		if( i2 == 0 )
			throw "Division by zero";
		result = i1.get() / i2;
		return CDSRInteger( result );
	};
	friend CDSRInteger operator / ( integer i1, CDSRInteger& i2 )
	{
		integer result;
		if( i2.get() == 0 )
			throw "Result of the operation is out of range";
		result = i1 / i2.get();
		return CDSRInteger( result );
	};
	friend int operator==( CDSRInteger& i1, CDSRInteger& i2 )
	{
		return( i1.get() == i2.get() );
	};
	friend int operator<( CDSRInteger& i1, CDSRInteger& i2 )
	{
		return( i1.get() < i2.get() );
	};
	friend int operator>( CDSRInteger& i1, CDSRInteger& i2 )
	{
		return( i1.get() > i2.get() );
	};
	friend int operator<=( CDSRInteger& i1, CDSRInteger& i2 )
	{
		return( i1.get() <= i2.get() );
	};
	friend int operator>=( CDSRInteger& i1, CDSRInteger& i2 )
	{
		return( i1.get() >= i2.get() );
	};
};

#endif
