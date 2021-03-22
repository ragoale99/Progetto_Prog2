#include "../header/user_standard.h"

bool user_standard::isAdmin() const{
    return false;
}

bool user_standard::isArtist() const{
    return false;
}

bool user_standard::canAdd() const{
	return false;
}

bool user_standard::canEdit() const{
	return false;
}

bool user_standard::canDelete() const{
    return false;
}

std::string user_standard::getType() const{
    return "STANDARD";
}

user_standard* user_standard::clone() const{
	return new user_standard(*this);
}
