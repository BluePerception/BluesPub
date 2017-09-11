 #include "logincontroller.h"
#include <iostream>
using namespace std;

//COSTRUTTORE
LoginController::LoginController(LoginView* aw) : loginview(aw), database(getUserDbInstance()) {

    //connects con gli slots
    connect(loginview, SIGNAL(loginSignal()), this, SLOT(login()));
    connect(loginview, SIGNAL(backSignal()), this, SLOT(back()));

}

LoginController::~LoginController(){
    database=0;
    delete loginview;
}

//SLOTS
void LoginController::login(){
    User* userLogged=database->checkLogin(loginview->getUsernameWritten(), loginview->getPasswordWritten());
    if(userLogged==nullptr){
        QMessageBox messageBox;
        messageBox.critical(0,"Errore","Username o password sbagliata.");
        messageBox.setFixedSize(500,200);
    }
    else{
        if(userLogged->getType()=="cliente"){
            Client* user= new Client(userLogged->getName(), userLogged->getSurname(),userLogged->getBd(), userLogged->getEmail(), userLogged->getUser(), userLogged->getPass());
            ClientView* clientview = new ClientView();
            emit changesignal(clientview, new ClientController(clientview, user));
        }
        else{
            if(userLogged->getType()=="cameriere"){
                Waiter* user= new Waiter(userLogged->getName(), userLogged->getSurname(),userLogged->getBd(), userLogged->getEmail(), userLogged->getUser(), userLogged->getPass());
                WaiterView* waiterview = new WaiterView();
                emit changesignal(waiterview, new WaiterController(waiterview, user));
            }
            else{
                Holder* user= new Holder(userLogged->getName(), userLogged->getSurname(),userLogged->getBd(), userLogged->getEmail(), userLogged->getUser(), userLogged->getPass());
                HolderView* holderview = new HolderView();
                emit changesignal(holderview, new HolderController(holderview, user));
            }
        }
    }
}

void LoginController::back(){
    StartView* startview = new StartView();
    emit changesignal(startview, new StartController(startview));
}


