#include "writer.h"

Writer::Writer(){

}

Writer::Writer(std::string us,  std::string pw, std::string lbl) : Account(us,pw,artist), Artist(us,pw,lbl){

}


bool Writer::insertSong(std::string title, int y, int m, int d, std::string prod, std::string sing) const{
    Song* s = new Song(title, y, m, d, prod, sing, username);
    vector<Song*>::iterator it = searchSong(*s);
    if(it == songs.end()){
        songs.push_back(s);
        return true;
    }else
        return false;
}

bool Writer::insertSong(const Song &s) const{
    return insertSong(s.getTitle(),s.getYear(),s.getMonth(),s.getDay(),s.getProd(),s.getSinger());
}

