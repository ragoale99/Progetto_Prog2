#include "../../GUI/header/admin_dialog.h"

Admin_dialog::Admin_dialog(vecUsers &lista_utenti, user *u, QWidget *parent): QMainWindow(parent), listaUtenti(lista_utenti), chiamante(u){
    setWindowTitle("Pannello di amministrazione");
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setWindowModality(Qt::ApplicationModal);

    adminWidget = new Admin_widget(listaUtenti,chiamante);
    QPalette pal = palette();
    adminWidget->setAutoFillBackground(true);
    pal.setColor(QPalette::Background, QColor(210,210,210));
    adminWidget->setPalette(pal);
    setCentralWidget(adminWidget);
    connect(adminWidget, SIGNAL(closeNow()), this, SLOT(close()));

    setMaximumSize(500,500);
}

