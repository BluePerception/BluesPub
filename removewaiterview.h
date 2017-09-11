#ifndef REMOVEWAITERVIEW_H
#define REMOVEWAITERVIEW_H

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class RemoveWaiterView;
}

class RemoveWaiterView : public QWidget {
    Q_OBJECT

public:
    explicit RemoveWaiterView(QWidget *parent = 0);
    ~RemoveWaiterView();
    QString getUsername() const;

private:
    Ui::RemoveWaiterView *ui;

private slots:
    void search();

signals:
    void searchSignal();
    void backSignal();
};

#endif // REMOVEWAITERVIEW_H
