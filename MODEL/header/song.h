#ifndef SONG_H
#define SONG_H
#include "exception_handling.h"
#include <QXmlStreamWriter>

class song{
private:
    string title;
    string path;
    string producer;
    string singer;
    string writer;
    string lyrics;
    string owner;
public:
    song(string t, string pa, string p, string s="", string w = "", string l="", string o="");

    string getLyrics() const;
    string getWriter() const;
    string getSinger() const;
    string getProducer() const;
    string getTitle() const;
    string getOwner() const;
    string getInfo() const;
    string getPath() const;
    string getOwnerType() const;

    void setTitle(const string &value);
    void setProducer(const string &value);
    void setSinger(const string &value);
    void setWriter(const string &value);
    void setLyrics(const string &value);
    void setOwner(const string &value);
    void setPath(const string &value);

    bool operator ==(const song &) const;
    bool operator !=(const song &) const;

    void exportXml(QXmlStreamWriter&) const;
    void exportMyXmlData(QXmlStreamWriter&) const;

    static void importMyXmlData(QXmlStreamReader&, string &title, string &path, string &producer, string &singer, string &writer, string &lyrics, string &owner);
    static song* importXmlData(QXmlStreamReader&);
    static song* build(const string &tipo, const string &owner);

    song* clone() const;
};

#endif // SONG_H
