#include <vector>
#include <algorithm>
#include <future>
#include <iostream>
#include <numeric>
using namespace std;

template <typename RDIter, typename T>
T parallel_sum(RDIter beg, RDIter end){
  auto diff = end-beg;
  if(diff < 100){
    return accumulate(beg, end, T());
  }
  auto mid = beg + diff/2;
  future<T> sndHalf = async(launch::async, parallel_sum<RDIter, T>, mid, end);// note the template instantiation syntax
  T firstHalf = parallel_sum<RDIter, T>(beg, mid); 
  return firstHalf + sndHalf.get();
}
int main(){
  vector<int> testdata;
  fill_n(back_inserter(testdata), 10000, 1);
  cout<<parallel_sum<vector<int>::iterator, int>(testdata.begin(), testdata.end())<<endl;//note the template instantiation syntax
  return 0;
}
