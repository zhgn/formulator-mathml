

#if !defined( __FORMULATOR_INCLUDE_FMLEXPORT_H__ )
#define __FORMULATOR_INCLUDE_FMLEXPORT_H__

#if defined( QT_VERSION )
#  ifdef FMLAPI_LIB
#    define FMLAPI_API	Q_DECL_EXPORT
#  else
#    define FMLAPI_API	Q_DECL_IMPORT
#  endif
#elif defined( WIN32 )
#  ifdef FMLAPI_LIB
#    define FMLAPI_API	__declspec(dllexport)
#  else
#    define FMLAPI_API	__declspec(dllimport)
#  endif
#else
#  ifdef FMLAPI_LIB
#    define FMLAPI_API
#  else
#    define FMLAPI_API
#  endif
#endif



#endif // __FORMULATOR_INCLUDE_FMLEXPORT_H__
