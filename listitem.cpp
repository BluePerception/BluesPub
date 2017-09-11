#include "listitem.h"

ListItem::ListItem(){}

ListItem::ListItem(const QString & name_, const QString & description_, const float & price_, const Type & type_):name(name_),
    description(description_), type(type_), price(price_) {}

ListItem::~ListItem() {}

QString ListItem::getName() const {
    return name;
}

QString ListItem::getDescription() const {
    return description;
}

ListItem::Type ListItem::getType() const {
    return type;
}

float ListItem::getPrice() const {
    return price;
}

QString ListItem::typeToString(const Type & type) {
    switch(type) {
        case(Type::SNACK) :
            return "Bruschetta"; break;
        case(Type::TOAST) :
            return "Toast"; break;
        case(Type::PANINO) :
            return "Panino"; break;
        case(Type::FRITTO) :
            return "Frittura"; break;
        case(Type::PIATTO) :
            return "Piatto"; break;
        case(Type::BIRRA) :
            return "Birra"; break;
        case(Type::ANALCOLICO) :
            return "Analcolico"; break;
        case(Type::APERITIVO) :
            return "Aperitivo"; break;
        case(Type::COCKTAIL) :
            return "Cocktail"; break;
        case(Type::DISTILLATO) :
            return "Distillato"; break;
        case(Type::UNK) :
            break;
    }
    return "";
}

ListItem::Type ListItem::stringToType(const QString & type) {
    if (type=="Bruschetta")
        return Type::SNACK;
    if (type=="Toast")
        return Type::TOAST;
    if (type=="Panino")
        return Type::PANINO;
    if (type=="Frittura")
        return Type::FRITTO;
    if (type=="Piatto")
        return Type::PIATTO;
    if (type=="Birra")
        return Type::BIRRA;
    if (type=="Analcolico")
        return Type::ANALCOLICO;
    if (type=="Aperitivo")
        return Type::APERITIVO;
    if (type=="Cocktail")
        return Type::COCKTAIL;
    if (type=="Distillato")
        return Type::DISTILLATO;
    return Type::UNK;
}

QXmlStreamWriter* ListItem::save(QXmlStreamWriter* xmlWriter) const {
    xmlWriter->writeTextElement("nome", getName());
    xmlWriter->writeTextElement("descrizione", getDescription());
    xmlWriter->writeTextElement("prezzo", Utility::floatToString(getPrice()));
    xmlWriter->writeTextElement("tipo",  ListItem::typeToString(getType()));
    return xmlWriter;
}

void ListItem::setName(const QString & name_) {
    name=QString(name_);
}

void ListItem::setDescription(const QString & description_) {
    description=QString(description_);
}

void ListItem::setType(const Type & type_) {
    type=Type(type_);
}

void ListItem::setPrice(const float & price_) {
    price=float(price_);
}

bool ListItem::operator==(const ListItem & item) const {
    return item.getName()==getName() &&
           item.getDescription()==getDescription() &&
           item.getType()==getType() &&
           item.getPrice()==getPrice();
}
