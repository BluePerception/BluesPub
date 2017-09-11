#ifndef CHECKER_H
#define CHECKER_H

#include <QString>
#include <QDate>
#include <QRegularExpression>

#include "db_user.h"

//classe di utilita' che viene estesa dalle classi che devono fare controlli sui dati presenti nel database degli utenti
class Checker{
private:
    db_user* database;

protected:
    Checker();

public:

    bool checkAdultUser(const QDate &) const;
    bool checkBirth(const QDate &) const;
    bool checkEmail(const QString &) const;
    bool checkUsername(const QString &) const;
    bool checkPassword(const QString &) const;
    bool checkConfirmationPassword(const QString &, const QString &) const;

};

#endif // CHECKER_H
