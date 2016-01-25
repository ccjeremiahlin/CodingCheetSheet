#include <cstdlib>
#include <iostream>
template <typename E>
class myVector{
  E * _buffer;
  size_t _capacity;
  size_t _size;
  public:
  typedef E * iterator;
  myVector();
  myVector(size_t);
  ~myVector();
  myVector<E> & operator=(myVector<E> &);
  myVector<E> & operator[](size_t index);
  iterator begin();
  iterator end();
  myVector<E> & front();
  myVector<E> & back();
  void push_back(E &);
  void reserve();
  size_t capacity();
  size_t size();
  bool empty();
  iterator insert(iterator, E &);
  iterator erase(iterator);
};

template <typename E>
myVector<E>::myVector():_buffer(NULL), _capacity(0), _size(0){}

template <typename E>
myVector<E>::myVector(size_t size){
  _capacity=1;
  while(_capacity<size){
    _capacity<<=1;
  }
  _buffer = new E[_capacity]; 
  _size=size;
}

template <typename E>
myVector<E>::~myVector(){
  if(_buffer) free(_buffer);
  std::cout<<"Destructed"<<std::endl;
}
template <typename E>
myVector<E> & myVector<E>::operator=(myVector<E> &from){
  if(_buffer) free(_buffer);
  _capacity = from._capacity;
  _size = from._size;
  _buffer = new E[_capacity];
  memcpy(_buffer, from._buffer, from._size);
  return *this;
}

template <typename E>
myVector<E> & myVector<E>::operator[](size_t index){
  return _buffer[index];
}

template <typename E>
typename myVector<E>::iterator myVector<E>::begin(){
  return _buffer;
}

template <typename E>
typename myVector<E>::iterator myVector<E>::end(){
  return _buffer+_size;
}

template <typename E>
void myVector<E>::push_back(E &value){
 if(_size>=_capacity){
   _capacity<<=1;
   E * tmpBuffer = new E[_capacity];
   for(int i=0;i<_size;i++)tmpBuffer[i]=_buffer[i];
   free(_buffer);
   _buffer = tmpBuffer;
 }
 _buffer[_size++] = value; 
}
