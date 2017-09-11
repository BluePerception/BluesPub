#include "user.h"

User::User(){
    name="";
    surname="";
    QDate();
    email="";
    username="";
    password="";
}

User::~User(){}

User::User(const QString & n, const QString & s, const QDate & b, const QString & e, const QString & u, const QString & p) :
    name(n), surname(s), birthDate(b), email(e), username(u), password(p){}

//GET
QString User::getName() const{
    return name;
}

QString User::getSurname() const{
    return surname;
}

QDate User::getBd() const{
    return birthDate;
}

QString User::getEmail() const{
    return email;
}

QString User::getUser() const{
    return username;
}

QString User::getPass() const{
    return password;
}

//SET
void User::setName(const QString& n){
    name=n;
}

void User::setSurname(const QString& s){
    surname=s;
}

void User::setBd(const QDate& bd){
    birthDate=bd;
}

void User::setEmail(const QString& e){
    email=e;
}

void User::setUser(const QString& u){
    username=u;
}

void User::setPass(const QString& p){
    password=p;
}



