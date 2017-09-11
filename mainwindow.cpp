#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), actualview(0){
    ui->setupUi(this);

}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::change(QWidget* m){
    if (actualview) {
        setCentralWidget(0);
        actualview->hide();
    }
    actualview = m;
    setCentralWidget(actualview);
    actualview->show();
}

