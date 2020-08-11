#ifndef ADMIN_H
#define ADMIN_H
#include "account.h"

class Admin : public Account{
public:
    Admin();
    Admin(QString us, QString pw);
    acc getType();
};

#endif // ADMIN_H
