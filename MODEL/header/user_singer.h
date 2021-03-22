#ifndef USER_SINGER
#define USER_SINGER

#include "user_artist.h"

class user_singer : virtual public user_artist{
private:
    static const int defaultSalary = 1500;
protected:
    static const int singPlus = 150;
public:
    user_singer(){}
    user_singer(string n, string p, string l, int s = defaultSalary) : user_artist(n, p, l, s) {}

	virtual bool isAdmin() const;
    virtual bool isArtist() const;
    virtual bool canAdd() const;
    virtual bool canEdit() const;
    virtual bool canDelete() const;
    virtual string getType() const;

    virtual int getDefaultSalary() const;
    void increaseSalary();

    user_singer* clone() const;
};

#endif //USER_SINGER
