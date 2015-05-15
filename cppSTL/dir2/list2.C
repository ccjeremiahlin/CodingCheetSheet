#include <list>
#include <iostream>
#include <iterator>
#include <cstdlib>
#include <numeric>
using namespace std;
void dump(list<int> &);
int main(){
  //init
  list<int> theList(10, 0);
  iota(theList.begin(), theList.end(), 0);
  //stat
  cout<<"Size: "<<theList.size()<<endl;
  //peak
  cout<<"Front: "<<theList.front()<<" Back: "<<theList.back()<<endl;
  //iterate
  for(auto it=theList.begin(); it!=theList.end();it++){
    cout<<*it<<" ";
  }
  cout<<endl;
  //push
  for(int i=0;i<10;i++){
    theList.push_back(10+i);
    theList.push_front(-1-i);
  }
  dump(theList);
  //iterator and insert after 2
  auto it=theList.begin();
  advance(it, 2); 
  theList.insert(it, 100);
  dump(theList);
  //insert a list after end
  theList.insert(theList.end(), {101, 102, 103});
  dump(theList);
  //pop
  for(int i=0;i<10;i++){
    theList.pop_front();
    theList.pop_back();
  }
  dump(theList);
  //erase from a position
  it=theList.begin();
  advance(it, 7);
  it=theList.erase(it);
  dump(theList);
  //erase from a range
  theList.erase(it, theList.end());
  dump(theList);
  //remove if
  remove_if(theList.begin(), theList.end(), [](int a){ return a<0;});
  dump(theList);
  //reverse, sort
  theList.reverse();
  dump(theList);
  theList.sort();
  dump(theList);
  //splice
  list<int> otherList={1,2,3,4,5};
  theList.splice(theList.end(), otherList);
  dump(otherList);
  dump(theList);
  //merge
  list<int> otherList2={1,2,3,4,5};
  theList.sort();
  theList.merge(otherList2);
  dump(otherList2);
  dump(theList);
  //unique
  
//sort descending
  theList.sort(greater<int>());
  dump(theList);
//non-modifying sequences operations
  //all_of, any_of, none_of
  //for_each
  //count, count_if
  //mismatch
  //equal
  //find, find_if, find_if_not, find_end, find_first_of
  //adjacent_find
  //search, search_n

//modifying sequences operations
  //
//Partitioning operations
  //
//Sorting operations
//
//Binary Search operations
//
//Set operations
  //difference
  //symmetric difference
  //intersection
  //union
//Heap Operations
//
//min/max Operations
//
//Numeric Operations
//
//C library, qsort, bsearch
//
//
  return 0;
}
void dump(list<int> &tmp){
  for(int i: tmp){
    cout<< i <<" ";
  }
  cout<<endl;
}
