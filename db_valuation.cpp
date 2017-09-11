#include "db_valuation.h"
#include <QTextStream>

//inizializzazione campo dati statico
const QString db_valuation::filename="databaserate.xml";
const QString db_valuation::tag="db_valutazioni";

db_valuation::db_valuation() : DbXml(tag, filename) {
    load_rates();
}

db_valuation::~db_valuation() {
    for(std::vector<Rate*>::iterator it=rates.begin(); it!=rates.end(); it++)
        delete *it;
}

//scritture e lettura del database
void db_valuation::save_rate(const Rate& rate){

    QXmlStreamWriter* xmlWriter = start_write();

    xmlWriter->writeStartElement("valutazione");
    xmlWriter->writeTextElement("servizio", rate.get_service());
    xmlWriter->writeTextElement("consumazione", rate.get_meal());
    xmlWriter->writeEndElement();

    end_write(xmlWriter);
}

void db_valuation::load_rates(){

    QXmlStreamReader* xmlReader = start_read();

    //Parse the XML until we reach end of it
    while(!xmlReader->atEnd() && !xmlReader->hasError()) {
            // Read next element
            //If token is just StartDocument - go to next
            if(xmlReader->isStartDocument()) {
                xmlReader->readNextStartElement();
            }
            //If token is StartElement - read it
            if(xmlReader->name() == "valutazione" && xmlReader->isStartElement()) {
                    if(xmlReader->name() == "valutazione") {
                            rates.push_back(load_rate(xmlReader));
                    }
            } else {
                xmlReader->readNextStartElement();
            }
    }

    end_read(xmlReader);
}

//MI SERVE DAVVERO QUESTO METODO?
//lettura dei campi del singolo questionario
Rate* db_valuation::load_rate(QXmlStreamReader*& xmlReader){

    QString service, fd;
    while(xmlReader->readNextStartElement() && xmlReader->name() != "valutazione") {
            if(xmlReader->name()=="servizio") {
                service=(xmlReader->readElementText());
            }
            else if(xmlReader->name()=="consumazione") {
                fd=(xmlReader->readElementText());
            }
    }
    xmlReader->readNextStartElement();
    return new Rate(service, fd);
}

void db_valuation::save_db() {
    clear_db();
    for(vector<Rate*>::const_iterator it = rates.begin(); it!=rates.end(); it++)
        save_rate(**it);
}

vector<Rate*> db_valuation::getRates() const {
    return rates;
}
