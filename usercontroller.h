#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H
#include <QObject>
#include <QWidget>
#include "controller.h"
#include "user.h"

class UserController: public Controller{
    Q_OBJECT

public:
    UserController();
};

#endif // USERCONTROLLER_H
