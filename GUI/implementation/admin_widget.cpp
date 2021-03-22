#include "../../GUI/header/admin_widget.h"

Admin_widget::Admin_widget(vecUsers& lista_utenti ,user* u,QWidget* parent):
    QWidget(parent), listaUtenti(lista_utenti), chiamante(u)
{
    grid = new QGridLayout();
    listaTasti = new Admin_buttons();
    listaUtentiGrafica = new Admin_list_users(listaUtenti,chiamante);
    grid->addItem(listaTasti,0,0);
    grid->addItem(listaUtentiGrafica,0,1);
    setLayout(grid);

    connect(listaUtentiGrafica, SIGNAL(newSelectedItem_Signal(bool)), listaTasti, SLOT(newSelectedItem_Slot(bool)));
    connect(listaTasti, SIGNAL(addUser()), listaUtentiGrafica, SLOT(addUser()));
    connect(listaTasti, SIGNAL(removedSelected()), listaUtentiGrafica, SLOT(removedSelected()));
    connect(listaTasti, SIGNAL(close()), this, SIGNAL(closeNow()));
    connect(listaTasti, SIGNAL(changeSelectedPassword()), listaUtentiGrafica, SLOT(changeSelectedPassword()));
    connect(listaTasti, SIGNAL(changeSelectedLabel()), listaUtentiGrafica, SLOT(changeSelectedLabel()));
    connect(listaTasti, SIGNAL(showSalary_Signal()), listaUtentiGrafica, SLOT(showSalary_Slot()));
}
