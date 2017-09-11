#ifndef DBXML_H
#define DBXML_H
#include <QFile>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QTextStream>

class DbXml {
private:
    static const QString pathToDb;

    const QString open_tag;
    const QString close_tag;
    const QString filename;
    qint64 size;
    QFile db;

    void open_db();
    void close_db();

protected:
    QXmlStreamReader* start_read();
    void end_read(QXmlStreamReader*);
    QXmlStreamWriter* start_write();
    void end_write(QXmlStreamWriter*);

public:
    DbXml(const QString &, const QString &);
    virtual ~DbXml();
    void clear_db();
    virtual void save_db() =0;
};

#endif // DBXML_H
