

#if !defined( __COMMON_LIMAUTO_H__ )
#define __COMMON_LIMAUTO_H__

#include <QDataStream>
#include "../basexxx.h"

// class LAuto
// ~~~~~ ~~~~~
class HUTILS_EXPORT LAuto
{
	
protected :

	qint32	CurrentState;	// ������� ��������� ��������� ��������
	qint32	PrevState;		// ���������� ��������� ��������� ��������
	qint32	nStates,		// ���������� ��������� ��������� ��������
			nAlphabet;		// ���������� �������� �������� ��������
	long*	Jmp;			// ������� ���������
	long*	EndStates;		// ������ ������ ���������
							// ��������� ��������� ��������
	qint32	read;			// ���������� ��������, �������� ��������
							// ��������� � ��������� ���
	QChar	character;		// ������� ������ �� �����
	
protected :
	
	virtual	void Deeds( void );						// ���������� ��������, ����������� ��� 
													// �������� ����� �����������
	virtual	long What( const QChar nextS ) = 0;		// ��������������� ������� ��������
													// �������� � ������ ������� ���������
	long	GetPreviousState( void );				// ���������� ���������

	void FreeMemory( void );
	
public :
	
	LAuto( void );
	LAuto( long anSt, long anAB, long* aJmp, long* aEndStates );
	virtual ~LAuto( void );
	
	int Analisys( const QStringRef& aText );	// ������� ���� ������� �������� ������
	long GetRead( void );					// ���������� ��������, �������� � ��������� ���
	void Reset( void );

	int ReadFile( QString path );
	int WriteFile( QString path );

	HUTILS_EXPORT friend QDataStream& operator << ( QDataStream& ar, const LAuto& lp );
	HUTILS_EXPORT friend QDataStream& operator >> ( QDataStream& ar, LAuto& lp );
};


inline
LAuto::LAuto( long anSt, long anAB, long* aJmp, long* aEndStates )
//     ~~~~~
	: CurrentState( 1 ), PrevState( 0 ), nStates( anSt ), nAlphabet( anAB ), read( 0 ), character( 0 )
{
	Jmp = new long[ nAlphabet * nStates ];
	memcpy( Jmp, aJmp, sizeof( long ) * nAlphabet * nStates );
	EndStates = new long[ nStates ];
	memcpy( EndStates, aEndStates, sizeof( long ) * nStates );
}

inline
LAuto::LAuto( void )
//     ~~~~~
	: CurrentState( 1 ), PrevState( 0 ), nStates( 0 ),
		nAlphabet( 0 ), read( 0 ), character( 0 )
{
	Jmp = 0;
	EndStates = 0;
}

inline
long LAuto::GetPreviousState( void )
//              ~~~~~~~~~~~~~~~~
{
	return PrevState;
}

inline
void LAuto::Deeds( void )
//          ~~~~~
{}

inline
long LAuto::GetRead( void )
//              ~~~~~~~
{
	return read;
}

inline
LAuto::~LAuto( void )
//     ~~~~~~
{
	FreeMemory();
}

inline
void LAuto::Reset( void )
{
	CurrentState = 1;
	PrevState = 0;
	read = 0;
	character = 0;
}

#endif
