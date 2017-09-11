#ifndef ACCEDICONTROLLER_H
#define ACCEDICONTROLLER_H
#include "accediview.h"
#include "controller.h"
#include "startview.h"
#include "startcontroller.h"

class AccediController : public Controller{
    Q_OBJECT

private:
    AccediView* accediview;

public:
    AccediController(AccediView*);

private slots:
    void accedi_slot();
    void back_slot();

};

#endif // ACCEDICONTROLLER_H
