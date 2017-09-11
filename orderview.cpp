#include "orderview.h"
#include "ui_orderview.h"

OrderView::OrderView(QWidget *parent) : QWidget(parent), ui(new Ui::OrderView), lastRow(0) {
    ui->setupUi(this);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);

    ui->type->addItem("-- Seleziona tipo --");
    ui->type->addItem("Cibo");
    ui->type->addItem("Bevanda");
    ui->specificType->setEnabled(false);
    ui->amount->setEnabled(false);

    connect(ui->type, SIGNAL(currentIndexChanged(int)), this, SLOT(changedType(int)));
    connect(ui->specificType, SIGNAL(currentIndexChanged(int)), this, SLOT(changedSpecificType(int)));
    connect(ui->ok, SIGNAL(clicked(bool)), this, SLOT(addOrder()));
    connect(ui->back, SIGNAL(clicked(bool)), this, SIGNAL(backSignal()));
    connect(ui->tableNumber, SIGNAL(valueChanged(int)), this, SIGNAL(tableChangeSignal(int)));

    foods.insert(0, "-- Seleziona cibo --");
    ui->specificType->addItems(foods);
    drinks.insert(0, "-- Seleziona bevanda --");
}

OrderView::~OrderView() {
    delete ui;
}

void OrderView::setAvailableFoods(const std::vector<QString>& foods_) {
    foods.clear();
    for(std::vector<QString>::const_iterator it = foods_.begin(); it!=foods_.end(); it++)
        foods.append(*it);
    foods.insert(0, "-- Seleziona cibo --");
}

void OrderView::setAvailableDrinks(const std::vector<QString>& drinks_) {
    drinks.clear();
    for(std::vector<QString>::const_iterator it = drinks_.begin(); it!=drinks_.end(); it++)
        drinks.append(*it);
    drinks.insert(0, "-- Seleziona bevanda --");

}

int OrderView::getSelectedQuantity() const {
    return ui->amount->text().toInt();
}

QString OrderView::getSelectedItem() const {
    return ui->specificType->itemText(ui->specificType->currentIndex());
}

int OrderView::getTable() const {
    return ui->tableNumber->text().toInt();
}

void OrderView::addOrder() {
    if ((ui->specificType->itemText(0) != "-- Seleziona cibo --" ||
       ui->specificType->itemText(0) != "-- Seleziona bevanda --") &&
       ui->type->itemText(0) != "-- Seleziona tipo --")
        emit addOrderSignal();
}

void OrderView::changedType(int index) {
    if (index != 0 && ui->type->itemText(0) == "-- Seleziona tipo --") {
        ui->type->removeItem(0);
        ui->specificType->setEnabled(true);
    }
    ui->specificType->clear();
    if (ui->type->currentText() == "Cibo")
        ui->specificType->addItems(foods);
    else
        ui->specificType->addItems(drinks);
}

void OrderView::changedSpecificType(int index) {
    if (index != 0 &&
       (ui->specificType->itemText(0) == "-- Seleziona cibo --" ||
        ui->specificType->itemText(0) == "-- Seleziona bevanda --")) {
        ui->specificType->removeItem(0);
    }
    ui->amount->setEnabled(true);
}

void OrderView::showNewOrder(Order* order) {
    lastRow++;
    ui->tableWidget->setRowCount(lastRow);
    ui->tableWidget->setItem(lastRow-1, 0, new QTableWidgetItem(QString::number(order->getQuantity())));
    ui->tableWidget->setItem(lastRow-1, 1, new QTableWidgetItem(order->getItem()->getName()));
    ui->tableWidget->setItem(lastRow-1, 2, new QTableWidgetItem("€" + QString(Utility::floatToString(order->getItem()->getPrice()))));
}

void OrderView::clearOrders() {
    lastRow=0;
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(lastRow);
}
