#ifndef TOTALVIEW_H
#define TOTALVIEW_H

#include <QWidget>
#include "order.h"
#include "utility.h"

namespace Ui {
class TotalView;
}

class TotalView : public QWidget {
    Q_OBJECT

public:
    explicit TotalView(QWidget *parent = 0);
    void setOrdersToDisplay(const std::vector<Order*> &);
    void setTotal(const float&);
    ~TotalView();

private:
    Ui::TotalView *ui;

signals:
    void tableChangeSignal(int);
    void backSignal();
    void closeSignal();
};

#endif // TOTALVIEW_H
