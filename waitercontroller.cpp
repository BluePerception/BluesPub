#include "waitercontroller.h"

//costruttore
WaiterController::WaiterController(WaiterView* wv, Waiter* w) : waiterview(wv), waiter(w){
    connect(waiterview, SIGNAL(logoutSignal()), this, SLOT(logout()));
    connect(waiterview, SIGNAL(takeOrderSignal()), this, SLOT(takeOrder()));
    connect(waiterview, SIGNAL(totalSignal()), this, SLOT(total()));
}

WaiterController::~WaiterController() {
    waiter=0;
    delete waiterview;
}

//slot
void WaiterController::logout(){
    StartView* sv = new StartView();
    emit changesignal(sv, new StartController(sv));
}

void WaiterController::takeOrder(){
    OrderView* ov = new OrderView();
    emit changesignal(ov, new OrderController(ov, waiter));
}

void WaiterController::total(){
    TotalView* tw = new TotalView();
    emit changesignal(tw, new TotalController(tw, waiter));
}
