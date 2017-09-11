#ifndef TABLE_H
#define TABLE_H
#include "total.h"
#include <vector>

class Table {
private:
    int id;
    Total* total;

public:
    Table(const int &);
    Table(const int &, Total *);
    ~Table();
    int getId();
    void addOrder(Order *);
    std::vector<Order*> getOrders();
    float getTotal();
    void clearOrders();

};

#endif // TABLE_H
