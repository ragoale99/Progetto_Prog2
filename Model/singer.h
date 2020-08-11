#ifndef SINGER_H
#define SINGER_H
#include "artist.h"

class Singer : virtual public Artist{
public:
    Singer();
    Singer(QString us, QString pw, QString lbl);
    acc getType();
    virtual void insertSong(QString title, int y, int m, int d);
    virtual void deleteSong(Song s);
};

#endif // SINGER_H
