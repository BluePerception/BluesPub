#include "waiterview.h"
#include "ui_waiterview.h"

//costruttore
WaiterView::WaiterView(QWidget *parent) : QWidget(parent), ui(new Ui::WaiterView){
    ui->setupUi(this);

    connect(ui->logout, SIGNAL(clicked(bool)), this, SIGNAL(logoutSignal()));
    connect(ui->order, SIGNAL(clicked(bool)), this, SIGNAL(takeOrderSignal()));
    connect(ui->bill, SIGNAL(clicked(bool)), this, SIGNAL(totalSignal()));
}

//distruttore
WaiterView::~WaiterView(){
    delete ui;
}
