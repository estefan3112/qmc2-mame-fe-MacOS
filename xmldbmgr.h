#ifndef _XMLDBMGR_H_
#define _XMLDBMGR_H_

#include <QObject>
#include <QSqlDatabase>
#include <QSqlDriver>

class XmlDatabaseManager : public QObject
{
	Q_OBJECT

	public:
		explicit XmlDatabaseManager(QObject *parent);
		~XmlDatabaseManager();

		QString emulatorVersion();
		void setEmulatorVersion(QString emu_version);
		QString qmc2Version();
		void setQmc2Version(QString qmc2_version);
		int xmlCacheVersion();
		void setXmlCacheVersion(int xmlcache_version);
		QString dtd();
		void setDtd(QString dtd);
		QString xml(QString id);
		void setXml(QString id, QString xml);

	public slots:
		void recreateDatabase();
		void beginTransaction() { m_db.driver()->beginTransaction(); }
		void commitTransaction() { m_db.driver()->commitTransaction(); }

	private:
		mutable QSqlDatabase m_db;
		QString m_tableBasename;
};

#endif
