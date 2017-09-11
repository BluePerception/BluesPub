#include "holdercontroller.h"

HolderController::HolderController(HolderView* hv, Holder* hr) : holderview(hv), holder(hr){
    connect(holderview, SIGNAL(valuationSignal()), this, SLOT(valuation()));
    connect(holderview, SIGNAL(addWaiterSignal()), this, SLOT(addWaiter()));
    connect(holderview, SIGNAL(removeWaiterSignal()), this, SLOT(removeWaiter()));
    connect(holderview, SIGNAL(billSignal()), this, SLOT(bill()));
    connect(holderview, SIGNAL(modifyListSignal()), this, SLOT(modifyList()));
    connect(holderview, SIGNAL(orderSignal()), this, SLOT(order()));
    connect(holderview, SIGNAL(logoutSignal()), this, SLOT(logout()));
}

HolderController::~HolderController(){
    delete holderview;
}

void HolderController::bill() {
    TotalView* tv = new TotalView();
    emit changesignal(tv, new TotalController(tv, holder));
}

void HolderController::order() {
    OrderView* ov = new OrderView();
    emit changesignal(ov, new OrderController(ov, holder));
}

void HolderController::modifyList() {
    HolderListView* hv = new HolderListView();
    emit changesignal(hv, new HolderListController(hv, holder));
}

void HolderController::addWaiter() {
    SignInView* sw = new SignInView();
    emit changesignal(sw, new SignInController(sw, holder));
}

void HolderController::removeWaiter() {
    RemoveWaiterView* rw = new RemoveWaiterView();
    emit changesignal(rw, new RemoveWaiterController(rw, holder));
}

void HolderController::logout() {
    StartView* startview = new StartView();
    emit changesignal(startview, new StartController(startview));
}

void HolderController::valuation() {
    ValuationView* vw = new ValuationView();
    emit changesignal(vw, new ValuationController(vw, holder));
}
