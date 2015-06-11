#include <iostream>
#include <algorithm>
#include <exception>

class MyVectorOutOfBoundEx : public std::exception{
  virtual const char* what() const throw()
  {
    return "Out of Bound Exception";
  }
}myex;

template <typename T>
class MyVector{
  T * _bufPtr;
  size_t _capacity;
  size_t _size;
  public:
  using iterator = T *;
  MyVector():_size(0), _capacity(4){
   _bufPtr = new T[_capacity]; 
  }
  MyVector(size_t size):_size(size){
    size_t l = 1;
    while(l<size)l<<=1;
    _bufPtr = new T[l];
    _capacity = l;
  }
  void push_back(const T &v){
    if(_size==_capacity){
      if(_capacity<<1 < _capacity) throw myex;
      T * tmpBuf = new T[_capacity<<1];
      _capacity<<=1;
      for(int i=0;i<_size;i++){
        tmpBuf[i] = _bufPtr[i];
      }
      std::swap(tmpBuf, _bufPtr);
      free(tmpBuf);
    }
    _bufPtr[_size++] = v;
  }
  void pop_back(){
    if(_size==0) throw myex;
    _size--;
  }
  T & operator[](size_t index){
    if(index>=_size)throw myex;
    return _bufPtr[index];
  }
  T & front(){
    if(_size==0)throw myex;
    return _bufPtr[0];
  }
  T & back(){
    if(_size==0) throw myex;
    return _bufPtr[_size-1];
  }
  void insert(iterator pos, const T &val){
    int targetIndex = pos-_bufPtr;
    if(_size==targetIndex){
      this->push_back(val);
      return;
    }
    bool boolNewBuf = _size==_capacity;
    T * _newbuf;
    _newbuf = boolNewBuf? new T[_capacity<<1] : _bufPtr;
    _capacity = boolNewBuf? _capacity<<1 : _capacity;

    T * oldend = _bufPtr+_size;
    T * oldtarget = _bufPtr+targetIndex;
    T * newend = _newbuf+_size+1;

    while((oldend+1)!=oldtarget)*newend-- = *oldend--;
    *newend-- = val;
    while(boolNewBuf && oldend+1!=_bufPtr) *newend-- = *oldend--;
    if(boolNewBuf){
      std::swap(_bufPtr, _newbuf);
      delete []_newbuf;
    }
    _size++;
  }
  iterator begin(){
    return _bufPtr;
  }
  iterator end(){
    return _bufPtr+_size;
  }
  size_t size(){return _size;}
  bool empty(){return _size==0;}
  size_t capacity(){return _capacity;}
};

template <typename T>
void dump(T &mv){
  std::cout<<std::endl;
  for(int i=0;i<mv.size();i++){
    std::cout<<mv[i]<<" ";
  }
  std::cout<<"Size: "<<mv.size()<<" ";
  std::cout<<"Capacity: "<<mv.capacity()<<std::endl;
  std::cout<<std::endl;
}

int main(){
  using namespace std;
  MyVector<int> mv;
  for(int i=0;i<8;i++){
    mv.push_back(i);
    std::cout<<"Size: "<<mv.size()<<" ";
    std::cout<<"Capacity: "<<mv.capacity()<<std::endl;
  }
  dump<MyVector<int>>(mv);
  srand(time(0));
  mv.insert(mv.begin()+rand()%mv.size(), 100);
  dump<MyVector<int>>(mv);
  std::cout<<std::endl;
  return 0;
}
