#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 * option 1. _size, _front, _rear
 * option 2. _front, _rear, _front==-1 and _rear ==-1 when empty
 */
template <typename T>
class MyQueue{
  vector<T> iarray;
  size_t _capacity;
  size_t _size; 
  size_t _front; 
  size_t _rear; 
  public:
  MyQueue(): _size(0), _front(0), _rear(0), _capacity(4){
    iarray=vector<T>(4);
  }
  MyQueue(size_t capacity):_size(0), _front(0), _rear(0), _capacity(capacity){
    iarray=vector<T>(capacity);
  }
  size_t size(){return _size;}
  size_t capacity(){return _capacity;}
  size_t empty(){return _size==0;}
  void push(T &val);
    //1. check capacity //2. insert
  void pop();
  T& front();
};

template<typename T>
void MyQueue<T>::push(T &val){
  //handle full case
  if(_size==_capacity){
    size_t newcapacity = _capacity<<1;
    vector<T> newarray(newcapacity);
    size_t newArrayIndex=0;
    for(size_t i = _front; newArrayIndex<_size; i = (i+1)%_capacity)
      newarray[newArrayIndex++] = iarray[i];
    _front=0;
    _rear=newArrayIndex;
    _capacity=newcapacity;
    iarray.swap(newarray);
  }
  iarray[_rear]=val;
  _rear = (_rear+1)%_capacity;
  ++_size;
}

template<typename T>
void MyQueue<T>::pop(){
  if(_size==0) throw "Empty Queue!";
  ++_front;
  _front%=_capacity;
  _size--;
}

template<typename T>
T& MyQueue<T>::front(){
  if(_size==0) throw "Empty Queue!";
  return iarray[_front];
}


int main(){
  MyQueue<int> testQ;
  for(int i=0;i<10;i++){
    testQ.push(i);
    cout<<"Size: "<<testQ.size()<<" Capacity: "<<testQ.capacity()<<endl;
  }
  while(!testQ.empty()){
    cout<<"Front: "<<testQ.front()<<" ";
    testQ.pop();
  }
  cout<<endl;
}
