#include "holderlistview.h"
#include "ui_holderlistview.h"

HolderListView::HolderListView(QWidget *parent) : QTabWidget(parent), ui(new Ui::HolderListView),
    mainLayoutFoods(new QVBoxLayout), scrollLayoutFoods(new QHBoxLayout),
    tableFoods(new QTableWidget), backLayoutFoods(new QHBoxLayout),
    spacerFoods(new QSpacerItem(0,0,QSizePolicy::Expanding)), backFoods(new QPushButton("Indietro")),
    addFoods(new QPushButton("Aggiungi")),
    mainLayoutDrinks(new QVBoxLayout), scrollLayoutDrinks(new QHBoxLayout),
    tableDrinks(new QTableWidget), backLayoutDrinks(new QHBoxLayout),
    spacerDrinks(new QSpacerItem(0,0,QSizePolicy::Expanding)), backDrinks(new QPushButton("Indietro")),
    addDrinks(new QPushButton("Aggiungi")) {
    ui->setupUi(this);

    backDrinks->setStyleSheet("font: 20pt");
    addDrinks->setStyleSheet("font: 20pt");
    backFoods->setStyleSheet("font: 20pt");
    addFoods->setStyleSheet("font: 20pt");
    tableFoods->setStyleSheet("font: 20pt");
    tableDrinks->setStyleSheet("font: 20pt");

    backLayoutDrinks->addSpacerItem(spacerDrinks);
    backLayoutDrinks->addWidget(backDrinks);
    backLayoutDrinks->addWidget(addDrinks);

    backLayoutFoods->addSpacerItem(spacerFoods);
    backLayoutFoods->addWidget(backFoods);
    backLayoutFoods->addWidget(addFoods);

    setupTableHeaders(tableFoods);
    setupTableHeaders(tableDrinks);

    connect(backFoods, SIGNAL(clicked(bool)), this, SIGNAL(backSignal()));
    connect(addFoods, SIGNAL(clicked(bool)), this, SIGNAL(addSignal()));
    connect(backDrinks, SIGNAL(clicked(bool)), this, SIGNAL(backSignal()));
    connect(addDrinks, SIGNAL(clicked(bool)), this, SIGNAL(addSignal()));
}

void HolderListView::setupTableHeaders(QTableWidget* table) {
    table->setColumnCount(5);
    table->setHorizontalHeaderItem(0, new QTableWidgetItem("Nome"));
    table->setHorizontalHeaderItem(1, new QTableWidgetItem("Descrizione"));
    table->setHorizontalHeaderItem(2, new QTableWidgetItem("Tipo"));
    table->setHorizontalHeaderItem(3, new QTableWidgetItem("Prezzo (€)"));
    table->setHorizontalHeaderItem(4, new QTableWidgetItem(""));
}

void HolderListView::showDrinks(const std::vector<const Drink*> & drinks_) {
    int lastRow=0;
    drinks=drinks_;
    tableDrinks->setRowCount(drinks.size());
    QStringList list;
    list.append("Birra");
    list.append("Analcolico");
    list.append("Aperitivo");
    list.append("Cocktail");
    list.append("Distillato");
    std::vector<const Drink*>::const_iterator it;
    for(it=drinks_.begin(); it!=drinks_.end(); it++) {
        setupTableRow(lastRow, (*it)->getName(), (*it)->getDescription(),
                      list, ListItem::typeToString((*it)->getType()),
                      Utility::floatToString((*it)->getPrice()),
                      false);
        lastRow++;
    }
    resizeTable(tableDrinks);
    scrollLayoutDrinks->addWidget(tableDrinks);
    ui->scrollAreaDrinks->setLayout(scrollLayoutDrinks);
    mainLayoutDrinks->insertWidget(0, ui->scrollAreaDrinks);
    mainLayoutDrinks->addLayout(backLayoutDrinks);
    ui->drinks->setLayout(mainLayoutDrinks);
    connect(tableDrinks, SIGNAL(cellChanged(int, int)), this, SLOT(changedDrink(int, int)));
}
#include <QtDebug>
void HolderListView::showFoods(const std::vector<const Food*> & foods_) {
    int lastRow=0;
    foods=foods_;
    tableFoods->setRowCount(foods.size());
    QStringList list;
    list.append("Bruschetta");
    list.append("Toast");
    list.append("Panino");
    list.append("Frittura");
    list.append("Piatto");
    std::vector<const Food*>::const_iterator it;
    for(it=foods.begin(); it!=foods.end(); it++) {
        if (*it) {
            setupTableRow(lastRow, (*it)->getName(), (*it)->getDescription(),
                          list, ListItem::typeToString((*it)->getType()),
                          Utility::floatToString((*it)->getPrice()),
                          true);
            lastRow++;
        }
    }
    resizeTable(tableFoods);
    scrollLayoutFoods->addWidget(tableFoods);
    ui->scrollAreaFoods->setLayout(scrollLayoutFoods);
    mainLayoutFoods->insertWidget(0, ui->scrollAreaFoods);
    mainLayoutFoods->addLayout(backLayoutFoods);
    ui->foods->setLayout(mainLayoutFoods);
    connect(tableFoods, SIGNAL(cellChanged(int, int)), this, SLOT(changedFood(int, int)));
}

