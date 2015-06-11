#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<typename T>
class MySet{
  //collision
  // chaining: easier to code, worst case O(n)
  // open addressing: different hash code or +1 rule. Collision propogation
  vector<vector<T>> iarray;
  int _size;
  int _bucketUsed;
  int _capacity;
  std::hash<T> hn;

  public:
  MySet():_size(0), _capacity(4), _bucketUsed(0){
    iarray = vector<vector<T>>(4, vector<T>());
  }
  bool insert(const T &v){
    //1. rehashing if threshold reached
    while(_bucketUsed==_capacity){
      size_t newcapacity = _capacity<<1;
      size_t newBucketUsed = 0;
      vector<vector<T>> newiarray(newcapacity);
      for(int i=0;i<_capacity;i++){
        for(int j=0;j<iarray[i].size();j++){
          size_t newHashIndex = hn(iarray[i][j])%newcapacity;
          if(newiarray[newHashIndex].empty())newBucketUsed++;
          newiarray[newHashIndex].push_back(iarray[i][j]);
        }
      }
      cout<<"Capacity grew from "<<_capacity<<" to "<<newcapacity<<endl;
      _bucketUsed = newBucketUsed;
      _capacity = newcapacity;
      iarray.swap(newiarray);
    }
    //2. collision
    size_t hashIndex = hn(v)%_capacity; 
    cout<<"Hash Index "<<hashIndex<<endl;
    if(iarray[hashIndex].empty()){
      _bucketUsed++;
    }else{
      for(int i=0;i<iarray[hashIndex].size();i++){
        if(iarray[hashIndex][i]==v) return false;
      }
    }
    iarray[hashIndex].push_back(v);
    _size++;

    return true;
    //3. iterator (skipped)
  }
  size_t count(const T& key){
    size_t hashindex = hn(key)%_capacity;
    for(int i=0;i<iarray[hashindex].size();i++){
      if(iarray[hashindex][i]==key)return 1;
    }
    return 0;
  }
};

int main(){
  MySet<string> ms;
  for(int i=0;i<16;i++){
    string tmp; tmp.push_back('a'+i);
    ms.insert(tmp);
    cout<<"finding "<<tmp<<" : "<<ms.count(tmp)<<" finding "<<tmp+" lala "<<ms.count(tmp+ " lala ")<<endl;
  }
  for(int i=0;i<16;i++){
    string tmp; tmp.push_back('a'+i);
    cout<<"finding "<<tmp<<" : "<<ms.count(tmp)<<endl;
  }
  return 0;
}
