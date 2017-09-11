#ifndef CLIENTVALUATIONVIEW_H
#define CLIENTVALUATIONVIEW_H

#include <QWidget>
#include <QString>

namespace Ui {class ClientValuationView;}

class ClientValuationView : public QWidget{
    Q_OBJECT

private:
    Ui::ClientValuationView *ui;

public:
    explicit ClientValuationView(QWidget *parent = 0);
    ~ClientValuationView();

    //metodi per vedere il punteggio scelto dall'utente nei RadioButton
    QString readServiceRate() const;
    QString readMealRate() const;

signals:
    void backSignal();
    void doneSignal();

private slots:
    void back();
    void done();
};

#endif // CLIENTVALUATIONVIEW_H
