#ifndef LISTITEM_H
#define LISTITEM_H
#include <QString>
#include <QXmlStreamWriter>
#include "utility.h"

class ListItem{
public:
    enum Type {
        SNACK,
        TOAST,
        PANINO,
        FRITTO,
        PIATTO,

        BIRRA,
        ANALCOLICO,
        APERITIVO,
        COCKTAIL,
        DISTILLATO,

        UNK,
    };

    ListItem();
    ListItem(const QString &, const QString &, const float &, const Type &);
    virtual ~ListItem();

    QString getName() const;
    QString getDescription() const;
    Type getType() const;
    float getPrice() const;

    virtual QXmlStreamWriter* save(QXmlStreamWriter*) const;
    virtual void load(QXmlStreamReader*) =0;
    virtual ListItem* clone() const =0;
    virtual bool operator==(const ListItem &) const;

    static QString typeToString(const Type &);
    static Type stringToType(const QString &);

private:
    QString name;
    QString description;
    Type type;
    float price;

protected:
    void setName(const QString &);
    void setDescription(const QString &);
    void setType(const Type &);
    void setPrice(const float &);
};

#endif // LISTITEM_H
