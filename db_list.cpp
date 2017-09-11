#include "db_list.h"


//inizializzazione campo dati statico
const QString db_list::filename="listino.xml";
const QString db_list::tag="db_list";

//COSTRUTTORE
db_list::db_list(): DbXml(tag, filename) {
    load_items();
}

db_list::~db_list() {
    for(std::vector<ListItem*>::iterator it=items.begin(); it!=items.end(); it++)
        delete *it;
}

//scritture e lettura del database
void db_list::save_item(const ListItem & item) {
    QXmlStreamWriter* xmlWriter = start_write();
    item.save(xmlWriter);
    end_write(xmlWriter);
    items.push_back(item.clone());
}


void db_list::load_items(){
    QXmlStreamReader* xmlReader = start_read();
    Food* f;
    Drink* d;
    //Parse the XML until we reach end of it
    while(!xmlReader->atEnd() && !xmlReader->hasError()) {
            // Read next element
            //If token is just StartDocument - go to next
            if(xmlReader->isStartDocument()) {
                xmlReader->readNextStartElement();
            }
            //If token is StartElement - read it
            if(xmlReader->name() == "cibo" && xmlReader->isStartElement()) {
                f = new Food();
                f->load(xmlReader);
                items.push_back(f);
            }
            if(xmlReader->name() == "bevanda" && xmlReader->isStartElement()) {
                d = new Drink();
                d->load(xmlReader);
                items.push_back(d);
            }
            else {
                xmlReader->readNextStartElement();
            }
    }

    end_read(xmlReader);
}

ListItem* db_list::getItemFromName(const QString & item_name) const {
    bool found = false;
    ListItem* item;
    for(std::vector<ListItem*>::const_iterator it=items.begin(); it!=items.end() && !found; it++) {
        found = (item_name == (*it)->getName());
        if (found)
            item = *it;
    }
    return item;
}

void db_list::changeListItem(const ListItem* oldItem, ListItem* newItem) {
    bool found=false;
    ListItem* punt;
    for(vector<ListItem*>::iterator it=items.begin(); it!=items.end() && !found; it++){
        if ((**it)==(*oldItem)){
            punt=*it;
            (*it)=(Food*)newItem;
            found=true;
            delete punt;
        }
    }

    save_db();
}

void db_list::removeItem(const ListItem* item) {
    bool found=false;
    ListItem* punt;
    for(vector<ListItem*>::iterator it=items.begin(); it!=items.end() && !found; it++){
        if ((**it)==(*item)){
            punt=*it;
            items.erase(it);
            found=true;
            delete punt;
        }
    }

    save_db();
}

void db_list::save_db() {
    clear_db();
    QXmlStreamWriter* xmlWriter=start_write();

    for(vector<ListItem*>::const_iterator it = items.begin(); it!=items.end(); it++)
        (*it)->save(xmlWriter);

    end_write(xmlWriter);
}

std::vector<const Food*> db_list::getFoods() const {
    std::vector<const Food*> foods;
    for(std::vector<ListItem*>::const_iterator it=items.begin(); it!=items.end(); it++) {
        if (dynamic_cast<Food*>(*it))
            foods.push_back((Food*)(*it));
    }
    return foods;
}

std::vector<const Drink*> db_list::getDrinks() const {
    std::vector<const Drink*> drinks;
    for(std::vector<ListItem*>::const_iterator it=items.begin(); it!=items.end(); it++) {
        if (dynamic_cast<Drink*>(*it))
            drinks.push_back((Drink*)(*it));
    }
    return drinks;
}

std::vector<const ListItem*> db_list::getItems() const {
    std::vector<const ListItem*> items_;
    for(std::vector<ListItem*>::const_iterator it=items.begin(); it!=items.end(); it++) {
        items_.push_back((*it));
    }
    return items_;
}
