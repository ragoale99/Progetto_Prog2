#ifndef ADMIN_LISTA_USERS_H
#define ADMIN_LISTA_USERS_H

#include <QVBoxLayout>
#include <QListWidget>
#include <QWidget>
#include <QLabel>
#include <QString>
#include <QFormLayout>
#include <QInputDialog>
#include <QComboBox>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>

#include "../../MODEL/header/vecUsers.h"
#include "../../MODEL/header/user.h"
#include "../../MODEL/header/user_admin.h"
#include "../../MODEL/header/user_artist.h"
#include "../../MODEL/header/user_producer.h"
#include "../../MODEL/header/user_singer.h"
#include "../../MODEL/header/user_writer.h"
#include "../../MODEL/header/user_songwriter.h"
#include "../../MODEL/header/user_standard.h"

class Admin_list_users : public QVBoxLayout{
    Q_OBJECT
private:
    struct Info{
        string label;
        int salary;
    };
    vecUsers& listaUtenti;
    QLabel* labelUtenti;
    QListWidget* lista;
    user* chiamante;

    QLabel* lsearch;
    QLineEdit* search;

    void reloadList();
    void filterList();
    Info addInfoArtist();
    static string removeInfoUser(string);
public:
    Admin_list_users(vecUsers& lista_utenti, user* u ,QWidget* parent=0);
public slots:
    void newItem();
    void reloadWidgetList();
    void filterWidgetList();
    void addUser();
    void removedSelected();
    void changeSelectedPassword();
    void changeSelectedLabel();
    void showSalary_Slot();
signals:
    void newSelectedItem_Signal(bool isArtist);
    void changeStatus(string);
};

#endif //ADMIN_LIST_USERS
