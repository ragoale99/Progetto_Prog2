#include "../header/song.h"

song::song(string t, string pa, string p, string s, string w, string l, string o) : title(t), path(pa), producer(p), singer(s), writer(w), lyrics(l), owner(o){}

string song::getLyrics() const{
    return lyrics;
}

string song::getWriter() const{
    return writer;
}

string song::getSinger() const{
    return singer;
}

string song::getProducer() const{
    return producer;
}

string song::getTitle() const{
    return title;
}


string song::getPath() const{
    return path;
}

string song::getInfo() const{
    return "Titolo: " + title + "\nSituata in:" + path + "\nProduttore: " + producer + "\nCantante: " + singer + "\nScrittore: " + writer + "\nProprietario: " + owner;
}

string song::getOwner() const{
    return owner;
}

string song::getOwnerType() const{
    if(owner==producer){
        return "PRODUCER";
    }else if(owner==singer && owner==writer){
        return "SONGWRITER";
    }else if(owner==singer){
        return "SINGER";
    }else if(owner==writer){
        return "WRITER";
    }else return "";
}

void song::setTitle(const string &value){
    title = value;
}

void song::setSinger(const string &value){
    singer = value;
}

void song::setWriter(const string &value){
    writer = value;
}

void song::setLyrics(const string &value){
    lyrics = value;
}

void song::setProducer(const string &value){
    producer = value;
}

void song::setOwner(const string &value){
    owner = value;
}

void song::setPath(const string &value){
    path = value;
}

bool song::operator ==(const song & s) const{
    return title == s.title && producer == s.producer && singer == s.singer && writer == s.writer && lyrics == s.lyrics;
}

bool song::operator !=(const song & s) const{
    return title != s.title || producer != s.producer || singer != s.singer || writer != s.writer || lyrics != s.lyrics;
}

void song::exportXml(QXmlStreamWriter& xmlOutput) const{
    xmlOutput.writeStartElement("Song");                                                // scrive l'elemento iniziale (in questo caso non bisogna distinguere un tipo)
    exportMyXmlData(xmlOutput);                                                         // avviene la scrittura di tutti gli elementi della canzone(titolo, path,lyrics ecc.)
    xmlOutput.writeEndElement();                                                        // chiude con l'elemento finale (</Song>)
}

void song::exportMyXmlData(QXmlStreamWriter& xmlOutput) const{                          // funzione che scrive tutti gli elementi descrittivi della canzone da esportare
    xmlOutput.writeTextElement("title", QString::fromStdString(getTitle()));
    xmlOutput.writeTextElement("path", QString::fromStdString(getPath()));
    xmlOutput.writeTextElement("producer", QString::fromStdString(getProducer()));
    xmlOutput.writeTextElement("singer", QString::fromStdString(getSinger()));
    xmlOutput.writeTextElement("writer", QString::fromStdString(getWriter()));
    xmlOutput.writeTextElement("lyrics", QString::fromStdString(getLyrics()));
    xmlOutput.writeTextElement("owner", QString::fromStdString(getOwner()));
}

song* song::importXmlData(QXmlStreamReader& xmlInput) {
    string title, path, producer, singer, writer, lyrics, owner;

    importMyXmlData(xmlInput, title, path, producer, singer, writer, lyrics, owner);
    return new song(title, path, producer, singer, writer, lyrics, owner);
}

void song::importMyXmlData(QXmlStreamReader &xmlInput, string& title, string& path, string& producer, string& singer, string& writer, string& lyrics, string& owner){
    importDataXml(xmlInput, "title", title);
    importDataXml(xmlInput, "path", path);
    importDataXml(xmlInput, "producer", producer);
    importDataXml(xmlInput, "singer", singer);
    importDataXml(xmlInput, "writer", writer);
    importDataXml(xmlInput, "lyrics", lyrics);
    importDataXml(xmlInput, "owner", owner);
}

song* song::build(const string& tipo, const string& owner){
    if(tipo == "ADMIN")
        return new song("","","","","","","");
    if(tipo == "PRODUCER")
        return new song("","",owner,"","","",owner);
    if(tipo == "SONGWRITER")
        return new song("","","",owner,owner,"",owner);
    if(tipo == "SINGER")
        return new song("","","",owner,"","",owner);
    if(tipo == "WRITER")
        return new song("","","",owner,"","",owner);
    return nullptr;
}

song *song::clone() const{
    return new song(*this);
}
