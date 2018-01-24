

#if !defined( __PARSEDSR_SYMBOL_SMBRECORD_H__ )
#define __PARSEDSR_SYMBOL_SMBRECORD_H__

#include "../hmathast_global.h"
#include "HUtils/ihkmap.h"
#include "HUtils/ihkstring.h"
#include "../type/typedsr.h"
#include "../operator/operator.h"

///////////////////////////////////////////////////////////////////////////////

enum CDsrSymbolTableRecordType
{
	SMBTABLE_TYPE_NONE = 0,
	SMBTABLE_TYPE_KEYWORD,
	SMBTABLE_TYPE_VARIABLE,
	SMBTABLE_TYPE_FUNCTION,
	SMBTABLE_TYPE_FORMULA
};

class CParseDsrSymbolTable;
class __HMATHLNGDLL__ CParseDsrSymbol
{
public:
	QString name;
	enum CDsrSymbolTableRecordType smb_record_type;
	CDsrDataType_Node *data_type;
	long param1;	// reserved for fun rec
	long param2;	// reserved-1 for var rec
	long param3;	// reserved-2 for var rec

public:
	CParseDsrSymbol( void )
	{
		name = _T("");
		data_type = 0;
		smb_record_type = SMBTABLE_TYPE_NONE;
		param1 = param2 = param3 = 0;
	}
	~CParseDsrSymbol( void )
	{}
	CParseDsrSymbol( QString _name, enum CDsrSymbolTableRecordType _type = SMBTABLE_TYPE_VARIABLE, CDsrDataType_Node *_data_type = 0 )
	{
		name = _name;
		smb_record_type = _type;
		data_type = _data_type;
		param1 = param2 = param3 = 0;
	}
	CDsrDataType_Node* getDataType( void )
	{
		return data_type;
	}
	void setDataType( CDsrDataType_Node *_data_type )
	{
		data_type = _data_type;
	}
	int is_predefined( void )
	{
		return param1 > FUNCTION_STD_NONE && param1 < FUNCTION_STD_LAST;
	}
	int hasSpecialName( void )
	{
		return name.length() && (name[ 0 ] == _T('@'));
	}
	int isVariable( void )
	{
		return smb_record_type == SMBTABLE_TYPE_VARIABLE;
	}
	int isFunction( void )
	{
		return smb_record_type == SMBTABLE_TYPE_FUNCTION;
	}
	long getArgNumber( long no = 0 );
	long getResNumber( long no = 0 );
	
	void debugPrint( QString& dest, CParseDsrSymbolTable *smbtable );
};

///////////////////////////////////////////////////////////////////////////////

#endif
