

#ifndef __COMMON_CDSRVECTOR_H__
#define __COMMON_CDSRVECTOR_H__

#include <assert.h>
#include <vector>
#include <limits>
#include <iterator>
#include <algorithm>

#ifndef NO_FOUND
	#define NO_FOUND					0xFFFFFFFF
#endif

typedef unsigned long					ulong;
typedef unsigned short					ushort;

//////////////////////////////////////////////////////////////////////

template <class T> class CDSRBaseVector : public std::vector<T>
{
public:
	CDSRBaseVector( long sz = 0, const T& value = T() )
		: std::vector<T>( sz, value )
	{
	}
	CDSRBaseVector( const CDSRBaseVector& vec )
		: std::vector<T>( vec )
	{
	}
	CDSRBaseVector( typename std::vector<T>::iterator fst, long sz )
		: std::vector<T>( fst, fst + sz )
	{
	}
	CDSRBaseVector( typename std::vector<T>::const_iterator fst, long sz )
		: std::vector<T>( fst, fst + sz )
	{
	}
	virtual ~CDSRBaseVector()
	{
	}

	typename std::vector<T>::const_reference at( long index ) const
	{
#ifdef _DEBUG
		assert( index < (long) std::vector<T>::size() );
#endif
		return std::vector<T>::at( index );
	}
	typename std::vector<T>::reference at( long index )
	{
#ifdef _DEBUG
		assert( index < std::vector<T>::size() );
#endif
		return std::vector<T>::at( index );
	}

	typename std::vector<T>::const_reference operator[]( long index ) const 
	{
#ifdef _DEBUG
		assert( index < (long) std::vector<T>::size() );
#endif
		return std::vector<T>::operator[]( index );
	}
	typename std::vector<T>::reference operator[]( long index )
	{
#ifdef _DEBUG
                assert( index < (long) std::vector<T>::size() );
#endif
		return std::vector<T>::operator[]( index );
	}

	typename std::vector<T>::const_reference getfirst( long index = 0 ) const 
	{
		return (*this)[ index ];
	}
	typename std::vector<T>::reference getfirst( long index = 0 )
	{
		return (*this)[ index ];
	}
	typename std::vector<T>::const_reference getlast( long index = 0 ) const 
	{
		return (*this)[ (long) std::vector<T>::size() - index - 1 ];
	}
	typename std::vector<T>::reference getlast( long index = 0 )
	{
		return (*this)[ (long) std::vector<T>::size() - index - 1 ];
	}

	// add, insert, erase
	void add( T value = T() )
	{
		push_back( value );
	}
	void insert( long index, const T& value = T() )
	{
		std::vector<T>::insert( std::vector<T>::begin() + index, value );
	}
	void erase( long index )
	{
		std::vector<T>::erase( std::vector<T>::begin() + index );
	}
	void erase( long first, long last )
	{
		std::vector<T>::erase( std::vector<T>::begin() + first, std::vector<T>::begin() + last );
	}
	void eraselast()
	{
		resize( std::vector<T>::size() - 1 );
	}

	const CDSRBaseVector<T>& operator = ( const CDSRBaseVector<T>& vect )
	{
		resize( vect.size() );
		for ( unsigned long i = 0; i < std::vector<T>::size(); i++ )
			(*this)[ i ] = vect[ i ];
		return (*this);
	}

	int operator == ( CDSRBaseVector<T>& vec )
	{
		if ( std::vector<T>::size() != vec.size() )
			return 0;
		for ( long i = 0; i < (long) std::vector<T>::size(); i++ )
			if( (*this)[ i ] != vec[ i ] )
				return 0;
		return -1;
	}

	long find( const T& value, long start = 0 )
	{
		typename std::vector<T>::iterator location = std::vector<T>::begin();
		location = std::find( location + start, std::vector<T>::end(), value );
		if ( location == std::vector<T>::end() )
			return NO_FOUND;	//numeric_limits<unsigned long>::max();
		return std::distance( std::vector<T>::begin(), location );
	}
};

//////////////////////////////////////////////////////////////////////
#endif //__COMMON_CDSRVECTOR_H__
