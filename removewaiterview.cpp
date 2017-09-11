#include "removewaiterview.h"
#include "ui_removewaiterview.h"

RemoveWaiterView::RemoveWaiterView(QWidget *parent) : QWidget(parent), ui(new Ui::RemoveWaiterView) {
    ui->setupUi(this);

    connect(ui->back, SIGNAL(clicked(bool)), this, SIGNAL(backSignal()));
    connect(ui->search, SIGNAL(clicked(bool)), this, SLOT(search()));
}

RemoveWaiterView::~RemoveWaiterView() {
    delete ui;
}

QString RemoveWaiterView::getUsername() const {
    return ui->username->text();
}

void RemoveWaiterView::search() {
    if (ui->username->text()!="")
        emit searchSignal();
    else {
        QMessageBox messageBox;
        messageBox.critical(0,"Errore","Nessun username inserito");
        messageBox.setFixedSize(500,200);
        messageBox.exec();
    }
}
