#include "rate.h"

//costruttori
Rate::Rate(){
    service="0";
    meal="0";
}

Rate::Rate(QString s, QString m) : service(s), meal(m){}

//metodi
 QString Rate::get_meal() const{
     return meal;
 }

 QString Rate::get_service() const{
     return service;
 }

 void Rate::set_meal(const QString& m){
     meal=m;
 }

 void Rate::set_service(const QString& s){
     service=s;

 }
