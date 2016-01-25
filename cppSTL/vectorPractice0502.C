#include <vector>
#include <iostream>
#include "dumpContainer.h"
#include <algorithm>
#include <numeric>
using namespace std;


int main(){
  //init vector
  vector<int> integerArray(10, 0);
  dump(integerArray); 
  //fill with integer sequence
  iota(integerArray.begin(), integerArray.end(), 0);
  dump(integerArray);
  //create from another vector
  vector<int> secondIntegerArray(integerArray.begin(), integerArray.end());
  dump(secondIntegerArray);
  vector<int> thirdIntegerArray(secondIntegerArray);
  dump(thirdIntegerArray);
  vector<int> fourthIntegerArray(move(thirdIntegerArray));
  cout<<"After Moved: size of Third Integer become "<<thirdIntegerArray.size()<<endl;
  dump(thirdIntegerArray);
  dump(fourthIntegerArray);
  //assign new value to original vector
  fourthIntegerArray.assign(fourthIntegerArray.size(), 4); 
  dump(fourthIntegerArray);
  integerArray.assign(secondIntegerArray.begin(), secondIntegerArray.end());
  dump(integerArray);

  //Element access
  integerArray.front() = 100;
  integerArray.back() = 200;
  dump(integerArray);

  //erase among looping? not a good method in a vector (introducing shifting effort)

  //reserve
  cout<<"Capacity before reserve: "<<integerArray.capacity()<<endl;
  integerArray.reserve(20);
  cout<<"Capacity after reserve: "<<integerArray.capacity()<<endl;
  cout<<"size() after reserve: "<<integerArray.size()<<endl;
  cout<<"max size(): "<<integerArray.max_size()<<endl;
  dump(integerArray);


  //add something to the end or in the middle

  integerArray.insert(integerArray.begin()+3, 3);
  dump(integerArray);

  //insert( pos, count, value )
  integerArray.insert(integerArray.end(), 5, 55);
  dump(integerArray);
  vector<int> tmp(5);

  //insert( pos, it1, it2)
  iota(tmp.begin(), tmp.end(), 500);
  integerArray.insert(integerArray.end(), tmp.begin(), tmp.end());
  dump(integerArray);


  //resize(count, value)
  integerArray.resize(integerArray.size()+10, 1000);
  dump(integerArray);

  //erase( pos, it1, it2)
  integerArray.erase(integerArray.end()-5, integerArray.end());
  dump(integerArray);

  return 0;
}
