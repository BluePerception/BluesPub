#ifndef HOLDERLISTVIEW_H
#define HOLDERLISTVIEW_H

#include <QTabWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QSpacerItem>
#include <QMessageBox>
#include <QComboBox>
#include <QPushButton>
#include <QSpacerItem>
#include <vector>
#include "food.h"
#include "drink.h"
#include "utility.h"
#include "listitem.h"

namespace Ui {
class HolderListView;
}

class HolderListView : public QTabWidget {
    Q_OBJECT

public:
    explicit HolderListView(QWidget *parent = 0);
    ~HolderListView();
    void showFoods(const std::vector<const Food*> &);
    void showDrinks(const std::vector<const Drink*> &);
    void notRemovableError();

private:
    Ui::HolderListView *ui;
    QVBoxLayout* mainLayoutFoods;
    QHBoxLayout* scrollLayoutFoods;
    QTableWidget* tableFoods;
    QHBoxLayout* backLayoutFoods;
    QSpacerItem* spacerFoods;
    QPushButton* backFoods;
    QPushButton* addFoods;
    QVBoxLayout* mainLayoutDrinks;
    QHBoxLayout* scrollLayoutDrinks;
    QTableWidget* tableDrinks;
    QHBoxLayout* backLayoutDrinks;
    QSpacerItem* spacerDrinks;
    QPushButton* backDrinks;
    QPushButton* addDrinks;

    std::vector<const Food*> foods;
    std::vector<const Drink*> drinks;

    bool checkPrice(const int &, QTableWidget*);
    void showWrongPrice();
    void setupTableRow(const int &, const QString &, const QString &, const QStringList &,
                       const QString &, const QString &, const bool &);
    void setupTableHeaders(QTableWidget*);
    void resizeTable(QTableWidget*);

signals:
    void changeFoodSignal(const Food*, Food*);
    void removeFoodSignal(Food*);
    void changeDrinkSignal(const Drink*, Drink*);
    void removeDrinkSignal(Drink*);
    void backSignal();
    void addSignal();

private slots:
    void changedFood(int, int);
    void changeTypeComboFoods();
    void removeFood();
    void changedDrink(int, int);
    void changeTypeComboDrinks();
    void removeDrink();
};

#endif // HOLDERLISTVIEW_H
