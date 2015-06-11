#include <vector>
#include <mutex>
#include <string>
#include <iostream>
#include <functional>
#include <thread>
using namespace std;


class HashTable{
  vector<vector<pair<string, string>>> iarray;
  long capacity;
  size_t getHashIndex(string key){
    hash<string> hash_fn;
    return hash_fn(key)%capacity;
  }
  vector<mutex> muVex;

public:
  HashTable(long capacity){
    this->capacity = capacity;
    iarray.reserve(capacity);
    muVex=vector<mutex>(100);
  }
  void insert(string key, string value){
    size_t hashIndex = getHashIndex(key);
    unique_lock<mutex> l1(muVex[hashIndex]);
    for(int i=0;i<iarray[hashIndex].size();i++){
      if(iarray[hashIndex][i].first==key){
        iarray[hashIndex][i].second = value;
        return;
      }
    }
    iarray[hashIndex].push_back(make_pair(key, value));
  }
  string get(string key){
    size_t hashIndex = getHashIndex(key);
    unique_lock<mutex> l1(muVex[hashIndex]);
    for(int i=0;i<iarray[hashIndex].size();i++){
      if(iarray[hashIndex][i].first==key){
        return iarray[hashIndex][i].second;
      }
    }
    return "";
  }
};

HashTable ht(100);

void task(int id){
  for(int i=0;i<10;i++){
    switch(id&1){
      case 0:
        ht.insert(to_string(i), to_string(i*i));
        break;
      case 1:
        cout<<"Looking for "<<i<<" : "<<ht.get(to_string(i))<<endl;
        break;
    }
  }
}
int main(){
  thread th1(task, 0);
  thread th2(task, 1);

  th1.join();
  th2.join();

  return 0;
}
