#ifndef CLIENTCONTROLLER_H
#define CLIENTCONTROLLER_H
#include "controller.h"
#include "clientview.h"
#include "startview.h"
#include "startcontroller.h"
#include "clientvaluationview.h"
#include "clientvaluationcontroller.h"
#include "edituserview.h"
#include "editusercontroller.h"
#include "client.h"
#include "user.h"
#include "listview.h"
#include "listcontroller.h"
#include <QObject>
#include <QWidget>

class ClientController : public Controller {
    Q_OBJECT
private:
    ClientView* clientview;
    Client* userLogged;
    db_user* db;

public:
    ClientController(ClientView*, Client*);
    ~ClientController();

private slots:
    void evaluate();
    void logout();
    void editUser();
    void deleteUser();
    void showMenu();
};

#endif // CLIENTCONTROLLER_H
