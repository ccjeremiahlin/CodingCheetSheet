#include <deque>
#include <numeric>
#include <iostream>
#include <algorithm>
using namespace std;
void dump(deque<int> &dq){
  for(int i=0;i<10;i++){
    cout<<"=";
  }
  cout<<endl;
  for(int a : dq){
    cout<<a<<" ";
  }
  cout<<endl;
}

int main(){
//increasing init
deque<int> dq(100); 
iota(dq.begin(),dq.end(), 0); 
dump(dq);
//pop front/back
dq.pop_front(); dq.pop_back();
dump(dq);
//
//push front/back
dq.push_front(100); dq.push_back(1000);
dump(dq);
//insert 
auto it= dq.insert(dq.begin()+rand()%dq.size(), 12345);
dump(dq);
//erase
dq.erase(it);
dump(dq);
//sort descending
sort(dq.begin(), dq.end(), std::greater<int>());
dump(dq);
//non-modifying sequences operations
  //all_of, any_of, none_of
  cout<<endl;
  cout<<boolalpha<<"All<100000? "<<all_of(dq.begin(), dq.end(), [](int a){return a<1000000;})<<endl;
  cout<<boolalpha<<"Any == 10 "<<any_of(dq.begin(), dq.end(), [](int a){return a==10;})<<endl;
  cout<<boolalpha<<"None > 100000 "<<none_of(dq.begin(), dq.end(), [](int a){return a>100000;})<<endl;
  //for_each
  //count, count_if
  cout<<"Number of 10: "<<count(dq.begin(), dq.end(), 10)<<endl;
  cout<<"Number of element 0<e<50: "<<count_if(dq.begin(), dq.end(), [](int a){ return a>0 && a<50;})<<endl;
  //mismatch
  deque<int> dq2(100, 0);
  auto p=mismatch(dq.begin(), dq.end(), dq2.begin());
  cout<<"First mismatch: dq: "<<*(p.first)<<" dq2: "<<*(p.second)<<endl;
  //equal
  cout<<boolalpha<<"is equal? "<<equal(dq.begin(), dq.end(), dq2.begin())<<endl;
  //find, find_if, find_if_not, find_end, find_first_of
  cout<<*find(dq.begin(), dq.end(), 10)<<endl;
  cout<<*find_if(dq.begin(), dq.end(), [](int a){ return a<5;})<<endl;
  cout<<*find_if_not(dq.begin(), dq.end(), [](int a){ return a<5;})<<endl;
  cout<<*find_first_of(dq.begin(), dq.end(), dq2.begin(), dq2.end())<<endl;
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
}
