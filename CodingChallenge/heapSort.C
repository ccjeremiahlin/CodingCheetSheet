#include <vector>
#include <iostream>
using namespace std;

using It = vector<int>::iterator;

void heapify(It begin, It from, It end){
  if(from>=end) return;
  It larger = from; 
  It left = from+(from-begin)+1;
  It right = from+(from-begin)+2;
  if(left<end && *left>*larger) larger = left;
  if(right<end && *right>*larger) larger = right;
  if(larger!=from){
    swap(*from, *larger);
    heapify(begin, larger, end);
  }
}

void mymake_heap(It begin, It end){
  int middle = (end-begin)/2;
  for(It it=begin+middle; it>=begin;--it){
    heapify(begin, it, end);
  }
}
void mypop_heap(It begin, It end){
  swap(*begin, *(end-1));
  heapify(begin, begin, end-1);
}

void heapsort(vector<int> &input){
  /*
   * make_heap
   * pop_heap
   */
  mymake_heap(input.begin(), input.end());
  for(int i=0;i<input.size();i++){
    mypop_heap(input.begin(), input.end()-i);
  }
}

int main(){
  vector<int> testdata;
  srand(time(0));
  generate_n(back_inserter(testdata), 20, [](){return rand()%20;});
  heapsort(testdata);
  for(int a:testdata){
    cout<<a<<" ";
  }
  cout<<endl;
}
