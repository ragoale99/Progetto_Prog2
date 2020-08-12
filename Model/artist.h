#ifndef ARTIST_H
#define ARTIST_H
#include "account.h"
#include "song.h"
#include <vector>
using std::vector;

class Artist : virtual public Account{
private:
    string label;
public:
    Artist();
    Artist(string us, string pw, string lbl);
    virtual acc getType() const;
    virtual bool insertSong(string title, int y, int m, int d, string = "", string = "") const= 0;
    virtual bool insertSong(const Song& s) const = 0;
    virtual bool deleteSong(const Song& s) const;
};

#endif // ARTIST_H
