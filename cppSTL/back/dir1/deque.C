#include <deque>
#include <iostream>
#include <iterator>
#include <cstdlib>
#include <algorithm>
using namespace std;
void dump(deque<int> &);
int main(){
  //init
  deque<int> testdeque {1, 2, 3, 4, 5};
  //stat
  cout<<"size: "<<testdeque.size()<<" empty?: "<<testdeque.empty()<<endl;
  //peak
  cout<<"head: "<<testdeque.front()<<" tail: "<<testdeque.back()<<endl;
  //iterate
  dump(testdeque);

  //push, insert
  testdeque.push_back(6);
  testdeque.push_front(0);
  testdeque.insert(testdeque.end(), {7,8,9});
  cout<<"After push and insert:"<<endl;
  dump(testdeque);
  //pop, remove
  testdeque.pop_front();
  testdeque.pop_back();
  testdeque.erase(testdeque.begin());
  //erase a range
  testdeque.erase(testdeque.begin()+3, testdeque.begin()+5);
  cout<<"After pop and remove:"<<endl;
  dump(testdeque);

  //reverse, sort
  sort(testdeque.begin(), testdeque.end());

  cout<<"testdeque:"<<endl;
  dump(testdeque);

  //intersection
  deque<int> secondDeque(testdeque);

  deque<int> resultDeque(testdeque.size()+secondDeque.size());


  auto it=set_intersection(testdeque.begin(), testdeque.end(), secondDeque.begin(), secondDeque.end(), resultDeque.begin());

  resultDeque.erase(it, resultDeque.end());
  dump(resultDeque);
  
  return 1;
}
void dump(deque<int> &tmp){
  for(int i: tmp){
    cout<< i <<" ";
  }
  cout<<endl;
}
