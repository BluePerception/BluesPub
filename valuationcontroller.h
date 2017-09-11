#ifndef VALUATIONCONTROLLER_H
#define VALUATIONCONTROLLER_H

#include "controller.h"
#include "valuationview.h"
#include "holderview.h"
#include "holdercontroller.h"
#include <vector>

class ValuationController : public Controller {
    Q_OBJECT
private:
    ValuationView* valuationview;
    Holder* holder;

    //metodo per mostrare le medie dei voti
    void showValuationMeans();

public:
    ValuationController(ValuationView*, Holder*);

private slots:
    void back();

};

#endif // VALUATIONCONTROLLER_H
