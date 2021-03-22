#include "../../GUI/header/admin_list_users.h"

Admin_list_users::Admin_list_users(vecUsers& lista_utenti, user *u, QWidget* parent) : QVBoxLayout(parent), listaUtenti(lista_utenti), chiamante(u){
    labelUtenti = new QLabel("Utenti:");

    lista = new QListWidget();
    lista->setFixedWidth(300);
    addWidget(lista);

    //cerca
    lsearch = new QLabel("Ricerca:");
    search = new QLineEdit();
    addWidget(lsearch);
    addWidget(search);
    connect(search, SIGNAL(textEdited(const QString&)), this, SLOT(filterWidgetList()));

    reloadList();
    connect(lista, SIGNAL(itemSelectionChanged()), this, SLOT(newItem()));

}


void Admin_list_users::reloadList(){
    lista->clear();
    for(vecUsers::Const_Iterator i = listaUtenti.begin(); i!= listaUtenti.end(); i++){
        QListWidgetItem *riga = new QListWidgetItem;
        riga->setText(QString::fromStdString("[" + (*i)->getType() + "] " + (*i)->getName() + " " + ((dynamic_cast<user_artist*>(*i)) ? "(" + (dynamic_cast<user_artist*>(*i))->getLabel() + ")" : "")));
        lista->addItem(riga);
    }
    if(search->text() != "")
        filterList();
}

void Admin_list_users::filterList(){
    int c=0;
    for(vecUsers::Const_Iterator i=listaUtenti.begin(); i!=listaUtenti.end();(++i,++c))
        if((QString::fromStdString((*i)->getName())).indexOf(search->text(), 0, Qt::CaseInsensitive) != -1)
                lista->setRowHidden(c, false);
        else
            lista->setRowHidden(c, true);
}

Admin_list_users::Info Admin_list_users::addInfoArtist(){
    Info i = {"", 0};
    QWidget* w = new QWidget();
    QDialog inputLabel(w);

    QPalette pal = inputLabel.palette();
    pal.setColor(QPalette::Background, QColor(210, 210, 210));
    inputLabel.setPalette(pal);

    inputLabel.setWindowTitle("Creazione utente");
    QFormLayout layoutLabel(&inputLabel);

    QLineEdit lelabel;
    layoutLabel.addRow(new QLabel("Etichetta discografica:"), &lelabel);

    QLineEdit lesalary;
    layoutLabel.addRow(new QLabel("Stipendio:"), &lesalary);
    lesalary.setValidator(new QRegExpValidator(QRegExp("[1-9]\\d{0,10}"), this));

    QPushButton lOk("Inserisci");
    layoutLabel.addRow(&lOk);
    connect(&lOk, SIGNAL(clicked()), &inputLabel, SLOT(accept()));
    int rit = inputLabel.exec();
    if(rit == QDialog::Accepted){
        i.label = lelabel.text().toStdString();
        i.salary = std::stoull(lesalary.text().toStdString());
    }
    return i;
}

string Admin_list_users::removeInfoUser(string nome){
    string n;
    string::size_type start = nome.find_first_of(' ');
    if(start != string::npos){
        n = nome.substr(start + 1);
        string::size_type end = n.find_last_of(' ');
        if(end != string::npos)
            return n.substr(0,end);
        else
            return "";
    } else
        return "";

}

void Admin_list_users::newItem(){
    if(dynamic_cast<user_artist*>(listaUtenti.search(removeInfoUser((lista->currentItem()->text()).toStdString()))))
        emit newSelectedItem_Signal(true);
    else
        emit newSelectedItem_Signal(false);
}

void Admin_list_users::reloadWidgetList(){
    reloadList();
}

void Admin_list_users::filterWidgetList(){
    filterList();
}

