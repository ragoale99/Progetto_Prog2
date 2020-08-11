#include "song.h"
#include <iostream>
string Song::getLyrics() const{
    return lyrics;
}

string Song::getWriter() const{
    return writer;
}

string Song::getSinger() const{
    return singer;
}

string Song::getProd() const{
    return prod;
}

string Song::getTitle() const{
    return title;
}

Song::Song(string t, int y, int m, int d, string p, string s, string w, string l) : title(t), year(y), month(m), day(d), prod(p), singer(s), writer(w), lyrics(l){
}

Song &Song::operator =(const Song & s){
    title = s.title;
    prod = s.prod;
    singer = s.singer;
    writer = s.writer;
    lyrics = s.lyrics;
    return *this;
}

bool Song::operator ==(const Song & s){
    return title == s.title && prod == s.prod && singer == s.singer && writer == s.writer && lyrics == s.lyrics;
}

bool Song::operator !=(const Song & s){
    return title != s.title || prod != s.prod || singer != s.singer || writer != s.writer || lyrics != s.lyrics;
}

std::ostream &operator<<(std::ostream& os, const Song & s){
    os<<"Title: "<<s.title<<", Date: "<<s.year<<":"<<s.month<<":"<<s.day<<", Producer: "<<s.prod<<", Singer: ";
    if (s.singer=="")
        os<<"NULL";
    else
        os<<s.singer;
    os<<", Writer: ";
    if (s.writer=="")
        os<<"NULL";
    else
        os<<s.writer;
    return os;
}
