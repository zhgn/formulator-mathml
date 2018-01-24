

#if !defined( __COMMON_UTILS_AUTOHEAP_H__ )
#define __COMMON_UTILS_AUTOHEAP_H__

#include "HUtils/ihkmap.h"

#define HU_DEFAULT_RTHEAP2FREE_SIZE	128

template <class T> class HU_Heap2Free
{
protected:
	HKMap<T*, long>	m_map;

public :
	MIArray<T> ptr_list;

	HU_Heap2Free( int delete_on_desctruct = 1, long scb = HU_DEFAULT_RTHEAP2FREE_SIZE )
		: ptr_list( delete_on_desctruct ? MIArray<T>::DeleteItems : MIArray<T>::LeaveItems, scb, 0, scb )
	{
	}
	~HU_Heap2Free( void )
	{
	}

	unsigned long Heap2FreeDim( void )
	{
		return ptr_list.ArrayDim();
	}
	void*& Get( unsigned i )
	{
		return ptr_list[ i ];
	}

	void Free( void );
	void Add2List( HU_Heap2Free& to_add );
	T*& Add2List( T*& ptr_to_list );
};

template <class T>
T*& HU_Heap2Free<T>::Add2List( T*& ptr_to_list )
{
	if( m_map.find( ptr_to_list ) == m_map.end() )
		m_map[ ptr_to_list ] = ptr_list.Add( ptr_to_list );
	return ptr_to_list;
}

template <class T>
void HU_Heap2Free<T>::Add2List( HU_Heap2Free& to_add )
{
	for( unsigned i = 0; i < to_add.Heap2FreeDim(); i++ )
		Add2List( to_add.Get( i ) );
}

template <class T>
void HU_Heap2Free<T>::Free( void )
{
	for( unsigned i = 0; i < ptr_list.ArrayDim(); i++ )
	{
		if( ptr_list[ i ] )
		{
			delete ptr_list[ i ];
			ptr_list[ i ] = 0;
		}
	}
	ptr_list.Flush();
}

#endif
