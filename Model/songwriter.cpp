#include "songwriter.h"

SongWriter::SongWriter(string us,  string pw, string lbl) : Account(us,pw,artist), Artist(us,pw,lbl){

}

bool SongWriter::insertSong(std::string title, int y, int m, int d, std::string prod, std::string st){
    Song* s = new Song(title, y, m, d, prod, username, username);
    vector<Song*>::iterator it = searchSong(*s);
    if(it == songs.end()){
        songs.push_back(s);
        return true;
    }else
        return false;
}
