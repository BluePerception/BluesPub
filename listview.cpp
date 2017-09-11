#include "listview.h"
#include "ui_listview.h"

ListView::ListView(QWidget *parent) : QTabWidget(parent), ui(new Ui::ListView),
    layoutFoods(new QVBoxLayout()), layoutDrinks(new QVBoxLayout()),
    backLayoutFoods(new QHBoxLayout()), backFoods(new QPushButton("Indietro")),
    spacerFoods(new QSpacerItem(0,0,QSizePolicy::Expanding)),
    backLayoutDrinks(new QHBoxLayout()), backDrinks(new QPushButton("Indietro")),
    spacerDrinks(new QSpacerItem(0,0,QSizePolicy::Expanding)),
    mainFoods(new QVBoxLayout()), mainDrinks(new QVBoxLayout()) {
    ui->setupUi(this);
    connect(backFoods, SIGNAL(clicked(bool)), this, SIGNAL(backSignal()));
    connect(backDrinks, SIGNAL(clicked(bool)), this, SIGNAL(backSignal()));
}

void ListView::setUpBruschettes(const int & number, const std::vector<QString> & names, const std::vector<QString> & descriptions, const std::vector<float> & prices) {
    setUpListForType("Bruschette", number, names, descriptions, prices, layoutFoods);
}

void ListView::setUpToasts(const int & number, const std::vector<QString> & names, const std::vector<QString> & descriptions, const std::vector<float> & prices) {
    setUpListForType("Toast", number, names, descriptions, prices, layoutFoods);
}

void ListView::setUpSandwiches(const int & number, const std::vector<QString> & names, const std::vector<QString> & descriptions, const std::vector<float> & prices) {
    setUpListForType("Panini", number, names, descriptions, prices, layoutFoods);
}

void ListView::setUpFries(const int & number, const std::vector<QString> & names, const std::vector<QString> & descriptions, const std::vector<float> & prices) {
    setUpListForType("Fritture", number, names, descriptions, prices, layoutFoods);
}

void ListView::setUpPlates(const int & number, const std::vector<QString> & names, const std::vector<QString> & descriptions, const std::vector<float> & prices) {
    setUpListForType("Piatti", number, names, descriptions, prices, layoutFoods);
}

void ListView::setUpBeers(const int & number, const std::vector<QString> & names, const std::vector<QString> & descriptions, const std::vector<float> & prices) {
    setUpListForType("Birre", number, names, descriptions, prices, layoutDrinks);
}

void ListView::setUpAnalcoholics(const int & number, const std::vector<QString> & names, const std::vector<QString> & descriptions, const std::vector<float> & prices) {
    setUpListForType("Analcolici", number, names, descriptions, prices, layoutDrinks);
}

void ListView::setUpAperitifs(const int & number, const std::vector<QString> & names, const std::vector<QString> & descriptions, const std::vector<float> & prices) {
    setUpListForType("Aperiviti", number, names, descriptions, prices, layoutDrinks);
}

void ListView::setUpCocktails(const int & number, const std::vector<QString> & names, const std::vector<QString> & descriptions, const std::vector<float> & prices) {
    setUpListForType("Cocktail", number, names, descriptions, prices, layoutDrinks);
}

void ListView::setUpDistillates(const int & number, const std::vector<QString> & names, const std::vector<QString> & descriptions, const std::vector<float> & prices) {
    setUpListForType("Distillati", number, names, descriptions, prices, layoutDrinks);
}

void ListView::show() {
    QWidget* w = new QWidget();
    layoutFoods->setSizeConstraint(QLayout::SetMinAndMaxSize);
    w->setLayout(layoutFoods);
    ui->scrollAreaFoods->setWidget(w);
    mainFoods->addWidget(ui->scrollAreaFoods);
    backFoods->setStyleSheet("font:20pt");
    backLayoutFoods->addItem(spacerFoods);
    backLayoutFoods->addWidget(backFoods);
    mainFoods->addLayout(backLayoutFoods);
    ui->foods->setLayout(mainFoods);

    w = new QWidget();
    layoutDrinks->setSizeConstraint(QLayout::SetMinAndMaxSize);
    w->setLayout(layoutDrinks);
    ui->scrollAreaDrinks->setWidget(w);
    mainDrinks->addWidget(ui->scrollAreaDrinks);
    backDrinks->setStyleSheet("font:20pt");
    backLayoutDrinks->addItem(spacerDrinks);
    backLayoutDrinks->addWidget(backDrinks);
    mainDrinks->addLayout(backLayoutDrinks);
    ui->drinks->setLayout(mainDrinks);
}

void ListView::setUpListForType(const QString & title_, const int & number, const std::vector<QString> & names, const std::vector<QString> & descriptions, const std::vector<float> & prices, QVBoxLayout* layout) {
    QVBoxLayout* v = new QVBoxLayout();
    QHBoxLayout* h;
    QLabel * title = new QLabel(title_);
    title->setStyleSheet("font: bold 25pt");
    v->addWidget(title);
    if (number > 0) {
        QLabel * name;
        QLabel * description;
        QLabel * price;
        for (int i = 0; i < number; i++) {
            h = new QHBoxLayout();
            h->setSizeConstraint(QLayout::SetFixedSize);
            name = new QLabel(names[i]);
            if (descriptions[i].size()>90){
                QString s = Utility::wordwrap(descriptions[i], descriptions[i].size(), 90);
                description = new QLabel(s);

            }else
                description = new QLabel(descriptions[i]);
            price = new QLabel("€" + QString(Utility::floatToString(prices[i])));
            name->setStyleSheet("font: 18pt");
            price->setStyleSheet("font: 18pt");
            description->setStyleSheet("font: italic 15pt");

            name->setAlignment(Qt::AlignLeft);
            price->setAlignment(Qt::AlignRight);
            description->setAlignment(Qt::AlignHCenter);
            h->addWidget(name);
            h->addWidget(description);
            h->addWidget(price);
            v->addLayout(h);
        }
    }
    v->addSpacerItem(new QSpacerItem(0, 20));
    layout->addLayout(v);
}
ListView::~ListView() {
    delete backLayoutDrinks;
    delete backLayoutFoods;
    delete layoutFoods;
    delete layoutDrinks;
    delete mainFoods;
    delete mainDrinks;
    delete ui;
}
