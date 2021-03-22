#ifndef MAIN_WIDGET_H
#define MAIN_WIDGET_H

#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QListWidget>
#include <QScrollArea>
#include <QDesktopServices>
#include <QUrl>
#include <QRadioButton>
#include <QFileInfo>

#include "../../MODEL/header/vecSongs.h"
#include "admin_dialog.h"
#include "addeditsong.h"

class Main_widget : public QWidget{
    Q_OBJECT
private:
    QGridLayout* grid;
    vecSongs listaCanzoni;
    vecUsers& listaUtenti;
    user* chiamante;
    QPushButton *buttOpenSong, *buttAdd, *buttEdit, *buttDelete, *buttLyrics;
    QPushButton *buttOpenAdminPanelButton, *butSalary;
    static bool switchbuttonName, switchbuttonSize;
    Admin_dialog* adminControlPanel;
    QListWidget* lista;
    QLabel *info;
    QScrollArea* infoView;

    QLineEdit* search;
    QHBoxLayout* radioLayout;
    QRadioButton* radioTitle;
    QRadioButton* radioLyrics;
    QHBoxLayout* caseLayout;
    QCheckBox* caseSens;
    QLabel* lInfoSong;
    QLabel* lCanzoni;
    QLabel* lVisual;
    QLabel* lModif;
    QLabel* lCerca;
    QLabel* lCase;
    void refreshLista();
    void showInfoSelectedElement();
    void showIfCanEdit();
    void showIfCanDelete();
    void createSearch();
    void refreshInfo();
    void clearSelection();
public:
    Main_widget(vecUsers& listaUser, user* utenteAttuale, QWidget* parent=0);
private slots:
    void showInfoFile();
    void refreshOpenSong();
    void refreshDelete();
    void refreshEdit();
    void refreshLyrics();
    void openSelectedSong();
    void deleteSelected();
    void showLyrics();
    void showSalary();
    void editSong();
    void addSong();
    void filtra();
signals:
    void reloginSlot();
};

#endif //MAIN_WIDGET
