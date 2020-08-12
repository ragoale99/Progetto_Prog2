#ifndef PRODUCER_H
#define PRODUCER_H
#include "artist.h"

class Producer : public Artist {
public:
    Producer();
    Producer(string us, string pw, string lbl);
    bool insertSong(string title, int y, int m, int d, string sing="", string write="") const;
    bool insertSong(const Song &s) const;
    Song& remix(const Song&) const;
};

#endif // PRODUCER_H
