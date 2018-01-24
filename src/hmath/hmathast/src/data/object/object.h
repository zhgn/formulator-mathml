

#ifndef __PARSEDSR_DATA_MMD_OBJECT_H__
#define __PARSEDSR_DATA_MMD_OBJECT_H__

#include "HMathBS/iarray.h"
#include "HMathBS/inumber.h"
#include "../../hmathast_global.h"
#include "../smbtbllink.h"

///////////////////////////////////////////////////////////////////////////////

class __HMATHLNGDLL__ MMD_Object
{
protected:
	CDsrDataType_Node *m_type;
	CParseDsrSymbolTable* m_smbtable;
public:
	MMD_Object( CParseDsrSymbolTable& _smbtable, CDsrDataType_Node *_type = 0 );
	MMD_Object( CParseDsrSymbolTable& _smbtable, enum CDsrDataTypes _type );
	MMD_Object( const MMD_Object& o );
	MMD_Object operator=( const MMD_Object& o );
	CParseDsrSymbolTable& getSmbTable( void ) const;
	void setDataType( CDsrDataType_Node *tp );
	CDsrDataType_Node* getDataType( void ) const;
	enum CDsrDataTypes getType( void );
	virtual QString getTypeName( void );
	virtual MMD_Object* copy( const MMD_Object *src );
	virtual ~MMD_Object( void );
	virtual QString getTextView( void );
	virtual QString getFormulatorView( void );
	virtual QString getMmlView( void );

	int operator == ( MMD_Object& a ) const 
	{
		return *m_type == *(a.m_type);
	}
};

///////////////////////////////////////////////////////////////////////////////

class __HMATHLNGDLL__ MMD_ObjectHeap : MIArray<MMD_Object>
{
public:
	MMD_ObjectHeap( void );
	~MMD_ObjectHeap( void );
};

inline
MMD_ObjectHeap::MMD_ObjectHeap( void ) :
	MIArray<MMD_Object>( MIArray<MMD_Object>::LeaveItems, 256, 0, 256 )
{}

///////////////////////////////////////////////////////////////////////////////

#endif
