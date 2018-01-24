

#if QT_VERSION > QT_VERSION_CHECK(5, 0, 0)
#include <QtWidgets>
#else
#include <QtGui>
#endif

#include "definesizedlg.h"
#include "HUtils/idrawstruct.h"
#include "HMathML/isettings.h"

/////////////////////////////////////////////////////////////////////////////

CDefineSizeDialog::CDefineSizeDialog( QWidget *parent )
	: QDialog( parent )
{
    QLabel *largeLabel = new QLabel(tr("&Large Symbol (pt):"));
	largeEdit = new QSpinBox();
	largeEdit->setRange(DEFAULT_SYMBOLSIZE_MIN, DEFAULT_SYMBOLSIZE_MAX);
	largeEdit->setValue( (int) ::getKegl(FTEXT_HEIGHT_LARGEOP) );
	largeLabel->setBuddy( largeEdit );

	QLabel *regularLabel = new QLabel(tr("&Regular (pt):"));
	regularEdit = new QSpinBox();
	regularEdit->setRange(DEFAULT_SYMBOLSIZE_MIN, DEFAULT_SYMBOLSIZE_MAX);
	regularEdit->setValue( (int) ::getKegl(FTEXT_HEIGHT_FRAME) );
	regularLabel->setBuddy( regularEdit );

	QLabel *subLabel = new QLabel(tr("&Subscript (pt):"));
	subEdit = new QSpinBox();
	subEdit->setRange(DEFAULT_SYMBOLSIZE_MIN, DEFAULT_SYMBOLSIZE_MAX);
	subEdit->setValue( (int) ::getKegl(FTEXT_HEIGHT_CHILD1) );
	subLabel->setBuddy( subEdit );

	QLabel *subsubLabel = new QLabel(tr("Su&b-Subscript (pt):"));
	subsubEdit = new QSpinBox();
	subsubEdit->setRange(DEFAULT_SYMBOLSIZE_MIN, DEFAULT_SYMBOLSIZE_MAX);
	subsubEdit->setValue( (int) ::getKegl(FTEXT_HEIGHT_CHILD2) );
	subsubLabel->setBuddy( subsubEdit );

	QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Vertical);
	connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
	connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
	connect(buttonBox->addButton(tr("&Reset"), QDialogButtonBox::ResetRole), SIGNAL(clicked()), this, SLOT(factorySettings()));

	QGridLayout *centralLayout = new QGridLayout();
	centralLayout->addWidget( largeLabel, 0, 0, Qt::AlignRight );
	centralLayout->addWidget( largeEdit, 0, 1, Qt::AlignLeft );
	centralLayout->addWidget( regularLabel, 1, 0, Qt::AlignRight );
	centralLayout->addWidget( regularEdit, 1, 1, Qt::AlignLeft );
	centralLayout->addWidget( subLabel, 2, 0, Qt::AlignRight );
	centralLayout->addWidget( subEdit, 2, 1, Qt::AlignLeft );
	centralLayout->addWidget( subsubLabel, 3, 0, Qt::AlignRight );
	centralLayout->addWidget( subsubEdit, 3, 1, Qt::AlignLeft );
	centralLayout->setVerticalSpacing(8);
	centralLayout->setHorizontalSpacing(16);
	QHBoxLayout *mainLayout = new QHBoxLayout();
	mainLayout->addLayout( centralLayout );
	mainLayout->addWidget( buttonBox );
	setLayout(mainLayout);

	setWindowTitle(tr("Define Size"));
}

CDefineSizeDialog::~CDefineSizeDialog()
{
}

void CDefineSizeDialog::accept()
{
	::getCurrentFormulatorStyle().setKegl( FTEXT_HEIGHT_LARGEOP, largeEdit->value() );
	::getCurrentFormulatorStyle().setKegl( FTEXT_HEIGHT_FRAME, regularEdit->value() );
	::getCurrentFormulatorStyle().setKegl( FTEXT_HEIGHT_CHILD1, subEdit->value() );
	::getCurrentFormulatorStyle().setKegl( FTEXT_HEIGHT_CHILD2, subsubEdit->value() );
	QDialog::accept();
}

void CDefineSizeDialog::factorySettings()
{
	largeEdit->setValue( (int) FKEGL_LARGEOP );
	regularEdit->setValue( (int) FKEGL_FRAME );
	subEdit->setValue( (int) FKEGL_CHILD1 );
	subsubEdit->setValue( (int) FKEGL_CHILD2 );
}

/////////////////////////////////////////////////////////////////////////////
