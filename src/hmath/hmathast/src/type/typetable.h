

#if !defined( __PARSEDSR_OPERATOR_TYPETABLE_H__ )
#define __PARSEDSR_OPERATOR_TYPETABLE_H__

#include "HUtils/iautoheap.h"
#include "typedsr.h"

class __HMATHLNGDLL__ CDsrDataTypeTable : public MIArray<CDsrDataType_Node>
{
protected:
	long reserved_idx[ DSRDATA_TYPE_LAST ];

	CDsrDataType_Node* __cloneDataTypeNode_FUNCTION( CDsrDataType_Node *clone_node );
	CDsrDataType_Node* __cloneDataTypeNode_COMPOSITION( CDsrDataType_Node *clone_node );
	CDsrDataType_Node* __cloneDataTypeNode_VECTOR( CDsrDataType_Node *clone_node );
	CDsrDataType_Node* __cloneDataTypeNode_SET( CDsrDataType_Node *clone_node );
	CDsrDataType_Node* __cloneDataTypeNode_POLYNOM( CDsrDataType_Node *clone_node );
	CDsrDataType_Node* __cloneDataTypeNode_RATIONAL_FUN( CDsrDataType_Node *clone_node );

public:
	CDsrDataTypeTable( void );
	~CDsrDataTypeTable( void );
	void Init( void );
	int Add( CDsrDataType_Node *n );
	long getTypeRecordIdx( enum CDsrDataTypes tp );
	CDsrDataType_Node* getTypeRecord( enum CDsrDataTypes tp );
	CDsrDataType_Node* makeDataTypeNode( CDsrDataType_Node *node );
	CDsrDataType_Node* makeDataTypeNode( enum CDsrDataTypes tp );
	CDsrDataType_Node* cloneDataTypeNode( CDsrDataType_Node *clone_node );
};

inline
long CDsrDataTypeTable::getTypeRecordIdx( enum CDsrDataTypes tp )
{
	return reserved_idx[ tp ];
}

inline
CDsrDataType_Node* CDsrDataTypeTable::getTypeRecord( enum CDsrDataTypes tp )
{
	return at( getTypeRecordIdx( tp ) );
}

#endif
