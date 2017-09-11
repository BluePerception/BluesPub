#ifndef FOOD_H
#define FOOD_H
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include "listitem.h"

class Food : public ListItem {
public:
    Food();
    Food(const QString &, const QString &, const float &, const ListItem::Type &);
    bool operator==(const ListItem &) const;
    Food* clone() const;
    QXmlStreamWriter* save(QXmlStreamWriter*) const;
    void load(QXmlStreamReader*);
};

#endif // FOOD_H
