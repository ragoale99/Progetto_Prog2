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

    // gestione della copia,assegnazione e distruzione profonda
    ~Container();                                       // distruttore profondo
    Container(const Container&);                        // costruttore di copia profonda (forse non viene nemmeno mai utilizzato)
    Container& operator=(const Container&);             // overl. del operatore =  per l'assegnazione profonda (forse non viene nemmeno mai utilizzato)

    unsigned int getSize() const;                       // restituisce il numero di elementi memorizzati
    void push_back(const T&);                           // inserisce un elemento dal fondo
    void pop(unsigned int = 0);                         // elimina l'elemento in posizione i dal Container

    // overloading dell'operatore []
    T& operator [](unsigned int) const;

    // iteratore
     class iterator{
        friend class Container<T>;
    private:
        T* punt;
    public:
       iterator();
       iterator(T*);
       iterator& operator ++();                                 // incremento prefisso
       iterator operator ++(int);                               // incremento postfisso
       iterator& operator --();                                 // decremento prefisso
       iterator operator --(int);                               // decremento postfisso
       T& operator *() const;
       T* operator ->() const;
       bool operator ==(const iterator&) const;
       bool operator !=(const iterator&) const;
    };
    // iteratore costante
    class constiterator{
        friend class Container<T>;
    private:
        T* punt;
    public:
       constiterator();
       constiterator(T*);
       constiterator& operator ++();
       constiterator& operator ++(int);
       constiterator& operator --();
       constiterator& operator --(int);
       const T& operator *() const;
       const T* operator ->() const;
       bool operator ==(const constiterator&) const;
       bool operator !=(const constiterator&) const;
    };
    constiterator begin() const;
    constiterator end() const;
};
#endif // CONTAINER_H

template<class T>
Container<T>::Container() : ptr(nullptr), size(0), dim(0) {}

template<class T>
Container<T>::~Container() {
    delete[] ptr;
}

template<class T>
Container<T>::Container(const Container& c) : ptr(c.ptr), size(c.size), dim(c.dim) {}

template<class T>
Container& Container<T>::operator =(const Container& c) {
    if(this != &c) {
        delete[] ptr;
        ptr = c.size == 0 ? nullptr : new T[c.size];
        for(unsigned int i = 0; i<c.size; i++)
            ptr[i] = c.ptr[i];
        size = c.size;
        dim = c.dim;
    }
    return *this;
}

template<class T>
T& Container<T>::operator [](unsigned int i) {
    return ptr[i];
}

template<class T>
unsigned int Container<T>::getSize() const{
    return size;
}

template<class T>
void Container<T>::redim(){
    if (!dim)
        dim++;
    else
        dim*=2;
    T* toelim = ptr;
    ptr = new T[dim];
    for(unsigned int i = 0; i<dim; i++)
        ptr[i] = toelim[i];
    delete[] toelim;
}

template<class T>
void Container<T>::push_back(const T& t){
    if(size == dim)
        redim();
    ptr[size] = t;
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
Container<T>::begin() const {
    return constiterator(ptr);
}

template<class T>
Container<T>::end() const {
    return constiterator(ptr + size);
}

    // iteratore
template<class T>
Container<T>::iterator() : punt(nullptr) {}

template<class T>
Container<T>::iterator(T* p) : punt(p) {}

template<class T>
T* Container<T>::iterator::operator ++() {
    punt++;
    return *this;
}

template<class T>
T* Container<T>::iterator::operator ++(int) {
    iterator temp = *this;
    ++*this;
    return temp;
}

template<class T>
T* Container<T>::iterator::operator --() {
    punt--;
    return *this;
}

template<class T>
T* Container<T>::iterator::operator --(int) {
    iterator temp = *this;
    --*this;
    return temp;
}

template<class T>
T& Container<T>::iterator::operator *() const {
    return *punt;
}

template<class T>
T* Container<T>::iterator::operator ->() const {
    return punt;
}

template<class T>
bool Container<T>::iterator::operator ==(const iterator& i) const {
    return i.punt == punt;
}

template<class T>
bool Container<T>::iterator::operator !=(const iterator& i) const {
    return i.punt != punt;
}

    // iteratore costante
template<class T>
Container<T>::constiterator() : punt(nullptr) {}

template<class T>
Container<T>::constiterator(T* p) : punt(p) {}

template<class T>
T* Container<T>::constiterator::operator ++() {
    punt++;
    return *this;
}

template<class T>
T* Container<T>::constiterator::operator ++(int) {
    iterator temp = *this;
    ++*this;
    return temp;
}

template<class T>
T* Container<T>::constiterator::operator --() {
    punt--;
    return *this;
}

template<class T>
T* Container<T>::constiterator::operator --(int) {
    iterator temp = *this;
    --*this;
    return temp;
}

template<class T>
const T& Container<T>::constiterator::operator *() const {
    return *punt;
}

template<class T>
const T* Container<T>::constiterator::operator ->() const {
    return punt;
}

template<class T>
bool Container<T>::constiterator::operator ==(const constiterator& c) const {
    return c.punt == punt;
}

template<class T>
bool Container<T>::constiterator::operator !=(const constiterator& c) const {
    return c.punt != punt;
}
