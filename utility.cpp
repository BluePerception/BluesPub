#include "utility.h"
#include <QDebug>

Utility::Utility(){}

const char* Utility::floatToString(const float & f) {
    std::ostringstream os;
    os<<std::fixed<<std::setprecision(2)<<f;
    return os.str().c_str();
}

QString Utility::wordwrap(const QString & string, const int & stringSize, const int & wrapsize) {
    const char* toWrap = string.toLatin1().data();
    char buffer[stringSize] = {0};
    return QString::fromLatin1(Utility::wrapper(buffer, toWrap, stringSize, wrapsize));
}

const char* Utility::wrapper(char* buffer, const char* string, const int & stringSize, const int & wrapSize) {
    int i = 0;
    int k, counter;

    while(i < stringSize) {
        //qDebug() << buffer;
        for ( counter = 1; counter <= wrapSize; counter++ ) {
            if ( i == stringSize) {
                buffer[i] = 0;
                return buffer;
            }
            buffer[i] = string[i];

            if (buffer[i] == '\n') {
                counter = 1;
            }
            i++;
        }

        if (isspace(string[i])) {
            buffer[i] = '\n';
            i++;
        } else {
            for (k=i; k>0; k--) {
                if (isspace(string[k])) {
                    buffer[k] = '\n';
                    i=k+1;
                    break;
                }
            }
        }
    }
    buffer[i] = 0;

    return buffer;
}
