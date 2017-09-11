#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H
#include "mainwindow.h"
#include "controller.h"
#include "startview.h"
#include "startcontroller.h"
#include <QWidget>

//maincontroller contiene tutti i vari controller da assegnare alle rispettive view
class MainController : public Controller{
    Q_OBJECT
private:
    MainWindow* mainwindow;
    Controller* actualcontroller;

public:
    MainController(MainWindow*);
    ~MainController();

private slots:
    void change(QWidget*, Controller*);

};

#endif // MAINCONTROLLER_H
