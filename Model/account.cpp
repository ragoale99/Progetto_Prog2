#include "account.h"

Account::Account(){}

Account::Account(string us, string pw, acc t) : username(us), password(pw), type(t) {}

vector<Song*>::iterator Account::searchSong(const Song& s){
    vector<Song*>::iterator it = songs.begin();
    while (it != songs.end() && **it != s)
        it++;
    return it;
}
