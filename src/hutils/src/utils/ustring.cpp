

#include <cstdlib>
#include "ustring.h"

QString generateTextSeed( unsigned long nSize )
{
    static QString bricks("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
    QString sum("");
    long idx;
    double randValue;
    for( unsigned long i = 0; i < nSize; i++ )
    {
        randValue = ((double) std::rand()) / RAND_MAX;
        idx = long(randValue * (bricks.length() - 1));
        sum.append( bricks.at(idx) );
    }
    return sum;
}

QString hstr_escape_blank( const QString& src )
{
    QString ret;
    for( long i = 0; i < src.length(); i++ )
    {
        switch( src.at(i).toLatin1() )
        {
        case _T('\t'):
            ret += "\\t";
            break;
        case _T('\r'):
            ret += "\\r";
            break;
        case _T('\n'):
            ret += "\\n";
            break;
        default:
            ret.append( src.at(i) );
        }
    }
    return ret;
}

QString hstr_escape( const QString& src )
{
    QString ret;
    for( long i = 0; i < src.length(); i++ )
    {
        switch( src.at(i).toLatin1() )
        {
        case _T('\\'):
        case _T('\''):
        case _T('\"'):
            ret.append( QChar('\\') );
            break;
        }
        ret.append( src.at(i) );
    }
    return ret;
}

HUTILS_EXPORT
const QString& hstr_escape_htmlamp( const QString& src )
{
    static const int ampstr_len = 5;
    static const QString ampstr = _T("&amp;");
    static QString ret;

    ret = "";
    for( long offs = 0, fnd = 0; offs < src.length(); )
    {
        fnd = src.indexOf( ampstr, offs );
        if( fnd == -1 )
        {
            ret.append( src.mid(offs, src.length() - offs) );
            break;
        }
        ret.append( src.mid(offs, fnd - offs) );
        ret.append( QChar('&') );
        offs = fnd + ampstr_len;
    }
    return ret;
}

HUTILS_EXPORT
void hstr_0a_to_0d0a( QString& str )
{
    // replace "\n" -> "\r\n"
    long pos = 0;
    while( (pos = str.indexOf( '\n', pos )) != -1 )
    {
        if( pos && (pos - 1 < str.length()) && str.at(pos - 1) != '\r' )
        {
            str.insert( pos, "\r" );
            pos += 2;
        }
        else
        {
            pos++;
        }
    }
}

HUTILS_EXPORT
void hstr_del_redundant_0d0a( QString& str )
{
    // replace "\r\n\r\n" -> "\r\n"
    long pos = 0;
    while( (pos = str.indexOf( "\r\n\r\n", pos )) != -1 )
        str.remove( pos, 2 );
}

/////////////////////////////////////////////////////////////////////////////
