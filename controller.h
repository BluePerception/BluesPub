#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "db_list.h"
#include "db_table.h"
#include "db_user.h"
#include "db_valuation.h"
#include <QWidget>

//la classe controller e' la classe base di tutte le classi controller specifiche derivate; per non richiamare ogni volta i database tengo un puntatore
//ad essi che puo' essere usato dalle sue sottoclassi

class Controller:public QWidget{
    Q_OBJECT
//dichiaro questi membri protetti in quanto solo le sottoclassi possono avere accesso
protected:
    static db_list* list;
    static db_table* table;
    static db_user* user;
    static db_valuation* valuation;

public:
    db_list* getListDbInstance() const;
    db_table* getTableDbInstance() const;
    db_user* getUserDbInstance() const;
    db_valuation* getValuationDbInstance() const;

protected:
    void deleteDbs();

signals:
    //segnale che mi permette di cambiare view e controller
    void changesignal(QWidget*, Controller*);

};

#endif // CONTROLLER_H
