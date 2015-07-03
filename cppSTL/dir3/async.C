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
    if(len<100){
      return accumulate(beg, end, 0);
    }
    //find middle
    auto middle = beg+(len/2);
    
    //fire async execution
    future<int> sndhalf = async(launch::async, parallel_sum<RAIter>, middle, end);
    int firhalf = parallel_sum(beg, middle);
    //return result
    return firhalf+sndhalf.get();
}
 
int main()
{
    std::vector<int> v(10000, 1);
    iota(v.begin(), v.end(), 0);
    std::cout << "The sum is " << parallel_sum(v.begin(), v.end()) << '\n';
}
