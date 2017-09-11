#ifndef CLIENTVIEW_H
#define CLIENTVIEW_H

#include <QWidget>

namespace Ui {class ClientView;}

class ClientView : public QWidget{
    Q_OBJECT

private:
    Ui::ClientView *ui;

public:
    explicit ClientView(QWidget *parent = 0);
    ~ClientView();

signals:
    void logoutSignal();
    void evaluateSignal();
    void editUserSignal();
    void deleteUserSignal();
    void showMenuSignal();

};

#endif // CLIENTVIEW_H
