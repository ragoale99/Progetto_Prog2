#ifndef CONTAINER_H
#define CONTAINER_H
#include <QFile>
#include <QString>
#include <string>
#include<QXmlStreamWriter>

using std::string;

template<class T>
class Container{
private:
    T* ptr;
    unsigned int size;
    unsigned int dim;

    void redim();                                               // per ridimensionare il container
public:
    Container();                                                // costruttore di defualt

    virtual ~Container();                                       // distruttore virtuale

    // overloading dell'operatore []
    T& operator [](unsigned int) const;                         // overl. dell'operatore di selezione

    unsigned int getSize() const;                               // ritorna la size, ossia il numero di elementi salvati nel container
    unsigned int getDim() const;                                // ritorna la dimensione, ossia il numero effettivo di elementi memorizzabili nel container (se dim == size => dim*2)
    void push_back(T);                                          // inserisce in fondo al container un elemento
    void pop(T);                                                // elimina l'elemento passato
    void pop_ind(unsigned int);                                 // elimina l'elemento in quella posizione passata

    // Iteratore
    class Iterator{
    private:
        T* punt;
    public:
       Iterator();
       Iterator(T*);
       Iterator& operator ++();
       Iterator operator ++(int);
       Iterator& operator --();
       Iterator operator --(int);
       T& operator *() const;
       T* operator ->() const;
       bool operator ==(const Iterator&) const;
       bool operator !=(const Iterator&) const;
    };

    // Iteratore costante
    class Const_Iterator{
    private:
        T* punt;
    public:
       Const_Iterator();
       Const_Iterator(T*);
       Const_Iterator& operator ++();
       Const_Iterator operator ++(int);
       Const_Iterator& operator --();
       Const_Iterator operator --(int);
       const T& operator *() const;
       const T* operator ->() const;
       bool operator ==(const Const_Iterator&) const;
       bool operator !=(const Const_Iterator&) const;
    };

    Const_Iterator begin() const;
    Const_Iterator end() const;

    virtual bool addEnd(T) = 0;
    virtual bool remove(string name) = 0;
    virtual QString getStartLabelXml() const = 0;
    virtual QString getDefaultFile() const = 0;
    virtual bool importXml() = 0;

    void exportXml();                                           // viene eseguita l'effettiva esportazione di un utente o di una canzone nell'oggetto contenitore
};

template<class T>
Container<T>::Container() : ptr(nullptr), size(0), dim(0) {}

template<class T>
Container<T>::~Container() {
    delete[] ptr;
}

template<class T>
unsigned int Container<T>::getSize() const{
    return size;
}

template<class T>
unsigned int Container<T>::getDim() const{
    return dim;
}

template<class T>
T& Container<T>::operator [](unsigned int i) const {
    return ptr[i];
}

template<class T>
void Container<T>::redim(){
    if (!dim)
        dim++;
    else
        dim*=2;
    T* toelim = ptr;
    ptr = new T[dim];
    for(unsigned int i = 0; i<size; i++)
        ptr[i] = toelim[i];
    delete[] toelim;
}

template<class T>
void Container<T>::push_back(T t){
    if(size == dim)
        redim();
    ptr[size] = t;
    size++;
}

template<class T>
void Container<T>::pop(T u){
    bool found = false;
    unsigned int i=0;
    while(i<size && !found){
        if(&ptr[i] == &u)
            found = true;
        i++;
    }
    if(found)
        pop_ind(i-1);
}

template<class T>
void Container<T>::pop_ind(unsigned int i) {
    delete ptr[i];
    while(i < size){
        ptr[i] = ptr[i+1];
        i++;
    }
    size--;
}

template<class T>
typename::Container<T>::Const_Iterator Container<T>::begin() const {
    return Const_Iterator(ptr);
}

template<class T>
typename::Container<T>::Const_Iterator Container<T>::end() const {
    return Const_Iterator(ptr + size);
}

template<class T>
void Container<T>::exportXml() {
    QFile file(getDefaultFile());                                           // file = userdata.xml (se sto esportando un utente) oppure = songadata.xml (se sto esportando una canzone)
    file.open(QIODevice::WriteOnly);                                        // il file viene aperto (in modalita` "sola scrittura") ('open()' e` un metodo ridefinito in QFile ma derivato da QIODevice)
    QXmlStreamWriter xmlOutput(&file);
    xmlOutput.setAutoFormatting(true);                                      // formattazione automatica del file xml per permettere una maggiore leggibilita del file
    xmlOutput.writeStartDocument();

    xmlOutput.writeStartElement(getStartLabelXml());
    for(auto ci = begin(); ci != end(); ++ci)
            (*ci)->exportXml(xmlOutput);
    xmlOutput.writeEndElement();
    xmlOutput.writeEndDocument();
    file.close();
}

    // Iteratore
template<class T>
Container<T>::Iterator::Iterator() : punt(nullptr) {}

template<class T>
Container<T>::Iterator::Iterator(T* p) : punt(p) {}

template<class T>
typename::Container<T>::Iterator& Container<T>::Iterator::operator ++() {
    punt++;
    return *this;
}

template<class T>
typename::Container<T>::Iterator Container<T>::Iterator::operator ++(int) {
    Iterator temp = *this;
    ++(*this);
    return temp;
}

template<class T>
typename::Container<T>::Iterator& Container<T>::Iterator::operator --() {
    punt--;
    return *this;
}

template<class T>
typename::Container<T>::Iterator Container<T>::Iterator::operator --(int) {
    Iterator temp = *this;
    --(*this);
    return temp;
}

template<class T>
T& Container<T>::Iterator::operator *() const {
    return *punt;
}

template<class T>
T* Container<T>::Iterator::operator ->() const {
    return punt;
}

template<class T>
bool Container<T>::Iterator::operator ==(const Iterator& i) const {
    return i.punt == punt;
}

template<class T>
bool Container<T>::Iterator::operator !=(const Iterator& i) const {
    return i.punt != punt;
}

// Iteratore costante
template<class T>
Container<T>::Const_Iterator::Const_Iterator() : punt(nullptr) {}

template<class T>
Container<T>::Const_Iterator::Const_Iterator(T* p) : punt(p) {}

template<class T>
typename::Container<T>::Const_Iterator& Container<T>::Const_Iterator::operator ++() {
    punt++;
    return *this;
}

template<class T>
typename::Container<T>::Const_Iterator Container<T>::Const_Iterator::operator ++(int) {
    Const_Iterator temp = *this;
    ++*this;
    return temp;
}

template<class T>
typename::Container<T>::Const_Iterator& Container<T>::Const_Iterator::operator --() {
    punt--;
    return *this;
}

template<class T>
typename::Container<T>::Const_Iterator Container<T>::Const_Iterator::operator --(int) {
    Const_Iterator temp = *this;
    --*this;
    return temp;
}

template<class T>
const T& Container<T>::Const_Iterator::operator *() const {
    return *punt;
}

template<class T>
bool Container<T>::Const_Iterator::operator ==(const Const_Iterator& i) const {
    return i.punt == punt;
}

template<class T>
bool Container<T>::Const_Iterator::operator !=(const Const_Iterator& i) const {
    return i.punt != punt;
}

#endif // CONTAINER_H
