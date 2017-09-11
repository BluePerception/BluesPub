#include "db_user.h"
#include <QTextStream>

//inizializzazione campo dati statico
const QString db_user::filename="databaseutenti.xml";
const QString db_user::tag="db_utenti";

//COSTRUTTORE
db_user::db_user(): DbXml(tag, filename) {
    load_users();
    if(users.size()==0){
        User* newHolder=new Holder("titolare", "titolare", QDate(1995, 01, 01), "titolare@titolare.it", "titolare", "titolare");
        save_user(*newHolder);
        QMessageBox::information(0,"Attenzione!", "Viene generato un titolare di default.");
    }
}

db_user::~db_user() {
    for(std::map<QString, User*>::iterator it=users.begin(); it!=users.end(); it++)
        delete it->second;
}

//scritture e lettura del database
void db_user::save_user(User& utente){

    users[utente.getUser()] = &utente;

    QXmlStreamWriter* xmlWriter = start_write();

    xmlWriter->writeStartElement("utente");
    xmlWriter->writeTextElement("nome", utente.getName());
    xmlWriter->writeTextElement("cognome", utente.getSurname());
    xmlWriter->writeStartElement("data_nascita");
    xmlWriter->writeTextElement("giorno", QString::number(utente.getBd().day()));
    xmlWriter->writeTextElement("mese", QString::number(utente.getBd().month()));
    xmlWriter->writeTextElement("anno", QString::number(utente.getBd().year()));
    xmlWriter->writeEndElement();
    xmlWriter->writeTextElement("email", utente.getEmail());
    xmlWriter->writeTextElement("username", utente.getUser());
    xmlWriter->writeTextElement("password", utente.getPass());
    xmlWriter->writeTextElement("tipo", utente.getType());
    xmlWriter->writeEndElement();

    end_write(xmlWriter);
}

void db_user::load_users(){

    QXmlStreamReader* xmlReader = start_read();

    //Parse the XML until we reach end of it
    while(!xmlReader->atEnd() && !xmlReader->hasError()) {
        // Read next element
        //If token is just StartDocument - go to next
        if(xmlReader->isStartDocument()) {
            xmlReader->readNextStartElement();
        }
        //If token is StartElement - read it
        if(xmlReader->name() == "utente" && xmlReader->isStartElement()) {
            if(xmlReader->name() == "utente") {
                User* user = load_user(xmlReader);
                users[user->getUser()] = user;
            }
        } else {
            xmlReader->readNextStartElement();
        }
    }

    end_read(xmlReader);
}

QDate db_user::load_birthday(QXmlStreamReader*& xmlReader){
    int d, m, y;
    while(xmlReader->readNextStartElement() && xmlReader->name()!="data_nascita") {
        if(xmlReader->name()=="giorno") {
            d=xmlReader->readElementText().toInt();
        }
        if(xmlReader->name()=="mese") {
            m=xmlReader->readElementText().toInt();
        }
        if(xmlReader->name()=="anno") {
            y=xmlReader->readElementText().toInt();
        }
    }
    QDate birth(y, m, d);
    return birth;
}

//lettura dei campi del singolo utente
User* db_user::load_user(QXmlStreamReader*& xmlReader){
    QString name, surname, email, username, password, type;
    QDate birthday;
    while(xmlReader->readNextStartElement() && xmlReader->name() != "utente") {
        if(xmlReader->name()=="nome") {
            name=(xmlReader->readElementText());
        }
        else if(xmlReader->name()=="cognome") {
            surname=(xmlReader->readElementText());
        }
        //richiamerà il metodo apposito per leggere la data di nascita
        else if(xmlReader->name()=="data_nascita") {
            birthday=(load_birthday(xmlReader));
        }
        else if(xmlReader->name()=="email") {
            email=(xmlReader->readElementText());
        }
        else if(xmlReader->name()=="username") {
            username=(xmlReader->readElementText());
        }
        else if(xmlReader->name()=="password") {
            password=(xmlReader->readElementText());
        }
        else if(xmlReader->name()=="tipo") {
            type=(xmlReader->readElementText());
        }
    }
    xmlReader->readNextStartElement();
    if(type=="cliente")
        return new Client(name, surname, birthday, email, username, password);
    else{
        if(type=="cameriere")
            return new Waiter(name, surname, birthday, email, username, password);
        else
            return new Holder(name, surname, birthday, email, username, password);
    }
}

//METODI PER LA REGISTRAZIONE
bool db_user::checkExistingEmail(const QString & email) const{
    bool found=false;
    map<QString, User*>::const_iterator it;

    for(it=users.begin(); it!=users.end() && !found; it++){
        if((it->second)->getEmail() == email){
            found=true;
        }
    }
    return found;
}

bool db_user::checkExistingUsername(const QString & username) const{
    return users.find(username) != users.end();
}

//METODI PER L'ACCESSO
User* db_user::checkLogin(const QString& user, const QString& pass){
    User* loggedUser=nullptr;
    map<QString, User*>::const_iterator it=users.find(user);
    if (it != users.end() && it->second->getPass()==pass)
        return it->second;
    return loggedUser;
}

User* db_user::findUser(const QString & username) {
    User* user=0;
    map<QString, User*>::const_iterator it=users.find(username);
    if (it != users.end())
        return it->second;
    return user;
}

void db_user::save_db() {
    clear_db();
    for(map<QString, User*>::const_iterator it = users.begin(); it!=users.end(); it++)
        save_user(*(it->second));
}

void db_user::modify_user(const QString & old_user, User * new_user) {
    map<QString,User*>::iterator it;
    it=users.find(old_user);
    users.erase(it);
    users[new_user->getUser()]=new_user;
    save_db();
}

void db_user::erase_user(const QString & username) {
    User * user = users.find(username)->second;
    delete user;
    users.erase(username);
    save_db();
}

