#include "artist.h"

Artist::Artist(){

}

Artist::Artist(QString us, QString pw, QString lbl) : Account(us,pw,artist), label(lbl){

}

acc Artist::getType(){
    return artist;
}

vector<Song *> Artist::getSongs() const{
    return songs;
}

