#ifndef SONG_H
#define SONG_H
#include <QString>

class Song{
    friend std::ostream& operator<< (std::ostream&, const Song&);
private:
    QString title;
    int year, month, day;
    QString prod;
    QString singer;
    QString writer;
    QString lyrics;
public:
    Song(QString t = "Title", int y=2000, int m=1, int d=1, QString p = NULL, QString s = NULL, QString w = NULL, QString l = NULL);
    Song& operator =(const Song&);
    bool operator ==(const Song &);
    bool operator !=(const Song &);
};
std::ostream& operator<< (std::ostream&, const Song&);

#endif // SONG_H
