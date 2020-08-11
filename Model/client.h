#ifndef CLIENT_H
#define CLIENT_H
#include "account.h"

class Client : virtual public Account{
public:
    Client(QString us, QString pw);
    acc getType();
};

#endif // CLIENT_H
