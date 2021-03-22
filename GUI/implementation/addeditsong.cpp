#include "../../GUI/header/addeditsong.h"

AddEditSong::AddEditSong(song* song_to_edit, user* chiamante, QWidget* parent) : QDialog(parent), s(song_to_edit), u(chiamante){
    if(s->getTitle() == "")
        setWindowTitle("Creazione nuova canzone");
    else
        setWindowTitle("Modifica canzone");
    setFixedSize(550,450);
    layout = new QFormLayout(this);
    if(view_song* v = new view_song(s)){
        v->buildGUI(chiamante->isArtist());
        layout->addWidget(v);
        QPalette pal = palette();
        v->setAutoFillBackground(true);
        pal.setColor(QPalette::Background, QColor(210, 210, 210));
        setPalette(pal);

        connect(v, SIGNAL(accept()), this, SLOT(accept()));
        connect(v, SIGNAL(reject()), this, SLOT(reject()));
    }
    else
        layout->addRow(new QLabel("La canzone passata è invalida, impossibile proseguire"));
}
