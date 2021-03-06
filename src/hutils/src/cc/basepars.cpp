

#include "basepars.h"

//////////////////////////////////////////////////////////////////////

ActionT* createActionT( LRTDATA *alrt )
{
	if( strcmp( LRTABLE_HEADER, alrt->Header ) ) return 0;

	ActionT *pRes = new ActionT();
	pRes->TableTNT = alrt->Terminals + alrt->NonTerminals;
	pRes->TableStates = alrt->StatesQuant;
	pRes->RulesQuant  = alrt->RulesQuant;
	pRes->NonTerms  = ( LEXEM* )(( char* )alrt + sizeof( struct LRTDATA ));
	pRes->RuleLen   = ( unsigned short* )(pRes->NonTerms + pRes->RulesQuant);
	ActionItem *allocated = ( ActionItem* )(pRes->RuleLen + pRes->RulesQuant);
	pRes->Table = new PtrActionItem[ pRes->TableStates ];

	unsigned i, j;
	for( i = 0; i < pRes->TableStates; i++, allocated += pRes->TableTNT )
		pRes->Table[ i ] = allocated;

	unsigned short CtrlSum = 0;
	for( i = 0; i < pRes->TableStates; i++ )
	{
		for( j = 0; j < pRes->TableTNT; j++ )
			CtrlSum += pRes->Table[ i ][ j ].hash();
	}

	if( CtrlSum != alrt->CtrlSum )
	{
		delete pRes;
		return 0;
	}

	return pRes;
}

//////////////////////////////////////////////////////////////////////

BaseParser::~BaseParser( void )
{
	if( scaner ) delete scaner;
	if( actions ) delete actions;
	if( error ) delete error;
	if( warning ) delete warning;
}

const QString& BaseParser::GetLexError( void )
{
	static const QString LexError( _T("Unknown symbol") );
	return LexError;
}

BaseParser::ShouldExit BaseParser::TryToSweep( void )
{
	return BaseParser::Exit;
}

void BaseParser::NewLex( Source& /*aSource*/ )
{
	scaner = 0;
}

void BaseParser::BeforeMake( void ){}
void BaseParser::AfterMake ( void ){}
void BaseParser::GenCode( unsigned ){}
void BaseParser::CheckDeed ( ActionItem * /*act*/ ){}

unsigned BaseParser::Make( void )
{
	unsigned short RuleNumber, state = 1, Status = 0;
	Lexem Smb, LexStorage, NonTermStorage; 

	BeforeMake();
	LexPoint = StatePoint = 0;
	LexStack.clear();
	StateStack.clear();
	StatePush( 1 );

	for(;;) 
	{
		switch( Status )
		{
		case 0 :
			LexStorage = Smb = scaner->NextLexem();
			if( LexStorage.LexType == ( LEXEM )0 )
			{
				SetError( GetLexError(), GetLine() );
				continue;
			}
			break;
		case 1 :
			Smb = LexStorage;
			Status = 0;
			break;
		case 2 :
			Status = 1;
			Smb = NonTermStorage;
			break;
		}
		ActionItem *act = (*actions)( state, Smb.LexType );
		CheckDeed( act );
		switch( act->select )
		{
		case _Shift :
			StatePush( state = act->value );
			LexPush( Smb );
			break;
		case _Reduce :
			RuleNumber = act->value;
			GenCode( RuleNumber );
			NonTermStorage.LexType = actions->NonTerms[ RuleNumber - 1 ];
			if( actions->RuleLen[ RuleNumber - 1 ] )
			{
				NonTermStorage.line = LexStack[ LexPoint - actions->RuleLen[ RuleNumber - 1 ] ].GetLine();
				NonTermStorage.col  = LexStack[ LexPoint - actions->RuleLen[ RuleNumber - 1 ] ].GetCol();
			}
			else
			{
				NonTermStorage.line = GetLine();
				NonTermStorage.col  = GetCol();
			}
			Pop( actions->RuleLen[ RuleNumber - 1 ] );
			Status = 2;
			state = TopState();
			break;
		case _Halt :
			if( IsError() )
			{
				SetSemanticError();
				return 0xFFFF;
			}
			else
			{  
				AfterMake();
				return 0;
			}  
		case _Error :
			SetSemanticError();
			SetError( *act, GetLine() );
			if( TryToSweep() == BaseParser::Exit )
				return 0xFFFF;
			break;
		}
	}
}

//////////////////////////////////////////////////////////////////////
