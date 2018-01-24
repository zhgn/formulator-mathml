

#ifndef __FMLCORE_DLG_EVALUATE_H__
#define __FMLCORE_DLG_EVALUATE_H__

#include "HUtils/imessage.h"
#include "../fmlcore_global.h"

class CMMLCalc;

class __YUNEN_FORMULIB__ QFormulatorCalc : public QObject
{
    //Q_OBJECT

protected:
	DRMessageManager m_dmm;
	long m_dmmPage;
	QString m_taskID, m_cmmlText, m_varText;
	TXML_Storage* m_xmlTree;
	CMMLCalc	*m_cmmlCalc;

public:
	QFormulatorCalc( QString taskID );
	~QFormulatorCalc();

	void init();
	void dispose();

	int compile( QString cmmlText );
	int compile( QString varText, QString mainBodyText, int useOnlyAssign = 0 );
	int evaluate();

	QStringList report();
	QString variableValue( QString name );
	QStringList itemsValue();
	QString lastItemValue();

	void setRealPrecision( int digits );
};

#endif

/////////////////////////////////////////////////////////////////////////////
