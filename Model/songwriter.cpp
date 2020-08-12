#include "songwriter.h"

SongWriter::SongWriter(string us,  string pw, string lbl) : Account(us,pw,artist), Artist(us,pw,lbl){

}

bool SongWriter::insertSong(std::string title, int y, int m, int d, std::string prod, std::string empty) const{
    Song* s = new Song(title, y, m, d, prod, username, username);
    vector<Song*>::iterator it = searchSong(*s);
    if(it == songs.end()){
        songs.push_back(s);
        return true;
    }else
        return false;
}

bool SongWriter::insertSong(const Song &s) const{
    return insertSong(s.getTitle(),s.getYear(),s.getMonth(),s.getDay(), s.getProd(),"");
}
