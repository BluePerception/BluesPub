#ifndef DB_VALUATION_H
#define DB_VALUATION_H

#include <QFile>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <iostream>
#include <QString>
#include <QDebug>
#include <vector>
#include <iostream>
#include <vector>
#include <iostream>
#include <rate.h>
#include <dbxml.h>
using namespace std;

class db_valuation : public DbXml{
private:
    static const QString filename;
    static const QString tag;
    vector<Rate*> rates;

    Rate* load_rate(QXmlStreamReader*&);
    void load_rates();

public:
    db_valuation();
    void save_db();
    void save_rate(const Rate&);
    ~db_valuation();
    vector<Rate*> getRates() const;
};

#endif // DB_VALUATION_H
