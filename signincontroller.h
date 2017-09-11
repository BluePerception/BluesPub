#ifndef SIGNINCONTROLLER_H
#define SIGNINCONTROLLER_H
#include "signinview.h"
#include "controller.h"
#include "checker.h"
#include "startview.h"
#include "startcontroller.h"
#include "db_user.h"
#include "user.h"
#include <iostream>
#include <list>
#include <QFile>
#include <QDate>
#include <QString>
#include <QRegularExpression>
#include "holderview.h"
#include "holdercontroller.h"


class SignInController : public Controller, public Checker{
    Q_OBJECT

private:
    SignInView* signinview;
    db_user* database;
    Holder* holder;

public:
    SignInController(SignInView*);
    SignInController(SignInView*, Holder*);
    ~SignInController();

private slots:
    void reg();
    void back();
    void error();
};

#endif // SIGNINCONTROLLER_H
