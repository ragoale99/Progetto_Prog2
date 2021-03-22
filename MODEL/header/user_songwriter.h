#ifndef USER_SONGWRITER
#define USER_SONGWRITER

#include "user_singer.h"
#include "user_writer.h"

class user_songwriter: public user_singer, public user_writer{
private:
    static const int defaultSalary = 2000;
public:
    user_songwriter(string n, string p, string l, int s = defaultSalary) : user_artist(n, p, l, s) {}

	virtual bool isAdmin() const;
    virtual bool isArtist() const;
    virtual bool canAdd() const;
    virtual bool canEdit() const;
    virtual bool canDelete() const;
    virtual string getType() const;

    virtual int getDefaultSalary() const;
    void increaseSalary();

    user_songwriter* clone() const;
};

#endif //USER_SONGWRITER
