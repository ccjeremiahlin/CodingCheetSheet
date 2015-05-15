#include<queue>
#include<vector>
#include<iostream>
using namespace std;
int main(){
  //init a random access container
  vector<int> v;
  generate_n(back_inserter(v), 10, [](){return rand()%100;});
  //init a priority_queue with a Comparator
  priority_queue<int, vector<int>, greater<int>> pq(v.begin(), v.end());
  //dump
  int count = 10;
  while(count){pq.push(rand()%100); count--;}
  //pop
  while(!pq.empty()){
    cout<<pq.top()<<" ";
    pq.pop();
  }
  return 0;
}
