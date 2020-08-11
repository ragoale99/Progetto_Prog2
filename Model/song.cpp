#include "song.h"

Song::Song(QString t, int y, int m, int d, QString p, QString s, QString w, QString l) : title(t), year(y), month(m), day(d), prod(p), singer(s), writer(w), lyrics(l){

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
    return os<<"Titolo: "<<s.title<<", Data:"<<s.year<<":"<<s.month<<":"<<s.day;
}
