#include "signinview.h"
#include "ui_signinview.h"

SignInView::SignInView(QWidget *parent) : QWidget(parent), ui(new Ui::SignInView){
    ui->setupUi(this);

    connect(ui->ind, SIGNAL(clicked(bool)), this, SLOT(back()));
    connect(ui->reg, SIGNAL(clicked(bool)), this, SLOT(reg()));
}

SignInView::~SignInView(){
    delete ui;
}


//controllo se vengono compilati tutti i campi
bool SignInView::emptyReg() const{
    return ui->name->text().isEmpty() ||
           ui->surname->text().isEmpty() ||
           ui->date->date().year()==1800 ||
           ui->email->text().isEmpty() ||
           ui->username->text().isEmpty() ||
           ui->password->text().isEmpty() ||
           ui->passwordconferma->text().isEmpty();
}

//metodi per ottenere le stringhe inserite dall'utente
QString SignInView::getName() const{
    return ui->name->text();
}

QString SignInView::getSurname() const{
    return ui->surname->text();
}

QString SignInView::getEmail() const{
    return ui->email->text();
}

QDate SignInView::getBirth() const{
    return ui->date->date();
}

QString SignInView::getUsername() const{
    return ui->username->text();
}

QString SignInView::getPassword() const{
    return ui->password->text();
}

QString SignInView::getConfirmationPassword() const{
    return ui->passwordconferma->text();
}

//SLOTS
void SignInView::reg(){
    if(!emptyReg())
        emit regSignal();
    else
        emit errorSignal();
}

void SignInView::back(){
    emit backSignal();
}
