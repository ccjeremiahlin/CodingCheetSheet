#include "myVector.h"
#include <iostream>
using namespace std;
int main(){
  myVector<int> myV;
  for(int i=0;i<5;i++){
    myV.push_back(i);
  }
  for(int i:myV){
    cout<<i<<" ";
  }
  cout<<endl;
}
