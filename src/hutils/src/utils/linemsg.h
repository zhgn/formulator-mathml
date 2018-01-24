

#if !defined( __HUTILS_LINEMSG_H__ )
#define __HUTILS_LINEMSG_H__

#include "../basexxx.h"
#include <vector>

struct HKLineMessage
{
	QString text;
	unsigned long line;

	HKLineMessage( const HKLineMessage& a )
		: text( a.text )
		, line( a.line )
	{}
	HKLineMessage( const QString& str, unsigned long ln )
		: text( str )
		, line( ln )
	{}
	HKLineMessage& operator=( const HKLineMessage& a )
	{
		text = a.text;
		line = a.line;
		return *this;
	}
};

class HKLineMessageTable
{
protected :
	std::vector<HKLineMessage> m_table;

public :
	HKLineMessageTable()
	{}
	const std::vector<HKLineMessage>& getTable()
	{
		return m_table;
	}
	void setMessage( const QString& str, unsigned long line = 0 )
	{
		m_table.push_back( HKLineMessage( str, line ) );
	}
	int hasMessages()
	{
		return m_table.size();
	}
};

#endif
