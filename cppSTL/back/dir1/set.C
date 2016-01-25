#include<set>
#include<vector>
#include<iostream>
#include<iterator>
#include<algorithm>
using namespace std;
template <typename Container> 
void dump(Container &s){
  for(int i : s){
    cout<<i<<" ";
  }
  cout<<endl;
}
int main(){
  //initialization
  set<int> theSet({1, 3, 4, 5, 1, 2, 3});
  dump(theSet);
  //stat
  cout<<theSet.size()<<endl;
  //insert
  for(int i=0;i<10;i++){
    theSet.insert(rand()%100);
  }
  dump(theSet);
  //remove
  theSet.erase(1);
  dump(theSet);
  //count
  for(int i=0;i<20;i++){
    cout<<"How many "<<i<<"? "<<theSet.count(i)<<endl;
  }
  //find
  auto it = theSet.find(3);
  it=theSet.erase(it);
  dump(theSet);
  cout<<*it<<endl;
  //equal_range
  auto range_pair = theSet.equal_range(7);
  cout<<"equal_range(7): ";
  auto newIT = next(range_pair.second);
  for_each(range_pair.first, newIT, [](int a){cout<<a<<" ";});
  cout<<endl;
  //lower_bound
  //upper_bound
  for_each(theSet.lower_bound(1), theSet.upper_bound(10), [](int a){cout<<a<<" ";});
  cout<<endl;
  //prev, next, advance
  auto prevIT = prev(newIT, 2);
  auto nextIT = next(newIT, 5);
  for_each(prevIT, nextIT, [](int a){cout<<a<<"|";});
  //clear
  //
}
