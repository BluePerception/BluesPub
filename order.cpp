#include "order.h"

Order::Order(const int & quantity_, ListItem* item_) : quantity(quantity_), item(item_) {}

int Order::getQuantity() {
    return quantity;
}

ListItem* Order::getItem() {
    return item;
}
