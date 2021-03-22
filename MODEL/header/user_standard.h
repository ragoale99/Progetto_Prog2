#ifndef USER_STANDARD
#define USER_STANDARD

#include "user.h"

class user_standard : public user{
public:
    user_standard(string n, string p) : user(n, p) {}

	virtual bool isAdmin() const;
    virtual bool isArtist() const;
    virtual bool canAdd() const;
    virtual bool canEdit() const;
    virtual bool canDelete() const;
    virtual string getType() const;

	user_standard* clone() const;
};

#endif //USER_STANDARD
