#include<map>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void dump(map<int, string, greater<int>> &);
int main(){
  //initialization
  srand(time(NULL));
  map<int, string, greater<int>> themap;
  for(int i=0;i<10;i++){
    string tmp;
    for(int j=0;j<6;j++){
      tmp.push_back(rand()%26+'a');
    }
    themap[i] = tmp;
  }
  dump(themap);
  //stat

  //insert
  themap[5] = "55555";
  dump(themap);
  //remove
  //lower_bound, upperbound
  themap.erase(themap.lower_bound(5), themap.upper_bound(3));
  dump(themap);
  //count
  //find
  //prev, next, advance
  auto p = themap.begin();
  advance(p, 3);
  cout<<"Begin + 3, key: "<<p->first <<" value: "<<p->second<<endl;
  //clear
  themap.clear();
}
void dump(map<int, string, greater<int>> &s){
  for(auto p : s){
    cout<<" key: "<<p.first<<" value: "<<p.second;
  }
  cout<<endl;
}
