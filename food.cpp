#include "food.h"

Food::Food() : ListItem() {}

Food::Food(const QString & name_, const QString & description_, const float & price_,
            const ListItem::Type & type_) :
    ListItem(name_, description_, price_, type_) {}

bool Food::operator==(const ListItem & item) const {
    const Food* itemPunt = dynamic_cast<const Food*>(&item);
    return itemPunt && ListItem::operator ==(item);
}

Food* Food::clone() const {
    return new Food(*this);
}

QXmlStreamWriter* Food::save(QXmlStreamWriter* xmlWriter) const {
    xmlWriter->writeStartElement("cibo");
    ListItem::save(xmlWriter);
    xmlWriter->writeEndElement();
    return xmlWriter;
}

void Food::load(QXmlStreamReader* xmlReader) {
    QString name, description;
    float price;
    ListItem::Type type;
    while(xmlReader->readNextStartElement() && xmlReader->name() != "cibo") {
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
