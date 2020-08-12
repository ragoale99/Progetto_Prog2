#ifndef ADMIN_H
#define ADMIN_H
#include "account.h"

class Admin : public Account{
public:
    Admin();
    Admin(string us, string pw);
    acc getType() const;
};

#endif // ADMIN_H
