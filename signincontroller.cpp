#include "signincontroller.h"
#include <QMessageBox>

SignInController::SignInController(SignInView* sw) : signinview(sw), database(getUserDbInstance()), holder(0) {
    connect(signinview, SIGNAL(backSignal()), this, SLOT(back()));
    connect(signinview, SIGNAL(errorSignal()), this, SLOT(error()));
    connect(signinview, SIGNAL(regSignal()), this, SLOT(reg()));
}

SignInController::SignInController(SignInView* sw, Holder* h) : signinview(sw), database(getUserDbInstance()), holder(h) {
    connect(signinview, SIGNAL(backSignal()), this, SLOT(back()));
    connect(signinview, SIGNAL(errorSignal()), this, SLOT(error()));
    connect(signinview, SIGNAL(regSignal()), this, SLOT(reg()));
}

SignInController::~SignInController(){
    database=0;
    holder=0;
    delete signinview;
}

//SLOTS
void SignInController::reg(){
    //se i controlli dei miei campi risultano positivi, allora posso procedere a salvare il mio utente nel database e dopo aver salvato l'utente lo riporto alla pagina iniziare dovepuù fare la login
    if(checkBirth(this->signinview->getBirth()) &&
       checkEmail(this->signinview->getEmail()) &&
       checkUsername(this->signinview->getUsername()) &&
       checkPassword(this->signinview->getPassword()) &&
       checkConfirmationPassword(this->signinview->getPassword(),  this->signinview->getConfirmationPassword())) {
        QMessageBox messageBox;
        messageBox.setText("Registrazione avvenuta con successo!");
        messageBox.setFixedSize(500,200);
        messageBox.exec();
        if (holder){
            Waiter* newUser = new Waiter(this->signinview->getName(), this->signinview->getSurname(), this->signinview->getBirth(), this->signinview->getEmail(), this->signinview->getUsername(), this->signinview->getPassword());
            database->save_user(*newUser);
            HolderView* hw=new HolderView();
            emit changesignal(hw, new HolderController(hw, holder));
        }
        else {
            Client* newUser = new Client(this->signinview->getName(), this->signinview->getSurname(), this->signinview->getBirth(), this->signinview->getEmail(), this->signinview->getUsername(), this->signinview->getPassword());
            database->save_user(*newUser);
            StartView* sw=new StartView();
            emit changesignal(sw, new StartController(sw));
        }
    }
    else{
        if(!checkBirth(this->signinview->getBirth())){
            QMessageBox messageBox;
            messageBox.critical(0,"Errore","Data di nascita non valida.");
            messageBox.setFixedSize(500,200);
        }
        if(!checkEmail(this->signinview->getEmail())){
            QMessageBox messageBox;
            messageBox.critical(0,"Errore","Email non valida.");
            messageBox.setFixedSize(500,200);
        }
        if(!checkUsername(this->signinview->getUsername())){
            QMessageBox messageBox;
            messageBox.critical(0,"Errore","Username non valido o non disponibile");
            messageBox.setFixedSize(500,200);
        }
        if(!checkPassword(this->signinview->getPassword())){
            QMessageBox messageBox;
            messageBox.critical(0,"Errore","Password troppo corta.");
            messageBox.setFixedSize(500,200);
        }
        if(!checkConfirmationPassword(this->signinview->getPassword(), this->signinview->getConfirmationPassword())){
            QMessageBox messageBox;
            messageBox.critical(0,"Errore","Password e password di conferma differenti.");
            messageBox.setFixedSize(500,200);
        }
    }

}

void SignInController::back(){
    if (holder){
        HolderView* hw=new HolderView();
        emit changesignal(hw, new HolderController(hw, holder));
    }
    else {
        StartView* sw=new StartView();
        emit changesignal(sw, new StartController(sw));
    }
}

void SignInController::error(){
    QMessageBox messageBox;
    messageBox.setStyleSheet("font: 20pt");
    messageBox.critical(0,"Errore","Non tutti i campi sono stati compilati");
    messageBox.setFixedSize(500,200);
}
