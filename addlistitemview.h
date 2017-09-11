#ifndef ADDLISTITEMVIEW_H
#define ADDLISTITEMVIEW_H

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class AddListItemView;
}

class AddListItemView : public QWidget {
    Q_OBJECT

private:
    Ui::AddListItemView *ui;

    QStringList foodTypes;
    QStringList drinkTypes;

public:
    explicit AddListItemView(QWidget *parent = 0);
    ~AddListItemView();
    //metodi per accedere ai campi inseriti nella view
    QString getFoodOrDrink() const;
    QString getType() const;
    QString getName() const;
    QString getDescription() const;
    QString getPrice() const;
    //metodo per lanciare una finestra che segnala un inserimento errato
    void showError(const QString &);

signals:
    void backSignal();
    void addSignal();

private slots:
    void chooseFoodOrDrink(int);
};

#endif // ADDLISTITEMVIEW_H
