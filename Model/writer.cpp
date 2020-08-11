#include "writer.h"

Writer::Writer(){

}

Writer::Writer(QString us,  QString pw, QString lbl) : Artist(us,pw,lbl){

}

acc Writer::getType(){
    return Artist::getType();
}

void Writer::insertSong(Song s)
{

}

void Writer::deleteSong(Song s)
{

}
