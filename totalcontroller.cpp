#include "totalcontroller.h"

TotalController::TotalController(TotalView* tw, Holder* h) : totalView(tw), userLogged(h) {
    holder = true;
    setupUi();
}

TotalController::TotalController(TotalView* tw, Waiter* w) : totalView(tw), userLogged(w) {
    holder = false;
    setupUi();
}

void TotalController::setupUi() {
    connect(totalView, SIGNAL(backSignal()), this, SLOT(back()));
    connect(totalView, SIGNAL(closeSignal()), this, SLOT(close()));
    connect(totalView, SIGNAL(tableChangeSignal(int)), this, SLOT(changeTable(int)));

    changeTable(1);
}

TotalController::~TotalController(){
    delete totalView;
}

void TotalController::changeTable(int number) {
    currentTable = number;

    db_table* dbTable = getTableDbInstance();
    const Total* total = dbTable->get_orders(currentTable);
    std::vector<Order*> orders = total->getOrders();

    totalView->setOrdersToDisplay(orders);
    totalView->setTotal(total->getTotal());
}

void TotalController::back() {
    if (holder){
        HolderView* hv=new HolderView();
        emit changesignal(hv, new HolderController(hv, (Holder*)userLogged));
    }else {
        WaiterView* wv=new WaiterView();
        emit changesignal(wv, new WaiterController(wv, (Waiter*)userLogged));
    }
}

void TotalController::close() {
    getTableDbInstance()->clear_orders(currentTable);
    changeTable(currentTable);
}
