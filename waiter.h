#ifndef WAITER_H
#define WAITER_H
#include "user.h"

class Waiter : public User{
public:
    Waiter(const QString &, const QString &, const QDate &, const QString &, const QString &, const QString &);
    QString getType() const;

};

#endif // WAITER_H
