#include "holder.h"

//costruttore
Holder::Holder(const QString & n, const QString & s, const QDate & bd, const QString & e, const QString & u, const QString & p) : Waiter(n, s, bd, e, u, p){}

//metodi
QString Holder::getType() const{
    return "titolare";
}
