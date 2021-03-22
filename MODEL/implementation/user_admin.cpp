#include "../header/user_admin.h"

bool user_admin::isAdmin() const{
    return true;
}

bool user_admin::isArtist() const{
    return false;
}

bool user_admin::canAdd() const{
	return true;
}

bool user_admin::canEdit() const{
	return true;
}

bool user_admin::canDelete() const{
    return true;
}

string user_admin::getType() const{
    return "ADMIN";
}

user_admin* user_admin::clone() const{
	return new user_admin(*this);
}
