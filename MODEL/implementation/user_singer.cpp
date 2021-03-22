#include "../header/user_singer.h"

bool user_singer::isAdmin() const{
    return false;
}

bool user_singer::isArtist() const{
    return true;
}

bool user_singer::canAdd() const{
	return true;
}

bool user_singer::canEdit() const{
	return true;
}

bool user_singer::canDelete() const{
    return true;
}

string user_singer::getType() const{
    return "SINGER";
}

int user_singer::getDefaultSalary() const{
    return defaultSalary;
}

void user_singer::increaseSalary(){
    setSalary(getSalary()+singPlus);
}

user_singer* user_singer::clone() const{
    return new user_singer(*this);
}

