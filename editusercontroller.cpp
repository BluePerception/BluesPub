#include "editusercontroller.h"

//costruttore
EditUserController::EditUserController(EditUserView* euv, User* u) :
    edituser(euv), userLogged(u), database(getUserDbInstance()){

    connect(edituser, SIGNAL(backSignal()), this, SLOT(back()));
    connect(edituser, SIGNAL(doneSignal()), this, SLOT(done()));
}

EditUserController::~EditUserController() {
    database=0;
    userLogged=0;
    delete edituser;
}

//slots
void EditUserController::back(){
    if(userLogged->getType()=="cliente"){
        Client* user= new Client(userLogged->getName(), userLogged->getSurname(),userLogged->getBd(), userLogged->getEmail(), userLogged->getUser(), userLogged->getPass());
        ClientView* cv=new ClientView();
        emit changesignal(cv, new ClientController(cv, user));
    }
    //fare lo stesso per gli altri tipi
}

void EditUserController::done(){
    QString oldUsername=userLogged->getUser();

    if(userLogged->getName()!=edituser->getName()){
        if(edituser->getName()==""){
            QMessageBox messageBox;
            messageBox.critical(0, "Errore","Campo dati 'Nome' vuoto.");
            messageBox.setFixedSize(500,200);
        }
        else
            userLogged->setName(edituser->getName());
    }
    if(userLogged->getSurname()!=edituser->getSurname()){
        if(edituser->getSurname()==""){
            QMessageBox messageBox;
            messageBox.critical(0, "Errore","Campo dati 'Cognome' vuoto.");
            messageBox.setFixedSize(500,200);
        }
        else
            userLogged->setSurname(edituser->getSurname());
    }
    if(userLogged->getBd()!=edituser->getBirth()){
        if(!checkBirth(edituser->getBirth())){
            QMessageBox messageBox;
            messageBox.critical(0, "Errore","Campo dati 'Data di nascita' vuoto.");
            messageBox.setFixedSize(500,200);
        }
        else
            userLogged->setBd(edituser->getBirth());
    }
    if(userLogged->getEmail()!=edituser->getEmail()){
        if(edituser->getEmail()==""){
            QMessageBox messageBox;
            messageBox.critical(0, "Errore","Campo dati 'Email' vuoto.");
            messageBox.setFixedSize(500,200);
        }
        else{
            if(checkEmail(edituser->getEmail()))
                userLogged->setEmail(edituser->getEmail());
            else{
                QMessageBox messageBox;
                messageBox.critical(0, "Errore","Email già presente nel database.");
                messageBox.setFixedSize(500,200);
            }
        }
    }
    if(userLogged->getUser()!=edituser->getUsername()){
        if(edituser->getUsername()==""){
            QMessageBox messageBox;
            messageBox.critical(0, "Errore","Campo dati 'Username' vuoto.");
            messageBox.setFixedSize(500,200);
        }
        else{
            if(checkUsername(edituser->getUsername()))
                userLogged->setUser(edituser->getUsername());
            else{
                QMessageBox messageBox;
                messageBox.critical(0, "Errore","Username già presente nel database.");
                messageBox.setFixedSize(500,200);
            }
        }
    }
    if(userLogged->getPass()!=edituser->getPassword()){
        if(edituser->getPassword()==""){
            QMessageBox messageBox;
            messageBox.critical(0, "Errore","Campo dati 'Passoword' vuoto.");
            messageBox.setFixedSize(500,200);
        }
        else
            userLogged->setPass(edituser->getPassword());
    }
    database->modify_user(oldUsername, userLogged);
    QMessageBox messageBox;
    messageBox.information(0,"BluesPub","Modifica dati effettuata!");
    messageBox.setFixedSize(500,200);
    if(userLogged->getType()=="cliente"){
        Client* user= new Client(userLogged->getName(), userLogged->getSurname(),userLogged->getBd(), userLogged->getEmail(), userLogged->getUser(), userLogged->getPass());
        ClientView* cv=new ClientView();
        emit changesignal(cv, new ClientController(cv, user));

    }

}
