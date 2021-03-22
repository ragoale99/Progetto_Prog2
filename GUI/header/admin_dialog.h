#ifndef ADMIN_DIALOG_H
#define ADMIN_DIALOG_H

#include <QMainWindow>
#include <QString>
#include <QPalette>
#include "../../MODEL/header/vecUsers.h"
#include "admin_widget.h"

class Admin_dialog : public QMainWindow {
private:
    vecUsers& listaUtenti;
    Admin_widget* adminWidget;
    user* chiamante;
public:
    Admin_dialog(vecUsers& lista_utenti, user* u ,QWidget* parent = 0);
};

#endif //ADMIN_DIALOG
