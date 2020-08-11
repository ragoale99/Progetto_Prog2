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
    virtual acc getType();
    virtual bool insertSong(string title, int y, int m, int d, string = "", string = "") = 0;
    virtual bool deleteSong(Song s);
};

#endif // ARTIST_H
