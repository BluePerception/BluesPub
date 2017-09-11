#include "dbxml.h"

//windows
//const QString DbXml::pathToDb = "..\\BluesPub\\";
//linux
const QString DbXml::pathToDb = "../BluesPub/";

DbXml::DbXml(const QString & tag, const QString & file) : open_tag(tag), close_tag("</" + tag + ">\n"),
filename(pathToDb + file),
db(pathToDb + file) {
    size = db.size();
}

DbXml::~DbXml() {
    if(db.isOpen())
        close_db();
}

void DbXml::open_db(){
     if (size > 0) {    //controlla che il db esista già
         db.open(QFile::ReadWrite);
     }
     else
         db.open(QFile::WriteOnly);
}//ora dovremo avere il file aperto come vogliamo

void DbXml::close_db(){
    db.close();
}

QXmlStreamWriter* DbXml::start_write() {
    open_db();
    QXmlStreamWriter* xmlWriter = new QXmlStreamWriter(&db);
    xmlWriter->setAutoFormatting(true);
    xmlWriter->setAutoFormattingIndent(2);

    if (size == 0) {     //se il file non esiste, allora ne creo uno nuovo
        xmlWriter->writeStartDocument();
        xmlWriter->writeStartElement(open_tag);
    }
    if (db.seek(size - close_tag.length()))   //per appendere in fondo in nuovo utente
        Q_ASSERT(db.pos() == size - close_tag.length());

    return xmlWriter;
}

void DbXml::end_write(QXmlStreamWriter* xmlWriter) {
    if (size == 0) {
            xmlWriter->writeEndElement();
            xmlWriter->writeEndDocument();
        }
    else
        QTextStream(&db) << close_tag;
    close_db();
    size=db.size();
    delete xmlWriter;
}

QXmlStreamReader * DbXml::start_read() {
    open_db();
    return new QXmlStreamReader(&db);
}

void DbXml::end_read(QXmlStreamReader * xmlReader) {
    close_db();
    delete xmlReader;
}

void DbXml::clear_db() {
    db.resize(0);
    size=0;
}
