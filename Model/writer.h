#ifndef WRITER_H
#define WRITER_H
#include "artist.h"

class Writer : virtual public Artist {
public:
    Writer();
    Writer(QString us, QString pw, QString lbl);
    acc getType();
    virtual void insertSong(Song s);
    virtual void deleteSong(Song s);

};

#endif // WRITER_H
