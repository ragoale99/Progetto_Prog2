#include "../header/user_producer.h"

bool user_producer::isAdmin() const{
    return false;
}

bool user_producer::isArtist() const{
    return true;
}

bool user_producer::canAdd() const{
	return true;
}

bool user_producer::canEdit() const{
	return true;
}

bool user_producer::canDelete() const{
    return true;
}

string user_producer::getType() const{
    return "PRODUCER";
}

int user_producer::getDefaultSalary() const{
    return defaultSalary;
}

void user_producer::increaseSalary(){
    setSalary(getSalary()+prodPlus);
}

user_producer* user_producer::clone() const{
    return new user_producer(*this);
}

