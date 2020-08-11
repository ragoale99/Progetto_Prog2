#ifndef PRODUCER_H
#define PRODUCER_H
#include "artist.h"

class Producer : public Artist {
public:
    Producer();
    Producer(QString us, QString pw, QString lbl);
    //acc getType() const;
    virtual void insertSong(QString title, int y, int m, int d);
    virtual void deleteSong(Song s);
};

#endif // PRODUCER_H
