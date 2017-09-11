#ifndef CLIENTVALUATIONCONTROLLER_H
#define CLIENTVALUATIONCONTROLLER_H
#include "controller.h"
#include "clientvaluationview.h"
#include "clientview.h"
#include "clientcontroller.h"
#include "rate.h"
#include "db_valuation.h"
#include "client.h"
#include <QObject>
#include <QWidget>
#include <QMessageBox>

class ClientValuationController : public Controller{
    Q_OBJECT
private:
    ClientValuationView* clientvalview;
    Client* userLogged;
    db_valuation* db;

public:
    ClientValuationController(ClientValuationView*, Client*);
    ~ClientValuationController();

private slots:
    void back();
    void done();

};

#endif // CLIENTVALUATIONCONTROLLER_H
