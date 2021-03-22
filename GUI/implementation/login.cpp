#include "../../GUI/header/login.h"

Login::Login(vecUsers& lista_user, user**loginUserRef, QWidget* parent) : QDialog(parent), listaUtenti(lista_user), loginUser(loginUserRef){
    setWindowTitle("Login - Libreria Musicale - Registrazione");
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    createLayoutLoginRegister();
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutLoginRegister);
    setLayout(mainLayout);
}

void Login::clean(){
    tname->clear();
    tpass->clear();
    tname->setFocus();
}

void Login::tryLogin(){
    if(listaUtenti.checkPassword(listaUtenti.search((tname->text()).toStdString()), (tpass->text()).toStdString())){
        *loginUser = listaUtenti.search((tname->text()).toStdString());
        this->close();
    } else {
        QMessageBox msgError;
        if(listaUtenti.search((tname->text()).toStdString())){
            msgError.setText("Password errata");
        } else
            msgError.setText("Utente non trovato");
        msgError.exec();
    }
}

void Login::createLayoutLoginRegister(){
    layoutLoginRegister = new QGridLayout();
    labname = new QLabel();
    labname->setText("Nome:");
    labpass = new QLabel();
    labpass->setText("Password:");
    lImgLogin = new QLabel;
    QPixmap img;
    img.load("./IMG/login.png");
    lImgLogin->setPixmap(img.scaled(60,60));
    tname = new QLineEdit();
    tpass = new QLineEdit();
    tpass->setEchoMode(QLineEdit::Password);
    layoutLoginRegister->addWidget(lImgLogin, 0, 2, 2, 1);
    layoutLoginRegister->addWidget(labname, 0, 0);
    layoutLoginRegister->addWidget(tname, 0, 1);
    layoutLoginRegister->addWidget(labpass, 1, 0);
    layoutLoginRegister->addWidget(tpass, 1, 1);
    butlogin = new QPushButton();
    butlogin->setText("Accedi");
    layoutLoginRegister->addWidget(butlogin, 2, 0, 1, 3);
    connect(butlogin, SIGNAL(clicked()), this, SLOT(tryLogin()));

    QLabel* space = new QLabel("----------------------- Oppure -----------------------");
    layoutLoginRegister->addWidget(space, 3, 0, 1, 3, Qt::AlignCenter);

    butregister = new QPushButton();
    butregister->setText("Registrati");
    layoutLoginRegister->addWidget(butregister, 4, 0, 1, 3);

    connect(butregister, SIGNAL(clicked()), this, SLOT(signIn()));

    setFixedSize(300,180);

    QPalette pal = palette();
    setAutoFillBackground(true);
    pal.setColor(QPalette::Background, QColor(210, 210, 210));
    setPalette(pal);
}

void Login::signIn(){
    QWidget * q = new QWidget(this);
    QDialog inputUserDialog(q);
    inputUserDialog.setWindowTitle("Registrati");
    QFormLayout layoutUserDialog(&inputUserDialog);
    QPalette pal = palette();
    setAutoFillBackground(true);
    pal.setColor(QPalette::Background, QColor(210, 210, 210));
    inputUserDialog.setPalette(pal);
    //drop-down button
    QComboBox listaTipi;
    listaTipi.addItem("Produttore");
    listaTipi.addItem("Cantante");
    listaTipi.addItem("Scrittore");
    listaTipi.addItem("Cantautore");
    listaTipi.addItem("Utente standard");
    layoutUserDialog.addRow(new QLabel("Tipologia:"), &listaTipi);

    //nome
    QLineEdit lenome;
    layoutUserDialog.addRow(new QLabel("Nome:"), &lenome);

    //password
    QLineEdit lepassword;
    layoutUserDialog.addRow(new QLabel("Password:"), &lepassword);

    //button per accettare
    QPushButton bOk("Crea");
    layoutUserDialog.addRow(&bOk);
    connect(&bOk, SIGNAL(clicked()), &inputUserDialog, SLOT(accept()));

    int rit = inputUserDialog.exec();
    bool isArtist = listaTipi.currentText() != "Utente standard";

    if(rit == QDialog::Accepted){
        string tipo = listaTipi.currentText().toStdString();
        string nome = lenome.text().toStdString();
        string password = lepassword.text().toStdString();


        if(nome == "" || password == ""){
            QMessageBox avviso;
            avviso.setText("Impossibile registrarsi, alcuni dati erano mancanti");
            avviso.exec();
            return;
        }


        if(listaUtenti.search(nome)){
            QMessageBox avviso;
            avviso.setText("Impossibile registrarsi, nome utente già in uso");
            avviso.exec();
            return;
        }

        string lbl;
        if (isArtist)
            lbl = addInfoArtist();

        if(isArtist && lbl == ""){
            QMessageBox avviso;
            avviso.setText("Impossibile registrarsi, alcuni dati erano mancanti");
            avviso.exec();
            return;
        }
        user* newUser = 0;
        if(tipo == "Produttore")
            newUser = new user_producer(nome, password, lbl);
        if(tipo == "Scrittore")
            newUser = new user_writer(nome, password, lbl);
        if(tipo == "Cantante")
            newUser = new user_singer(nome, password, lbl);
        if(tipo == "Cantautore")
            newUser = new user_songwriter(nome, password, lbl);
        if(tipo == "Utente standard")
            newUser = new user_standard(nome, password);

        if(newUser!=0){
            listaUtenti.addEnd(newUser);
            listaUtenti.exportXml();
            *loginUser = newUser;
            this->close();
        }
    }
}


string Login::addInfoArtist(){
    QWidget* w = new QWidget(this);
    w->move(640,240);
    QDialog inputLabel(w);
    inputLabel.setWindowTitle("Inserisci etichetta discografica");
    QFormLayout layoutLabel(&inputLabel);

    QLineEdit lelabel;
    layoutLabel.addRow(new QLabel("Etichetta discografica:"), &lelabel);

    QPushButton lOk("Inserisci");
    layoutLabel.addRow(&lOk);
    connect(&lOk, SIGNAL(clicked()), &inputLabel, SLOT(accept()));
    QPalette pal = palette();
    setAutoFillBackground(true);
    pal.setColor(QPalette::Background, QColor(210, 210, 210));
    inputLabel.setPalette(pal);
    inputLabel.exec();
    return lelabel.text().toStdString();
}
