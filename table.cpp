#include "table.h"

Table::Table(const int & id_) : id(id_), total(new Total()) {}

Table::Table(const int & id_, Total * total_) : id(id_), total(total_) {}

Table::~Table() {
    delete total;
}

int Table::getId() {
    return id;
}

void Table::addOrder(Order * order) {
    total->addOrder(order);
}

float Table::getTotal() {
    float t = total->getTotal();
    total->clear();
    return t;
}

std::vector<Order*> Table::getOrders() {
    return total->getOrders();
}

void Table::clearOrders() {
    total->clear();
}
