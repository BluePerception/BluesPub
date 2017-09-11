#include "accediview.h"
#include "ui_accedi.h"

AccediView::AccediView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AccediView)
{
    ui->setupUi(this);
}

AccediView::~AccediView()
{
    delete ui;
}
