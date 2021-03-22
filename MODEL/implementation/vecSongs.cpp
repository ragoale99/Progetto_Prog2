#include "../header/vecSongs.h"

QString vecSongs::startLabel = "SONGS";
QString vecSongs::defaultFile = "InputXML/songdata.xml";

QString vecSongs::getStartLabelXml() const{
    return startLabel;                                          // ritorna SONGS
}

QString vecSongs::getDefaultFile() const{
    return defaultFile;                                         // ritorna in questo caso songdata.xml
}

bool vecSongs::addEnd(song *s){                                 // aggiunge in fondo al Container una canzone s
    push_back(s->clone());                                      // invocato il push_back di Container
    return true;                                                // ritorna true per confermare l'avvenuta dell'inserimento
}

bool vecSongs::remove(string title){                            // rimuove la canzone con 'title' come titolo (se presente => ritorna true, altrimenti false se non presente)
    for(auto ci = begin(); ci != end(); ++ci)
        if((*ci)->getTitle() == title){
            delete *ci;
            pop(*ci);                                           // viene invocato pop di Container
            return true;
        }
    return false;
}

song* vecSongs::getAtIndex(int i){                              // ritorna la canzone in posizine i nel container
    if(getSize() != 0)
        return operator [](i);
    else
        return nullptr;
}

bool vecSongs::importXml(){                                     // metodo per l'importazione delle canzoni dal file songdata.xml all'applicazione
    bool b = false;
    QFile file(getDefaultFile());                               // file = songdata.xml
    if (file.open(QFile::ReadOnly | QFile::Text)){              // si apre il file in sola lettura
        QXmlStreamReader xmlInput(&file);                       // parser per la lettura del del file songadata.xml
        while(xmlInput.readNextStartElement()){                 // finche ci sono elementi da leggere
            if(xmlInput.name() == getStartLabelXml()){              // il nome dello stream deve essere = SONGS (altrimenti errore e il file viene chiuso)
                while(xmlInput.readNextStartElement()){                 // finche ci sono elementi da leggere
                    song* s = 0;                                            // s = canzone da aggiungere nell'applicazione
                    try{                                                    // 'try' => si cerca di fare la corretta importazione
                        s = song::importXmlData(xmlInput);                  // importXmlData ritorna la canzone esportata dal file e vien salvata in s
                        if(s){                                              // se tutto e` avvenuto correttamente (s contiene effttivamente delle informazioni)
                            addEnd(s->clone());                                 // viene aggiunta in fondo al container
                            delete s;                                           // viene eliminata s (variabile locale)
                            b = true;                                           // b = true => l'importazione e` avvenuta correttamente
                        }
                        xmlInput.skipCurrentElement();                      // l'elemento e` stato gia` tutto visitato in importXmlData => si salta all'elemento successivo da importare
                    }
                    catch(importException x){                           // nel caso sia andato storto qualcosa l'eccezione viene catturata
                        while (!xmlInput.isEndElement() || xmlInput.name() != "Song")
                            xmlInput.readNext();
                    }
               }
            }
        }
    }
    file.close();                                               // si chiude il file (songdata.xml)
    return b;                                                   // si ritorna b => true sse almeno una canzone e` stata importata correttamente
}
