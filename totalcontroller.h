#ifndef TOTALCONTROLLER_H
#define TOTALCONTROLLER_H

#include "controller.h"
#include "totalview.h"
#include "waitercontroller.h"
#include "waiterview.h"

class TotalController : public Controller {
    Q_OBJECT

private:
    TotalView* totalView;
    int currentTable;
    User* userLogged;
    bool holder;

    void setupUi();

public:
    TotalController(TotalView*, Waiter*);
    TotalController(TotalView*, Holder*);
    ~TotalController();

private slots:
    void close();
    void changeTable(int);
    void back();
};

#endif // TOTALCONTROLLER_H
