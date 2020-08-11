#ifndef SONGS_H
#define SONGS_H
#include "song.h"
#include <QVector>

class Songs{
  private:
    Song* a;
    unsigned int _size;
  public:
    Songs(unsigned int size);
    Songs(const Songs&);
    unsigned int size() const;
    Songs& operator= (const Songs&);
    ~Songs();
    Song& operator[] (unsigned int) const;
    void append (const Songs&);
    bool operator== (const Songs&) const;
    bool insert(const Song&);
};
Songs operator+ (const Songs&, const Songs&);
//std::ostream& operator<< (std::ostream&, const Songs&);
#endif
