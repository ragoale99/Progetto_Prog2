#ifndef ADDEDITSONG_H
#define ADDEDITSONG_H

#include <QFormLayout>
#include <QPalette>
#include "../../MODEL/header/song.h"
#include "../../MODEL/header/user.h"
#include "view_song.h"

class AddEditSong : public QDialog {
    Q_OBJECT
private:
    song* s;
    user* u;
    QFormLayout* layout;
public:
    AddEditSong(song* song_to_edit, user *chiamante, QWidget* parent = 0);
};

#endif //ADDEDITSONG
