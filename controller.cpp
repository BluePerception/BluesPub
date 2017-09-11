#include "controller.h"

db_list* Controller::list=0;
db_table* Controller::table=0;
db_user* Controller::user=0;
db_valuation* Controller::valuation=0;

db_list* Controller::getListDbInstance() const {
    if (list == 0)
        list = new db_list();
    return list;
}

db_table* Controller::getTableDbInstance() const {
    if (table == 0)
        table = new db_table();
    return table;
}

db_user* Controller::getUserDbInstance() const {
    if (user == 0)
        user = new db_user();
    return user;
}

db_valuation* Controller::getValuationDbInstance() const {
    if (valuation == 0)
        valuation = new db_valuation();
    return valuation;
}

void Controller::deleteDbs() {
    if (list)
        delete list;
    if (table)
        delete table;
    if (user)
        delete user;
    if (valuation)
        delete valuation;
}
