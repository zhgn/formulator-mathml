

#ifndef __COMMON_CDSRARRAY_H__
#define __COMMON_CDSRARRAY_H__

#include "cdsrbasevector.h"

template <class T> class CDSRArray : public CDSRBaseVector<T>
{
public:
	CDSRArray( long size = 0, const T& value = T() )
		: CDSRBaseVector<T>( size, value )
	{
	}
	CDSRArray( const CDSRArray& vec )
		: CDSRBaseVector<T>( vec )
	{
	}
	CDSRArray( typename CDSRBaseVector<T>::iterator first, long size )
		: CDSRBaseVector<T>( first, size )
	{
	}
	CDSRArray( typename CDSRBaseVector<T>::const_iterator first, long size )
		: CDSRBaseVector<T>( first, size )
	{
	}
	CDSRArray( long size, typename CDSRBaseVector<T>::const_iterator first )
		: CDSRBaseVector<T>( first, size )
	{
	}
	virtual ~CDSRArray()
	{
	}
};

//////////////////////////////////////////////////////////////////////
#endif //__COMMON_CDSRARRAY_H__
