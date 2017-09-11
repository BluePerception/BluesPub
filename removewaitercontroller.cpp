#include "removewaitercontroller.h"

RemoveWaiterController::RemoveWaiterController(RemoveWaiterView* rw, Holder* h) : removeview(rw), holder(h) {
    connect(removeview, SIGNAL(searchSignal()), this, SLOT(search()));
    connect(removeview, SIGNAL(backSignal()), this, SLOT(back()));
}

void RemoveWaiterController::showUsernameNotFoundError(){
    QMessageBox messageBox;
    messageBox.critical(0,"Errore","Nessun dipendente trovato con username " + removeview->getUsername());
    messageBox.setFixedSize(500,200);
}

void RemoveWaiterController::removeWaiter(Waiter* waiter) {
    getUserDbInstance()->erase_user(waiter->getUser());
}

void RemoveWaiterController::showWaiterInformation(Waiter* waiter) {
    QMessageBox msgBox;
    msgBox.setText(QString("Sei sicuro di voler eliminare questo account?\n") +
                   "Nome:\t\t" + waiter->getName() + "\n" +
                   "Cognome:\t" + waiter->getSurname() + "\n" +
                   "Data di nascita:\t" + waiter->getBd().toString("dd MMMM yyyy") + "\n" +
                   "Email:\t\t" + waiter->getEmail() + "\n" +
                   "Username:\t" + waiter->getUser());
    msgBox.setStyleSheet("font:15pt");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.show();
    if (msgBox.exec() == QMessageBox::Ok) {
        removeWaiter(waiter);
        back();
    }
}

void RemoveWaiterController::back() {
    HolderView* hv=new HolderView();
    emit changesignal(hv, new HolderController(hv, holder));
}

void RemoveWaiterController::search() {
    if (getUserDbInstance()->checkExistingUsername(removeview->getUsername())){
        User* user = getUserDbInstance()->findUser(removeview->getUsername());
        if (user->getType() != "cameriere")
            showUsernameNotFoundError();
        else
            showWaiterInformation((Waiter*)user);
    } else
        showUsernameNotFoundError();
}
