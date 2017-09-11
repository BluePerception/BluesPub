#include "listcontroller.h"

ListController::ListController(ListView* listview_, Client* client_) : listview(listview_), list(getListDbInstance()), userLogged(client_) {
    std::vector<QString> names = getNamesForType(ListItem::SNACK);
    listview->setUpBruschettes(names.size(), names, getDescriptionsForType(ListItem::SNACK), getPricesForType(ListItem::SNACK));
    names = getNamesForType(ListItem::PANINO);
    listview->setUpSandwiches(names.size(), names, getDescriptionsForType(ListItem::PANINO), getPricesForType(ListItem::PANINO));
    names = getNamesForType(ListItem::TOAST);
    listview->setUpToasts(names.size(), names, getDescriptionsForType(ListItem::TOAST), getPricesForType(ListItem::TOAST));
    names = getNamesForType(ListItem::FRITTO);
    listview->setUpFries(names.size(), names, getDescriptionsForType(ListItem::FRITTO), getPricesForType(ListItem::FRITTO));
    names = getNamesForType(ListItem::PIATTO);
    listview->setUpPlates(names.size(), names, getDescriptionsForType(ListItem::PIATTO), getPricesForType(ListItem::PIATTO));
    names = getNamesForType(ListItem::BIRRA);
    listview->setUpBeers(names.size(), names, getDescriptionsForType(ListItem::BIRRA), getPricesForType(ListItem::BIRRA));
    names = getNamesForType(ListItem::ANALCOLICO);
    listview->setUpAnalcoholics(names.size(), names, getDescriptionsForType(ListItem::ANALCOLICO), getPricesForType(ListItem::ANALCOLICO));
    names = getNamesForType(ListItem::APERITIVO);
    listview->setUpAperitifs(names.size(), names, getDescriptionsForType(ListItem::APERITIVO), getPricesForType(ListItem::APERITIVO));
    names = getNamesForType(ListItem::COCKTAIL);
    listview->setUpCocktails(names.size(), names, getDescriptionsForType(ListItem::COCKTAIL), getPricesForType(ListItem::COCKTAIL));
    names = getNamesForType(ListItem::DISTILLATO);
    listview->setUpDistillates(names.size(), names, getDescriptionsForType(ListItem::DISTILLATO), getPricesForType(ListItem::DISTILLATO));

    listview->show();

    connect(listview, SIGNAL(backSignal()), this, SLOT(back()));
}

ListController::~ListController() {
    list=0;
    userLogged=0;
    delete listview;
}

std::vector<QString> ListController::getNamesForType(ListItem::Type type) {
    std::vector<QString> names;
    std::vector<const ListItem*> items=getListDbInstance()->getItems();
    for(std::vector<const ListItem*>::const_iterator it = items.begin();
        it!=items.end(); it++) {
        if ((*it)->getType() == type)
            names.push_back((*it)->getName());
    }
    return names;
}

std::vector<QString> ListController::getDescriptionsForType(ListItem::Type type) {
    std::vector<QString> descriptions;
    std::vector<const ListItem*> items=getListDbInstance()->getItems();
    for(std::vector<const ListItem*>::const_iterator it = items.begin();
        it!=items.end(); it++) {
        if ((*it)->getType() == type)
            descriptions.push_back((*it)->getDescription());
    }

    return descriptions;
}

std::vector<float> ListController::getPricesForType(ListItem::Type type) {
    std::vector<float> prices;
    std::vector<const ListItem*> items=getListDbInstance()->getItems();
    for(std::vector<const ListItem*>::const_iterator it = items.begin();
        it!=items.end(); it++) {
        if ((*it)->getType() == type)
            prices.push_back((*it)->getPrice());
    }
    return prices;
}

void ListController::back() {
    ClientView* clientview = new ClientView();
    emit changesignal(clientview, new ClientController(clientview, userLogged));
}
