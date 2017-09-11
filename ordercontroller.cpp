#include "ordercontroller.h"

OrderController::OrderController(OrderView* ow, Waiter* w) : orderview(ow), userLogged(w), holder(false){
    setupUi();
}

OrderController::OrderController(OrderView* ow, Holder* h) : orderview(ow), userLogged(h), holder(true){
    setupUi();
}

void OrderController::setupUi() {
    std::vector<QString> drinks;
    std::vector<const Drink*> allDrinks=getListDbInstance()->getDrinks();
    for(std::vector<const Drink*>::const_iterator it = allDrinks.begin();
        it != allDrinks.end(); it++)
        drinks.push_back((*it)->getName());
    std::vector<QString> foods;
    std::vector<const Food*> allFoods=getListDbInstance()->getFoods();
    for(std::vector<const Food*>::const_iterator it = allFoods.begin();
        it != allFoods.end(); it++)
        foods.push_back((*it)->getName());
    orderview->setAvailableDrinks(drinks);
    orderview->setAvailableFoods(foods);

    connect(orderview, SIGNAL(addOrderSignal()), this, SLOT(addOrder()));
    connect(orderview, SIGNAL(tableChangeSignal(int)), this, SLOT(tableChanged(int)));
    connect(orderview, SIGNAL(backSignal()), this, SLOT(back()));

    tableChanged(1);
}

OrderController::~OrderController(){
    delete orderview;
}

void OrderController::addOrder() {
    int table = orderview->getTable();
    int amount = orderview->getSelectedQuantity();
    QString name = orderview->getSelectedItem();

    Order* o = new Order(amount, getListDbInstance()->getItemFromName(name));
    getTableDbInstance()->add_order(table, o);
    orderview->showNewOrder(o);
}

void OrderController::back() {
    if (holder) {
        HolderView* hv=new HolderView();
        emit changesignal(hv, new HolderController(hv, (Holder*)userLogged));
    } else {
        WaiterView* wv=new WaiterView();
        emit changesignal(wv, new WaiterController(wv, (Waiter*)userLogged));
    }
}

void OrderController::tableChanged(int table) {
    orderview->clearOrders();
    db_table* dbTable = getTableDbInstance();
    const Total* total = dbTable->get_orders(table);
    std::vector<Order*> orders = total->getOrders();
    for (std::vector<Order*>::const_iterator it=orders.begin(); it!=orders.end(); it++)
        orderview->showNewOrder(*it);
}
