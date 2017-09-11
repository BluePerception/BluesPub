#include "accediview.h"
#include "ui_accediview.h"
#include <iostream>
using namespace std;

AccediView::AccediView(QWidget *parent) : QWidget(parent),ui(new Ui::AccediView){
    ui->setupUi(this);

    connect(ui->ind,SIGNAL(clicked(bool)),this, SLOT(back_slot()));

}

AccediView::~AccediView(){
    delete ui;
}

void AccediView::back_slot(){
    emit back_signal();
    cout<<"segnale indietro emesso"<<endl;
}







