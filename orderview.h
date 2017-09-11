#ifndef ORDERVIEW_H
#define ORDERVIEW_H

#include <QWidget>
#include <vector>
#include "order.h"
#include "utility.h"

namespace Ui {
class OrderView;
}

class OrderView : public QWidget {
    Q_OBJECT

public:
    explicit OrderView(QWidget *parent = 0);
    ~OrderView();
    void setAvailableFoods(const std::vector<QString>& foods);
    void setAvailableDrinks(const std::vector<QString>& drinks);
    int getSelectedQuantity() const;
    QString getSelectedItem() const;
    QString getSelectedType() const;
    int getTable() const;
    void showNewOrder(Order*);
    void clearOrders();

private:
    Ui::OrderView *ui;
    QStringList foods;
    QStringList drinks;
    int lastRow;

signals:
    void addOrderSignal();
    void backSignal();
    void tableChangeSignal(int);

private slots:
    void addOrder();
    void changedType(int);
    void changedSpecificType(int);

};

#endif // ORDERVIEW_H
