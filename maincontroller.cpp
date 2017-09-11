#include "maincontroller.h"

MainController::MainController(MainWindow * mw) : mainwindow(mw), actualcontroller(0){
    StartView* start= new StartView();
    StartController* cont= new StartController(start);
    change(start, cont);
}

void MainController::change(QWidget * view, Controller * cont){
    mainwindow->change(view);
    if (actualcontroller)
        delete actualcontroller;
    actualcontroller=cont;
    connect(actualcontroller, SIGNAL(changesignal(QWidget*,Controller*)), this, SLOT(change(QWidget*,Controller*)));
}

MainController::~MainController() {
    deleteDbs();
    delete mainwindow;
}
