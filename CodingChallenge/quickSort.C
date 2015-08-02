#include <vector>
#include <iostream>
using namespace std;

int partition(vector<int> &input, int begin , int end){
  int pivotIndex = rand()%(end-begin)+begin;
  int pivotValue = input[pivotIndex];
  swap(input[pivotIndex], input[end]);
  int smaller=begin;
  for(int i=begin;i<end;i++){
    if(input[i]<pivotValue){
      swap(input[i], input[smaller++]);
    }
  }
  swap(input[end], input[smaller]);
  return smaller;
}

void quicksortHelper(vector<int> &input, int begin, int end){
  if(begin>=end) return;
  int pos = partition(input, begin, end);
  quicksortHelper(input, begin, pos-1);
  quicksortHelper(input, pos+1, end);
}

void quicksort(vector<int> &input){
  quicksortHelper(input, 0, input.size()-1);
}

int main(){
  vector<int> testdata;
  srand(time(0));
  generate_n(back_inserter(testdata), 20, [](){return rand()%20;});
  quicksort(testdata);
  for(int a:testdata){
    cout<<a<<" ";
  }
  cout<<endl;
}
