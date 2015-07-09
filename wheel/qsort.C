#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &A, int begin, int end){
  int pivot = A[begin];
  int smaller = begin+1;
  for(int i=begin+1;i<=end;i++){
    if(A[i]<pivot){
      swap(A[i], A[smaller++]);
    }
  }
  swap(A[begin], A[smaller-1]);
  return smaller-1;
}

void myqsort(vector<int> &A, int begin, int end){
  if(begin>=end) return;
  int pos = partition(A, begin, end);
  myqsort(A, begin, pos-1);
  myqsort(A, pos+1, end);
}

int main(){
  vector<int> intary;
  srand(time(0));
  generate_n(back_inserter(intary), 20, [](){return rand()%10;});
  myqsort(intary, 0, intary.size()-1);
  for(int a: intary){
    cout<<a<<" ";
  }
  cout<<endl;
}
