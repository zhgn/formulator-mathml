

#include "HUtils/iustring.h"
#include "htmlcolor.h"

/////////////////////////////////////////////////////////////////////////////

static QString __hk_htmlColorName[ HTML_COLORS_NUMBER ] =
{
	_T("black"), _T("green"), _T("silver"), _T("lime"),
	_T("gray"), _T("olive"), _T("white"), _T("yellow"),
	_T("maroon"), _T("navy"), _T("red"), _T("blue"),
	_T("purple"), _T("teal"), _T("fuchsia"), _T("aqua"), 
	_T("orange")
};

static unsigned char __hk_htmlColorValue[ HTML_COLORS_NUMBER ][ 3 ] =
{
	{0x00, 0x00, 0x00},	{0x00, 0x80, 0x00},	{0xC0, 0xC0, 0xC0},	{0x00, 0xFF, 0x00},
	{0x80, 0x80, 0x80},	{0x80, 0x80, 0x00},	{0xFF, 0xFF, 0xFF},	{0xFF, 0xFF, 0x00},
	{0x80, 0x00, 0x00},	{0x00, 0x00, 0x80},	{0xFF, 0x00, 0x00},	{0x00, 0x00, 0xFF},
	{0x80, 0x00, 0x80},	{0x00, 0x80, 0x80},	{0xFF, 0x00, 0xFF},	{0x00, 0xFF, 0xFF}, 
	{0xFF, 0xA0, 0x00}
};

/////////////////////////////////////////////////////////////////////////////

int html_color_name2rgb( const QString& name, unsigned short& r, unsigned short& g, unsigned short& b )
{
	for( long i = 0; i < HTML_COLORS_NUMBER; i++ )
		if( !html_strcmp( __hk_htmlColorName[ i ], name ) )
		{
			r = __hk_htmlColorValue[ i ][ 0 ];
			g = __hk_htmlColorValue[ i ][ 1 ];
			b = __hk_htmlColorValue[ i ][ 2 ];
			return 0;
		}

	return -1;
}

QString html_rgb2color_name( unsigned short& r, unsigned short& g, unsigned short& b )
{
	for( long i = 0; i < HTML_COLORS_NUMBER; i++ )
	{
		if( r == __hk_htmlColorValue[ i ][ 0 ] && 
			g == __hk_htmlColorValue[ i ][ 1 ] &&
			b == __hk_htmlColorValue[ i ][ 2 ] )
			return __hk_htmlColorName[ i ];
	}

	return "";
}

/////////////////////////////////////////////////////////////////////////////


#define HK_RGB( r, g, b )	((unsigned long)(((unsigned char)(r)|((unsigned short)((unsigned char)(g))<<8))|(((unsigned long)(unsigned char)(b))<<16)))


static unsigned long __hk_htmlColorValue_Ex[ HK_HTML_COLOUR_ROW * HK_HTML_COLOUR_COL ] =
{
	HK_RGB( 0x00, 0x00, 0x00 ),
	HK_RGB( 0xA0, 0x40, 0x00 ),
	HK_RGB( 0x40, 0x40, 0x00 ),
	HK_RGB( 0x00, 0x40, 0x00 ),
	HK_RGB( 0x00, 0x40, 0x64 ),
	HK_RGB( 0x00, 0x00, 0x80 ),
	HK_RGB( 0x40, 0x40, 0xA0 ),
	HK_RGB( 0x40, 0x40, 0x40 ),

	HK_RGB( 0x80, 0x00, 0x00 ),
	HK_RGB( 0x00, 0xA5, 0x00 ),
	HK_RGB( 0x80, 0x80, 0x00 ),
	HK_RGB( 0x00, 0x80, 0x00 ),
	HK_RGB( 0x00, 0x80, 0x80 ),
	HK_RGB( 0x00, 0x00, 0xFF ),
	HK_RGB( 0x64, 0x64, 0xA0 ),
	HK_RGB( 0x80, 0x80, 0x80 ),

	HK_RGB( 0xFF, 0x00, 0x00 ),
	HK_RGB( 0xFF, 0xA0, 0x00 ),
	HK_RGB( 0xA0, 0xD0, 0x00 ),
	HK_RGB( 0x40, 0xA0, 0x64 ),
	HK_RGB( 0x40, 0xD0, 0xD0 ),
	HK_RGB( 0x40, 0x64, 0xFF ),
	HK_RGB( 0x80, 0x00, 0x80 ),
	HK_RGB( 0x96, 0x96, 0x96 ),

	HK_RGB( 0xFF, 0x00, 0xFF ),
	HK_RGB( 0xFF, 0xD0, 0x00 ),
	HK_RGB( 0xFF, 0xFF, 0x00 ),
	HK_RGB( 0x00, 0xFF, 0x00 ),
	HK_RGB( 0x00, 0xFF, 0xFF ),
	HK_RGB( 0x00, 0xD0, 0xFF ),
	HK_RGB( 0xA0, 0x40, 0x64 ),
	HK_RGB( 0xC0, 0xC0, 0xC0 ),

	HK_RGB( 0xFF, 0xA0, 0xD0 ),
	HK_RGB( 0xFF, 0xD0, 0xA0 ),
	HK_RGB( 0xFF, 0xFF, 0xA0 ),
	HK_RGB( 0xD0, 0xFF, 0xD0 ),
	HK_RGB( 0xD0, 0xFF, 0xFF ),
	HK_RGB( 0xA0, 0xD0, 0xFF ),
	HK_RGB( 0xD0, 0xA0, 0xFF ),
	HK_RGB( 0xFF, 0xFF, 0xFF )
};

/////////////////////////////////////////////////////////////////////////////

QString __hk_htmlColorName_Ex[ HK_HTML_COLOUR_ROW * HK_HTML_COLOUR_COL ] =
{
	_T("black"),
	_T("#a04000"),
	_T("#404000"),
	_T("#004000"),
	_T("#004064"),
	_T("navy"),
	_T("#4040a0"),
	_T("#404040"),
       
	_T("maroon"),
	_T("#00a500"),
	_T("olive"),
	_T("green"),
	_T("teal"),
	_T("blue"),
	_T("#6464a0"),
	_T("gray"),
       
	_T("red"),
	_T("orange"),
	_T("#a0d000"), 
	_T("#40a064"),
	_T("#40d0d0"),
	_T("#4064ff"),
	_T("purple"),
	_T("#969696"),
       
	_T("fuchsia"),
	_T("#ffd000"),
	_T("yellow"),    
	_T("lime"),
	_T("aqua"),
	_T("#00d0ff"),
	_T("#a04064"),
	_T("silver"),
       
	_T("#ffa0d0"),
	_T("#ffd0a0"),
	_T("#ffffa0"),
	_T("#d0ffd0"),
	_T("#d0ffff"),
	_T("#a0d0ff"),
	_T("#d0a0ff"),
	_T("white")
};

/////////////////////////////////////////////////////////////////////////////

unsigned long* get_htmlColorValue_Ex()
{
	return __hk_htmlColorValue_Ex;
}

const QString* get_hk_htmlColorName_Ex()
{
	return __hk_htmlColorName_Ex;
}

/////////////////////////////////////////////////////////////////////////////
