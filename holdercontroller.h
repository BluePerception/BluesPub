#ifndef HOLDERCONTROLLER_H
#define HOLDERCONTROLLER_H

#include <QObject>
#include <QWidget>
#include "holderview.h"
#include "controller.h"
#include "startview.h"
#include "startcontroller.h"
#include "holder.h"
#include "removewaiterview.h"
#include "removewaitercontroller.h"
#include "valuationview.h"
#include "valuationcontroller.h"
#include "holderlistview.h"
#include "holderlistcontroller.h"

class HolderController : public Controller{
    Q_OBJECT
private:
    HolderView* holderview;
    Holder* holder;

public:
    HolderController(HolderView*, Holder*);
    ~HolderController();

private slots:
    void bill();
    void order();
    void modifyList();
    void addWaiter();
    void removeWaiter();
    void logout();
    void valuation();

};

#endif // HOLDERCONTROLLER_H
