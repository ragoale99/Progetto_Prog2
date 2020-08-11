#include "producer.h"

Producer::Producer(string us, string pw, string lbl) : Account(us,pw,artist), Artist(us,pw,lbl){}

bool Producer::insertSong(string title, int y, int m, int d, std::string sing, std::string write){
    Song* s = new Song(title, y, m, d, username, sing, write);
    vector<Song*>::iterator it = searchSong(*s);
    if(it == songs.end()){
        songs.push_back(s);
        return true;
    }else
        return false;
}

