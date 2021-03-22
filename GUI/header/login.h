#ifndef LOGIN
#define LOGIN

#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QPicture>
#include <QMessageBox>
#include <QFormLayout>
#include <QComboBox>

#include "../../MODEL/header/vecUsers.h"
#include "../../MODEL/header/user.h"
#include "../../GUI/header/admin_list_users.h"

class Login : public QDialog {
    Q_OBJECT
private:
    void createLayoutLoginRegister();

    vecUsers& listaUtenti;
    user** loginUser;

    QGridLayout* layoutLoginRegister;
    QLabel* labname;
    QLabel* labpass;
    QLabel* lImgLogin;
    QLineEdit* tname;
    QLineEdit* tpass;
    QPushButton* butlogin;
    QPushButton* butregister;

    string addInfoArtist();
public:
    Login(vecUsers& lista_user, user**loginUserRef, QWidget* parent = 0);
    void clean();
public slots:
    void tryLogin();
    void signIn();
};

#endif //LOGIN
