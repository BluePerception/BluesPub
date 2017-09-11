#ifndef VALUATIONVIEW_H
#define VALUATIONVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include "utility.h"

namespace Ui {
class ValuationView;
}

class ValuationView : public QWidget {
    Q_OBJECT

public:
    explicit ValuationView(QWidget *parent = 0);
    ~ValuationView();

    // metdoi per accedere alle medie dei voti del servizio e dei pasti
    void setMeanFoodsAndDrinksValuation(const float &);
    void setMeanServiceValuation(const float &);

private:
    Ui::ValuationView *ui;

signals:
    void backSignal();

};

#endif // VALUATIONVIEW_H
