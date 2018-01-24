

/////////////////////////////////////////////////////////////////////

#include "../mathml/mml_defs.h"
#include "btn_attr.h"

/////////////////////////////////////////////////////////////////////

void FBtnAttr::setColorAttr( const HMathMLAttr& a )
{
	QString _dest;
	if( a.getFilteredAttr( FBL_ATTR_mathcolor, _dest ) != -1 )
		m_mmlAttr.setFilteredAttr( FBL_ATTR_mathcolor, _dest );
	if( a.getFilteredAttr( FBL_ATTR_mathbackground, _dest ) != -1 )
		m_mmlAttr.setFilteredAttr( FBL_ATTR_mathbackground, _dest );
}

void FBtnAttr::setMathMLAttr( const HMathMLAttr& a )
{
	if( a.isMOFence() )
		setFlag( HF_FLAG_OP_IS_FENCE );
	if( a.isMOSeparator() )
		setFlag( HF_FLAG_OP_IS_SEPARATOR );
	if( a.isMOStretchy() )
		setFlag( HF_FLAG_OP_STRETCHY );
	if( a.isMOSymmetric() )
		setFlag( HF_FLAG_OP_IS_SYMMETRIC );
	if( a.isMOLargeop() )
		setFlag( HF_FLAG_OP_IS_LARGEOP );
	if( a.isMOMovable() )
		setFlag( HF_FLAG_OP_IS_MOVABLELIMITS );
	if( a.isMOAccent() )
		setFlag( HF_FLAG_OP_IS_ACCENT );
	m_mmlAttr = a;
}

const HMathMLAttr& FBtnAttr::getMathMLAttr( void )
{
	isSetFlag( HF_FLAG_OP_IS_FENCE ) ?
		m_mmlAttr.setMOFence() : m_mmlAttr.clearMOFence();
	isSetFlag( HF_FLAG_OP_IS_SEPARATOR ) ?
		m_mmlAttr.setMOSeparator() : m_mmlAttr.clearMOSeparator();
	isSetFlag( HF_FLAG_OP_STRETCHY ) ?
		m_mmlAttr.setMOStretchy() : m_mmlAttr.clearMOStretchy();
	isSetFlag( HF_FLAG_OP_IS_SYMMETRIC ) ?
		m_mmlAttr.setMOSymmetric() : m_mmlAttr.clearMOSymmetric();
	isSetFlag( HF_FLAG_OP_IS_LARGEOP ) ?
		m_mmlAttr.setMOLargeop() : m_mmlAttr.clearMOLargeop();
	isSetFlag( HF_FLAG_OP_IS_MOVABLELIMITS ) ?
		m_mmlAttr.setMOMovable() : m_mmlAttr.clearMOMovable();
	isSetFlag( HF_FLAG_OP_IS_ACCENT ) ?
		m_mmlAttr.setMOAccent() : m_mmlAttr.clearMOAccent();
	return m_mmlAttr;
}

/////////////////////////////////////////////////////////////////////
