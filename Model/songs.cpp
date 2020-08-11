#include "songs.h"

Songs::Songs(unsigned int size) : _size(size){
}

Songs::Songs(const Songs& v) : a(v._size==0 ? 0 : new Song[v._size]) , _size(v._size){
  for (int i=0; i<_size;++i)
    a[i] = v[i];
}

Songs& Songs::operator= (const Songs& v){
  if (this != &v){
    delete[] a;
    a= v._size==0 ? 0 : new Song[v._size];
    _size=v._size;
    for(int i=0; i<_size;++i) a[i]=v[i];
  }
  return *this;
}

Songs::~Songs(){
  delete[] a;
}

Song& Songs::operator[] (unsigned int i) const{
  return a[i];
}
void Songs::append (const Songs& v){
  *this = *this + v;
}

bool Songs::operator== (const Songs& v) const{
  if(_size != v._size)
    return false;
  for(int i=0;i<_size;++i)
    if(a[i] != v[i])
      return false;
  return true;
}

bool Songs::insert(const Song& s){
    _size++;
    this[_size]= s;
}

unsigned int Songs::size() const{
  return _size;
}
Songs operator+ (const Songs& v1, const Songs& v2){
  Songs aux(v1.size() + v2.size());
  int i=0;
  for( ; i<v1.size();++i)
    aux[i]= v1[i];
  for( ; i<aux.size();++i)
    aux[i]= v2[i-v1.size()];
  return aux;
}

/*std::ostream& operator<< (std::ostream& os, const Songs& v){
  for (int i=0;i<v.size();++i) os << v[i] <<' ';
  return os;
}*/
