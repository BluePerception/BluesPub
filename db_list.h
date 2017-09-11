#ifndef DB_LIST_H
#define DB_LIST_H
#include <QFile>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QString>
#include <QDebug>
#include <vector>
#include <QTextStream>
#include "listitem.h"
#include "drink.h"
#include "food.h"
#include "utility.h"
#include "dbxml.h"

using namespace std;

class db_list : public DbXml {
private:
    static const QString filename;
    static const QString tag;
    vector<ListItem*> items;

    //metodi per caricare e salvare le modifiche nel database
    void load_items();

public:
    db_list();
    ~db_list();
    //metodi per salvare o modificare lo specifico oggetto nel contenitore listino
    void save_db();
    void save_item(const ListItem&);
    ListItem* getItemFromName(const QString &) const;
    void changeListItem(const ListItem*, ListItem*);
    void removeItem(const ListItem*);
    std::vector<const Food*> getFoods() const;
    std::vector<const Drink*> getDrinks() const;
    std::vector<const ListItem*> getItems() const;
};

#endif // DB_LIST_H
