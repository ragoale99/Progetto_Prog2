#include "../header/user_writer.h"

bool user_writer::isAdmin() const{
    return false;
}

bool user_writer::isArtist() const{
    return true;
}

bool user_writer::canAdd() const{
	return true;
}

bool user_writer::canEdit() const{
	return true;
}

bool user_writer::canDelete() const{
    return true;
}

string user_writer::getType() const{
    return "WRITER";
}

int user_writer::getDefaultSalary() const{
    return defaultSalary;
}

void user_writer::increaseSalary(){
    setSalary(getSalary()+writePlus);
}

user_writer* user_writer::clone() const{
    return new user_writer(*this);
}

