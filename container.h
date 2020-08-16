#ifndef CONTAINER_H
#define CONTAINER_H

template<class T>
class Container {
private:
    T* ptr;                                             // puntatore al primo elemento del Container
    unsigned int size;                                  // numero di elementi nel Container
    unsigned int dim;                                   // dimensione del Container

    void redim();                                       // metodo privato per il ridimensionamento del Container
public:
    Container();                                        // costruttore di default

    // gestione della distruzione profonda
    ~Container();                                       // distruttore profondo

    // overloading dell'operatore []
    T& operator [](unsigned int) const;

    unsigned int getSize() const;                       // restituisce il numero di elementi memorizzati
    unsigned int getDim() const;
    void push_back(T*);                                 // inserisce un elemento dal fondo
    void pop(unsigned int);                             // elimina l'elemento in posizione i dal Container


    // Iteratore
    class Iterator{
    private:
        T* punt;
    public:
       Iterator();
       Iterator(T*);
       Iterator& operator ++();                                 // incremento prefisso
       Iterator operator ++(int);                               // incremento postfisso
       Iterator& operator --();                                 // decremento prefisso
       Iterator operator --(int);                               // decremento postfisso
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
void Container<T>::push_back(T* t){
    if(size == dim)
        redim();
    ptr[size] = *t;
    size++;
}

template<class T>
void Container<T>::pop(unsigned int i) {
    if(i < size){
        ptr[i] = ptr[size-1];
        ptr[size-1] = nullptr;
        size--;
    }
}

template<class T>
typename::Container<T>::Const_Iterator Container<T>::begin() const {
    return Const_Iterator(ptr);
}

template<class T>
typename::Container<T>::Const_Iterator Container<T>::end() const {
    return Const_Iterator(ptr + size);
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

#endif // CONTAINER_H
