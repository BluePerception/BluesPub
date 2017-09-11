#ifndef REMOVEWAITERCONTROLLER_H
#define REMOVEWAITERCONTROLLER_H

#include "controller.h"
#include "removewaitercontroller.h"
#include "removewaiterview.h"
#include "holderview.h"
#include "holdercontroller.h"

class RemoveWaiterController : public Controller {
    Q_OBJECT
private:
    RemoveWaiterView* removeview;
    Holder* holder;

    void showUsernameNotFoundError();
    void removeWaiter(Waiter*);
    void showWaiterInformation(Waiter*);

public:
    RemoveWaiterController(RemoveWaiterView*, Holder*);

private slots:
    void back();
    void search();

};

#endif // REMOVEWAITERCONTROLLER_H
