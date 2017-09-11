#include "client.h"

//COSTRUTTORE
Client::Client(const QString & n, const QString & s, const QDate & bd, const QString & e, const QString & u, const QString & p) :
    User(n, s, bd, e, u, p){}

//METODI
QString Client::getType() const{
    return "cliente";
}
