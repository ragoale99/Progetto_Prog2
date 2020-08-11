#include "singer.h"

Singer::Singer(){

}

Singer::Singer(QString us, QString pw, QString lbl) : Artist(us,pw,lbl){

}

acc Singer::getType(){
    return Artist::getType();
}

void Singer::insertSong(QString title, int y, int m, int d){
    songs.push_back(new Song(title, y, m, d, "prod", username, "writer"));
}


void Singer::deleteSong(Song s){
}
