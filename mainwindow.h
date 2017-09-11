#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    QWidget* actualview;      //puntatore a una view generica -> polimorfismo

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void change(QWidget*);
};

#endif // MAINWINDOW_H
