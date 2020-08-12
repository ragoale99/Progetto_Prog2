#include "admin.h"

Admin::Admin(){

}

Admin::Admin(std::string us, std::string pw) : Account(us,pw,admin){

}

acc Admin::getType() const{
    return admin;
}
