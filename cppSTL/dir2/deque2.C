#include <deque>
#include <numeric>
#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;
void dump(deque<int> &dq){
  for(int a : dq){
    cout<<a<<" ";
  }
  cout<<endl;
}

int main(){
  srand(time(NULL));
  //init and assign values
  deque<int> mydeq(10);
  iota(mydeq.begin(), mydeq.end(), 0);
  dump(mydeq);
  iota(mydeq.rbegin(), mydeq.rend(), 0);
  dump(mydeq);
  generate(mydeq.begin(), mydeq.end(), [](){return rand()%10;});
  dump(mydeq);
  
  //pop front/back
  mydeq.pop_front();
  mydeq.pop_back();
  //push front/back
  mydeq.push_front(100);
  mydeq.push_back(200);
  //insert 
  deque<int> secondqueue(10, 0);
  generate(secondqueue.begin(), secondqueue.end(), rand);
  mydeq.insert(mydeq.begin()+rand()%mydeq.size(), 12345);
  mydeq.insert(mydeq.begin()+rand()%mydeq.size(), secondqueue.begin(), secondqueue.end());
  dump(mydeq);
  //erase
  mydeq.erase(mydeq.begin()+rand()%mydeq.size());
  dump(mydeq);
  //sort descending
  sort(mydeq.begin(), mydeq.end(), greater<int>());
  dump(mydeq);
  //random shuffle
  random_shuffle(mydeq.begin(), mydeq.end());
  dump(mydeq);
  //nth_element;
  nth_element(mydeq.begin(), mydeq.begin()+5, mydeq.end());
  dump(mydeq);
  //non-modifying sequences operations
  //all_of, any_of, none_of
  cout<<"is all number >0? "<<boolalpha<<all_of(mydeq.begin(), mydeq.end(), [](int a){return a>0;})<<endl;
  cout<<"any number ==0? "<<boolalpha<<any_of(mydeq.begin(), mydeq.end(), [](int a){return a==0;})<<endl;
  cout<<"any number <0? "<<boolalpha<<any_of(mydeq.begin(), mydeq.end(), [](int a){return a<0;})<<endl;
  cout<<"none number <0? "<<boolalpha<<none_of(mydeq.begin(), mydeq.end(), [](int a){return a<0;})<<endl;
  //for_each
  //count, count_if
  cout<<"count number ==0 "<<count(mydeq.begin(), mydeq.end(), 0)<<endl;
  cout<<"count number >0 "<<count_if(mydeq.begin(), mydeq.end(), [](int a){return a>0;})<<endl;
  //mismatch
  //equal
  //find, find_if, find_if_not, find_end, find_first_of
  //adjacent_find
  //search, search_n

//modifying sequences operations
  //copy, copy_if, copy_n, copy_backward
  //move, move_backward, 
  //fill, fill_n
  //transform
  //generate, generate_n
  //remove, remove_if, remove_copy, remove_copy_if
  //replace, replace_if, replace_copy, replace_copy_if, 
  //swap, swap_ranges, iter_swap
  //reverse, reverse_copy, 
  //rotate, rotate_copy
  //random_shuffle
  //unique, unique_copy
  
//Partitioning operations
  // is_partitioned
  // partition, stable_partition, partion_copy
  // partition_point
  
//Sorting operations
  // is_sorted, is_sorted_until
  // sort, partial_sort, partial_sort_copy, stable_sort
  // nth_element
  
//Binary Search operations //ON SORTED RANGE
  //lower_bound, upper_bound, equal_range
  //binary_search
//Set operations //ON SORTED RANGE
  //merge, inplace_merge
  //set_difference
  //set_symmetric_difference
  //set_intersection
  //set_union
//Heap Operations
  //is_heap, is_heap_until
  //make_heap, push_heap, pop_heap, sort_heap
//min/max Operations
  //max_element, min_element, minmax_element
//Numeric Operations
  // itoa
  // accumulate
  // inner_product
  // adjacent_difference
  // partial_sum
}
