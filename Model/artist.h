#ifndef ARTIST_H
#define ARTIST_H
#include "account.h"
#include "songs.h"
#include <vector>
using std::vector;

class Artist : virtual public Account{
private:
    QString label;
protected:
    vector<Song*> songs;
public:
    Artist();
    Artist(QString us, QString pw, QString lbl);
    virtual acc getType();
    virtual void insertSong(QString title, int y, int m, int d) = 0;
    virtual void deleteSong(Song s) = 0;
    vector<Song*> getSongs() const;
};

#endif // ARTIST_H
