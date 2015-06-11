#include <iostream>
#include <vector>
using namespace std;

template <typename T, class Comparator=std::less<T>>
class PriorityQueue{
  vector<T> buffer;
  public:
  PriorityQueue(){}
  void push(T &v); 
  void pop();
  T & top();
  bool empty(){ return buffer.empty();}
  size_t size(){ return buffer.size();}
};

template <typename T, class Comparator>
void PriorityQueue<T, Comparator>::push(T &v){
  buffer.push_back(v);
  /*
   0 1 2 3 4 5 6 7 8
   v v v    
   */
  Comparator comparatorFn;
  int newnode = buffer.size()-1;
  while(newnode>0){
    int parent = (newnode-1)/2;
    if(comparatorFn(buffer[parent], buffer[newnode]))swap(buffer[parent], buffer[newnode]);
    newnode = parent;
  }
}

template <typename T, class Comparator>
void PriorityQueue<T, Comparator>::pop(){
  if(buffer.empty()) throw "Empty";
  if(buffer.size()>1){
    swap(buffer.front(), buffer.back());
  }
  buffer.pop_back();
  Comparator comparatorFn;
  int end = buffer.size();
  int node = 0;
  while(node<end){
    int toswap = node;
    int child = 2*node+1;
    if(child>=end) break;
    if(comparatorFn(buffer[toswap],buffer[child])) toswap=child;
    if(child+1<end && comparatorFn(buffer[toswap], buffer[child+1])) toswap=child+1;
    if(toswap==node)break;
    swap(buffer[toswap], buffer[node]);
    node=toswap;
  }
}

template <typename T, class Comparator>
T& PriorityQueue<T, Comparator>::top(){
  if(buffer.empty()) throw "Empty!";
  return buffer[0];
}

int main(){
  PriorityQueue<int> pq;
  for(int i=0;i<10;i++){
    pq.push(i);
  }
  while(!pq.empty()){
    cout<<pq.top()<<" ";
    pq.pop();
  }
}
