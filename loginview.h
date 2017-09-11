#ifndef LOGINVIEW_H
#define LOGINVIEW_H

#include <QWidget>

namespace Ui {class LoginView;}

class LoginView : public QWidget{
    Q_OBJECT
private:
    Ui::LoginView *ui;

public:
    explicit LoginView(QWidget *parent = 0);
    ~LoginView();

    QString getUsernameWritten();
    QString getPasswordWritten();

signals:
    void loginSignal();
    void backSignal();

};

#endif // LOGINVIEW_H
