#ifndef MAIN
#define MAIN
#include <QApplication>
#include <iostream>
#include "producer.h"
#include "client.h"
#include "songwriter.h"
#include "admin.h"
#include "song.h"


int main(/*int argc, char *argv[]*/)
{
    /*QApplication a(argc, argv);
    Player w;
    w.show();

    return a.exec();*/
    Producer prod("a","b","a");
    prod.insertSong("canzone1", 1990,20,2);
    Singer sing("s", "pw", "lable");
    Song s("t", 2, 2, 2, "a", "a", "a", "a");
    //prod.insertSong("canzone2", 1990,20,2);
    std::cout<<s;
}

#endif
