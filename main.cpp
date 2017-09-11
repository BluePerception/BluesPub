//#include "mainwindow.h"
#include "maincontroller.h"
#include "mainwindow.h"
#include <QApplication>

using namespace std;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow* w = new MainWindow();
    MainController* c = new MainController(w);
    w->showMaximized();
    int ret = a.exec();
    delete c;
    return ret;
}
