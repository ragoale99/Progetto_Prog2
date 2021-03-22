#ifndef ADMIN_LAYOUT_H
#define ADMIN_LAYOUT_H

#include <QGridLayout>
#include <QWidget>

#include "../../MODEL/header/vecUsers.h"
#include "admin_buttons.h"
#include "admin_list_users.h"

class Admin_widget : public QWidget{
    Q_OBJECT
private:
    vecUsers& listaUtenti;
    QGridLayout* grid;
    Admin_buttons* listaTasti;
    Admin_list_users* listaUtentiGrafica;
    user* chiamante;
public:
    Admin_widget(vecUsers& lista_utenti ,user* u,QWidget* parent = 0);
signals:
    void closeNow();
};

#endif
