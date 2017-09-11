#ifndef START_H
#define START_H

#include <QWidget>

namespace Ui {
class StartView;
}


class StartView : public QWidget{
    Q_OBJECT

private:
    Ui::StartView *ui;

public:
    explicit StartView(QWidget *parent = 0);
    ~StartView();

signals:
    void loginSignal();
    void regSignal();

private slots:
    void login();
    void reg();
};

#endif // START_H



