#include <iostream> 
#include <vector>
using namespace std;

class FileDescriptor{
  vector<int> fd;
  int idx;
  public:
  FileDescriptor(vector<int> v){
    fd = v;
    idx=0;
  }
  bool hasNext(){
    return idx<fd.size();
  }
  int next(){
    return fd[idx++];
  }
};

bool isOneOrLessEditDistance(FileDescriptor &a, FileDescriptor &b){
  vector<vector<int>> dp(2, vector<int>(2, 0));
  vector<int> aPrev, bPrev;

  while(a.hasNext() && b.hasNext()){
    int aCur = a.next(), bCur = b.next();

    if(aPrev.empty() || aPrev[0]!=bCur){
      dp[1][0] = min(dp[1][0], dp[1][1]) + 1;
    }//else aPrev[0]==bCur, dp[1][0] stay the same

    if(bPrev.empty() || bPrev[0]!=aCur){
      dp[0][1] = min(dp[0][1], dp[1][1]) + 1;
    }//else stay the same

    if(aCur!=bCur){
      dp[1][1] = min(dp[1][1], min(dp[0][1], dp[1][0])) + 1 ; 
    }
    if(min(dp[1][1], min(dp[0][1], dp[1][0])) > 1) return false; 
    if(aPrev.empty()) aPrev.push_back(aCur); else aPrev[0]=aCur;
    if(bPrev.empty()) bPrev.push_back(bCur); else bPrev[0]=bCur;
  }

  if(a.hasNext()){
    int aCur = a.next(); 
    if((bPrev.empty() || bPrev[0]!=aCur)){
      dp[0][1] = min(dp[0][1], dp[1][1]) + 1 ;
    }
    return dp[0][1]<=1 && !a.hasNext();
  }
  if(b.hasNext()){
    int bCur = b.next(); 
    if(aPrev.empty() || aPrev[0]!=bCur){
      dp[1][0] = min(dp[1][0], dp[1][1]) + 1 ;
    }
    return dp[1][0]<=1 && !b.hasNext();
  }
  return dp[1][1]<=1;
}

int main(){
  
  FileDescriptor A(vector<int>({1, 2, 4}));
  FileDescriptor B(vector<int>({1, 3}));
  
  cout<<boolalpha<<isOneOrLessEditDistance(A, B)<<endl;

  FileDescriptor C(vector<int>({1, 2, 4}));
  FileDescriptor D(vector<int>({1, 3, 4}));
  
  cout<<boolalpha<<isOneOrLessEditDistance(C, D)<<endl;

  FileDescriptor E(vector<int>({1, 2, 3, 3}));
  FileDescriptor F(vector<int>({1, 3, 3}));
  
  cout<<boolalpha<<isOneOrLessEditDistance(E, F)<<endl;

  FileDescriptor G(vector<int>({1, 2, 3, 3}));
  FileDescriptor H(vector<int>({2, 3, 3}));
  
  cout<<boolalpha<<isOneOrLessEditDistance(G, H)<<endl;

  FileDescriptor I(vector<int>({1, 2, 3, 3, 3}));
  FileDescriptor J(vector<int>({2, 3, 3}));
  
  cout<<boolalpha<<isOneOrLessEditDistance(I, J)<<endl;

  FileDescriptor K(vector<int>({1}));
  FileDescriptor L(vector<int>({}));
  
  cout<<boolalpha<<isOneOrLessEditDistance(K, L)<<endl;

  FileDescriptor M(vector<int>({1, 1, 3}));
  FileDescriptor N(vector<int>({1, 2, 3, 3}));
  
  cout<<boolalpha<<isOneOrLessEditDistance(M, N)<<endl;

}
