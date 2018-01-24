

#if !defined( __BULAN_VMI_CALC_H__ )
#define __BULAN_VMI_CALC_H__

#include <QVector>

#include "HUtils/idrawstruct.h"
#include "HUtils/iustring.h"

#include "vmi_picode.h"

///////////////////////////////////////////////////////////////////////////////

#define FBtnVM_EM_NAME						_T("em")
#define FBtnVM_ASCENT_NAME					_T("ascent")
#define FBtnVM_DESCENT_NAME					_T("descent")

#define FBtnVM_Margin_Left					_T("left_margin")
#define FBtnVM_Margin_Top					_T("top_margin")
#define FBtnVM_Margin_Right					_T("right_margin")
#define FBtnVM_Margin_Bottom				_T("bottom_margin")

#define SVG_NodeTemplate_Parameter_Left_Name	_T("left")
#define SVG_NodeTemplate_Parameter_Top_Name		_T("top")
#define SVG_NodeTemplate_Parameter_Right_Name	_T("right")
#define SVG_NodeTemplate_Parameter_Bottom_Name	_T("bottom")

#define SVG_NodeTemplate_Parameter_Left		0
#define SVG_NodeTemplate_Parameter_Top		1
#define SVG_NodeTemplate_Parameter_Right	2
#define SVG_NodeTemplate_Parameter_Bottom	3
#define SVG_NodeTemplate_Parameter_Center	4

inline
QString getGraphicsFieldName( long i )
{
	static QString _names[ 4 + 1 ] = 
	{
		SVG_NodeTemplate_Parameter_Left_Name,
		SVG_NodeTemplate_Parameter_Top_Name,
		SVG_NodeTemplate_Parameter_Right_Name,
		SVG_NodeTemplate_Parameter_Bottom_Name,
		_T("")
	};
	if( i >= 0 && i <= 3 )
		return _names[ i ];
	else 
		return _names[ 4 ];
}

inline
long getGraphicsFieldIdx( const QString& strName )
{
	static const QString _names[ 4 ] = 
	{
		SVG_NodeTemplate_Parameter_Left_Name,
		SVG_NodeTemplate_Parameter_Top_Name,
		SVG_NodeTemplate_Parameter_Right_Name,
		SVG_NodeTemplate_Parameter_Bottom_Name
	};
	for( long i = 0; i < 4; i++ )
		if( !xml_strcmp( _names[ i ], strName ) )
			return i;
	return -1;
}

///////////////////////////////////////////////////////////////////////////////

class __YUNEN_FORMULIB__ FBtnCalc : public QVector<FBtnPiCode>
{
public:
	QVector<double> locals;

public:
	FBtnCalc();
	void operator=( const FBtnCalc& ls );

	void debug_print( QString& str );

	void AddLocal( double val = 0.0 );
	void SetLocal( long idx, double val );
	double GetLocal( long idx );

	int Add( enum FBtnPiCode_Command c = LPC_NONE, long fr_no = -1, long v_no = -1 );
	int Add( enum FBtnPiCode_Command c, double aval );
	int Add( long ln, enum FBtnPiCode_Command c = LPC_NONE, long fr_no = -1, long v_no = -1 );
	int Add( long ln, enum FBtnPiCode_Command c, double aval );

	int PositionRun( QVector<RealFde>& frames_ltrb, QVector<RealFde>& frames_margin_ltrb, QVector<RealFde>& primitive_ltrb );

	int isParentMarginAddr( long idx );

};

/////////////////////////////////////////////////////////////////////

inline
int isFrameAddress( long a )
{
	return a > 0;
}
inline
int isPrimitiveAddress( long a )
{
	return a < 0;
}
inline
int isLocalAddress( long a )
{
	return a == 0;
}
inline
int isField( long b )
{
	return b >= 0;
}
inline
int isMargin( long b )
{
	return b < 0;
}

/////////////////////////////////////////////////////////////////////

inline
QDataStream& operator << ( QDataStream& ar, const FBtnCalc& lp )
{
	ar << (const QVector<FBtnPiCode>&) lp;
	return ar << lp.locals;
}

inline
QDataStream& operator >> ( QDataStream& ar, FBtnCalc& lp )
{
	ar >> (QVector<FBtnPiCode>&) lp;
	return ar >> lp.locals;
}

/////////////////////////////////////////////////////////////////////

inline
FBtnCalc::FBtnCalc()
{
}

inline
void FBtnCalc::AddLocal( double val )
{
	locals.push_back( val );
}

inline
void FBtnCalc::SetLocal( long idx, double val )
{
	locals[ idx ] = val;
}

inline
double FBtnCalc::GetLocal( long idx )
{
	return locals[ idx ];
}

inline
int FBtnCalc::isParentMarginAddr( long idx )
{
	return  idx > SVG_NodeTemplate_Parameter_Bottom &&
			idx < 2 * (SVG_NodeTemplate_Parameter_Bottom + 1);
}

inline
int FBtnCalc::Add( enum FBtnPiCode_Command c, long fr_no, long v_no )
{
	int ret = size();
	push_back( FBtnPiCode(c, fr_no, v_no) );
	return ret;
}

inline
int FBtnCalc::Add( enum FBtnPiCode_Command c, double aval )
{
	int ret = size();
	push_back( FBtnPiCode(c, aval) );
	return ret;
}

inline
int FBtnCalc::Add( long ln, enum FBtnPiCode_Command c, long fr_no, long v_no )
{
	int ret = size();
	push_back( FBtnPiCode(ln, c, fr_no, v_no) );
	return ret;
}

inline
int FBtnCalc::Add( long ln, enum FBtnPiCode_Command c, double aval )
{
	int ret = size();
	push_back( FBtnPiCode(ln, c, aval) );
	return ret;
}

///////////////////////////////////////////////////////////////////////////////

#endif
