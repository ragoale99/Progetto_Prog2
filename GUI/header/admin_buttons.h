#ifndef ADMIN_BUTTONS_H
#define ADMIN_BUTTONS_H

#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>

class Admin_buttons : public QVBoxLayout {
    Q_OBJECT
private:
    QPushButton *butAggiungi, *butElimina, *butCambiaPassword, *butCambiaLabel, *butEsci, *butShowSalary;
public:
    Admin_buttons(QWidget* parent=0);
private slots:
    void disableButtons();
public slots:
    void newSelectedItem_Slot(bool isArtist);
signals:
    void addUser();
    void changeSelectedPassword();
    void changeSelectedLabel();
    void removedSelected();
    void close();
    void showSalary_Signal();
};

#endif //ADMIN_BUTTONS
