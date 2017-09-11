#include "db_table.h"

const QString db_table::filename="databasetavoli.xml";
const QString db_table::tag="db_tavoli";

db_table::db_table() : DbXml(tag, filename), list(new db_list()) {
    load_tables();
}

db_table::~db_table() {
    for(std::map<int, Table*>::iterator it=tables.begin(); it!=tables.end(); it++)
        delete it->second;
}

void db_table::save_table(Table& table) {

    tables[table.getId()] = &table;

    QXmlStreamWriter* xmlWriter = start_write();

    xmlWriter->writeStartElement("tavolo");
    xmlWriter->writeTextElement("id", QString::number(table.getId()));
    xmlWriter->writeStartElement("ordinazioni");
    std::vector<Order*> orders = table.getOrders();
    for(std::vector<Order*>::const_iterator it=orders.begin(); it!=orders.end(); it++) {
        xmlWriter->writeStartElement("ordinazione");
        xmlWriter->writeTextElement("quantita", QString::number((*it)->getQuantity()));
        xmlWriter->writeTextElement("item", QString((*it)->getItem()->getName()));
        xmlWriter->writeEndElement();
    }
    xmlWriter->writeEndElement();
    xmlWriter->writeEndElement();

    end_write(xmlWriter);
}

void db_table::load_tables() {
    QXmlStreamReader* xmlReader = start_read();

    //Parse the XML until we reach end of it
    while(!xmlReader->atEnd() && !xmlReader->hasError()) {
        // Read next element
        //If token is just StartDocument - go to next
        if(xmlReader->isStartDocument()) {
            xmlReader->readNextStartElement();
        }
        //If token is StartElement - read it
        if(xmlReader->name() == "tavolo" && xmlReader->isStartElement()) {
            if(xmlReader->name() == "tavolo") {
                Table* table = load_table_and_total(xmlReader);
                tables[table->getId()] = table;
            }
        } else {
            xmlReader->readNextStartElement();
        }
    }

    end_read(xmlReader);
}

Table* db_table::load_table_and_total(QXmlStreamReader*& xmlReader) {
    Total* t = 0;
    int id = -1;
    while(xmlReader->readNextStartElement() && xmlReader->name() != "tavolo") {
        if(xmlReader->name()=="id") {
            id=xmlReader->readElementText().toInt();
        }
        else if(xmlReader->name()=="ordinazioni") {
            t=load_total(xmlReader);
        }
    }
    return new Table(id, t);
}

Total* db_table::load_total(QXmlStreamReader*& xmlReader) {
    Total* t = new Total();
    while(xmlReader->readNextStartElement() && xmlReader->name() != "ordinazioni") {
        if(xmlReader->name()=="ordinazione") {
            t->addOrder(load_order(xmlReader));
        }
    }
    return t;
}

Order* db_table::load_order(QXmlStreamReader*& xmlReader) {
    int quantity = -1;
    QString item;
    while(xmlReader->readNextStartElement() && xmlReader->name() != "ordinazioni") {
        if(xmlReader->name()=="quantita") {
            quantity=xmlReader->readElementText().toInt();
        }
        else if(xmlReader->name()=="item") {
            item=xmlReader->readElementText();
        }
    }
    ListItem* li = list->getItemFromName(item);
    return new Order(quantity, li);
}

void db_table::save_db() {
    clear_db();
    for(map<int, Table*>::const_iterator it = tables.begin(); it!=tables.end(); it++)
        save_table(*(it->second));
}

void db_table::add_order(const int & id, Order * order) {
    map<int, Table*>::iterator it = tables.find(id);
    if (it == tables.end()) {
        tables[id] = new Table(id);
        it = tables.find(id);
    }
    it->second->addOrder(order);
    save_db();
}

void db_table::clear_orders(const int & id) {
    map<int, Table*>::iterator it = tables.find(id);
    it->second->clearOrders();
    save_db();
}

const Total* db_table::get_orders(const int & id) {
    Total* total = new Total();
    std::map<int, Table*>::const_iterator mapIterator = tables.find(id);
    if (mapIterator!=tables.end()) {
        Table * t = mapIterator->second;
        std::vector<Order*> orders = t->getOrders();
        for (vector<Order*>::iterator it=orders.begin(); it!=orders.end(); it++)
            total->addOrder(*it);
    } else {
        tables[id]=new Table(id);
    }
    return total;
}

std::vector<int> db_table::getTables() const {
    std::vector<int> ids;
    for(std::map<int, Table*>::const_iterator it=tables.begin(); it!=tables.end(); it++)
        ids.push_back(it->first);
    return ids;
}
