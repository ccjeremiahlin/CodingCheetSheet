#include<queue>
#include<iostream>
#include<functional>
using namespace std;
int main(){
  //init a random access container
  vector<int> vc;
  generate_n(back_inserter(vc), 10, [](){return rand()%100;});
  //init a priority_queue with a Comparator
  priority_queue<int> pqmax(vc.begin(), vc.end());
  //dump
  while(!pqmax.empty()){
    cout<<pqmax.top()<<" "; pqmax.pop();
  }
  cout<<endl;
  //push
  priority_queue<int, vector<int>, greater<int>> pqmin(vc.begin(), vc.end());
  while(!pqmin.empty()){
    cout<<pqmin.top()<<" "; pqmin.pop();
  }
  cout<<endl;
  //pop
  return 0;
}
