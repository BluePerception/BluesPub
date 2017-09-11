#include "startcontroller.h"
#include<iostream>
using namespace std;

StartController::StartController(StartView * sw) : startview(sw){
    //connect view con gli slots
    connect(startview, SIGNAL(loginSignal()), this, SLOT(login()));
    connect(startview, SIGNAL(regSignal()), this, SLOT(reg()));
}

StartController::~StartController(){
    //delete startview;
}

void StartController::login(){
    LoginView* loginview = new LoginView();
    emit changesignal(loginview, new LoginController(loginview));
}

void StartController::reg(){
    SignInView* signin = new SignInView();
    emit changesignal(signin, new SignInController(signin));
}
