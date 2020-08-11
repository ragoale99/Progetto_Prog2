#ifndef SINGER_H
#define SINGER_H
#include "artist.h"

class Singer : virtual public Artist{
public:
    Singer();
    Singer(string us, string pw, string lbl);
    virtual bool insertSong(std::string title, int y, int m, int d, string prod, string write);
};

#endif // SINGER_H
