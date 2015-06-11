#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <future>
using namespace std; 
template <typename RAIter>
int parallel_sum(RAIter beg, RAIter end)
{
    auto len = end - beg;
    //set optimal computation condition
    if(len<1000){
      return accumulate(beg, end, 0);
    }
    //find middle
    auto mid = beg+len/2;
    //fire async execution
    future<int> handle = async(launch::async, parallel_sum<RAIter>, mid, end);
    
    int firsthalfSum = parallel_sum(beg, mid);
    
    //return result
    
    return firsthalfSum+handle.get();
}
 
int main()
{
    std::vector<int> v(10000, 2);
    std::cout << "The sum is " << parallel_sum(v.begin(), v.end()) << '\n';
}
