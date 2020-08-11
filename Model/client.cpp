#include "client.h"

Client::Client(std::string us, std::string pw) : Account(us,pw,client){

}

acc Client::getType(){
    return client;
}

vector<Song *> Client::searchArtist(string artist) const{
    vector<Song*> ris;
    for(vector<Song*>::iterator it = songs.begin(); it != songs.end(); it++) {
        if((*it)->getProd() == artist || (*it)->getSinger() == artist || (*it)->getWriter() == artist)
            ris.push_back(*it);
    }
    return ris;
}
