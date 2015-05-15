#include<map>
#include<iostream>
#include<string>
using namespace std;
void dump(map<int, string> &);
int main(){
  //initialization
  map<int,string> s={{1,"one"},{2,"two"},{4,"four"},{3,"three"},{5,"five"}};
  dump(s);

  //stat
  cout<<"size: "<<s.size()<<" empty?: "<<s.empty()<<endl;

  //insert
  auto pair=s.insert(make_pair(2,"twotwo")); 
  cout<<"inserting 2: itr_of_2 -> key: "<<pair.first->first<<" value: "<<pair.first->second<<" succesful?: "<<boolalpha<<pair.second<<endl;
  s.insert({{6,"six"},{7,"seven"}});
  dump(s);
  //remove
  //lower_bound, upperbound
  s.erase(2);
  s.erase(s.lower_bound(1), s.upper_bound(3)); 
  dump(s);
  //count
  cout<<"cout 4"<<s.count(4)<<endl;
  //find
  cout<<boolalpha<<(s.find(3)!=s.end())<<endl;
  //prev, next, advance
  auto pos = s.find(4);
  advance(pos, 1);
  auto next2 = next(pos, 2);
  s.erase(pos, next2);
  dump(s);
  //clear
  //
}
void dump(map<int, string> &s){
  for(auto p : s){
    cout<<" key: "<<p.first<<" value: "<<p.second;
  }
  cout<<endl;
}
