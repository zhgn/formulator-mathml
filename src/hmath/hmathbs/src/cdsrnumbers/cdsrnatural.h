

#ifndef _CDSRNATURAL_H_
#define _CDSRNATURAL_H_

typedef /*unsigned*/ long natural;

struct CDSRNaturalStorage
{
	natural value;
	natural& operator = ( double v ) { return value = (natural) v; }
};

class CDSRNatural : public CDSRNaturalStorage
{
public:
	CDSRNatural( natural val = 1 )
	{
		if( val < 1 )
			throw "Result of the operation is out of range";
		value = val;
	};

	natural get(){ return value; };

	CDSRNatural operator = (const CDSRNatural& n )
	{
		value = n.value;
		return *this;
	};
	CDSRNatural operator = ( natural& val )
	{
		if( val < 1 )
			throw "Result of the operation is out of range";
		value = val;
		return *this;
	};

	friend CDSRNatural operator + ( CDSRNatural& n1, CDSRNatural& n2 )
	{
		long r = n1.get() + n2.get();

		//__asm jno mmm;
		//throw "Result of the operation is out of range";
		//__asm mmm: nop;

		return CDSRNatural( r );
	};

	friend CDSRNatural operator + ( CDSRNatural& n1, long n2 )
	{
		long r = n1.get() + n2;

		//__asm jno mmm;
		//throw "Result of the operation is out of range";
		//__asm mmm: nop;

		return CDSRNatural( r );
	};

	friend CDSRNatural operator + ( long n1, CDSRNatural& n2 )
	{
		long r = n1 + n2.get();

		//__asm jno mmm;
		//throw "Result of the operation is out of range";
		//__asm mmm: nop;

		return CDSRNatural( r );
	};

	friend CDSRNatural operator - ( CDSRNatural& n1, CDSRNatural& n2 )
	{
		if( n1.get() <= n2.get() )
			throw "Result of the operation is out of range";
		return CDSRNatural( n1.get() - n2.get() );
	};

	friend CDSRNatural operator - ( CDSRNatural& n1, long n2 )
	{
		if( n1.get() <= n2 )
			throw "Result of the operation is out of range";
		return CDSRNatural( n1.get() - n2 );
	};

	friend CDSRNatural operator - ( long n1, CDSRNatural& n2 )
	{
		if( n1 <= n2.get() )
			throw "Result of the operation is out of range";
		return CDSRNatural( n1 - n2.get() );
	};

	friend CDSRNatural operator * ( CDSRNatural& n1, CDSRNatural& n2 )
	{
		long r = n1.get() * n2.get();

		//__asm jno mmm;
		//throw "Result of the operation is out of range";
		//__asm mmm: nop;

		return CDSRNatural( r );
	};

	friend CDSRNatural operator * ( CDSRNatural& n1, long n2 )
	{
		long r = n1.get() * n2;

		//__asm jno mmm;
		//throw "Result of the operation is out of range";
		//__asm mmm: nop;

		return CDSRNatural( r );
	};

	friend CDSRNatural operator * (long n1, CDSRNatural& n2 )
	{
		long r = n1 * n2.get();

		//__asm jno mmm;
		//throw "Result of the operation is out of range";
		//__asm mmm: nop;

		return CDSRNatural( r );
	};

	friend CDSRNatural operator / ( CDSRNatural& n1, CDSRNatural& n2 )
	{
		if( n1.get() < n2.get() )
			throw "Result of the operation is out of range";
		return CDSRNatural( n1.get() / n2.get() );
	};

	friend int operator == ( CDSRNatural& n1, CDSRNatural& n2 )
	{
		return( n1.get() == n2.get() );
	};
	friend int operator < ( CDSRNatural& n1, CDSRNatural& n2 )
	{
		return( n1.get() < n2.get() );
	};
	friend int operator > ( CDSRNatural& n1, CDSRNatural& n2 )
	{
		return( n1.get() > n2.get() );
	};
	friend int operator <= ( CDSRNatural& n1, CDSRNatural& n2 )
	{
		return( n1.get() <= n2.get() );
	};
	friend int operator >= ( CDSRNatural& n1, CDSRNatural& n2 )
	{
		return( n1.get() >= n2.get() );
	};

};

#endif
