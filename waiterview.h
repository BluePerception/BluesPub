#ifndef WAITERVIEW_H
#define WAITERVIEW_H

#include <QWidget>

namespace Ui {class WaiterView;}

class WaiterView : public QWidget{
    Q_OBJECT

private:
    Ui::WaiterView *ui;

public:
    explicit WaiterView(QWidget *parent = 0);
    ~WaiterView();

signals:
    void logoutSignal();
    void takeOrderSignal();
    void totalSignal();
};

#endif // WAITERVIEW_H
