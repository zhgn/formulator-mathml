

#include "fdedraw_qt.h"
#include "drawengine.h"

/////////////////////////////////////////////////////////////////////
//
//
//
//
//
/////////////////////////////////////////////////////////////////////

CFmlDrawEngine::CFmlDrawEngine( QPaintDevice * /*device*/ )
	: m_printing( false )
	, m_states()
{
}

CFmlDrawEngine::CFmlDrawEngine()
	: m_printing( false )
	, m_states()
{
}

/////////////////////////////////////////////////////////////////////

CFmlDrawEngine::~CFmlDrawEngine( void )
{
}

/////////////////////////////////////////////////////////////////////
//
//
//
//
//
/////////////////////////////////////////////////////////////////////

static enum FmlDrawEngineTypes g_fmlDrawEngineType = FmlDrawEngine_None;

/////////////////////////////////////////////////////////////////////

quint32 StartUpFDE( enum FmlDrawEngineTypes type )
{
	g_fmlDrawEngineType = type;

	switch( g_fmlDrawEngineType )
	{
	case FmlDrawEngine_Qt:
		return 1;
	case FmlDrawEngine_Gdi:
	case FmlDrawEngine_GgiPlus: 
	case FmlDrawEngine_OpenLG: 
	case FmlDrawEngine_DirectDraw: 
	case FmlDrawEngine_Direct3D9: 
	case FmlDrawEngine_Direct3D10: 
		return 0;
	default:
		break;
	}

	return 0;
}

quint32 ShutDownFDE( void )
{
	switch( g_fmlDrawEngineType )
	{
	case FmlDrawEngine_Qt:
		return 1;
	case FmlDrawEngine_Gdi:
	case FmlDrawEngine_GgiPlus: 
	case FmlDrawEngine_OpenLG: 
	case FmlDrawEngine_DirectDraw: 
	case FmlDrawEngine_Direct3D9: 
	case FmlDrawEngine_Direct3D10: 
		return 0;
	default:
		break;
	}

	return 0;
}

/////////////////////////////////////////////////////////////////////

CFmlDrawEngine* CreateFDE( QPaintDevice *device )
{
	if( g_fmlDrawEngineType == FmlDrawEngine_None ) return NULL;

	switch( g_fmlDrawEngineType )
	{
	case FmlDrawEngine_Qt: 
		return new CFmlDrawEngineQt( device );
	case FmlDrawEngine_Gdi:
	case FmlDrawEngine_GgiPlus: 
	case FmlDrawEngine_OpenLG: 
	case FmlDrawEngine_DirectDraw: 
	case FmlDrawEngine_Direct3D9: 
	case FmlDrawEngine_Direct3D10: 
		return NULL;
	default:
		break;
	}

	return NULL;
}

CFmlDrawEngine* CreateFDE( QPainter& painter )
{
	if( g_fmlDrawEngineType == FmlDrawEngine_None ) return NULL;

	switch( g_fmlDrawEngineType )
	{
	case FmlDrawEngine_Qt: 
		return new CFmlDrawEngineQt( painter );
	case FmlDrawEngine_Gdi:
	case FmlDrawEngine_GgiPlus: 
	case FmlDrawEngine_OpenLG: 
	case FmlDrawEngine_DirectDraw: 
	case FmlDrawEngine_Direct3D9: 
	case FmlDrawEngine_Direct3D10: 
		return NULL;
	default:
		break;
	}

	return NULL;
}

void DeleteFDE( CFmlDrawEngine*& pFde )
{
	if( pFde != NULL )
	{
		delete pFde;
		pFde = NULL;
	}
}

/////////////////////////////////////////////////////////////////////
