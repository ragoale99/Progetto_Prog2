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
    Song(string t, int y, int m, int d, string p, string s="", string w = "", string l="");
    Song& operator =(const Song&);
    bool operator ==(const Song &) const;
    bool operator !=(const Song &) const;
    string getLyrics() const;
    string getWriter() const;
    string getSinger() const;
    string getProd() const;
    string getTitle() const;
    int getYear() const;
    int getMonth() const;
    int getDay() const;
};
std::ostream& operator<< (std::ostream&, const Song&);

#endif // SONG_H
