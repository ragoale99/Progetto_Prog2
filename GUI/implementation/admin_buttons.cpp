#include "../../GUI/header/admin_buttons.h"
#include "../../GUI/header/admin_list_users.h"

Admin_buttons::Admin_buttons(QWidget* parent) : QVBoxLayout(parent){
    butAggiungi = new QPushButton();
    butElimina = new QPushButton();
    butCambiaPassword = new QPushButton();
    butCambiaLabel = new QPushButton();
    butShowSalary = new QPushButton();
    butEsci = new QPushButton();
    butAggiungi->setText("Aggiungi un utente");
    butElimina->setText("Elimina l'utente");
    butElimina->setDisabled(true);
    butCambiaPassword->setText("Cambia la password");
    butCambiaPassword->setDisabled(true);
    butCambiaLabel->setText("Cambia l'etichetta");
    butCambiaLabel->setDisabled(true);
    butShowSalary->setText("Visualizza stipendio");
    butShowSalary->setDisabled(true);
    butEsci->setText("Torna alla gestione dati");
    addWidget(butAggiungi);
    addWidget(butElimina);
    addWidget(butCambiaPassword);
    addWidget(butCambiaLabel);
    addWidget(butShowSalary);
    addWidget(butEsci);
    connect(butAggiungi, SIGNAL(clicked()), this, SIGNAL(addUser()));
    connect(butElimina, SIGNAL(clicked()), this, SIGNAL(removedSelected()));
    connect(butElimina, SIGNAL(clicked()), this, SLOT(disableButtons()));
    connect(butCambiaPassword, SIGNAL(clicked()), this, SIGNAL(changeSelectedPassword()));
    connect(butCambiaLabel, SIGNAL(clicked()), this, SIGNAL(changeSelectedLabel()));
    connect(butShowSalary, SIGNAL(clicked()), this, SIGNAL(showSalary_Signal()));
    connect(butEsci, SIGNAL(clicked()), this, SIGNAL(close()));
}

void Admin_buttons::newSelectedItem_Slot(bool isArtist){
    butElimina->setDisabled(false);
    butCambiaPassword->setDisabled(false);
    butCambiaLabel->setDisabled(!isArtist);
    butShowSalary->setDisabled(!isArtist);
}

void Admin_buttons::disableButtons(){
    butElimina->setDisabled(true);
    butCambiaPassword->setDisabled(true);
    butCambiaLabel->setDisabled(true);
    butShowSalary->setDisabled(true);
}
