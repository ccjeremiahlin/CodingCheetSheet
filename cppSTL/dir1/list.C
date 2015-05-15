#include <list>
#include <iostream>
#include <iterator>
#include <cstdlib>
using namespace std;
void dump(list<int> &);
int main(){
  //init
  list<int> testList {1, 2, 3, 4, 5};
  //stat
  cout<<"size: "<<testList.size()<<" empty?: "<<testList.empty()<<endl;
  //peak
  cout<<"head: "<<testList.front()<<" tail: "<<testList.back()<<endl;
  //iterate
  cout<<"iterating traditional: ";
  for(auto itr=testList.begin();itr!=testList.end();itr++){
    cout<<*itr<<" ";
  }
  cout<<endl;
  cout<<"iterating range based: ";
  for(int element : testList){
    cout<<element<<" ";
  }
  cout<<endl;

  //push, insert
  testList.push_back(6);
  testList.push_front(0);
  auto pos=testList.begin();
  advance(pos, 2);
  testList.insert(pos, 2);
  testList.insert(testList.end(), {7,8,9});
  cout<<"After push and insert:"<<endl;
  dump(testList);
  //pop, remove
  testList.pop_front();
  testList.pop_back();
  testList.erase(testList.begin());
  //erase a range
  auto pos2 = testList.begin();
  auto pos1 = testList.begin();
  advance(pos1, 1);
  advance(pos2, 2);
  testList.erase(testList.begin(), pos2);
  //remove if
  testList.remove_if([](int e){
      return e<5; 
      });
  cout<<"After pop and remove:"<<endl;
  dump(testList);

  cout<<"pos1: "<<*pos1<<endl;
  cout<<"pos2: "<<*pos2<<endl;


  testList.push_back(rand());
  //reverse, sort
  testList.reverse();
  testList.sort();

  //splice
  list<int> otherList={3,4,1,2,6,9};
  cout<<"otherList:"<<endl;
  dump(otherList);

  pos1=testList.begin();
  advance(pos1, 3);
  testList.splice(pos1, otherList);

  cout<<"testList:"<<endl;
  dump(testList);
  cout<<"otherList:"<<endl;
  dump(otherList);

  testList.splice(testList.begin(), testList, pos1);
  cout<<"after slice testList:"<<endl;
  dump(testList);
  
  //merge, unique
  otherList={1,2,3,4,5};
  testList.sort();
  testList.merge(otherList);
  testList.unique();

  cout<<"testList:"<<endl;
  dump(testList);
  cout<<"otherList:"<<endl;
  dump(otherList);

  return 0;
}
void dump(list<int> &tmp){
  for(int i: tmp){
    cout<< i <<" ";
  }
  cout<<endl;
}
