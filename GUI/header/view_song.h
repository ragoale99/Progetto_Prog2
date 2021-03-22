#ifndef VIEW_SONG_H
#define VIEW_SONG_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QFormLayout>
#include <QMessageBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QRegExpValidator>
#include <QDir>
#include <QFileDialog>

#include "../../MODEL/header/song.h"

class view_song : public QWidget{
    Q_OBJECT
private:
    void build_buttons();
protected:
    bool check() const;
    void build_layout(bool);

    song* s;
    QGridLayout* layout;
    QPushButton* butNo;
    QPushButton* butOk;

    QLineEdit* title;
    QLineEdit* producer;
    QLineEdit* singer;
    QLineEdit* writer;
    QTextEdit* lyrics;
    QWidget* wPath;
    QPushButton* butPath;
    QLineEdit* path;
    QLineEdit* owner;
public:
    view_song(song* song, QWidget* parent=nullptr) : QWidget(parent), s(song){}
    void buildGUI(bool);
public slots:
    void checkAndEdit();
    void rejectedits();
    void browse();
signals:
    void reject();
    void accept();
};

#endif // VIEW_SONG
