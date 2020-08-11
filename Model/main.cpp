#include <QApplication>
#include <iostream>
#include "producer.h"
#include "client.h"
#include "songwriter.h"
#include "admin.h"
#include <vector>

int main(/*int argc, char *argv[]*/){
    /*QApplication a(argc, argv);
    Player w;
    w.show();

    return a.exec();*/
    Producer prod("a","b","a");
    prod.insertSong("canzone1", 1990,20,2);
    Singer sing("s", "pw", "lable");
    sing.insertSong("canzone2", 1990,20,2, "prod", "write");
    SongWriter songwr("sw", "pw", "lbl");
    songwr.insertSong("canzone3", 200,12,12,"prod2","");
    prod.insertSong("canzone4", 1990,20,2);
    prod.insertSong("canzone5", 1990,20,2);
    std::cout<<*(Artist::songs[0])<<std::endl;
    std::cout<<*(Artist::songs[1])<<std::endl;
    std::cout<<*(Artist::songs[2])<<std::endl;
    std::cout<<*(Artist::songs[3])<<std::endl;
    std::cout<<prod.insertSong("canzone4", 1990,20,2)<<std::endl;
    Client c("us","pw");
    std::vector<Song*> s = c.searchArtist("a");
    std::cout<<*(s[0])<<std::endl;
    std::cout<<*(s[1])<<std::endl;
    std::cout<<*(s[2])<<std::endl;

}
