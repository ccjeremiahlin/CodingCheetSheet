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
  set<int> theset;
  generate_n(inserter(theset, theset.end()), 10, [](){return rand()%100;});
  dump(theset);
  //stat
  //insert
  theset.insert(1000); 
  dump(theset);
  //remove
  theset.erase(1000);
  //lower_bound
  //upper_bound
  theset.erase(theset.lower_bound(20), theset.upper_bound(60));
  dump(theset);
  //count
  //find
  //equal_range
  auto range_pair = theset.equal_range(*theset.begin());
  for(auto it=range_pair.first;it!=range_pair.second;it++)cout<<*it<<" ";
  cout<<endl;
  //prev, next, advance
  auto itbegin_3 = theset.begin();
  advance(itbegin_3, 3);
  cout<<*itbegin_3<<endl;
  auto itbegin_1 = prev(itbegin_3, 2);
  auto itbegin_4 = next(itbegin_3, 1);
  cout<<*itbegin_1<<endl;
  cout<<*itbegin_3<<endl;
  cout<<*itbegin_4<<endl;
  //clear
}
