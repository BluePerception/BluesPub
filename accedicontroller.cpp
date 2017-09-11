#include "accedicontroller.h"
#include <iostream>
using namespace std;

AccediController::AccediController(AccediView* aw) : accediview(aw){
    //connects con gli slots
    connect(accediview,SIGNAL(back_signal()),this,SLOT(back_slot()));

}

void AccediController::accedi_slot(){

}

void AccediController::back_slot(){
    cout<<"cambia pagina"<<endl;
    StartView* startview = new StartView();
    emit changesignal(startview, new StartController(startview));
}


