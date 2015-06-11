#include <iostream>

using namespace std;

int fib(int n){
  // fn = fn-1 + fn-2
  // fn-2 = fn - fn-1
  if(n==0 || n==1) return 1;
  if(n>0){
    int fn_1=1;
    int fn_2=1;
    int fn;
    for(int i=2;i<=n;i++){
      fn = fn_1+fn_2;
      fn_2 = fn_1;
      fn_1 = fn;
    }
    return fn;
  }
  if(n<0){
    int fn_2;
    int fn=1;
    int fn_1=1;
    for(int i=-1;i>=n;i--){
      fn_2 = fn - fn_1;
      fn = fn_1;
      fn_1 = fn_2;
    }
    return fn_2;
  }
  return 0;
}
int main(){
  for(int i=0;i<10;i++){
    cout<<fib(i)<<" ";
  }
  cout<<endl;
  for(int i=0;i>-10;i--){
    cout<<fib(i)<<" ";
  }
  cout<<endl;
  return 0;
}
