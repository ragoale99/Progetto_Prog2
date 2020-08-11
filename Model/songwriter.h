#ifndef SONGWRITER_H
#define SONGWRITER_H
#include "writer.h"
#include "singer.h"

class SongWriter : public Writer, public Singer{
public:
    SongWriter(string us, string pw,  string lbl);
    virtual bool insertSong(std::string title, int y, int m, int d, string prod, string);
};

#endif // SONGWRITER_H
