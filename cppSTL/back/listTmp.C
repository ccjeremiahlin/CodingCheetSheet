#include <list>
#include <iostream>
#include <iterator>
#include <cstdlib>
using namespace std;
void dump(list<int> &);
int main(){
  //init
  //stat
  //peak
  //iterate
  cout<<"iterating range based: ";
  //push
  //iterator and insert after 2
  //insert a list after end
  cout<<"After push and insert:"<<endl;
  //pop
  //erase from a position
  //erase from a range
  //remove if
  //reverse, sort
  //splice
  //merge
  list<int> otherList={1,2,3,4,5};

  //unique
  
//sort descending

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