void HolderListView::setupTableRow(const int & row, const QString & name, const QString & description,
                                   const QStringList &  types, const QString & selType, const QString & price,
                                   const bool & food) {
    QTableWidget* table;
    if(food)
        table=tableFoods;
    else
        table=tableDrinks;
    table->setItem(row, 0, new QTableWidgetItem(name));
    table->setItem(row, 1, new QTableWidgetItem(description));
    QComboBox* type=new QComboBox();
    type->addItems(types);
    type->setProperty("row", row);
    type->setCurrentText(selType);
    table->setCellWidget(row, 2, type);
    if (food)
        connect(type, SIGNAL(currentTextChanged(QString)), this, SLOT(changeTypeComboFoods()));
    else
        connect(type, SIGNAL(currentTextChanged(QString)), this, SLOT(changeTypeComboDrinks()));
    table->setItem(row, 3, new QTableWidgetItem(price));
    QPushButton* remove=new QPushButton("Rimuovi");
    remove->setProperty("row", row);
    table->setCellWidget(row, 4, remove);
    if (food)
        connect(remove, SIGNAL(clicked(bool)), this, SLOT(removeFood()));
    else
        connect(remove, SIGNAL(clicked(bool)), this, SLOT(removeDrink()));
}

void HolderListView::resizeTable(QTableWidget* table) {
    table->resizeColumnsToContents();
    table->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    table->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    table->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    table->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    table->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents);
}

bool HolderListView::checkPrice(const int & row, QTableWidget* table) {
    QString price=table->item(row, 3)->text();
    QRegularExpression regular("^[0-9]{0,5}[.][0-9]{1,2}");
    return regular.match(price).hasMatch();
}

void HolderListView::showWrongPrice() {
    QMessageBox messageBox;
    messageBox.setText("Prezzo inserito non valido");
    messageBox.setFixedSize(500,200);
    messageBox.exec();
}

void HolderListView::changedFood(int row, int){
    if (!checkPrice(row, tableFoods)){
        showWrongPrice();
        tableFoods->item(row, 3)->setText(Utility::floatToString(foods[row]->getPrice()));
    } else {
        Food* f=new Food(tableFoods->item(row, 0)->text(), tableFoods->item(row, 1)->text(),
                         tableFoods->item(row, 3)->text().toFloat(),
                         ListItem::stringToType(((QComboBox*)tableFoods->cellWidget(row, 2))->currentText()));
        const Food* old = foods[row];
        foods[row]=f;
        emit changeFoodSignal(old, f);
    }
}

void HolderListView::changeTypeComboFoods() {
    QObject* obj = sender();
    changedFood(obj->property("row").toInt(), 2);
}

void HolderListView::removeFood() {
    QMessageBox msgBox;
    msgBox.setText("Sei sicuro di voler eliminare l'articolo?");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    if (msgBox.exec() == QMessageBox::Ok) {
        QObject* obj = sender();
        int row=obj->property("row").toInt();
        Food* f=new Food(tableFoods->item(row, 0)->text(), tableFoods->item(row, 1)->text(),
                         tableFoods->item(row, 3)->text().toFloat(),
                         ListItem::stringToType(((QComboBox*)tableFoods->cellWidget(row, 2))->currentText()));
        emit removeFoodSignal(f);
    }
}

void HolderListView::changedDrink(int row, int){
    if (!checkPrice(row, tableDrinks)){
        showWrongPrice();
        tableDrinks->item(row, 3)->setText(Utility::floatToString(drinks[row]->getPrice()));
    } else {
        Drink* f=new Drink(tableDrinks->item(row, 0)->text(), tableDrinks->item(row, 1)->text(),
                         tableDrinks->item(row, 3)->text().toFloat(),
                         ListItem::stringToType(((QComboBox*)tableDrinks->cellWidget(row, 2))->currentText()));
        const Drink* old = drinks[row];
        drinks[row]=f;
        emit changeDrinkSignal(old, f);
    }
}

void HolderListView::changeTypeComboDrinks(){
    QObject* obj = sender();
    changedDrink(obj->property("row").toInt(), 2);
}

void HolderListView::removeDrink(){
    QMessageBox msgBox;
    msgBox.setText("Sei sicuro di voler eliminare l'articolo?");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    if (msgBox.exec() == QMessageBox::Ok) {
        QObject* obj = sender();
        int row=obj->property("row").toInt();
        Drink* f=new Drink(tableDrinks->item(row, 0)->text(), tableDrinks->item(row, 1)->text(),
                         tableDrinks->item(row, 3)->text().toFloat(),
                         ListItem::stringToType(((QComboBox*)tableDrinks->cellWidget(row, 2))->currentText()));
        emit removeDrinkSignal(f);
    }
}


void HolderListView::notRemovableError() {
    QMessageBox messageBox;
    messageBox.setText("Non è possibile eliminare l'articolo perchè ci sono delle ordinazioni ad esso associate");
    messageBox.setFixedSize(500,200);
    messageBox.exec();
}

HolderListView::~HolderListView() {
    delete tableFoods;
    delete tableDrinks;
    delete backLayoutDrinks;
    delete backLayoutFoods;
    delete scrollLayoutFoods;
    delete scrollLayoutDrinks;
    delete mainLayoutDrinks;
    delete mainLayoutFoods;
    delete ui;
}
