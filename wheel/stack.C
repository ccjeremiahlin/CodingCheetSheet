#include <iostream>
#include <string>
template <typename T>
class MyStack{
  T * _buf;
  size_t _size;
  size_t _capacity;
  public:
  MyStack():_size(0),_capacity(4){
    _buf = new T[4];
  }
  ~MyStack(){
    delete [] _buf;
  }
  void push(const T &v){
    if(_size==_capacity){
      size_t l=1;
      while(l<_size){
        l<<=1;
      }
      T * newbuf = new T[l];
      _capacity = l;
      for(int i=0;i<_size;i++){
        newbuf[i]=_buf[i];
      }
      delete [] _buf;
      _buf = newbuf;
    }
    _buf[_size++] =  v;
  }
  void pop(){
    if(_size==0){
      throw std::string("empty stack error");
    }
    _size--;
  }

  T & top(){
    if(_size==0) throw std::string("empty stack error");
    return _buf[_size-1];
  }
  bool empty(){return _size==0;}
  bool size() {return _size;}
};

int main(){
  MyStack<int> ms;
  for(int i=0;i<10;i++){
    ms.push(i);
  }
  while(!ms.empty()){
    std::cout<<ms.top()<<" ";
    ms.pop();
  }
  try{
    ms.pop();
  }catch(...){
    std::cerr<<"Error"<<std::endl;
  }
}
