#ifndef MAIN_DIALOG
#define MAIN_DIALOG

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QString>
#include <QMessageBox>
#include <QString>
#include <QPalette>

#include "../../MODEL/header/vecUsers.h"
#include "../../GUI/header/main_widget.h"
#include <string>

class Main_dialog : public QMainWindow {
    Q_OBJECT
private:
    Main_widget* mainWidget;
    QMenuBar* menubar;
    QMenu* mbFile;
    QMenu* mbInfo;
    QAction* mbLogOut;
    QAction* mbEsci;
    QAction* mbInfoShow;

    vecUsers& listaUtenti;
    user* chiamante;

    bool& relogin;
    void setUser();
    void setMenuBar();
public:
    Main_dialog(vecUsers& lu, user* loginUser, bool& reloginRef, QWidget *parent=0);
private slots:
    void showInfo();
public slots:
    void reloginSlot();
};

#endif //MAIN DIALOG
