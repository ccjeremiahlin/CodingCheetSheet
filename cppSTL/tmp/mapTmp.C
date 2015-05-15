#include<map>
#include<iostream>
#include<string>
using namespace std;
void dump(map<int, string> &);
int main(){
  //initialization

  //stat

  //insert
  //remove
  //lower_bound, upperbound
  //count
  //find
  //prev, next, advance
  //clear
  //
}
void dump(map<int, string> &s){
  for(auto p : s){
    cout<<" key: "<<p.first<<" value: "<<p.second;
  }
  cout<<endl;
}
