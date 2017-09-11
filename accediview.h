#ifndef ACCEDIVIEW_H
#define ACCEDIVIEW_H

#include <QWidget>

namespace Ui {class AccediView;}

class AccediView : public QWidget{
    Q_OBJECT
private:
    Ui::AccediView *ui;

public:
    explicit AccediView(QWidget *parent = 0);
    ~AccediView();

signals:
    void back_signal();

private slots:
    void back_slot();

};

#endif // ACCEDIVIEW_H
