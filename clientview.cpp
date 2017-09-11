#include "clientview.h"
#include "ui_clientview.h"

//costruttore
ClientView::ClientView(QWidget *parent) : QWidget(parent), ui(new Ui::ClientView){
    ui->setupUi(this);

    connect(ui->logout, SIGNAL(clicked(bool)), this, SIGNAL(logoutSignal()));
    connect(ui->evaluate, SIGNAL(clicked(bool)), this, SIGNAL(evaluateSignal()));
    connect(ui->editUser, SIGNAL(clicked(bool)), this, SIGNAL(editUserSignal()));
    connect(ui->deleteUser, SIGNAL(clicked(bool)), this, SIGNAL(deleteUserSignal()));
    connect(ui->menu, SIGNAL(clicked(bool)), this, SIGNAL(showMenuSignal()));
}

//distruttore
ClientView::~ClientView(){
    delete ui;
}
