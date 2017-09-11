#ifndef CLIENT_H
#define CLIENT_H
#include "user.h"

class Client : public User {
public:
    Client(const QString &, const QString &, const QDate &, const QString &, const QString &, const QString &);
    QString getType() const;
};

#endif // CLIENT_H
