#include "holderlistcontroller.h"

HolderListController::HolderListController(HolderListView* hw, Holder* h) : holderListView(hw), holder(h) {
    holderListView->showFoods(loadFoodsIntoVector());
    holderListView->showDrinks(loadDrinksIntoVector());

    connect(holderListView, SIGNAL(changeFoodSignal(const Food*,Food*)), this, SLOT(changeFood(const Food*,Food*)));
    connect(holderListView, SIGNAL(removeFoodSignal(Food*)), this, SLOT(removeFood(Food*)));
    connect(holderListView, SIGNAL(changeDrinkSignal(const Drink*,Drink*)), this, SLOT(changeDrink(const Drink*,Drink*)));
    connect(holderListView, SIGNAL(removeDrinkSignal(Drink*)), this, SLOT(removeDrink(Drink*)));
    connect(holderListView, SIGNAL(backSignal()), this, SLOT(back()));
    connect(holderListView, SIGNAL(addSignal()), this, SLOT(add()));
}

HolderListController::~HolderListController() {
    holder=0;
    delete holderListView;
}

bool HolderListController::removable(ListItem* item) const {
    bool found=false;
    db_table* db=getTableDbInstance();
    std::vector<int> tables=db->getTables();
    for(std::vector<int>::const_iterator it=tables.begin(); it!=tables.end() && !found; it++){
        const Total* t=db->get_orders(*it);
        std::vector<Order*> orders=t->getOrders();
        for(std::vector<Order*>::const_iterator w=orders.begin(); w!=orders.end() && !found; w++){
            found=((*w)->getItem()->getName()==item->getName());
        }
    }
    return !found;
}

void HolderListController::changeFood(const Food* oldFood, Food* newFood) {
    getListDbInstance()->changeListItem(oldFood, newFood);
}

void HolderListController::removeFood(Food* food) {
    if (removable(food)) {
        getListDbInstance()->removeItem(food);
        holderListView->showFoods(loadFoodsIntoVector());
    } else {
        holderListView->notRemovableError();
    }
}

std::vector<const Food*> HolderListController::loadFoodsIntoVector() {
    return getListDbInstance()->getFoods();
}

void HolderListController::changeDrink(const Drink* oldDrink, Drink* newDrink) {
    getListDbInstance()->changeListItem(oldDrink, newDrink);
}

void HolderListController::removeDrink(Drink* drink) {
    if (removable(drink)) {
        db_list* db = getListDbInstance();
        db->removeItem(drink);
       holderListView->showDrinks(loadDrinksIntoVector());
    } else {
        holderListView->notRemovableError();
    }
}

std::vector<const Drink*> HolderListController::loadDrinksIntoVector() {
    return getListDbInstance()->getDrinks();
}

void HolderListController::add() {
    AddListItemView* aw=new AddListItemView();
    emit changesignal(aw, new AddListItemController(aw, holder));
}

void HolderListController::back() {
    HolderView* hw=new HolderView();
    emit changesignal(hw, new HolderController(hw, holder));
}
