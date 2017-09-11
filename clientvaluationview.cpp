#include "clientvaluationview.h"
#include "ui_clientvaluationview.h"
#include <QDebug>

//costruttore
ClientValuationView::ClientValuationView(QWidget *parent) : QWidget(parent), ui(new Ui::ClientValuationView){
    ui->setupUi(this);

    connect(ui->back, SIGNAL(clicked(bool)), this, SLOT(back()));
    connect(ui->done, SIGNAL(clicked(bool)), this, SLOT(done()));

}

//distruttore
ClientValuationView::~ClientValuationView(){
    delete ui;
}

//metodi
QString ClientValuationView::readMealRate() const{
    QRadioButton* checked = (QRadioButton*)ui->foods->checkedButton();
    return checked->text();
}

QString ClientValuationView::readServiceRate() const{
    QRadioButton* checked = (QRadioButton*)ui->service->checkedButton();
    return checked->text();
}

//slots
void ClientValuationView::back(){
    emit backSignal();
}

void ClientValuationView::done(){
    emit doneSignal();
}
