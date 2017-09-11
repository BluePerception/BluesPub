#include "holderview.h"
#include "ui_holderview.h"

HolderView::HolderView(QWidget *parent) : QWidget(parent), ui(new Ui::HolderView) {
    ui->setupUi(this);
    connect(ui->valuation, SIGNAL(clicked(bool)), this, SIGNAL(valuationSignal()));
    connect(ui->bill, SIGNAL(clicked(bool)), this, SIGNAL(billSignal()));
    connect(ui->order, SIGNAL(clicked(bool)), this, SIGNAL(orderSignal()));
    connect(ui->modifyList, SIGNAL(clicked(bool)), this, SIGNAL(modifyListSignal()));
    connect(ui->addWaiter, SIGNAL(clicked(bool)), this, SIGNAL(addWaiterSignal()));
    connect(ui->removeWaiter, SIGNAL(clicked(bool)), this, SIGNAL(removeWaiterSignal()));
    connect(ui->logout, SIGNAL(clicked(bool)), this, SIGNAL(logoutSignal()));

}

HolderView::~HolderView(){
    delete ui;
}
