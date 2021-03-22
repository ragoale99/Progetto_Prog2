#ifndef USER_ARTIST
#define USER_ARTIST

#include "user.h"

class user_artist : public user {
private:
    string label;
    int salary;
public:
    user_artist(){}
    user_artist(string n, string p, string l, int s) : user(n, p), label(l), salary(s) {}

    string getLabel() const;                        // ritorna l'etichetta dell'artista
    int getSalary() const;                          // ritorna il salario dell'artista
    void setSalary(int value);                      // imposta il salario
    void setLabel(const string &value);             // imposta l'etichetta

	virtual bool isAdmin() const =0;
    virtual bool isArtist() const =0;
    virtual bool canAdd() const =0;
    virtual bool canEdit() const =0;
    virtual bool canDelete() const =0;
    virtual string getType() const = 0;

    virtual int getDefaultSalary() const = 0;       // ritorna il salario base (da cui un artista inizia) (varia a seconda del tipo di artista)
    virtual void increaseSalary() = 0;              // aumenta il "salary" (aumenta in modo diverso a seconda del tipo di artista)

    void exportXml(QXmlStreamWriter&) const;        // overriding

    user_artist* clone() const = 0;
};

#endif //USER_ARTIST
