#include "clientvaluationcontroller.h"


//costruttore
ClientValuationController::ClientValuationController(ClientValuationView* cvv, Client* u) :
    clientvalview(cvv), userLogged(u), db(getValuationDbInstance()){

    connect(clientvalview, SIGNAL(backSignal()), this, SLOT(back()));
    connect(clientvalview, SIGNAL(doneSignal()), this, SLOT(done()));
}

ClientValuationController::~ClientValuationController(){
    db=0;
    userLogged=0;
    delete clientvalview;
}

//slots
void ClientValuationController::back(){
    Client* user=userLogged;
    ClientView* cv = new ClientView();
    emit changesignal(cv, new ClientController(cv, user));
}

void ClientValuationController::done(){
    //non serve controllare che l'utente abbia messo un punteggio, perchè di defaul c'è la spunta sul punteggio massimo
    //che sia meglio lasciare tutto libero, è un altro discorso
    Client* user=userLogged;
    Rate newRate(clientvalview->readServiceRate(), clientvalview->readMealRate());
    db->save_rate(newRate);
    QMessageBox messageBox;
    messageBox.information(0,"Valutazione inviata","Grazie per averci dato il tuo parere!");
    messageBox.setFixedSize(500,200);
    ClientView* cw=new ClientView();
    emit changesignal(cw, new ClientController(cw, user));
}
