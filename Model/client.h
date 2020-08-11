#ifndef CLIENT_H
#define CLIENT_H
#include "account.h"
#include "song.h"
#include "artist.h"
#include <vector>
using std::vector;

class Client : virtual public Account{
public:
    Client(string us, string pw);
    acc getType();
    vector<Song*> searchArtist(string) const;
};

#endif // CLIENT_H
