#ifndef RATE_H
#define RATE_H

#include <QObject>
#include <QWidget>
#include <QString>

class Rate{
private:
    QString service, meal;
public:
    Rate();
    Rate(QString, QString);

    QString get_service() const;
    QString get_meal() const;

    void set_service(const QString&);
    void set_meal(const QString&);
};

#endif // RATE_H
