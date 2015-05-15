#include<queue>
#include<deque>
#include<iostream>
#include<functional>
using namespace std;
int main(){
  //init a random access container
  deque<int> deq={1,3,4,2,3,6};
  priority_queue<int, deque<int>, greater<int> > pQueue(greater<int>(), deq);
  cout<<"current top: "<<pQueue.top()<<endl;
  cout<<"pushing 7"<<endl;
  pQueue.push(7);
  cout<<"current top: "<<pQueue.top()<<endl;
  return 1;
}
