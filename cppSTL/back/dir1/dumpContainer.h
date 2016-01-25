#include <iostream>

template <typename CONTAINER>
void dump(CONTAINER &con){
  using namespace std;
  for(auto &e: con){
    cout<<e<<" ";
  }
  cout<<endl;
}
