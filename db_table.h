#ifndef DB_TABLE_H
#define DB_TABLE_H
#include <map>
#include "table.h"
#include <QXmlStreamReader>
#include "dbxml.h"
#include "db_list.h"

class db_table : public DbXml {
private:
    static const QString filename;
    static const QString tag;
    static const int table_number;
    const db_list* const list;

    std::map<int, Table*> tables;

    void load_tables();
    Table* load_table_and_total(QXmlStreamReader*&);
    Order* load_order(QXmlStreamReader*&);
    Total* load_total(QXmlStreamReader*&);

public:
    db_table();
    ~db_table();
    void save_db();
    void save_table(Table&);
    void add_order(const int &, Order *);
    void clear_orders(const int &);
    const Total* get_orders(const int &);
    std::vector<int> getTables() const;

};

#endif // DB_TABLE_H
