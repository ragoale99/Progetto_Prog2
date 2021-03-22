#include "../../GUI/header/main_dialog.h"

Main_dialog::Main_dialog(vecUsers& lu, user* loginUser, bool& reloginRef, QWidget* parent) : QMainWindow(parent), listaUtenti(lu), chiamante(loginUser), relogin(reloginRef){
    QPalette pal = palette();
    setAutoFillBackground(true);
    pal.setColor(QPalette::Background, QColor(210,210,210));
    setPalette(pal);

    setWindowTitle("Libreria Musicale");
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setUser();
    setMenuBar();
}

void Main_dialog::setUser(){
    mainWidget = new Main_widget(listaUtenti, chiamante);
    setCentralWidget(mainWidget);
    connect(mainWidget,SIGNAL(reloginSlot()),this, SLOT(reloginSlot()));
}

void Main_dialog::setMenuBar(){
    menubar = menuBar();

    mbFile = new QMenu("Esci", nullptr);
    mbLogOut = new QAction("Cambia utente", nullptr);
    mbEsci = new QAction("Chiudi applicazione", nullptr);
    mbFile->addAction(mbLogOut);
    mbFile->addSeparator();
    mbFile->addAction(mbEsci);
    menubar->addMenu(mbFile);

    mbInfo  = new QMenu("Info", nullptr);
    mbInfoShow = new QAction("Info sugli sviluppatori", nullptr);
    mbInfo->addAction(mbInfoShow);
    menubar->addMenu(mbInfo);

    connect(mbLogOut, SIGNAL(triggered(bool)), this, SLOT(reloginSlot()));
    connect(mbLogOut, SIGNAL(triggered(bool)), this, SLOT(close()));
    connect(mbEsci, SIGNAL(triggered(bool)), this, SLOT(close()));
    connect(mbInfoShow, SIGNAL(triggered(bool)), this, SLOT(showInfo()));
}

void Main_dialog::reloginSlot(){
    relogin = true;
}

void Main_dialog::showInfo(){
    QMessageBox info;
    info.setText("Applicazione realizzata da Samuele De Simone e Alessandro Rago");
    info.setWindowTitle("Informazioni sull'applicazione");
    info.exec();
}
