#ifndef USER_ADMIN
#define USER_ADMIN

#include "user.h"

class user_admin : public user{
public:
    user_admin(string n, string p) : user(n, p) {}

	virtual bool isAdmin() const;
    virtual bool isArtist() const;
    virtual bool canAdd() const;
    virtual bool canEdit() const;
    virtual bool canDelete() const;
    virtual string getType() const;

    user_admin* clone() const;
};

#endif //USER_ADMIN
