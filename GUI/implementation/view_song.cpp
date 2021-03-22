#include "../../GUI/header/view_song.h"


void view_song::buildGUI(bool isEditingArtist){
    build_layout(isEditingArtist);
    build_buttons();
}

void view_song::build_layout(bool isEditingArtist){
    layout = new QGridLayout(this);
    path = new QLineEdit();
    title = new QLineEdit();
    producer = new QLineEdit();
    singer = new QLineEdit();
    writer = new QLineEdit();
    lyrics = new QTextEdit();
    owner = new QLineEdit();
    title->setPlaceholderText(QString("Es: TitoloCanzone"));
    path->setPlaceholderText(QString("Es: /home/Music/prova.mp3"));
    producer->setPlaceholderText(QString("Producer"));
    singer->setPlaceholderText(QString("Cantante"));
    writer->setPlaceholderText(QString("Scrittore"));
    lyrics->setPlaceholderText(QString("Testo della canzone"));
    owner->setPlaceholderText(QString("Proprietario"));

    title->setText(QString::fromStdString(s->getTitle()));
    path->setText(QString::fromStdString(s->getPath()));
    producer->setText(QString::fromStdString(s->getProducer()));
    singer->setText(QString::fromStdString(s->getSinger()));
    writer->setText(QString::fromStdString(s->getWriter()));
    lyrics->setText(QString::fromStdString(s->getLyrics()));
    owner->setText(QString::fromStdString(s->getOwner()));

    if(s->getOwner() != "" and isEditingArtist){  // se == "" =>sta inserendo un admin
        owner->setDisabled(true);
        if(s->getOwnerType()=="PRODUCER"){
            producer->setDisabled(true);
        }else if(s->getOwnerType()=="WRITER"){
            writer->setDisabled(true);
        }else if(s->getOwnerType()=="SINGER"){
            singer->setDisabled(true);
        }else if(s->getOwnerType()=="SONGWRITER"){
            singer->setDisabled(true);
            writer->setDisabled(true);
        }
    }

    layout->addWidget(new QLabel("* Titolo:"),0,0);
    layout->addWidget(new QLabel("* Percorso:"),1,0);
    layout->addWidget(new QLabel("* Produttore:"),2,0);
    layout->addWidget(new QLabel("   Scrittore:"),3,0);
    layout->addWidget(new QLabel("   Cantante:"),4,0);
    layout->addWidget(new QLabel("   Testo:"),5,0,1,1,Qt::AlignTop);
    layout->addWidget(new QLabel("   Proprietario:"),6,0);
    layout->addWidget(title,0,1,1,2);
    layout->addWidget(path,1,1,1,1);
    layout->addWidget(producer,2,1,1,2);
    layout->addWidget(singer,3,1,1,2);
    layout->addWidget(writer,4,1,1,2);
    layout->addWidget(lyrics,5,1,1,2);
    layout->addWidget(owner,6,1,1,2);
}

void view_song::browse(){
    QString directory = QFileDialog::getOpenFileName(this,tr("Seleziona canzone"), "/home", tr("Song Files (*.mp3 *.wav *.m4a)"));
    if (!directory.isEmpty()){
        path->setText(directory);
    }
}

void view_song::build_buttons(){
    butNo = new QPushButton();
    butOk = new QPushButton();
    butPath = new QPushButton();
    butNo->setText("Annulla");
    butNo->setFixedWidth(200);
    butOk->setText("Ok");
    butOk->setFixedWidth(200);
    butOk->setDefault(true);
    butPath->setText("...");
    butPath->setMaximumWidth(50);
    butPath->setAutoDefault(false);
    layout->addWidget(butOk,7,0);
    layout->addWidget(butNo,7,1);
    layout->addWidget(butPath,1,2,1,1);
    QLabel* obbl = new QLabel("I campi contraddistinti dall'asterisco (*) sono obbligatori");
    layout->addWidget(obbl,8,0,1,2);

    connect(butNo, SIGNAL(clicked()), this, SLOT(rejectedits()));
    connect(butOk, SIGNAL(clicked()), this, SLOT(checkAndEdit()));
    connect(butPath,SIGNAL(clicked()), this, SLOT(browse()));
}

bool view_song::check() const{
    if(title->text() == "" || producer->text() == "" || path->text() == ""){
        QMessageBox msgErr;
        msgErr.setWindowTitle("Errore!");
        msgErr.setText("Controlla di aver inserito tutti i campi obbligatori");
        msgErr.exec();
        return false;
    }

    if(path->text().count(QLatin1Char('.')) < 1 || path->text().count(QLatin1Char(' ')) > 0){
        QMessageBox msgErr;
        msgErr.setWindowTitle("Errore!");
        msgErr.setText("Il percorso inserito non sembra essere valido");
        msgErr.exec();
        return false;
    }

    if((owner->text().toStdString() != producer->text().toStdString()) && (owner->text().toStdString() != singer->text().toStdString()) && (owner->text().toStdString() != writer->text().toStdString())){
        QMessageBox msgErr;
        msgErr.setWindowTitle("Errore!");
        msgErr.setText("Il proprietario inserito non è presente tra gli artisti");
        msgErr.exec();
        return false;
    }
    //superati tutti i controlli
    return true;
}

void view_song::checkAndEdit(){
    if(check()){
        s->setTitle(title->text().toStdString());
        s->setPath(path->text().toStdString());
        s->setLyrics(lyrics->toPlainText().toStdString());
        s->setProducer(producer->text().toStdString());
        s->setSinger(singer->text().toStdString());
        s->setWriter(writer->text().toStdString());
        s->setOwner(owner->text().toStdString());
        emit accept();
    }
}

void view_song::rejectedits(){
    emit reject();
}
