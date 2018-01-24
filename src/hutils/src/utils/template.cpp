

#include "HUtils/imessage.h"
#include "template.h"

int HKMatchTemplate::Treate( const QString& src, const QVector<QString>& args )
{
	static const QString mark = __YUNEN_TEMPLATE_MARK;
	static const int delta[ 9 ][ 2 ] = {{0, 0},
										{2, 1},
										{3, 1},
										{4, 1},
										{1, 5},
										{1, 6},
										{1, 0},
										{0, 0}};
	buffer.clear();
	int i, a = 0, cb, state;
	for( i = cb = 0; cb < args.size() && i < src.length(); )
	{
		a = i;
		state = 1;
		while( state && i < src.length() )
		{
			if( src.at(i) == QChar('/') )
				state = delta[ state ][ 0 ];
			else
			{
				if( src.at(i) == QChar('$') )
					state = delta[ state ][ 1 ];
				else
					state = 1;
			}
			i++;
		}
		if( state )
			break;
		else
		{
			buffer.append( src.mid(a, i - mark.length() - a) );
			buffer.append( args[ cb ] );
			cb++;

			state = 1;
			while( i < src.length() )
			{
				if( src.at(i) == QChar('\x0d') )
				{
					state = 2;
					i++;
					continue;
				}
				if( src[ i++ ] == QChar('\x0a') && state == 2 )
				{
					i -= 2;
					break;
				}
				else
					state = 1;
			}
		}
	}

	for( ; i < src.length(); )
	{
		a = i;
		state = 1;
		while( state && (i < src.length()) )
		{
			if( src.at(i) == QChar('/') )
				state = delta[ state ][ 0 ];
			else
			{
				if( src.at(i) == QChar('$') )
					state = delta[ state ][ 1 ];
				else
					state = 1;
			}
			i++;
		}
		if( state )
			break;
		else
		{
			cb++;
			state = 1;
			while( i < src.length() )
			{
				if( src.at(i) == QChar('\x0d') )
				{
					state = 2;
					i++;
					continue;
				}
				if( src.at(i++) == QChar('\x0a') && state == 2 )
				{
					i -= 2;
					break;
				}
				else
					state = 1;
			}
		}
	}
	buffer.append( src.mid(a, i - a) );
	return (cb != args.size()) ? -1 : 0;
}
