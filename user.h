#ifndef UTENTE_H
#define UTENTE_H
#include <iostream>
#include <QDate>
#include <QString>

class User{
private:
    //campi che definiscono il mio utente (tipo attributi della tabella "User")
    QString name;
    QString surname;
    QDate birthDate;
    QString email;
    QString username;
    QString password;

protected:
    User();
    User(const QString &, const QString &, const QDate &, const QString &, const QString &, const QString &);

public:
    virtual ~User();

    //medoti
    //questi metodi che hanno il compito di restituirmi il campo richiesto, li posso dischiare const (non devo apportare modifiche)
    QString getName() const;
    QString getSurname() const;
    QDate getBd() const;
    QString getEmail() const;
    virtual QString getType() const =0;
    QString getUser() const;
    QString getPass() const;

    //metodi per settare il valore nei vari campi di utente, ovviamente passo l'oggetto per riferimento
    void setName(const QString&);
    void setSurname(const QString&);
    void setBd(const QDate&);
    void setEmail(const QString&);
    void setUser(const QString&);
    void setPass(const QString&);

    //metodi per salvare e leggere i dati di login nel database


};

#endif // UTENTE_H
