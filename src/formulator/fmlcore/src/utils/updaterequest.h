

#ifndef __FMLCORE_UTILS_UPDATEREQUEST_H__
#define __FMLCORE_UTILS_UPDATEREQUEST_H__

#include <QDialog>
#include <QBuffer>

QT_BEGIN_NAMESPACE
class QHttp;
class QHttpResponseHeader;
class QByteArray;
class QString;
QT_END_NAMESPACE

class CUpdateRequest : public QObject
{
	Q_OBJECT

public:
    CUpdateRequest( QObject *uiobject );
    ~CUpdateRequest();
	QString text();

protected slots:
    void requestFinished( int id, bool error );
	void dataReadProgress( int done, int total );
	void readResponseHeader(const QHttpResponseHeader &responseHeader);

protected:
    QHttp*			m_http;
    int				m_id;
	QBuffer			m_buffer;
	QString			m_errorMsg;
	bool			m_isHttpAborted;
	enum
	{
		MaxExpectedReplyTotal = 1024
	};

signals:
	void requestOk();
};

#endif
