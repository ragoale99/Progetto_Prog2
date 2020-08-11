#ifndef WRITER_H
#define WRITER_H
#include "artist.h"

class Writer : virtual public Artist {
public:
    Writer();
    Writer(string us, string pw, string lbl);
    virtual bool insertSong(std::string title, int y, int m, int d, string prod, string sing);
};

#endif // WRITER_H
