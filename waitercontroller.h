#ifndef WAITERCONTROLLER_H
#define WAITERCONTROLLER_H

#include <QObject>
#include <QWidget>
#include"waiterview.h"
#include "controller.h"
#include "startview.h"
#include "startcontroller.h"
#include "orderview.h"
#include "ordercontroller.h"
#include "totalview.h"
#include "totalcontroller.h"

class WaiterController : public Controller{
    Q_OBJECT

private:
    WaiterView* waiterview;
    Waiter* waiter;

public:
    WaiterController(WaiterView*, Waiter*);
    ~WaiterController();

private slots:
    void logout();
    void takeOrder();
    void total();
};

#endif // WAITERCONTROLLER_H
