#ifndef ORDERCONTROLLER_H
#define ORDERCONTROLLER_H

#include <QObject>
#include <QWidget>
#include "controller.h"
#include "orderview.h"
#include <vector>
#include "waitercontroller.h"
#include "waiterview.h"

class OrderController : public Controller {
    Q_OBJECT

private:
    OrderView* orderview;
    User* userLogged;
    bool holder;

    void setupUi();
public:
    OrderController(OrderView*, Waiter*);
    OrderController(OrderView*, Holder*);
    ~OrderController();

private slots:
    void addOrder();
    void back();
    void tableChanged(int);
};

#endif // ORDERCONTROLLER_H
