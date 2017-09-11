#include "edituserview.h"
#include "ui_edituserview.h"
#include "iostream"
using namespace std;

EditUserView::EditUserView(User* & user, QWidget *parent) : QWidget(parent), ui(new Ui::EditUserView), userData(user) {
    ui->setupUi(this);
    ui->name->setText(userData->getName());
    ui->surname->setText(user->getSurname());
    ui->date->setDate(user->getBd());
    ui->email->setText(user->getEmail());
    ui->username->setText(user->getUser());
    ui->password->setText(user->getPass());
    ui->passwordConferma->setText(user->getPass());

    //connect
    connect(ui->back, SIGNAL(clicked(bool)), this, SIGNAL(backSignal()));
    connect(ui->done, SIGNAL(clicked(bool)), this, SIGNAL(doneSignal()));
}

//distruttore
EditUserView::~EditUserView(){
    delete ui;
}

//metodi per ottenere le stringhe inserite dall'utente
QString EditUserView::getName() const{
    return ui->name->text();
}

QString EditUserView::getSurname() const{
    return ui->surname->text();
}

QString EditUserView::getEmail() const{
    return ui->email->text();
}

QDate EditUserView::getBirth() const{
    return ui->date->date();
}

QString EditUserView::getUsername() const{
    return ui->username->text();
}

QString EditUserView::getPassword() const{
    return ui->password->text();
}

QString EditUserView::getConfirmationPassword() const{
    return ui->passwordConferma->text();
}
