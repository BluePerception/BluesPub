#include "valuationview.h"
#include "ui_valuationview.h"

ValuationView::ValuationView(QWidget *parent) : QWidget(parent), ui(new Ui::ValuationView) {
    ui->setupUi(this);
    connect(ui->back, SIGNAL(clicked(bool)), this, SIGNAL(backSignal()));
}

ValuationView::~ValuationView() {
    delete ui;
}

void ValuationView::setMeanFoodsAndDrinksValuation(const float & val) {
    ui->foodsAndDrinks->setText(Utility::floatToString(val));
}

void ValuationView::setMeanServiceValuation(const float & val) {
    ui->service->setText(Utility::floatToString(val));
}
