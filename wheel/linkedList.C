#include <iostream>
using namespace std;

template <typename T>
class ListNode{
  public:
  T val;
  ListNode *_next;
  ListNode():_next(NULL){}
  ListNode(const T &v):_next(NULL){this->val=v;}
};

template <typename T>
class LinkedList{
  size_t _size;
  ListNode<T> *_head;
  ListNode<T> *_tail;
  public:
  LinkedList():_size(0), _head(NULL), _tail(NULL){ }
  ~LinkedList(){
    while(_head){
      ListNode<T> *tmp = _head->_next;
      delete _head;
      _head = tmp;
    }
  }
  void push_back(const T&);
  void push_front(const T&);
  T & back();
  T & front();
  void insert(int, const T &);
  void pop_back();
  void pop_front();
  void erase(size_t);
  void erase(const T&);
  void print(){
    ListNode<T> *ptr = _head;
    while(ptr){
      cout<<ptr->val<<" ";
      ptr=ptr->_next;
    }
    cout<<endl;
  }
  int size(){return _size;}
};

template <typename T>
void LinkedList<T>::push_back(const T &v){
  ListNode<T> *newnode = new ListNode<T>(v);
  if(_tail==NULL){
    _head = _tail = newnode;
  }else{
    _tail = _tail->_next = newnode;
  }
  _size++;
}

template <typename T>
void LinkedList<T>::push_front(const T &v){
  ListNode<T> *newnode = new ListNode<T>(v);
  if(_head==NULL){
    _head=_tail=newnode;
  }else{
    newnode->_next = _head;
    _head = newnode;
  }
  _size++;
}
template <typename T>
void LinkedList<T>::insert(int pos, const T &v){
  /*
   *    dummy head 1 
   *     ptr   0   1  2
   */
  ListNode<T> dummyHead;
  dummyHead._next = _head;
  ListNode<T> *ptr = &dummyHead;
  while(ptr && pos > 0){
    ptr=ptr->_next;
    --pos;
  }
  if(pos!=0) throw "out of bound";
  ListNode<T> *newnode = new ListNode<T>(v);
  newnode->_next = ptr->_next;
  ptr->_next = newnode;
  if(newnode->_next == NULL) _tail = newnode;
  _size++;
}

template <typename T>
T& LinkedList<T>::front(){
  if(_head==NULL) throw "Empty List";
  return _head->val;
};

template <typename T>
T& LinkedList<T>::back(){
  if(_tail==NULL) throw "Empty List";
  return _tail->val;
}

template <typename T>
void LinkedList<T>::erase(const T &v){
  ListNode<T> dummyHead;
  ListNode<T> *tail = &dummyHead;
  while(_head){
    if(_head->val == v){
      ListNode<T> *tmp = _head;
      _head = _head->_next;
      delete tmp;
    }else{
      tail = tail->_next = _head;
      _head = _head->_next;
    }
  }
  tail->_next = NULL;
  _tail = tail;
  _head = dummyHead._next;
}

template <typename T>
void LinkedList<T>::erase(size_t index){
  /*
   *    dummy  0 1 2 
   *     ptr 
   */
  ListNode<T> dummyHead;
  dummyHead._next = _head;
  ListNode<T> *ptr = &dummyHead;

  while(ptr && index>0){
    ptr = ptr->_next;
    index--;
  }
  if(index!=0) throw "out of range";
  ListNode<T> *tmp = ptr->_next;
  ptr->_next = tmp->_next;
  delete tmp;
  if(ptr->_next==NULL) _tail = ptr;
  _head = dummyHead._next;
}

int main(){
  LinkedList<int> intlist;
  for(int i=0;i<10;i++){
    intlist.push_back(i);
  }
  intlist.insert(3, 100);
  intlist.insert(11, 100);
  cout<<intlist.size()<<endl;
  intlist.print();
  intlist.erase(100);
  intlist.print();
  cout<<intlist.front()<<" <->  "<<intlist.back()<<endl;
  intlist.erase((size_t)0);
  intlist.print();
  intlist.erase((size_t)8);
  intlist.print();
  cout<<intlist.front()<<" <->  "<<intlist.back()<<endl;
  return 0;
}
