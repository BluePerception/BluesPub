#ifndef TOTAL_H
#define TOTAL_H
#include <vector>
#include "order.h"

class Total {
private:
    std::vector<Order *> orders;

public:
    Total();
    ~Total();
    void addOrder(Order *);
    std::vector<Order *> getOrders() const;
    float getTotal() const;
    void clear();

};

#endif // TOTAL_H
