#include <vector>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <iostream>

using namespace std;
//left, right
// index 0 1
//      max(0+1, 0*1)
// index 0 1 2 
//      max(0, 1) 2   or  0, max(1, 2)
// index 0 1 2 3 
//      max(0) max(1,2,3) max(0,1) max(2,3), max(0,1,2) max(3) 

int findMaxValHelper(vector<vector<int> > &localResult, int left, int right, vector<int> &num){
  if(left>right)assert(false);
  if(left==right)return num[left];
  if(localResult[left][right]!=0) return localResult[left][right];
    int localMax = 0;
  for(int index=left;index<right;index++){
    int maxLeft = findMaxValHelper(localResult, left, index, num);
    int maxRight = findMaxValHelper(localResult, index+1, right, num);
    int tmpMax = max(maxLeft+maxRight, maxLeft*maxRight); 
    if(tmpMax>localMax)localMax=tmpMax;
  }
  localResult[left][right]=localMax;
  return localMax;
}

int findMaxExpressionValue(vector<int> &num){
  vector<vector<int> > localResult(num.size(), vector<int>(num.size(), 0));
  return findMaxValHelper(localResult, 0, num.size()-1, num); 
}

int main(){
  vector<int> num(5);

  generate(num.begin(), num.end(), [](){return rand()%5;});

  cout<<"Input: "<<endl;
  for(int i : num)
    cout<<i<<" ";
  cout<<endl;
  
  cout<<"Max: "<<findMaxExpressionValue(num)<<endl; 

  return 0;
}
