#ifndef UTILITY_H
#define UTILITY_H
#include <sstream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <QString>

//classe di utilita' per la gestione delle stringhe
class Utility {
private:
    static const char* wrapper(char* buffer, const char* string, const int &, const int &);
    Utility();

public:
    //conversione da float a arrai di caratteri
    static const char* floatToString(const float &);

    //metodo per spezzare la stringa in un numero di colonne prestabilito contando gli spazi
    static QString wordwrap(const QString &, const int &, const int &);

};

#endif // UTILITY_H
