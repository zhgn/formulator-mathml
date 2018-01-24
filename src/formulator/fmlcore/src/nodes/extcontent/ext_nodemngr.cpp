

#include <QDir>
#include "HUtils/iloadimage.h"
#include "../../settings/options.h"
#include "../node.h"
#include "ext_nodemngr.h"
#include "ext_node.h"
#include "extc_classid.h"

/////////////////////////////////////////////////////////////////////////////

CExtNode* CreateExtNode( long externalNodeClassID, void *pData )
{
	switch( externalNodeClassID )
	{
	case EXTNODECONTENT_ID_TEST:
		{
			CExtNodeContent_Test *_obj = new CExtNodeContent_Test();
			_obj->Init( pData );

			CExtNode *pNewNode = new CExtNode();
			pNewNode->setContent( _obj );

			return pNewNode;
		}
		break;
	case EXTNODECONTENT_ID_IMG:
		{
			CExtNodeContent_Image *_obj = new CExtNodeContent_Image();
			_obj->Init( pData );

			CExtNode *pNewNode = new CExtNode();
			pNewNode->setContent( _obj );

			return pNewNode;
		}
		break;
	default:
		break;
	}
	return NULL;
}

/////////////////////////////////////////////////////////////////////////////

void* PrepareExtNodeData( long extNodeClasssID, const QString& strImgPath, const QString& strDocPath )
{
	switch( extNodeClasssID )
	{
	case EXTNODECONTENT_ID_TEST:
		break;

	case EXTNODECONTENT_ID_IMG:
		{
			QString strPathName = _T("");
			if( strImgPath != NULL )
			{
				strPathName = strImgPath;
			}
			else
			{
				int iRet = ::LoadImagePath( strPathName );
				if( iRet == -1 || strPathName == _T( "" ) )
					return NULL;
			}

			if( strDocPath.length() > 0 )
				strPathName = QDir(strDocPath).relativeFilePath(strPathName);
			return new CExtNodeContent_Image_Data( 
				EXTNODECONTENT_ID_IMG__FLAG_ATTACHED, strPathName );
		}
		break;

	default:
		break;
	}
	return NULL;
}

/////////////////////////////////////////////////////////////////////////////
