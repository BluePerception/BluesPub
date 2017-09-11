#include "valuationcontroller.h"

ValuationController::ValuationController(ValuationView* vw, Holder* h) : valuationview(vw), holder(h) {
    connect(valuationview, SIGNAL(backSignal()), this, SLOT(back()));
    showValuationMeans();
}

void ValuationController::showValuationMeans() {
    std::vector<Rate*> rates=getValuationDbInstance()->getRates();
    int val=rates.size();
    if(val>0) {
        float foodsAndDrinks=0, service=0;
        for(std::vector<Rate*>::const_iterator it=rates.begin(); it!=rates.end(); it++) {
            foodsAndDrinks += (*it)->get_meal().toFloat();
            service += (*it)->get_service().toFloat();
        }
        valuationview->setMeanFoodsAndDrinksValuation(foodsAndDrinks/val);
        valuationview->setMeanServiceValuation(service/val);
    }
}

void ValuationController::back() {
    HolderView* hv=new HolderView();
    emit changesignal(hv, new HolderController(hv, holder));
}
