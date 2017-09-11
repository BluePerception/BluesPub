#include "clientcontroller.h"

//costruttore
ClientController::ClientController(ClientView* cv, Client* u) :
    clientview(cv), userLogged(u), db(getUserDbInstance()){
    connect(clientview, SIGNAL(evaluateSignal()), this, SLOT(evaluate()));
    connect(clientview, SIGNAL(logoutSignal()), this, SLOT(logout()));
    connect(clientview, SIGNAL(editUserSignal()), this, SLOT(editUser()));
    connect(clientview, SIGNAL(deleteUserSignal()), this, SLOT(deleteUser()));
    connect(clientview, SIGNAL(showMenuSignal()), this, SLOT(showMenu()));
}

ClientController::~ClientController() {
    db=0;
    userLogged=0;
    delete clientview;
}

//slots
void ClientController::evaluate() {
    Client* user=userLogged;
    ClientValuationView* cvv = new ClientValuationView();
    emit changesignal(cvv, new ClientValuationController(cvv, user));
}

void ClientController::logout() {
    StartView* startview = new StartView();
    emit changesignal(startview, new StartController(startview));
}

void ClientController::editUser() {
    User* user=userLogged;
    EditUserView* edituser = new EditUserView(user);
    emit changesignal(edituser, new EditUserController(edituser, user));
}

void ClientController::deleteUser() {
    QMessageBox msgBox;
    msgBox.setText("Sei sicuro di voler eliminare il tuo account?");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    if (msgBox.exec() == QMessageBox::Ok) {
        db->erase_user(userLogged->getUser());
        logout();
    }
}

void ClientController::showMenu() {
    ListView* listview = new ListView();
    emit changesignal(listview, new ListController(listview, userLogged));
}
