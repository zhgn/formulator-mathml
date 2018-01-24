

#if !defined( __FORMULATOR_EXT_FORMULA_H__ )
#define __FORMULATOR_EXT_FORMULA_H__
 
#include <QVector>
#include <map>
#include "HUtils/idrawstruct.h"
#include "../../fmlcore_global.h"

class CParentNode;
typedef std::map<RealFde, RealFde> CExCalcMap;

class CFormulaPos  
{
protected:
	RectFde		m_pos;
	qint32		m_align;
	qint32		m_level;

public:
	CFormulaPos( const RectFde& pos = RectFde(), long align = 0, long level = 0 )
		: m_pos( pos ), m_align( align ), m_level( level ) {}
	CFormulaPos( const CFormulaPos& fp )
		: m_pos( fp.m_pos ), m_align( fp.m_align ), m_level( fp.m_level ) {}
	const CFormulaPos& operator = ( const CFormulaPos& fp )
		{ m_pos = fp.m_pos; m_align = fp.m_align; m_level = fp.m_level; return *this; }

	const RectFde& GetPecentPosition( void ) const { return m_pos; };
	void SetPecentPosition( const RectFde& pos ) { m_pos = pos; };

	long GetAlignType( void ) const { return m_align; };
	void SetAlignType( long align ) { m_align = align; };

	long GetLevel( void ) const { return m_level; };
	void SetLevel( long level ) { m_level = level; };

	friend QDataStream& operator << ( QDataStream& ar, const CFormulaPos& pos );
	friend QDataStream& operator >> ( QDataStream& ar, CFormulaPos& pos );
};

///////////////////////////////////////////////////////////////////////////////

inline
QDataStream& operator << ( QDataStream& ar, const CFormulaPos& fp )
	{ return ar << fp.m_pos << fp.m_align << fp.m_level; }

inline
QDataStream& operator >> ( QDataStream& ar, CFormulaPos& fp )
	{ return ar >> fp.m_pos >> fp.m_align >> fp.m_level; }

///////////////////////////////////////////////////////////////////////////////
//

class CFormulaExCalc  
{
public:
	CFormulaExCalc();
	CFormulaExCalc( CFormulaExCalc* pFormulaEx );
	virtual ~CFormulaExCalc();

public:
	long GetSlotCount( void );
	CFormulaPos& GetSlot( long i );
	void AddSlot( const CFormulaPos& fp );

public:

	virtual void Store( QDataStream& ar ) const;
	virtual void Load( QDataStream& ar );
	virtual SizeFde RecalculateSize( CParentNode *pParentNode );
	virtual SizeFde GetDefaultSize( void );
	virtual RectFde GetRealPosition( RectFde rc );

protected:
	SizeFde CalculateDefaultSize( CParentNode *pParentNode );
	SizeFde CalculateFormulaSize( const SizeFde& defSize, CParentNode *pParentNode );
	SizeFde CalculateSizeByPercents( QVector<RectFde>& rects, QVector<SizeFde>& sizes );
	RealFde GetMapValue( RealFde value, CExCalcMap& ps );

protected:
	QVector<CFormulaPos>		m_slots;

	SizeFde		m_defSize;
	CExCalcMap	m_psx;
	CExCalcMap	m_psy;
};

///////////////////////////////////////////////////////////////////////////////

inline
long CFormulaExCalc::GetSlotCount( void )
	{ return (long) m_slots.size(); }

inline
CFormulaPos& CFormulaExCalc::GetSlot( long i )
	{ return m_slots[ i ]; }

inline
void CFormulaExCalc::AddSlot( const CFormulaPos& fp )
	{ m_slots.push_back( fp ); }

inline
SizeFde CFormulaExCalc::GetDefaultSize( void )
	{ return m_defSize; }

///////////////////////////////////////////////////////////////////////////////

#endif
