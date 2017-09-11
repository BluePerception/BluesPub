#ifndef LISTVIEW_H
#define LISTVIEW_H

#include <QTabWidget>
#include <vector>
#include <QVBoxLayout>
#include <QLabel>
#include "utility.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDebug>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSpacerItem>

namespace Ui {
class ListView;
}

class ListView : public QTabWidget
{
    Q_OBJECT

public:
    explicit ListView(QWidget *parent = 0);
    void setUpBruschettes(const int &, const std::vector<QString> &, const std::vector<QString> &, const std::vector<float> &);
    void setUpSandwiches(const int &, const std::vector<QString> &, const std::vector<QString> &, const std::vector<float> &);
    void setUpToasts(const int &, const std::vector<QString> &, const std::vector<QString> &, const std::vector<float> &);
    void setUpFries(const int &, const std::vector<QString> &, const std::vector<QString> &, const std::vector<float> &);
    void setUpPlates(const int &, const std::vector<QString> &, const std::vector<QString> &, const std::vector<float> &);
    void setUpBeers(const int &, const std::vector<QString> &, const std::vector<QString> &, const std::vector<float> &);
    void setUpAperitifs(const int &, const std::vector<QString> &, const std::vector<QString> &, const std::vector<float> &);
    void setUpCocktails(const int &, const std::vector<QString> &, const std::vector<QString> &, const std::vector<float> &);
    void setUpDistillates(const int &, const std::vector<QString> &, const std::vector<QString> &, const std::vector<float> &);
    void setUpAnalcoholics(const int &, const std::vector<QString> &, const std::vector<QString> &, const std::vector<float> &);
    void show();
    ~ListView();

private:
    Ui::ListView *ui;
    QVBoxLayout* layoutFoods;
    QVBoxLayout* layoutDrinks;
    QHBoxLayout* backLayoutFoods;
    QPushButton* backFoods;
    QSpacerItem* spacerFoods;
    QHBoxLayout* backLayoutDrinks;
    QPushButton* backDrinks;
    QSpacerItem* spacerDrinks;
    QVBoxLayout* mainFoods;
    QVBoxLayout* mainDrinks;

    void setUpListForType(const QString&, const int&, const std::vector<QString>&, const std::vector<QString>&, const std::vector<float>&, QVBoxLayout*);

signals:
    void backSignal();

};

#endif // LISTVIEW_H

