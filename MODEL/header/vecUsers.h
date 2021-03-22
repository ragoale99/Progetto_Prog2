#ifndef VECUSERS_H
#define VECUSERS_H

#include "user.h"
#include "user_admin.h"
#include "user_producer.h"
#include "user_artist.h"
#include "user_artist.h"
#include "user_singer.h"
#include "user_writer.h"
#include "user_songwriter.h"
#include "user_standard.h"
#include "exception_handling.h"
#include "container.h"

template class Container<user*>;

class vecUsers : public Container<user*>{
private:
    static QString startLabel;
    static QString defaultFile;
    QString getStartLabelXml() const;
    QString getDefaultFile() const;
public:
    vecUsers(): Container() {}
    bool addEnd(user* u);
    bool remove(string name);

    user* search(string nome) const;
    bool search(const user*) const;
    static bool checkPassword(const user* u, string pw);
    void changePassword(user*, string);
    void changeLabel(user *, string);
    bool importXml();

    void defaultData();
};

#endif //VECUSERS
