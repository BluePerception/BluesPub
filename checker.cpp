#include "checker.h"

Checker::Checker() : database(new db_user){}

//METODI CHECK
bool Checker::checkAdultUser(const QDate & userBirth) const{    //verifico che l'utente sia maggiorenne
    QDate today = QDate::currentDate();
    if(today.year()-userBirth.year() > 18)
        return true;
    else{
        if(today.month()-userBirth.month() > 0)
            return true;
        else{
            return (today.day()-userBirth.day() > -1);
        }
    }
}

bool Checker::checkBirth(const QDate & birthAdded) const{    //controllo che la data sia valida e di un utente maggiorenne
    return (birthAdded.isValid() && checkAdultUser(birthAdded));
}

bool Checker::checkEmail(const QString & emailAdded) const{
    QRegularExpression regular("^[0-9a-zA-Z]+([0-9a-zA-Z]*[-._+])*[0-9a-zA-Z]+@[0-9a-zA-Z]+([-.][0-9a-zA-Z]+)*([0-9a-zA-Z]*[.])[a-zA-Z]{2,6}$");
    return (regular.match(emailAdded).hasMatch() && !(database->checkExistingEmail(emailAdded)));
}

bool Checker::checkUsername(const QString & usernameAdded) const{
    return (usernameAdded.size() > 5 && !(database->checkExistingUsername(usernameAdded)));
}

bool Checker::checkPassword(const QString & password) const{
    return (password.size() > 5);
}

bool Checker::checkConfirmationPassword(const QString & password, const QString & confirmation) const{
    return (password == confirmation);
}
