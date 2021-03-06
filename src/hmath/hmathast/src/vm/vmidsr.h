

#if !defined( __PARSEDSR_VMI_H__ )
#define __PARSEDSR_VMI_H__

#include "HUtils/ihkstring.h"
#include "HUtils/ihkarray.h"
#include "HUtils/ihkflag.h"
#include "../hmathast_global.h"
#include "../symbol/symbol_table_dsr.h"

#define VM_Dsr_MODE__TEXT			0
#define VM_Dsr_MODE__FORMULATOR		1
#define VM_Dsr_MODE__BINCODE		2

#define VM_Dsr_FLAG__JUST_AFTER_EOL	0x00000001

class __HMATHLNGDLL__ VM_Dsr
{
protected:
	long mode;							// mode of printing
	QString text_buffer;					// where to print textual information
	CParseDsrSymbolTable*& ptr_symbol_table;	// symbol table (id, specials, keywords)
	HKLongFlag modifier;				// misc. flags

public:
	VM_Dsr( CParseDsrSymbolTable*& _ptr_symbol_table, long init_mode = VM_Dsr_MODE__TEXT );
	virtual ~VM_Dsr();

	CParseDsrSymbolTable& getSmbTable( void );
	void setTextBuffer( QString src = QString("") );
	const QString& getTextBuffer( void );

	// AST-to-Code API
	virtual void Nop( long line, long level );
	virtual void ConstInt( long value, long line, long level );
	virtual void ConstReal( double value, QString aspect, long line, long level );
	virtual void ConstString( QString value, long line, long level );
	virtual void SymbolTableItem( long id, long line, long level );
	virtual void SymbolTableItem( CParseDsrSymbol *smb, long line, long level );
	virtual void SeparatorGrammarIndex( long id, long line, long level );
	virtual void Op( long id, long line, long level );
	virtual void Remark( QString value, long line, long level );
	virtual void Blank( QString value, long line, long level );
	virtual void EOL( QString value, long line, long level );
	virtual void Text( QString value, long line, long level );

	virtual void LeftRoundBracket( long line, long level );
	virtual void RightRoundBracket( long line, long level );
	virtual void LeftSquareBracket( long line, long level );
	virtual void RightSquareBracket( long line, long level );
	virtual void LeftCurlyBracket( long line, long level );
	virtual void RightCurlyBracket( long line, long level );

protected:
	QString SymbolTableItem2String( long id );
	QString SeparatorGrammarIndex2String( long id );
	QString Op2String( long id );

	// Printing
	virtual void PrintTAB( long line, long level );
	virtual void PrintEOL( long line, long level );
	virtual void PrintText( QString value, long line, long level );
	virtual void PrintText( long value, long line, long level );
	virtual void PrintText( double value, long line, long level );
};

/////////////////////////////////////////

#endif
