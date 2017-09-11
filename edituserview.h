#ifndef EDITUSERVIEW_H
#define EDITUSERVIEW_H

#include <QWidget>
#include "client.h"
#include "user.h"
#include "db_user.h"
#include "signinview.h"

namespace Ui {class EditUserView;}

class EditUserView : public QWidget{
    Q_OBJECT
private:
    Ui::EditUserView *ui;
    User* const userData;

public:
    explicit EditUserView(User*&, QWidget *parent=0);
    ~EditUserView();

    QString getName() const;
    QString getSurname() const;
    QString getEmail() const;
    QDate getBirth() const;
    QString getUsername() const;
    QString getPassword() const;
    QString getConfirmationPassword() const;

signals:
    void backSignal();
    void doneSignal();

};

#endif // EDITUSERVIEW_H
