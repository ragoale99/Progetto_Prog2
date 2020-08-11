#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <QString>
enum acc {artist = 0, client = 1, admin = 2};

class Account{

public:
    Account();
    Account(QString us, QString pw, acc t);
    virtual acc getType() = 0;
private:
    acc type;  //true: artist, false: user
protected:
        QString username;
        QString password;
};

#endif // ACCOUNT_H
