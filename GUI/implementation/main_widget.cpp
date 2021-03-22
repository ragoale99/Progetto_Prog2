#include "../../GUI/header/main_widget.h"


Main_widget::Main_widget(vecUsers& listaUser, user* utenteAttuale, QWidget* parent) : QWidget(parent), listaUtenti(listaUser), chiamante(utenteAttuale){
    listaCanzoni.importXml();

    grid = new QGridLayout();
    setLayout(grid);

    //ADMIN
    if(chiamante->isAdmin()){
        buttOpenAdminPanelButton = new QPushButton("Apri il pannello admin");
        buttOpenAdminPanelButton->setFixedSize(300 ,25);
        adminControlPanel = new Admin_dialog(listaUtenti, chiamante);
        connect(buttOpenAdminPanelButton, SIGNAL(clicked()), adminControlPanel, SLOT(show()));
        grid->addWidget(buttOpenAdminPanelButton,11,1);
    }

    //ARTISTA
    if(chiamante->isArtist()){
        butSalary = new QPushButton("Visualizza stipendio");
        butSalary->setFixedSize(300 ,25);
        connect(butSalary, SIGNAL(clicked()), this, SLOT(showSalary()));
        grid->addWidget(butSalary,11,1);
    }

    lCanzoni = new QLabel("Canzoni:");
    lCanzoni->setMaximumHeight(25);
    lCanzoni->setMinimumHeight(25);
    lCanzoni->setAlignment(Qt::AlignTop);
    grid->addWidget(lCanzoni,0,0);


    lista = new QListWidget();
    lista->setMinimumWidth(450);
    grid->addWidget(lista,1,0,9,1);

    infoView = new QScrollArea;
    info = new QLabel();
    infoView->setWidget(info);
    info->setText("Nessuna canzone selezionata");
    info->setFixedWidth(280);
    info->setWordWrap(true);

    infoView->setFixedWidth(300);
    infoView->setFixedHeight(200);

    lInfoSong = new QLabel("Info Canzone:");
    lInfoSong->setMaximumHeight(25);
    lInfoSong->setMinimumHeight(25);
    lInfoSong->setAlignment(Qt::AlignTop);
    grid->addWidget(lInfoSong,0,1);

    grid->addWidget(infoView,1,1);

    lVisual = new QLabel("Visualizzazione:");
    lVisual->setMaximumHeight(18);
    lVisual->setMinimumHeight(18);
    grid->addWidget(lVisual,2,1);

    buttOpenSong = new QPushButton("Apri canzone");
    grid->addWidget(buttOpenSong,3,1);
    buttOpenSong->setDisabled(true);
    buttLyrics = new QPushButton("Visualizza il testo");
    grid->addWidget(buttLyrics,4,1);
    buttLyrics->setDisabled(true);

    lModif = new QLabel("Operazioni:");
    lModif->setMaximumHeight(18);
    lModif->setMinimumHeight(18);
    grid->addWidget(lModif,5,1);

    buttAdd = new QPushButton("Aggiungi una canzone");
    grid->addWidget(buttAdd,6,1);
    if(!chiamante->canAdd())
        buttAdd->setDisabled(true);
    buttEdit = new QPushButton("Modifica la canzone");
    grid->addWidget(buttEdit,7,1);
    buttEdit->setDisabled(true);
    buttDelete = new QPushButton("Elimina la canzone");
    grid->addWidget(buttDelete,8,1);
    buttDelete->setDisabled(true);

    connect(lista, SIGNAL(itemSelectionChanged()), this, SLOT(showInfoFile()));
    connect(lista, SIGNAL(itemSelectionChanged()), this, SLOT(refreshOpenSong()));
    connect(lista, SIGNAL(itemSelectionChanged()), this, SLOT(refreshEdit()));
    connect(lista, SIGNAL(itemSelectionChanged()), this, SLOT(refreshDelete()));
    connect(lista, SIGNAL(itemSelectionChanged()), this, SLOT(refreshLyrics()));
    connect(buttOpenSong, SIGNAL(clicked()), this, SLOT(openSelectedSong()));
    connect(lista, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(openSelectedSong()));
    connect(buttDelete, SIGNAL(clicked()), this, SLOT(deleteSelected()));
    connect(buttAdd, SIGNAL(clicked()), this, SLOT(addSong()));
    connect(buttEdit, SIGNAL(clicked()), this, SLOT(editSong()));
    connect(buttLyrics, SIGNAL(clicked()), this, SLOT(showLyrics()));

    createSearch();
    refreshLista();
}



void Main_widget::refreshLista(){
    lista->clear();
    for(vecSongs::Const_Iterator i=listaCanzoni.begin(); i!=listaCanzoni.end();i++)    {
        QListWidgetItem *riga = new QListWidgetItem;
        riga->setText(QString::fromStdString((*i)->getTitle()));
        lista->addItem(riga);
    }
    showInfoFile();
    emit filtra();
}

void Main_widget::createSearch(){
    lCerca = new QLabel("Cerca:");
    lCerca->setMaximumHeight(18);
    lCerca->setMinimumHeight(18);
    grid->addWidget(lCerca,10,0);
    search = new QLineEdit();
    search->setPlaceholderText("Ricerca case sensitive");
    grid->addWidget(search,11,0);
    radioLayout = new QHBoxLayout();
    radioTitle = new QRadioButton("Filtra dal titolo");
    radioTitle->setChecked(true);
    radioLyrics = new QRadioButton("Filtra dal testo");
    radioLayout->addSpacing(15);
    radioLayout->addWidget(radioTitle);
    radioLayout->addWidget(radioLyrics);
    grid->addLayout(radioLayout,12,0);

    connect(search, SIGNAL(textEdited(const QString&)), this, SLOT(filtra()));
    connect(radioTitle, SIGNAL(clicked()), this, SLOT(filtra()));
    connect(radioLyrics, SIGNAL(clicked()), this, SLOT(filtra()));
}

