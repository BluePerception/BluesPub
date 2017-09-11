#include "waiter.h"

//costruttore
Waiter::Waiter(const QString & n, const QString & s, const QDate & bd, const QString & e, const QString & u, const QString & p) :
    User(n, s, bd, e, u, p){}

//metodi
QString Waiter::getType() const{
    return "cameriere";
}
