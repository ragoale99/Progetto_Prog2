#include "admin.h"

Admin::Admin(){

}

Admin::Admin(QString us, QString pw) : Account(us,pw,admin){

}

acc Admin::getType(){
    return admin;
}
