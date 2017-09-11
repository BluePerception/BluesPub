#ifndef HOLDERVIEW_H
#define HOLDERVIEW_H

#include <QWidget>

namespace Ui {class HolderView;}

class HolderView : public QWidget{
    Q_OBJECT

public:
    explicit HolderView(QWidget *parent = 0);
    ~HolderView();

private:
    Ui::HolderView *ui;

signals:
    void valuationSignal();
    void billSignal();
    void orderSignal();
    void modifyListSignal();
    void addWaiterSignal();
    void removeWaiterSignal();
    void logoutSignal();
};

#endif // HOLDERVIEW_H
