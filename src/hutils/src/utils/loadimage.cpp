

#include <QFileDialog>
#include "loadimage.h"

int LoadImagePath( QString& dest )
{
	QString strFilter = "Image Files (*.bmp *.gif *.jpg *.png);;"
						"Windows Bitmap Format (*.bmp);;Graphic Interchange Format (*.gif);;"
						"JPEG File Interchange Format (*.jpg);;Portable Network Graphics Format (*.png);;"
						"All Files (*.*)";
	dest = QFileDialog::getOpenFileName( 0, "Open Image", "./", strFilter);
	return dest.isNull() ? -1 : 0;
}

/////////////////////////////////////////////////////////////////////////////
