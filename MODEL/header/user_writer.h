#ifndef USER_WRITER
#define USER_WRITER

#include "user_artist.h"

class user_writer: virtual public user_artist{
private:
    static const int defaultSalary = 1500;
protected:
    static const int writePlus = 150;
public:
    virtual int getDefaultSalary() const;
    user_writer(){}
    user_writer(string n, string p, string l, int s = defaultSalary) : user_artist(n, p, l, s) {}
	virtual bool isAdmin() const;
    virtual bool isArtist() const;
    virtual bool canAdd() const;
    virtual bool canEdit() const;
    virtual bool canDelete() const;
    virtual string getType() const;
    void increaseSalary();

    user_writer* clone() const;
};

#endif //USER_WRITER
