#ifndef DB_USER_H
#define DB_USER_H
#include <QFile>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <iostream>
#include <QString>
#include <QDebug>
#include "user.h"
#include "client.h"
#include "waiter.h"
#include "holder.h"
#include "clientview.h"
#include <map>
#include <iostream>
#include <QTextStream>
#include <QMessageBox>
#include "dbxml.h"
#include "user.h"
#include "holder.h"


using namespace std;

class db_user : public DbXml {
private:
    static const QString filename;
    static const QString tag;

    map<QString, User*> users;

    User* load_user(QXmlStreamReader*&);
    QDate load_birthday(QXmlStreamReader*&);

    void load_users();

public:
    db_user();
    ~db_user();
    void save_db();

    //utilizzati per la registrazione
    void save_user(User&);
    bool checkExistingEmail(const QString &) const;
    bool checkExistingUsername(const QString &) const;

    void modify_user(const QString &, User*);
    void erase_user(const QString &);

    //utilizzati per il login
    User* checkLogin(const QString&, const QString&);

    User* findUser(const QString &);

};

#endif // DB_USER_H
