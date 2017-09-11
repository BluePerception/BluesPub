#ifndef LOGINCONTROLLER_H
#define LOGINCONTROLLER_H
#include "loginview.h"
#include "controller.h"
#include "startview.h"
#include "startcontroller.h"
#include "db_user.h"
#include "user.h"
#include "clientview.h"
#include "clientcontroller.h"
#include "waiterview.h"
#include "waitercontroller.h"
#include "holderview.h"
#include "holdercontroller.h"
#include <iostream>
#include <list>
#include <QFile>
#include <QDate>
#include <QString>
#include <QMessageBox>

class LoginController : public Controller{
    Q_OBJECT

private:
    LoginView* loginview;
    db_user* database;

public:
    LoginController(LoginView*);
    ~LoginController();

private slots:
    void login();
    void back();

};

#endif // LOGINCONTROLLER_H
