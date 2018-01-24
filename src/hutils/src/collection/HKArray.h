

#if !defined( __HUTILS_HKARRAYS_H__ )
#define __HUTILS_HKARRAYS_H__

#include <limits.h>
#include <vector>

template <class T>
class MArray : public std::vector<T>
{
public :
	long	delta;

        MArray( long st, long /*lw*/ = 0, long dl = 0 ) :
		std::vector<T>()
	{
		delta = dl;
		std::vector<T>::resize(0);
		if( !st ) return;
		else
			std::vector<T>::reserve(st);
	};
	T& operator[]( long i )
	{
		if( i >= (long) std::vector<T>::size() ) std::vector<T>::resize(i+1);
		return std::vector<T>::at(i);
	}
	T& ItemAt( long i )
	{
		if( i >= (long) std::vector<T>::size() ) std::vector<T>::resize(i+1);
		return std::vector<T>::at(i);
	}
	const T& operator[]( long i ) const
	{
		return (const T&)std::vector<T>::at(i);
	}
	const T& ItemAt( long i ) const
	{
		return (const T&)std::vector<T>::at(i);
	}
	int Add( T& ref )
	{
		std::vector<T>::resize(std::vector<T>::size()+1,ref);
		return (int) (std::vector<T>::size() - 1);
	}
	int AddAt( T& ref, unsigned i )
	{
		if( !ArrayDim() )
			std::vector<T>::resize( i + 1, ref );
		else
			std::vector<T>::insert( std::vector<T>::begin() + i, ref );
		return i;
	}
	long ArrayDim( void ) const
	{
		return (long) std::vector<T>::size();
	}
	int IsEmpty( void )
	{
		return ArrayDim() == 0;
	}
	long GetItemsInContainer( void ) const
	{
		return ArrayDim();
	}
	void Flush( void )
	{
		std::vector<T>::resize(0);
	}
	void Flush( long count_from_end )
	{
		if( count_from_end <= (long) std::vector<T>::size() )
			std::vector<T>::erase( std::vector<T>::end() - count_from_end, std::vector<T>::end() );
	}
	int Find( T& obj );
	int HasMember( T& obj )
	{
		int tmp;
		if( ( tmp = Find(obj) ) == INT_MAX )
			return 0;
		else
			return tmp + 1;
	}
	void Detach( long i )
	{
		if( i >= 0 && i < (long) std::vector<T>::size() )
			std::vector<T>::erase(std::vector<T>::begin() + i);
	}
	void Copy( const MArray<T>& src );
};

template <class T>
int MArray<T>::Find( T& obj )
{
	for( long i = 0; i < ArrayDim(); i++ )
		if( (*this)[ i ] == obj )
			return i;
	return INT_MAX;
}

template <class T>
void MArray<T>::Copy( const MArray<T>& src )
{
	Flush();
	resize( src.ArrayDim() );
	std::copy( src.begin(), src.end(), std::vector<T>::begin() );
}

template <class T> class MIArray : public std::vector<T*>
{
public :
	enum MIArrayShouldDelete
	{
		LeaveItems,
		DeleteItems
	};
protected :
	enum MIArrayShouldDelete should_Delete;
public :
	long	delta;

        MIArray( enum MIArrayShouldDelete should_del, long st, long /*lw*/ = 0, long dl = 0) :
		std::vector<T*>()
	{
		should_Delete = should_del;
		delta = dl;
		std::vector<T*>::resize(0);
		if( !st ) return;
		else
			std::vector<T*>::reserve(st);
	};
        MIArray( long st, long /*lw*/ = 0, long dl = 0 ) :
		std::vector<T*>()
	{
		delta = dl;
		should_Delete = MIArray::DeleteItems;
		if( st )
			std::vector<T*>::reserve( st );
	};
	void Delete( long i )
	{
		if( i >= 0 && i < (long) std::vector<T*>::size() )
			std::vector<T*>::erase(std::vector<T*>::begin() + i);
	}
	void Detach( long i )
	{
		if( i >= 0 && i < (long) std::vector<T*>::size() )
		{
			if( should_Delete == MIArray::DeleteItems )
				delete ItemAt( i );
			std::vector<T*>::erase(std::vector<T*>::begin() + i);
		}
	}
	T*& operator[]( long i )
	{
		if( i >= (long) std::vector<T*>::size() ) std::vector<T*>::resize(i + 1, 0);
		return *(std::vector<T*>::begin() + i);
	}
	T*& ItemAt( long i )
	{
		if( i >= (long) std::vector<T*>::size() ) std::vector<T*>::resize(i + 1, 0);
		return *(std::vector<T*>::begin() + i);
	}
	const T*& operator[]( long i ) const
	{
		return (const T*&)(*(std::vector<T*>::begin() + i));
	}
	const T*& ItemAt( long i ) const
	{
		return (const T*&)(*(std::vector<T*>::begin() + i));
	}
	int Add( T* ptr )
	{
		std::vector<T*>::resize(std::vector<T*>::size() + 1, ptr);
		return (int) (std::vector<T*>::size() - 1);
	}
	int AddAt( T* ptr, unsigned long i )
	{
		if( !ArrayDim() )
			std::vector<T*>::resize( i + 1, ptr );
		else
			std::vector<T*>::insert( std::vector<T*>::begin() + i, ptr );
		return i;
	}
	long ArrayDim( void ) const
	{
		return (long) std::vector<T*>::size();
	}
	int IsEmpty( void )
	{
		return ArrayDim() == 0;
	}
	long GetItemsInContainer( void ) const
	{
		return ArrayDim();
	}
	int Find( T* pobj );
	int HasMember( T* pobj )
	{
		int tmp;
		if( ( tmp = Find(pobj) ) == INT_MAX )
			return 0;
		else
			return tmp + 1;
	}
	void Flush( void )
	{
		if( should_Delete == MIArray::DeleteItems )
			for( long i = 0; i < ArrayDim(); i++ )
				delete ItemAt(i);
		std::vector<T*>::erase(std::vector<T*>::begin(), std::vector<T*>::end());
	}
	void Flush( long count_from_end )
	{
		if( count_from_end )
		{
			if( should_Delete == MIArray::DeleteItems )
				for( long i = ArrayDim() - count_from_end; i < ArrayDim(); i++ )
					delete ItemAt( i );
			std::vector<T*>::erase( std::vector<T*>::end() - count_from_end, std::vector<T*>::end() );
		}
		else
			throw;
	}
	~MIArray( void );
};

template <class T> MIArray<T>::~MIArray( void )
{
	if( should_Delete == MIArray::LeaveItems ) return;
	for( long i = 0; i < ArrayDim(); i++ )
		if( ItemAt(i) ) delete ItemAt(i);
}

template <class T>
int MIArray<T>::Find( T* obj )
{
	for( long i = 0; i < ArrayDim(); i++ )
		if( *(*this)[ i ] == *obj )
			return (int) i;
	return INT_MAX;
}

#endif
