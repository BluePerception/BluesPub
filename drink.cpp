#include "drink.h"

Drink::Drink() : ListItem() {}

Drink::Drink(const QString & name_, const QString & description_, const float & price_,
             const ListItem::Type & type_) :
    ListItem(name_, description_, price_, type_){}

bool Drink::operator==(const ListItem & item) const {
    const Drink* itemPunt = dynamic_cast<const Drink*>(&item);
    return itemPunt && ListItem::operator ==(item);
}

Drink* Drink::clone() const {
    return new Drink(*this);
}

QXmlStreamWriter* Drink::save(QXmlStreamWriter* xmlWriter) const {
    xmlWriter->writeStartElement("bevanda");
    ListItem::save(xmlWriter);
    xmlWriter->writeEndElement();
    return xmlWriter;
}

void Drink::load(QXmlStreamReader* xmlReader) {
    QString name, description;
    float price;
    ListItem::Type type;
    while(xmlReader->readNextStartElement() && xmlReader->name() != "bevanda") {
            if(xmlReader->name()=="nome") {
                name=(xmlReader->readElementText());
            }
            else if(xmlReader->name()=="descrizione") {
                description=(xmlReader->readElementText());
            }
            else if(xmlReader->name()=="prezzo") {
                price=xmlReader->readElementText().toFloat();
            }
            else if(xmlReader->name()=="tipo") {
                type=ListItem::stringToType(xmlReader->readElementText());
            }
    }
    setName(name);
    setDescription(description);
    setPrice(price);
    setType(type);
}
