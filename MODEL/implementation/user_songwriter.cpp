#include "../header/user_songwriter.h"

bool user_songwriter::isAdmin() const{
    return false;
}

bool user_songwriter::isArtist() const{
    return true;
}

bool user_songwriter::canAdd() const{
	return true;
}

bool user_songwriter::canEdit() const{
	return true;
}

bool user_songwriter::canDelete() const{
    return true;
}

string user_songwriter::getType() const{
    return "SONGWRITER";
}

int user_songwriter::getDefaultSalary() const{
    return defaultSalary;
}

void user_songwriter::increaseSalary(){
    setSalary(getSalary()+singPlus + writePlus);
}

user_songwriter* user_songwriter::clone() const{
    return new user_songwriter(*this);
}