void Admin_list_users::addUser(){
    QWidget * q = new QWidget();
    QDialog inputUserDialog(q);
    inputUserDialog.setWindowTitle("Creazione utente");
    QFormLayout layoutUserDialog(&inputUserDialog);

    QPalette pal = inputUserDialog.palette();
    pal.setColor(QPalette::Background, QColor(210, 210, 210));
    inputUserDialog.setPalette(pal);

    QComboBox listaTipi;
    listaTipi.addItem("Amministratore");
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

    if(rit == QDialog::Accepted){

        //prelievo e controllo i dati
        string tipo = listaTipi.currentText().toStdString();
        string nome = lenome.text().toStdString();

        if(listaUtenti.search(nome)){
            QMessageBox avviso;
            avviso.setWindowIcon(QIcon(QPixmap(":/warning")));
            avviso.setText("Impossibile aggiungere l'utente, è già presente nel sistema");
            avviso.exec();
            return;
        }

        bool isArtist = tipo == "Produttore" || tipo == "Cantante" || tipo == "Scrittore" || tipo == "Cantautore";
        //label
        Info i = {"", 0};
        if (isArtist)
            i = addInfoArtist();
        string password = lepassword.text().toStdString();
        string etichetta = i.label;
        int stipendio = i.salary;

        if(nome == "" || password == "" || (isArtist && (etichetta=="" || stipendio == 0))){
            QMessageBox avviso;
            avviso.setWindowIcon(QIcon(QPixmap(":/error")));
            avviso.setText("Impossibile aggiungere l'utente, alcuni dati erano mancanti");
            avviso.exec();
            return;
        }

        user* newUser = 0;
        if(tipo == "Amministratore")
            newUser = new user_admin(nome, password);
        if(tipo == "Produttore")
            newUser = new user_producer(nome, password, etichetta,stipendio);
        if(tipo == "Scrittore")
            newUser = new user_writer(nome, password, etichetta,stipendio);
        if(tipo == "Cantante")
            newUser = new user_singer(nome, password, etichetta,stipendio);
        if(tipo == "Cantautore")
            newUser = new user_songwriter(nome, password, etichetta,stipendio);
        if(tipo == "Utente standard")
            newUser = new user_standard(nome, password);

        if(newUser!=0){
            listaUtenti.addEnd(newUser);
            listaUtenti.exportXml();
            lista->addItem(new QListWidgetItem(QString::fromStdString("[" + newUser->getType() + "] " + newUser->getName() + " " + ((dynamic_cast<user_artist*>(newUser)) ? "(" + (dynamic_cast<user_artist*>(newUser))->getLabel() + ")" : ""))));
            lista->setCurrentRow(lista->count()-1);
        }
    }
}

void Admin_list_users::removedSelected(){
    if(chiamante == listaUtenti.search(removeInfoUser((lista->currentItem()->text()).toStdString()))){
        QMessageBox* del = new QMessageBox(this->parentWidget());
        del->setWindowTitle("Impossibile eliminare");
        del->setText("Impossibile eliminare, questo è il proprio utente");
        del->exec();
    }else{
        QWidget * q = new QWidget();
        int confirmation = QMessageBox::question(q,"Elimina", "Sei sicuro di voler cancellare l'utente " + QString::fromStdString(removeInfoUser((lista->currentItem()->text()).toStdString()))+"?","Si","No");
        if (confirmation == 0){
            listaUtenti.pop_ind(lista->currentRow());
            lista->takeItem(lista->currentIndex().row());
            listaUtenti.exportXml();
            lista->clearSelection();
        }
    }
}

void Admin_list_users::changeSelectedPassword(){
    bool accettato;
    QWidget * q = new QWidget();
    QInputDialog* inputDialog;
    inputDialog = new QInputDialog();
    QString newPass = inputDialog->getText(q, "Cambio password", "Inserisci la nuova password:", QLineEdit::Normal, "", &accettato);
    if(accettato){
        listaUtenti.changePassword(listaUtenti.search(removeInfoUser((lista->currentItem()->text()).toStdString())), newPass.toStdString());
        listaUtenti.exportXml();
    }
}

void Admin_list_users::changeSelectedLabel(){
    bool accettato;
    QWidget * q = new QWidget();
    QInputDialog* inputDialog;
    inputDialog = new QInputDialog();
    QString newLabel = inputDialog->getText(q, "Cambio etichetta", "Inserisci la nuova etichetta:", QLineEdit::Normal, "", &accettato);
    if(accettato){
        listaUtenti.changeLabel(listaUtenti.search(removeInfoUser((lista->currentItem()->text()).toStdString())), newLabel.toStdString());
        listaUtenti.exportXml();
        reloadList();
    }
}

void Admin_list_users::showSalary_Slot(){
    QMessageBox salaryBox;
    user* chiamante = listaUtenti.search(removeInfoUser((lista->currentItem()->text()).toStdString()));
    int salary = dynamic_cast<user_artist*>(chiamante)->getSalary();
    salaryBox.setWindowTitle(QString::fromStdString("Stipendio di " + chiamante->getName()));
    salaryBox.setText(QString::fromStdString("Lo stipendio di " + chiamante->getName() + " e':\n" + std::to_string(salary)));
    salaryBox.exec();
}
