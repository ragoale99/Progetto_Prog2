#include "songwriter.h"

SongWriter::SongWriter(QString us,  QString pw, QString lbl) : Artist(us,pw,lbl){

}

acc SongWriter::getType(){
    return Artist::getType();
}

void SongWriter::insertSong(Song s)
{

}

void SongWriter::deleteSong(Song s)
{

}
