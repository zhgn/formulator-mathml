

#if !defined(AFX_ODEONESTEPPARAM_H__801102A0_6EC8_11D4_8A72_4854E82A9A73__INCLUDED_)
#define AFX_ODEONESTEPPARAM_H__801102A0_6EC8_11D4_8A72_4854E82A9A73__INCLUDED_

#include "HMathBS/inumber.h"

class COdeOneStepParam  
{
public:
	COdeOneStepParam(CDSRReal betta, CDSRReal gamma);
	virtual ~COdeOneStepParam();

	void setStep(CDSRReal step);

public:
	CDSRReal b21h;
	CDSRReal p22h;
	CDSRReal p21h;
	CDSRReal b32h;
	CDSRReal b31h;
	CDSRReal p33h;
	CDSRReal p32h;
	CDSRReal p31h;

	CDSRReal pe31h;
	CDSRReal pe32h;

protected:
	CDSRReal b21;
	CDSRReal p22;
	CDSRReal p21;
	CDSRReal b32;
	CDSRReal b31;
	CDSRReal p33;
	CDSRReal p32;
	CDSRReal p31;

	CDSRReal pe31;
	CDSRReal pe32;
};

#endif // !defined(AFX_ODEONESTEPPARAM_H__801102A0_6EC8_11D4_8A72_4854E82A9A73__INCLUDED_)
