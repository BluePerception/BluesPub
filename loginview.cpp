#include "loginview.h"
#include "ui_loginview.h"
#include <iostream>
using namespace std;

//costruttore
LoginView::LoginView(QWidget *parent) : QWidget(parent),ui(new Ui::LoginView){
    ui->setupUi(this);

    //connessioni
    connect(ui->login, SIGNAL(clicked(bool)), this, SIGNAL(loginSignal()));
    connect(ui->back, SIGNAL(clicked(bool)), this, SIGNAL(backSignal()));

}
//distruttore
LoginView::~LoginView(){
    delete ui;
}

//metodi per accedere ai dati inseriti
QString LoginView::getUsernameWritten(){
    return ui->username->text();
}

QString LoginView::getPasswordWritten(){
    return ui->password->text();
}
