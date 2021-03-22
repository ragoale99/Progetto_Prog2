#include "MODEL/header/vecUsers.h"
#include "MODEL/header/vecSongs.h"
#include "MODEL/header/user.h"
#include "GUI/header/login.h"
#include "GUI/header/main_dialog.h"
#include <QApplication>
#include <QMessageBox>
#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char **argv){
    QApplication app(argc, argv);

    vecUsers listaUtenti;                                       // lista di utenti da importare
    if(!listaUtenti.importXml()){                               // se non avviene correttamente l'import degli utenti dal file xml
        listaUtenti.defaultData();                                  // viene inizializzata la listaUtenti con l'utente di default (admin,admin)
        listaUtenti.exportXml();                                    // e lo si esporta nel file xml
        QMessageBox info;                                           // viene poi eseguito un messageBox d'errore
        info.setText("Nessun utente trovato");
        info.setWindowTitle("Errore di apertura del file .xml");
        info.exec();
    }

    user* loginUser = 0;                                        // puntatore a un utente che vuole effettuare il login
    Login* login = new Login(listaUtenti, &loginUser);          // puntatore a un nuovo oggetto Login, inizializzato con lista i utenti importata e l'uente che vuole effettuare l'accesso

    bool exit=false;
    while(!exit){
        loginUser=0;
        login->clean();
        login->exec();                                          // viene eseguito il Login (QDialog)
        if(loginUser==0)                                        // se l'utente non e` stato riconosciuto e quindi loginUser == 0
            exit=true;                                              // exit = true => si esce dall'applicazione
        else{                                                   // se l'utente e` stato riconosciuto e quindi loginUser != 0
            bool relogin=false;                                     // flag per il relogin
            Main_dialog md(listaUtenti, loginUser, relogin);        // si apre il main_dialog (QMainWindow)
            md.setWindowModality(Qt::ApplicationModal);             // viene impostata la modalita` della finestra => ApplicationModal
                                                                    // => blocca l'input alle altre finestre (a meno che non siano figlie di essa)
            md.show();                                              // aperta la finestra principale
            app.exec();                                             // viene eseguita l'applicazione
            if(!relogin)                                            // se relogin == false => si vuole uscire dall'app
                exit=true;                                              // viene chiusa la finestra principale e viene posto exit = true e si esce
                                                                    // altrimenti se relogin == true => si vuole rieffettuare l'accesso
                                                                    // => exit viene mantenuto a false => non si esce dal ciclo while
        }
    }
    return 0;
}

