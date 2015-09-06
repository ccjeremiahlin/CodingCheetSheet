/*
 * Utilizing leetcode test cases for One Edit Distance to verify the FileDescriptor API on-the-fly problem
 * https://leetcode.com/problems/one-edit-distance/
 */

class FileDescriptor{
  string fd;
  int idx;
  public:
  FileDescriptor(string v){
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

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        FileDescriptor a(s);
        FileDescriptor b(t);
        return isOneOrLessEditDistance(a, b);
    }
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
        return dp[0][1]==1 && !a.hasNext();
      }
      if(b.hasNext()){
        int bCur = b.next(); 
        if(aPrev.empty() || aPrev[0]!=bCur){
          dp[1][0] = min(dp[1][0], dp[1][1]) + 1 ;
        }
        return dp[1][0]==1 && !b.hasNext();
      }
      return dp[1][1]==1;
    }
    
};


