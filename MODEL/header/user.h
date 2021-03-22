#ifndef USER
#define USER

#include <QXmlStreamWriter>                         // classe per la scrittura su file .xml
#include <string>
using std::string;

class user {
private:
    string name;
    string password;
public:
    user(){}
    user(string n, string pw) : name(n), password(pw) {}
	
    string getName() const;                                     // ritorna il nome dell'utente
    string getPassword() const;                                 // ritorna la password dell'utente
    void setPassword(string);                                   // modifica la password dell'utente

    virtual bool isAdmin() const = 0;                           // controllo se l'utente e` admin
    virtual bool isArtist() const = 0;                          // controllo se l'utente e` artista
    virtual bool canAdd() const = 0;                            // controllo se l'utente puo` aggiungere canzoni
    virtual bool canEdit() const = 0;                           // controllo se l'utente puo` modificare canzoni
    virtual bool canDelete() const = 0;                         // controllo se l'utente puo` eliminare canzoni
    virtual string getType() const = 0;                         // ritorna il tipo di tente

    virtual user* clone() const = 0;                            // costruttore di copia polimorfo
    virtual ~user() {}                                          // distruttore virtuale

    virtual void exportXml(QXmlStreamWriter&) const;            // per l'esportazione del nuovo utente creato nel file userdata.xml
                                                                // virtuale perche un utente artista richiede piu` informazioni da esportare nel file ripsetto a un utente standard o admin (salario e etichetta)

	bool operator == (const user&) const;
	bool operator != (const user&) const;
};

#endif //USER
