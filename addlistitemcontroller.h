#ifndef ADDLISTITEMCONTROLLER_H
#define ADDLISTITEMCONTROLLER_H

#include "holderlistview.h"
#include "holderlistcontroller.h"
#include "controller.h"
#include "addlistitemview.h"
#include "holder.h"

class AddListItemController : public Controller {
    Q_OBJECT

private:
    AddListItemView* addlistitemview;
    Holder* holder;

public:
    AddListItemController(AddListItemView*, Holder*);
    ~AddListItemController();

private slots:
    void back();
    void add();

};

#endif // ADDLISTITEMCONTROLLER_H
