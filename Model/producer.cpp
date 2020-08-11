#include "producer.h"

Producer::Producer(){

}

Producer::Producer(QString us, QString pw, QString lbl) : Artist(us,pw,lbl){

}

/*acc Producer::getType() const{
    return Artist::getType();
}*/

void Producer::insertSong(QString title, int y, int m, int d){
    songs.push_back(new Song(title, y, m, d, username));
}

void Producer::deleteSong(Song s){
    vector<Song*>::const_iterator it;
    while (it != songs.end() && s != *(*it)){
        it++;
    }
    if (it != songs.end())
        songs.erase(it);
}
