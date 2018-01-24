

#if !defined( __COMMON_LONGFLAG_H__ )
#define __COMMON_LONGFLAG_H__

#include <QDataStream>

template<class T> class HKFlag
{
protected:
	T __flag_value;
public:
	HKFlag( T init = 0 )
	{	resetFlag( init );				}
	T isSetFlag( T flags ) const
	{	return __flag_value & flags;	}
	void setFlag( T flags )
	{	__flag_value |= flags;			}
	void clearFlag( T flags )
	{	__flag_value &= ~flags;			}
	void resetFlag( T init = 0 )
	{	__flag_value = init;			}
	T getValue( void ) const
	{	return __flag_value;			}
	void setValue( T s )
	{	__flag_value = s;				}

	T operator = ( const T v )
	{	return __flag_value = v;	}
	T operator = ( const HKFlag& flag )
	{	return __flag_value = flag.__flag_value;	}
	int operator == ( const HKFlag& flag )
	{	return __flag_value == flag.__flag_value;	}
	int operator != ( const HKFlag& flag )
	{	return __flag_value != flag.__flag_value;	}
};

typedef HKFlag<qint32>					HKLongFlag;

inline
QDataStream& operator << ( QDataStream& ar, const HKLongFlag& lp )
{
	return ar << lp.getValue();
}

inline
QDataStream& operator >> ( QDataStream& ar, HKLongFlag& lp )
{
	qint32 v;
	QDataStream& ret = ar >> v;
	lp.setValue( v );
	return ret;
}

typedef HKFlag<qint16>					HKShortFlag;

inline
QDataStream& operator << ( QDataStream& ar, const HKShortFlag& lp )
{
	return ar << lp.getValue();
}

inline
QDataStream& operator >> ( QDataStream& ar, HKShortFlag& lp )
{
	qint16 v;
	QDataStream& ret = ar >> v;
	lp.setValue( v );
	return ret;
}

#endif
