#include "total.h"

Total::Total() : orders(std::vector<Order*>()) {}

Total::~Total() {
    for(std::vector<Order*>::iterator it=orders.begin(); it!=orders.end(); it++)
        delete *it;
}

void Total::addOrder(Order * order) {
    orders.push_back(order);
}

std::vector<Order*> Total::getOrders() const {
    if (orders.size() == 0)
        return std::vector<Order*>();
    return orders;
}

float Total::getTotal() const{
    float total = 0;
    for(std::vector<Order*>::const_iterator it=orders.begin(); it!=orders.end(); it++) {
        total += (*it)->getQuantity() * (*it)->getItem()->getPrice();
    }
    return total;
}

void Total::clear() {
    for(std::vector<Order*>::iterator it=orders.begin(); it!=orders.end(); it++) {
        delete *it;
    }
    orders.clear();
}
