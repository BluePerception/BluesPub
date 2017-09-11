#ifndef SIGNINVIEW_H
#define SIGNINVIEW_H

#include <QWidget>
#include "user.h"

namespace Ui {class SignInView;}

class SignInView : public QWidget{
    Q_OBJECT

private:
    Ui::SignInView *ui;

public:
    explicit SignInView(QWidget *parent = 0);
    ~SignInView();

    bool emptyReg() const;
    QString getName() const;
    QString getSurname() const;
    QString getEmail() const;
    QDate getBirth() const;
    QString getUsername() const;
    QString getPassword() const;
    QString getConfirmationPassword() const;

signals:
    void regSignal();
    void backSignal();
    void errorSignal();

private slots:
    void reg();
    void back();

};

#endif // SIGNINVIEW_H
