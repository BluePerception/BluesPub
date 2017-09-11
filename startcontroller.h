#ifndef STARTCONTROLLER_H
#define STARTCONTROLLER_H
#include "startview.h"
#include "controller.h"
#include "loginview.h"
#include "logincontroller.h"
#include "signinview.h"
#include "signincontroller.h"


class StartController : public Controller {
    Q_OBJECT

private:
    StartView* startview;

public:
    StartController(StartView*);
    ~StartController();

private slots:
    void login();
    void reg();

};

#endif // STARTCONTROLLER_H