void Main_widget::refreshInfo(){
    info->setText(QString::fromStdString((listaCanzoni.getAtIndex(lista->currentRow()))->getInfo()));
    info->adjustSize();
}

void Main_widget::showInfoFile(){
    if(lista->currentRow() >=0)
        refreshInfo();
}

void Main_widget::refreshOpenSong(){
    buttOpenSong->setDisabled(false);
}

void Main_widget::refreshDelete(){
    if(listaCanzoni.getAtIndex(lista->currentRow())) {
        if((listaCanzoni.getAtIndex(lista->currentRow()))->getOwner() == chiamante->getName())
            buttDelete->setDisabled(false);
        else
            buttDelete->setDisabled(!chiamante->isAdmin());
    }
}

void Main_widget::refreshEdit(){
    if(listaCanzoni.getAtIndex(lista->currentRow())) {
        if(chiamante->canEdit() && (listaCanzoni.getAtIndex(lista->currentRow())->getOwner() == chiamante->getName()))
            buttEdit->setDisabled(false);
        else
            buttEdit->setDisabled(!chiamante->isAdmin());
    }
}

void Main_widget::refreshLyrics(){
    buttLyrics->setDisabled(false);
}

void Main_widget::openSelectedSong(){
    QString path = QString::fromStdString(listaCanzoni.getAtIndex(lista->currentRow())->getPath());

    QFileInfo p(path);
    if(p.exists())
        QDesktopServices::openUrl(QUrl(path));
    else {
        QMessageBox err;
        err.setWindowTitle("Errore!");
        err.setText("Canzone non trovata");
        err.exec();
    }
}

void Main_widget::deleteSelected(){
    int confirmation = QMessageBox::question(this, "Elimina", "Sei sicuro di voler cancellare la canzone " +lista->currentItem()->text()+ "?", "Si", "No");
    if (confirmation == 0){
        listaCanzoni.pop_ind(lista->currentRow());
        lista->takeItem(lista->currentIndex().row());
        listaCanzoni.exportXml();
        clearSelection();
    }
}

void Main_widget::showLyrics(){
    QString lyrics = QString::fromStdString(listaCanzoni.getAtIndex(lista->currentRow())->getLyrics());
    QString titleCurrent = QString::fromStdString(listaCanzoni.getAtIndex(lista->currentRow())->getTitle());
    QMessageBox lyricsBox;
    lyricsBox.setWindowTitle("Testo di " +titleCurrent);
    lyricsBox.setText("Il testo della canzone " + titleCurrent + " e':\n\n" + lyrics);
    lyricsBox.exec();
}

void Main_widget::showSalary(){
    QMessageBox salaryBox;
    int salary = dynamic_cast<user_artist*>(chiamante)->getSalary();
    salaryBox.setWindowTitle(QString::fromStdString("Stipendio di " + chiamante->getName()));
    salaryBox.setText(QString::fromStdString("Il tuo stipendio è:\n" + std::to_string(salary)));
    salaryBox.exec();
}

void Main_widget::editSong(){
    int tmpPos = lista->currentRow();
    song* s = listaCanzoni.getAtIndex(lista->currentRow());
    AddEditSong* aef = new AddEditSong(s, chiamante);
    int ris = aef->exec();
    if(ris == QDialog::Accepted){
        listaCanzoni.exportXml();
        lista->item(lista->currentRow())->setText(QString::fromStdString(s->getTitle()));
        refreshInfo();
    }
    else
        lista->setCurrentRow(tmpPos);
}

void Main_widget::addSong(){
    song* s=song::build(chiamante->getType(), chiamante->getName());
    if(s!=nullptr){
        //chiama la modifica
        AddEditSong* aef = new AddEditSong(s, chiamante);
        aef->exec();
        if(s->getTitle()!=""){
            listaCanzoni.addEnd(s);
            listaCanzoni.exportXml();
            lista->addItem(new QListWidgetItem(QString::fromStdString(s->getTitle())));
            lista->setCurrentRow(lista->count()-1);
            if(dynamic_cast<user_artist*>(chiamante))
                dynamic_cast<user_artist*>(chiamante)->increaseSalary();
        }
    } else {
        QMessageBox msgErr;
        msgErr.setWindowTitle("Errore!");
        msgErr.exec();
    }
}


void Main_widget::filtra(){
    int c=0;

    for(vecSongs::Const_Iterator i=listaCanzoni.begin(); i!=listaCanzoni.end();(++i,++c)){
        if(radioTitle->isChecked()){
            if((QString::fromStdString((*i)->getTitle())).indexOf(search->text(), 0) != -1)
                lista->setRowHidden(c, false);
            else
                lista->setRowHidden(c, true);
        }
        if(radioLyrics->isChecked()){
            if((QString::fromStdString((*i)->getLyrics())).indexOf(search->text(), 0) != -1)
                lista->setRowHidden(c, false);
            else
                lista->setRowHidden(c, true);
        }
    }
}

void Main_widget::clearSelection(){
    lista->clearSelection();
    buttOpenSong->setDisabled(true);
    buttDelete->setDisabled(true);
    buttEdit->setDisabled(true);
    info->setText("Nessuna canzone selezionata");
    info->adjustSize();
}


