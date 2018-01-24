

#include "HKMap.h"

HKStringMap::HKStringMap( void )
	: HKMap<QString,QString>()
{
}

HKStringMap::HKStringMap( const HKStringMap& x )
	: HKMap<QString, QString>( x )
{
}

HKStringMap::~HKStringMap( void )
{
}

//////////////////////////////////////////////////////////////////////
