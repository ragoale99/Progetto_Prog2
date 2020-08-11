#ifndef SONGWRITER_H
#define SONGWRITER_H
#include "writer.h"
#include "singer.h"

class SongWriter : public Writer, public Singer{
public:
    SongWriter(QString us, QString pw,  QString lbl);
    acc getType();
    virtual void insertSong(Song s);
    virtual void deleteSong(Song s);
};

#endif // SONGWRITER_H
