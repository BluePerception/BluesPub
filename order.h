#ifndef ORDER_H
#define ORDER_H
#include <listitem.h>

class Order {
private:
    const int quantity;
    ListItem* item;

public:
    Order(const int &, ListItem*);
    int getQuantity();
    ListItem* getItem();
};

#endif // ORDER_H
