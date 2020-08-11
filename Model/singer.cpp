#include "singer.h"
#include <iostream>
Singer::Singer(){

}

Singer::Singer(string us, string pw, string lbl) : Account(us,pw,artist), Artist(us,pw,lbl){

}

bool Singer::insertSong(string title, int y, int m, int d, std::string prod, std::string write){
    Song* s = new Song(title, y, m, d, prod, username, write);
    vector<Song*>::iterator it = searchSong(*s);
    if(it == songs.end()){
        songs.push_back(s);
        return true;
    }else
        return false;
}


