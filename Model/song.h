#ifndef SONG_H
#define SONG_H
#include <QString>
using std::string;

class Song{
    friend std::ostream& operator<< (std::ostream&, const Song&);
private:
    string title;
    int year, month, day;
    string prod;
    string singer;
    string writer;
    string lyrics;
public:
    Song(string t = "Title", int y=2000, int m=1, int d=1, string p = "", string s = "", string w = "", string l = "");
    Song& operator =(const Song&);
    bool operator ==(const Song &);
    bool operator !=(const Song &);
    string getLyrics() const;
    string getWriter() const;
    string getSinger() const;
    string getProd() const;
    string getTitle() const;
};
std::ostream& operator<< (std::ostream&, const Song&);

#endif // SONG_H
