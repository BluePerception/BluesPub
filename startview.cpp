#include "startview.h"
#include "ui_startview.h"
#include <iostream>
using namespace std;

StartView::StartView(QWidget *parent) : QWidget(parent), ui(new Ui::StartView){
    ui->setupUi(this);
    this->setStyleSheet("background-image: url(res/images/sunset.jpg);");

    //connetto i bottoni ai segnali
    connect(ui->accedi, SIGNAL(clicked(bool)), this, SLOT(login()));
    connect(ui->registrati, SIGNAL(clicked(bool)), this, SLOT(reg()));
}

StartView::~StartView(){
    delete ui;
}

void StartView::login(){
    emit loginSignal();
}

void StartView::reg(){
    emit regSignal();
}
