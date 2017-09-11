#include "addlistitemcontroller.h"

AddListItemController::AddListItemController(AddListItemView* aw, Holder* h) :
    addlistitemview(aw), holder(h) {
    connect(addlistitemview, SIGNAL(backSignal()), this, SLOT(back()));
    connect(addlistitemview, SIGNAL(addSignal()), this, SLOT(add()));
}

AddListItemController::~AddListItemController(){
    holder=0;
    delete addlistitemview;
}

void AddListItemController::back() {
    HolderListView* hv = new HolderListView();
    emit changesignal(hv, new HolderListController(hv, holder));
}

void AddListItemController::add() {
    bool error=false;
    QString foodOrDrink=addlistitemview->getFoodOrDrink(),
            name=addlistitemview->getName(),
            description=addlistitemview->getDescription();
    ListItem::Type type=ListItem::stringToType(addlistitemview->getType());
    float price=(addlistitemview->getPrice()).toFloat();

    if (foodOrDrink != "Cibo" && foodOrDrink != "Bevanda") {
        error=true;
        addlistitemview->showError("Seleziona cibo o bevanda");
    } else if (type == ListItem::Type::UNK) {
        error=true;
        addlistitemview->showError("Tipo non selezionato");
    } else if (name == "") {
        error=true;
        addlistitemview->showError("Nome non inserito");
    } else if (price == 0) {
        error=true;
        addlistitemview->showError("Prezzo inserito non valido");
    }

    if(!error) {
        if (foodOrDrink == "Cibo") {
            Food* f = new Food(name, description, price, type);
            getListDbInstance()->save_item(*f);
        } else {
            Drink* d = new Drink(name, description, price, type);
            getListDbInstance()->save_item(*d);
        }
        back();
    }
}
