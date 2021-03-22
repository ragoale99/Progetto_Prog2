#ifndef VECSONGS_H
#define VECSONGS_H

#include <QFile>
#include <QXmlStreamWriter>

#include "song.h"
#include "container.h"
#include<iostream>
using std::cout; using std::endl;

template class Container<song*>;

class vecSongs : public Container<song*>{
private:
    static QString startLabel;
    static QString defaultFile;

    QString getStartLabelXml() const;
    QString getDefaultFile() const;
public:
    vecSongs() : Container() {}
    bool addEnd(song* s);
    bool remove(string title);

    song* getAtIndex(int);

    bool importXml();
};

#endif //VECSONGS
