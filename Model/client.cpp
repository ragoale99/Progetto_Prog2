#include "client.h"

Client::Client(QString us, QString pw) : Account(us,pw,client){

}

acc Client::getType(){
    return client;
}


