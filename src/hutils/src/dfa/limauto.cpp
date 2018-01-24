

#include <QFile>
#include "limauto.h"

//#include <io.h>
//#include <fcntl.h>
//#include <sys\stat.h>

void LAuto::FreeMemory()
{
	if( Jmp )
	{
		delete[] Jmp;
		Jmp = 0;
	}
	if( EndStates )
	{
		delete[] EndStates;
		EndStates = 0;
	}
}

QDataStream& operator >> ( QDataStream& ar, LAuto& lp )
{
	ar >> lp.CurrentState >> lp.PrevState >> lp.nStates >> lp.nAlphabet >> lp.read;
	lp.FreeMemory();
	lp.Jmp = new long[ lp.nAlphabet * lp.nStates ];
	lp.EndStates = new long[ lp.nStates ];
	qint32 v;
	long i;
	for( i = 0; i < lp.nStates * lp.nAlphabet; i++ )
	{
		ar >> v;
		lp.Jmp[ i ] = v;
	}
	for( i = 0; i < lp.nStates; i++ )
	{
		ar >> v;
		lp.EndStates[ i ] = v;
	}
	return ar >> lp.character;
}

QDataStream& operator << ( QDataStream& ar, const LAuto& lp )
{
	ar << lp.CurrentState << lp.PrevState << lp.nStates << lp.nAlphabet << lp.read;
	long i;
	for( i = 0; i < lp.nStates * lp.nAlphabet; i++ )
		ar << (qint32) lp.Jmp[ i ];
	for( i = 0; i < lp.nStates; i++ )
		ar << (qint32) lp.EndStates[ i ];
	return ar << lp.character;
}

int LAuto::ReadFile( QString path )
{
	QFile file( path );
	if( !file.open(QIODevice::ReadOnly) ) return -1;
	QDataStream ar( &file );
	ar >> *this;
	file.close();
	return 0;
}

int LAuto::WriteFile( QString path )
{
	QFile file( path );
	if( !file.open(QIODevice::WriteOnly) ) return -1;
	QDataStream ar( &file );
	ar << *this;
	file.close();
	return 0;
}

int LAuto::Analisys( const QStringRef& aText )
//         ~~~~~~~~
{
	long pos, resState;
	for( read = 0; ; read++ )
	{
		Deeds();
		if( read >= aText.size() ) break;
		character = aText.at(read);
		pos = What( character );
		if( pos == 0 ) break;
		if( ( resState = Jmp[ ( CurrentState - 1 ) * nAlphabet + ( pos - 1 ) ] ) == 0 )
			break;
		else
		{
			PrevState = CurrentState;
			CurrentState = resState;
		}
	}
	return EndStates[ CurrentState - 1 ];  //Is CurrentState an endable state
}
