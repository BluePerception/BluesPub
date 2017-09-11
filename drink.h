#ifndef DRINK_H
#define DRINK_H
#include "listitem.h"

class Drink : public ListItem {
public:
    Drink();
    Drink(const QString &, const QString &, const float &, const ListItem::Type &);
    bool operator==(const ListItem &) const;
    Drink* clone() const;
    QXmlStreamWriter* save(QXmlStreamWriter* xmlWriter) const;
    void load(QXmlStreamReader*);
};

#endif // DRINK_H
