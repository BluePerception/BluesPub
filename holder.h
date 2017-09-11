#ifndef HOLDER_H
#define HOLDER_H
#include "waiter.h"
#include "user.h"

class Holder : public Waiter{
public:
    Holder(const QString &, const QString &, const QDate &, const QString &, const QString &, const QString &);
    QString getType() const;
};

#endif // HOLDER_H
