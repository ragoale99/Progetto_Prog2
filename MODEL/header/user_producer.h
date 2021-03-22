#ifndef USER_PRODUCER
#define USER_PRODUCER

#include "user_artist.h"

class user_producer : public user_artist{
private:
    static const int defaultSalary = 1200;
    static const int prodPlus = 120;
public:
    user_producer(string n, string p, string l, int s = defaultSalary) : user_artist(n, p, l, s) {}

	virtual bool isAdmin() const;
    virtual bool isArtist() const;
    virtual bool canAdd() const;
    virtual bool canEdit() const;
    virtual bool canDelete() const;
    virtual string getType() const;

    virtual int getDefaultSalary() const;
    void increaseSalary();

    user_producer* clone() const;
};

#endif //USER_PRODUCER
