#include "artist.h"

Artist::Artist(){}

Artist::Artist(std::string us, std::string pw, std::string lbl) : Account(us,pw,artist), label(lbl){
}

acc Artist::getType(){
    return artist;
}

bool Artist::deleteSong(Song s){
    vector<Song*>::iterator it = searchSong(s);
    if(it != songs.end()){
        songs.erase(it);
        return true;
    }else
        return false;
}

