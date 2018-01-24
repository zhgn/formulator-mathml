

#if !defined( __COMMON_UTILS_TEMPLATE_H__ )
#define __COMMON_UTILS_TEMPLATE_H__

#include <QVector>

#include "HUtils/ihkstring.h"
#include "../hutils_global.h"

#define __YUNEN_TEMPLATE_MARK	_T("///$$$")

// class HKMatchTemplate
// ~~~~~ ~~~~~~~~~~
//
class HUTILS_EXPORT HKMatchTemplate
{
protected :
	QString buffer;

public :
	HKMatchTemplate() {}
	QString& getBuffer() { return buffer; }
	int Treate( const QString& src, const QVector<QString>& args );
};

#endif
