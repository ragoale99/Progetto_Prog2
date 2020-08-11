#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "song.h"
#include <string>
#include <vector>
using std::string;
using std::vector;
enum acc {artist = 0, client = 1, admin = 2};

class Account{
public:
    Account();
    Account(string us, string pw, acc t);
    virtual acc getType() = 0;
    inline static vector<Song*> songs;
    static vector<Song*>::iterator searchSong(const Song&);
private:
    acc type;  //true: artist, false: user
protected:
    string username;
    string password;
};

#endif // ACCOUNT_H
