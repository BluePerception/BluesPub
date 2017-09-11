#ifndef HOLDERLISTCONTROLLER_H
#define HOLDERLISTCONTROLLER_H

#include <vector>
#include "controller.h"
#include "holderlistview.h"
#include "holderview.h"
#include "holdercontroller.h"
#include "addlistitemview.h"
#include "addlistitemcontroller.h"
#include "holder.h"

class HolderListController : public Controller {
    Q_OBJECT

private:
    HolderListView* holderListView;
    Holder* holder;

    std::vector<const Food*> loadFoodsIntoVector();
    std::vector<const Drink*> loadDrinksIntoVector();

    bool removable(ListItem*) const;
public:
    HolderListController(HolderListView*, Holder*);
    ~HolderListController();

private slots:
    void changeFood(const Food*, Food*);
    void removeFood(Food*);
    void changeDrink(const Drink*, Drink*);
    void removeDrink(Drink*);
    void add();
    void back();

};

#endif // HOLDERLISTCONTROLLER_H
