

#if !defined( __HUTILS_HTML_COLOR_H__ )
#define __HUTILS_HTML_COLOR_H__

#include "../basexxx.h"

/////////////////////////////////////////////////////////////////////////////

#define HTML_COLORS_NUMBER 17
#define HK_HTML_COLOUR_ROW				5
#define HK_HTML_COLOUR_COL				8

HUTILS_EXPORT int html_color_name2rgb( const QString& name, unsigned short& r, unsigned short& g, unsigned short& b );
HUTILS_EXPORT QString html_rgb2color_name( unsigned short& r, unsigned short& g, unsigned short& b );
HUTILS_EXPORT unsigned long* get_htmlColorValue_Ex();
HUTILS_EXPORT const QString* get_hk_htmlColorName_Ex();

/////////////////////////////////////////////////////////////////////////////

#endif
