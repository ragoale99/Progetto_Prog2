#include "../header/vecUsers.h"

QString vecUsers::startLabel = "UTENTI";
QString vecUsers::defaultFile = "InputXML/userdata.xml";

QString vecUsers::getStartLabelXml() const{
    return startLabel;                                              // ritorna UTENTI
}

QString vecUsers::getDefaultFile() const{
    return defaultFile;                                             // ritorna il file di default che in questo caso e` userdata.xml
}

bool vecUsers::addEnd(user* us){                                    // aggiunge in fondo al container l'utente us
    if(us)
        if(!search(us->getName())){                                     // solo se non esiste un utente gia salvato che ha lo stesso nome
            push_back(us->clone());
            return true;
        }
    return false;                                                   // altrimenti ritorna false
}

bool vecUsers::remove(string name){                                 // per rimuovere un utente con 'name' come username
    for(auto ci = begin(); ci != end(); ++ci)
        if((*ci)->getName() == name){
            delete *ci;
            pop(*ci);
            return true;
        }
    return false;
}

user* vecUsers::search(string nome) const{                          // ricerca dell' utente con username == nome
    for(auto ci = begin(); ci != end(); ++ci)
        if(*ci != nullptr && nome == (*ci)->getName())
            return *ci;
    return nullptr;
}

bool vecUsers::search(const user* u) const{                         // ricerca dell'utente u
    if(!u)
        return false;
    for(Container<user*>::Const_Iterator ci = begin(); ci != end(); ++ci)
        if(*u == **ci)
            return true;
    return false;
}

bool vecUsers::checkPassword(const user* u, string pw){             // ritorna true se la password dell'utente u e` effitavamente pw, altrimenti false
    if(!u)
        return false;
    return u->getPassword() == pw;
}

void vecUsers::changePassword(user* edit, string new_pass){         // cambio di password
    edit->setPassword(new_pass);
}

void vecUsers::changeLabel(user* edit, string newLbl){              // cambio d'etichetta
    if(dynamic_cast<user_artist*>(edit))
        dynamic_cast<user_artist*>(edit)->setLabel(newLbl);
}

bool vecUsers::importXml(){
    bool c = false;

    QFile file(getDefaultFile());
    if (file.open(QFile::ReadOnly | QFile::Text)){
        QXmlStreamReader xmlInput(&file);

        while(xmlInput.readNextStartElement()){
            if(xmlInput.name() == getStartLabelXml()){
                while(xmlInput.readNextStartElement()){
                    string classname = (xmlInput.name().toString()).toStdString();
                    string name, pass, label;
                    int salary=0;

                    try{
                        importDataXml(xmlInput, "nome", name);
                        importDataXml(xmlInput, "password", pass);
                        bool isArtist = (classname == "PRODUCER" || classname == "SINGER" || classname == "WRITER" || classname == "SONGWRITER");
                        if (isArtist){
                            importDataXml(xmlInput, "label", label);
                            string stringSalary;
                            importDataXml(xmlInput, "salary", stringSalary);
                            salary = stoull(stringSalary);
                        }

                        user* u = 0;
                        if (classname == "ADMIN")
                            u = new user_admin(name, pass);
                        if (classname == "STANDARD")
                            u = new user_standard(name, pass);
                        if (classname == "PRODUCER")
                            u = new user_producer(name, pass, label, salary);
                        if (classname == "SINGER")
                            u = new user_singer(name, pass, label, salary);
                        if (classname == "WRITER")
                            u = new user_writer(name, pass, label, salary);
                        if (classname == "SONGWRITER")
                            u = new user_songwriter(name, pass, label, salary);

                        if(u){
                            addEnd(u);
                            delete u;
                            c = true;
                        }
                        xmlInput.skipCurrentElement();
                    }
                    catch(importException x){
                        while (!xmlInput.isEndElement() || xmlInput.name() != QString::fromStdString(classname))
                            xmlInput.readNext();
                    }
               }
            }
        }
    }
    file.close();
    return c;
}

void vecUsers::defaultData(){                       // se l'importazione non avviene correttamente viene creato un file con questo valore di default
    user_admin u("admin","admin");                      // utente 'admin','admin'
    addEnd(&u);                                         // aggiunto alla fine
}
