#include "addlistitemview.h"
#include "ui_addlistitemview.h"

AddListItemView::AddListItemView(QWidget *parent) : QWidget(parent), ui(new Ui::AddListItemView) {
    ui->setupUi(this);

    ui->foodOrDrink->addItem("-- Seleziona tipo --");
    ui->foodOrDrink->addItem("Cibo");
    ui->foodOrDrink->addItem("Bevanda");
    ui->type->setEnabled(false);

    drinkTypes.append("Birra");
    drinkTypes.append("Analcolico");
    drinkTypes.append("Aperitivo");
    drinkTypes.append("Cocktail");
    drinkTypes.append("Distillato");

    foodTypes.append("Bruschetta");
    foodTypes.append("Toast");
    foodTypes.append("Panino");
    foodTypes.append("Frittura");
    foodTypes.append("Piatto");

    connect(ui->foodOrDrink, SIGNAL(currentIndexChanged(int)), this, SLOT(chooseFoodOrDrink(int)));
    connect(ui->back, SIGNAL(clicked(bool)), this, SIGNAL(backSignal()));
    connect(ui->add, SIGNAL(clicked(bool)), this, SIGNAL(addSignal()));
}

void AddListItemView::chooseFoodOrDrink(int index) {
    if (index != 0 && ui->foodOrDrink->itemText(0) == "-- Seleziona tipo --") {
        ui->foodOrDrink->removeItem(0);
        ui->type->setEnabled(true);
    }
    ui->type->clear();
    if (ui->foodOrDrink->currentText() == "Cibo")
        ui->type->addItems(foodTypes);
    else
        ui->type->addItems(drinkTypes);
}

QString AddListItemView::getFoodOrDrink() const {
    return ui->foodOrDrink->currentText();
}

QString AddListItemView::getType() const {
    return ui->type->currentText();
}

QString AddListItemView::getName() const {
    return ui->name->text();
}

QString AddListItemView::getDescription() const {
    return ui->description->toPlainText();
}

QString AddListItemView::getPrice() const {
    return QString::number(ui->price->value());
}

void AddListItemView::showError(const QString & error) {
    QMessageBox messageBox;
    messageBox.setText(error);
    messageBox.setFixedSize(500,200);
    messageBox.exec();
}

AddListItemView::~AddListItemView() {
    delete ui;
}
