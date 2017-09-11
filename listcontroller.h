#ifndef LISTCONTROLLER_H
#define LISTCONTROLLER_H
#include "listview.h"
#include "controller.h"
#include "db_list.h"
#include <vector>
#include "listitem.h"
#include "client.h"
#include "clientview.h"
#include "clientcontroller.h"

class ListController : public Controller {
    Q_OBJECT
private:
    ListView* listview;
    db_list* list;
    Client* userLogged;

    std::vector<QString> getNamesForType(ListItem::Type);
    std::vector<QString> getDescriptionsForType(ListItem::Type);
    std::vector<float> getPricesForType(ListItem::Type);

public:
    ListController(ListView*, Client*);
    ~ListController();

private slots:
    void back();
};

#endif // LISTCONTROLLER_H
