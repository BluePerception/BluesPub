#ifndef EDITUSERCONTROLLER_H
#define EDITUSERCONTROLLER_H

#include <QObject>
#include <QWidget>
#include "controller.h"
#include "checker.h"
#include "edituserview.h"
#include "user.h"
#include "clientview.h"
#include "clientcontroller.h"
#include "db_user.h"
#include <QMessageBox>

class EditUserController : public Controller, public Checker{
    Q_OBJECT
private:
    EditUserView* edituser;
    User* userLogged;
    db_user* database;

public:
    EditUserController(EditUserView*, User*);
    ~EditUserController();

private slots:
    void back();
    void done();

};

#endif // EDITUSERCONTROLLER_H
