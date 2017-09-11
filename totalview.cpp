#include "totalview.h"
#include "ui_totalview.h"

TotalView::TotalView(QWidget *parent) : QWidget(parent), ui(new Ui::TotalView) {
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);

    connect(ui->tableNumber, SIGNAL(valueChanged(int)), this, SIGNAL(tableChangeSignal(int)));
    connect(ui->back, SIGNAL(clicked(bool)), this, SIGNAL(backSignal()));
    connect(ui->close, SIGNAL(clicked(bool)), this, SIGNAL(closeSignal()));
}

TotalView::~TotalView() {
    delete ui;
}

void TotalView::setOrdersToDisplay(const std::vector<Order *> & orders) {
    int number = orders.size();
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(number);
    for(int i = 0; i < number; i++) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(orders[i]->getQuantity())));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(orders[i]->getItem()->getName()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem("€" + QString(Utility::floatToString(orders[i]->getItem()->getPrice()))));
    }
}

void TotalView::setTotal(const float& total) {
    ui->total->setText(QString(Utility::floatToString(total)));
}
