

#ifndef FMLCORE_GLOBAL_H
#define FMLCORE_GLOBAL_H

#include <qglobal.h>

#ifndef FML_STATIC_LINK
#ifdef FMLCORE_LIB
# define __YUNEN_FORMULIB__ Q_DECL_EXPORT
#else
# define __YUNEN_FORMULIB__ Q_DECL_IMPORT
#endif
#else
# define __YUNEN_FORMULIB__
#endif

#endif // FMLCORE_GLOBAL_H
