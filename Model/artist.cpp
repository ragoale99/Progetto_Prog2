#include "artist.h"
#include <iostream>
Artist::Artist(){}

Artist::Artist(std::string us, std::string pw, std::string lbl) : Account(us,pw,artist), label(lbl){
}

acc Artist::getType() const{
    return artist;
}

bool Artist::deleteSong(const Song &s) const{
    vector<Song*>::iterator it = searchSong(s);
    if(it != songs.end() && (username == (*it)->getProd() || username == (*it)->getWriter() || username == (*it)->getSinger())){
        songs.erase(it);
        return true;
    }else
        return false;
}

